from sys import argv, exit, stderr
import os
import re
import rospkg
import rosmsg

def is_identifier(s):
    return re.match('^[a-zA-Z_][a-zA-Z0-9_]*$', s)

fast_write_types = {'int32': 'Int32', 'float32': 'Float', 'float64': 'Double'}

# parse a type specification, such as Header, geometry_msgs/Point, or string[12]
class TypeSpec:
    ctype_builtin = {
            'bool':         'uint8_t',
            'int8':         'int8_t',
            'uint8':        'uint8_t',
            'int16':        'int16_t',
            'uint16':       'uint16_t',
            'int32':        'int32_t',
            'uint32':       'uint32_t',
            'int64':        'int64_t',
            'uint64':       'uint64_t',
            'float32':      'float',
            'float64':      'double',
            'string':       'std::string',
            'time':         'ros::Time',
            'duration':     'ros::Duration'
    }
    deprecated_builtins = {
            'byte':         'int8',
            'char':         'uint8'
    }
    def __init__(self, s):
        self.array = False
        self.array_size = None
        m = re.match(r'^(.*)\[(\d*)\]$', s)
        if m:
            self.array = True
            s = m.group(1)
            if len(m.group(2)) > 0:
                self.array_size = int(m.group(2))
        # perform substitutions:
        if s in self.deprecated_builtins: s = self.deprecated_builtins[s]
        # check builtins:
        self.builtin = s in self.ctype_builtin
        self.fullname = s
        if self.builtin:
            self.mtype = s
        else:
            if '/' not in s:
                raise ValueError('bad type: %s' % s)
            tok = s.split('/')
            if len(tok) != 2:
                raise ValueError('bad type: %s' % s)
            if not is_identifier(tok[0]) or not is_identifier(tok[1]):
                raise ValueError('bad type: %s' % s)
            self.package = tok[0]
            self.mtype = tok[1]

    # normalize fullname to C identifier (replace / with __)
    def normalized(self):
        return ('{}__'.format(self.package) if not self.builtin else '') + self.mtype

    # get C++ type declaration
    def ctype(self):
        if self.builtin: return self.ctype_builtin[self.mtype]
        return self.package + '::' + self.mtype

    def __str__(self):
        t = self.mtype
        if not self.builtin:
            t = self.package + '/' + t
        if self.array:
            t += '[]'
        return t

# parse msg / srv definition
def get_fields(lines):
    fields = {}

    for ln in lines:
        if ln.startswith('  '):
            # ignore expansions of nested types
            continue

        if ln == '':
            # ignore empty lines
            continue

        ln_orig1 = ln

        ln = ln.replace('=',' = ')

        tokens = ln.split()

        if len(tokens) == 4 and tokens[2] == '=':
            # it's a constant definition: ignore
            continue

        if len(tokens) == 2:
            t = TypeSpec(tokens[0])
            n = tokens[1]
            fields[n] = t
        else:
            raise ValueError('unrecognized line: ' + ln_orig1)

    return fields

# parse msg definition
def get_msg_fields(msg_name, rospack=None):
    lines = rosmsg.get_msg_text(msg_name, False, rospack).splitlines()
    return get_fields(lines)

# parse srv definition
def get_srv_fields(srv_name, rospack=None):
    lines = rosmsg.get_srv_text(srv_name, False, rospack).splitlines()
    sep = '---'
    if sep not in lines:
        raise ValueError('bad srv definition')
    i = lines.index(sep)
    return get_fields(lines[:i]), get_fields(lines[i+1:])

def generate_msg_wr_h(gt, fields, d, f):
    s = '''
void write__{norm}(const {ctype}& msg, int stack, const WriteOptions *opt = NULL);
'''.format(**d)
    f.write(s)

def generate_msg_rd_h(gt, fields, d, f):
    s = '''
void read__{norm}(int stack, {ctype} *msg, const ReadOptions *opt = NULL);
'''.format(**d)
    f.write(s)

def generate_msg_cb_h(gt, fields, d, f):
    s = '''
void ros_callback__{norm}(const boost::shared_ptr<{ctype} const>& msg, SubscriberProxy *proxy);
'''.format(**d)
    f.write(s)

def generate_msg_h(gt, fields, d, f):
    generate_msg_wr_h(gt, fields, d, f)
    generate_msg_rd_h(gt, fields, d, f)
    generate_msg_cb_h(gt, fields, d, f)

def generate_msg_wr_cpp(gt, fields, d, f):
    wf = '''
void write__{norm}(const {ctype}& msg, int stack, const WriteOptions *opt)
{{
    try
    {{
        simPushTableOntoStackE(stack);
'''.format(**d)
    for n, t in fields.items():
        d1 = d
        d1['n'] = n
        d1['t'] = t
        d1['ctype1'] = t.ctype()
        d1['nf'] = '{}::{}'.format(gt.ctype(), n)
        d1['norm1'] = t.normalized()
        if t.array:
            if t.builtin and t.mtype in fast_write_types:
                wf += '''
        try
        {{
            // write field '{n}' (using fast specialized function)
            simPushStringOntoStackE(stack, "{n}", 0);
            simPush{fast_write_type}TableOntoStackE(stack, &(msg.{n}[0]), msg.{n}.size());
            simInsertDataIntoStackTableE(stack);
        }}
        catch(exception& ex)
        {{
            std::string msg = "field '{n}': ";
            msg += ex.what();
            throw exception(msg);
        }}'''.format(fast_write_type=fast_write_types[t.mtype], **d1)
            elif t.builtin and t.mtype == 'uint8':
                wf += '''
        try
        {{
            // write field '{n}' (using fast specialized function)
            simPushStringOntoStackE(stack, "{n}", 0);
            if(opt && opt->uint8array_as_string)
                simPushStringOntoStackE(stack, (simChar*)&(msg.{n}[0]), msg.{n}.size());
            else
                simPushUInt8TableOntoStackE(stack, &(msg.{n}[0]), msg.{n}.size());
            simInsertDataIntoStackTableE(stack);
        }}
        catch(exception& ex)
        {{
            std::string msg = "field '{n}': ";
            msg += ex.what();
            throw exception(msg);
        }}'''.format(**d1)
            else:
                wf += '''
        try
        {{
            // write field '{n}'
            simPushStringOntoStackE(stack, "{n}", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.{n}.size(); i++)
            {{
                write__int32(i + 1, stack, opt);
                write__{norm1}(msg.{n}[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }}
            simInsertDataIntoStackTableE(stack);
        }}
        catch(exception& ex)
        {{
            std::string msg = "field '{n}': ";
            msg += ex.what();
            throw exception(msg);
        }}'''.format(**d1)
        else:
            wf += '''
        try
        {{
            // write field '{n}'
            simPushStringOntoStackE(stack, "{n}", 0);
            write__{norm1}(msg.{n}, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }}
        catch(exception& ex)
        {{
            std::string msg = "field '{n}': ";
            msg += ex.what();
            throw exception(msg);
        }}'''.format(**d1)
    wf += '''
    }}
    catch(exception& ex)
    {{
        std::string msg = "write__{norm}: ";
        msg += ex.what();
        throw exception(msg);
    }}
}}

'''.format(**d)
    f.write(wf)

def generate_msg_rd_cpp(gt, fields, d, f):
    rf = '''
void read__{norm}(int stack, {ctype} *msg, const ReadOptions *opt)
{{
    try
    {{
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {{
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {{
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {{}}'''.format(**d)
    for n, t in fields.items():
        d1 = d
        d1['n'] = n
        d1['t'] = t
        d1['ctype1'] = t.ctype()
        d1['nf'] = '{}::{}'.format(gt.ctype(), n)
        d1['norm1'] = t.normalized()
        if t.array:
            if t.builtin and t.mtype in fast_write_types:
                if t.array_size:
                    reserve_space = '// field has fixed size -> no need to reserve space into vector'
                else:
                    reserve_space = 'msg->{n}.resize(sz);'.format(**d1)
                rf += '''
                else if(strcmp(str, "{n}") == 0)
                {{
                    try
                    {{
                        // read field '{n}' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        {reserve_space}
                        simGetStack{fast_write_type}TableE(stack, &(msg->{n}[0]), sz);
                        simPopStackItemE(stack, 1);
                    }}
                    catch(exception& ex)
                    {{
                        std::string msg = "field {n}: ";
                        msg += ex.what();
                        throw exception(msg);
                    }}
                }}'''.format(reserve_space=reserve_space, fast_write_type=fast_write_types[t.mtype], **d1)
            elif t.builtin and t.mtype == 'uint8':
                if t.array_size:
                    reserve_space = '// field has fixed size -> no need to reserve space into vector'
                else:
                    reserve_space = 'msg->{n}.resize(sz);'.format(**d1)
                rf += '''
                else if(strcmp(str, "{n}") == 0)
                {{
                    try
                    {{
                        if(opt && opt->uint8array_as_string)
                        {{
                            // read field '{n}' (uint8[]) as string
                            simChar *str;
                            simInt sz;
                            if((str = simGetStackStringValueE(stack, &sz)) != NULL && sz > 0)
                            {{
                                /*
                                 * XXX: if an alternative version of simGetStackStringValue woudl exist
                                 * working on an externally allocated buffer, we won't need this memcpy:
                                 */
                                {reserve_space}
                                std::memcpy(&(msg->{n}[0]), str, sz);
                                simReleaseBufferE(str);
                            }}
                            else throw exception("string read error when trying to read uint8[]");
                        }}
                        else
			{{
                            // read field '{n}' (using fast specialized function)
                            int sz = simGetStackTableInfoE(stack, 0);
                            if(sz < 0)
                                throw exception("expected uint8 array");
                            if(simGetStackTableInfoE(stack, 2) != 1)
                                throw exception("fast_write_type uint8[] reader exception #1");
                            {reserve_space}
                            simGetStackUInt8TableE(stack, &(msg->{n}[0]), sz);
                            simPopStackItemE(stack, 1);
			}}
                    }}
                    catch(exception& ex)
                    {{
                        std::string msg = "field {n}: ";
                        msg += ex.what();
                        throw exception(msg);
                    }}
                }}'''.format(reserve_space=reserve_space, **d1)
            else:
                if t.array_size:
                    ins = 'msg->{n}[i] = (v);'.format(**d1)
                else:
                    ins = 'msg->{n}.push_back(v);'.format(**d1)
                rf += '''
                else if(strcmp(str, "{n}") == 0)
                {{
                    try
                    {{
                        // read field '{n}'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {{
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            {ctype1} v;
                            read__{norm1}(stack, &v, opt);
                            {ins}
                        }}
                    }}
                    catch(exception& ex)
                    {{
                        std::string msg = "field {n}: ";
                        msg += ex.what();
                        throw exception(msg);
                    }}
                }}'''.format(ins=ins, **d1)
        else:
            rf += '''
                else if(strcmp(str, "{n}") == 0)
                {{
                    try
                    {{
                        // read field '{n}'
                        read__{norm1}(stack, &(msg->{n}), opt);
                    }}
                    catch(exception& ex)
                    {{
                        std::string msg = "field {n}: ";
                        msg += ex.what();
                        throw exception(msg);
                    }}
                }}'''.format(**d1)
    rf += '''
                else
                {{
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }}

                simReleaseBuffer(str);
            }}
            else
            {{
                throw exception("malformed table (bad key type)");
            }}

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }}
    }}
    catch(exception& ex)
    {{
        std::string msg = "read__{norm}: ";
        msg += ex.what();
        throw exception(msg);
    }}
}}

'''.format(**d)
    f.write(rf)

def generate_msg_cb_cpp(gt, fields, d, f):
    cb = '''
void ros_callback__{norm}(const boost::shared_ptr<{ctype} const>& msg, SubscriberProxy *proxy)
{{
    int stack = -1;
    try
    {{
        stack = simCreateStackE();
        write__{norm}(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }}
    catch(exception& ex)
    {{
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__{norm}: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }}
}}

'''.format(**d)
    f.write(cb)

def generate_msg_cpp(gt, fields, d, f):
    generate_msg_wr_cpp(gt, fields, d, f)
    generate_msg_rd_cpp(gt, fields, d, f)
    generate_msg_cb_cpp(gt, fields, d, f)

def generate_msg_pub(gt, fields, d, f):
    p = '''    else if(publisherProxy->topicType == "{fn}")
    {{
        {ctype} msg;
        read__{norm}(p->stackID, &msg, &(publisherProxy->rd_opt));
        publisherProxy->publisher.publish(msg);
    }}
'''.format(**d)
    f.write(p)

def generate_msg_adv(gt, fields, d, f):
    p = '''    else if(in->topicType == "{fn}")
    {{
        publisherProxy->publisher = nh->advertise<{ctype}>(in->topicName, in->queueSize, in->latch);
    }}
'''.format(**d)
    f.write(p)

def generate_msg_sub(gt, fields, d, f):
    p = '''    else if(in->topicType == "{fn}")
    {{
        subscriberProxy->subscriber = nh->subscribe<{ctype}>(in->topicName, in->queueSize, boost::bind(ros_callback__{norm}, _1, subscriberProxy));
    }}
'''.format(**d)
    f.write(p)

def generate_srv_cli(gt, fields_in, fields_out, d, f):
    p = '''    else if(in->serviceType == "{fn}")
    {{
        serviceClientProxy->client = nh->serviceClient<{ctype}>(in->serviceName);
    }}
'''.format(**d)
    f.write(p)

def generate_srv_srv(gt, fields_in, fields_out, d, f):
    p = '''    else if(in->serviceType == "{fn}")
    {{
        serviceServerProxy->server = nh->advertiseService<{ctype}::Request, {ctype}::Response>(in->serviceName, boost::bind(ros_srv_callback__{norm}, _1, _2, serviceServerProxy));
    }}
'''.format(**d)
    f.write(p)

def generate_srv_call(gt, fields_in, fields_out, d, f):
    p = '''    else if(serviceClientProxy->serviceType == "{fn}")
    {{
        {ctype} srv;
        read__{norm}Request(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {{
            write__{norm}Response(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }}
        else
        {{
            throw exception("failed to call service {fn}");
        }}
    }}
'''.format(**d)
    f.write(p)

def generate_srv_cb_h(gt, fields_in, fields_out, d, f):
    p = '''
bool ros_srv_callback__{norm}({ctype}::Request& req, {ctype}::Response& res, ServiceServerProxy *proxy);
'''.format(**d)
    f.write(p)

def generate_srv_cb_cpp(gt, fields_in, fields_out, d, f):
    p = '''
bool ros_srv_callback__{norm}({ctype}::Request& req, {ctype}::Response& res, ServiceServerProxy *proxy)
{{
    bool ret = false;
    int stack = -1;

    try
    {{
        stack = simCreateStackE();
        write__{norm}Request(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__{norm}Response(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }}
    catch(exception& ex)
    {{
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__{norm}: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }}
}}
'''.format(**d)
    f.write(p)

def generate_srv_h(gt, fields_in, fields_out, d, f):
    ctype = d['ctype']
    norm = d['norm']
    for k, v in {'Request': fields_in, 'Response': fields_out}.items():
        d['ctype'] = ctype + k
        d['norm'] = norm + k
        generate_msg_wr_h(gt, v, d, f)
        generate_msg_rd_h(gt, v, d, f)
    d['ctype'] = ctype
    d['norm'] = norm
    generate_srv_cb_h(gt, fields_in, fields_out, d, f)

def generate_srv_cpp(gt, fields_in, fields_out, d, f):
    ctype = d['ctype']
    norm = d['norm']
    for k, v in {'Request': fields_in, 'Response': fields_out}.items():
        d['ctype'] = ctype + k
        d['norm'] = norm + k
        generate_msg_wr_cpp(gt, v, d, f)
        generate_msg_rd_cpp(gt, v, d, f)
    d['ctype'] = ctype
    d['norm'] = norm
    generate_srv_cb_cpp(gt, fields_in, fields_out, d, f)

def main(argc, argv):
    if argc != 4:
        stderr.write('argument error\n')
        exit(42)

    messages_file = argv[1]
    services_file = argv[2]
    output_dir = argv[3]

    # populate msg list
    msg_list = set()
    with open(messages_file) as f:
        for l in f.readlines():
            l = l.strip()
            if not l: continue
            msg_list.add(l)

    # and srv list
    srv_list = set()
    with open(services_file) as f:
        for l in f.readlines():
            l = l.strip()
            if not l: continue
            srv_list.add(l)

    f_msg_cpp = open(output_dir + '/ros_msg_io.cpp', 'w')
    f_msg_h = open(output_dir + '/ros_msg_io.h', 'w')
    f_msg_adv = open(output_dir + '/adv.cpp', 'w')
    f_msg_pub = open(output_dir + '/pub.cpp', 'w')
    f_msg_sub = open(output_dir + '/sub.cpp', 'w')

    f_srv_cpp = open(output_dir + '/ros_srv_io.cpp', 'w')
    f_srv_h = open(output_dir + '/ros_srv_io.h', 'w')
    f_srv_call = open(output_dir + '/srvcall.cpp', 'w')
    f_srv_cli = open(output_dir + '/srvcli.cpp', 'w')
    f_srv_srv = open(output_dir + '/srvsrv.cpp', 'w')

    f_msg_cpp.write('''#include <ros_msg_io.h>
#include <v_repLib.h>
#include <stubs.h>
#include <cstring>

''')
    f_msg_h.write('''#ifndef VREP_ROS_PLUGIN__ROS_MSG_IO__H
#define VREP_ROS_PLUGIN__ROS_MSG_IO__H

#include <ros_msg_builtin_io.h>
#include <vrep_ros_interface.h>

''')
    f_srv_cpp.write('''#include <ros_msg_io.h>
#include <ros_srv_io.h>
#include <v_repLib.h>

''')
    f_srv_h.write('''#ifndef VREP_ROS_PLUGIN__ROS_SRV_IO__H
#define VREP_ROS_PLUGIN__ROS_SRV_IO__H

#include <ros_msg_builtin_io.h>
#include <ros/ros.h>
#include <vrep_ros_interface.h>

''')

    # Utility class used by rosmsg functions
    # Initializing it in advance yields better performance
    rospack = rospkg.RosPack()

    # get msg definitions
    print('Getting msg definitions...')
    msg_fields = {}
    for msg in sorted(msg_list):
        print('Getting definition of msg %s...' % msg)
        try:
            msg_fields[msg] = get_msg_fields(msg, rospack)
        except rosmsg.ROSMsgException:
            print('WARNING: bad msg: %s' % msg)
            continue

    # get srv definitions
    print('Getting srv definitions...')
    srv_fields = {}
    for srv in sorted(srv_list):
        print('Getting definition of srv %s...' % srv)
        try:
            srv_fields[srv] = get_srv_fields(srv, rospack)
        except rosmsg.ROSMsgException:
            print('WARNING: bad srv: %s' % srv)
            continue

    print('Generating header...')
    # for each msg/srv include corresponding header
    for msg in sorted(msg_fields):
        f_msg_h.write('#include <%s.h>\n' % msg)
    f_msg_h.write('\n')
    for srv in sorted(srv_fields):
        f_srv_h.write('#include <%s.h>\n' % srv)
    f_srv_h.write('\n')

    # for each msg generate cpp, h, adv, pub, sub code
    for msg, fields in sorted(msg_fields.items()):
        print('Generating code for message %s...' % msg)
        gt = TypeSpec(msg)
        d = {'norm': gt.normalized(), 'ctype': gt.ctype(), 'fn': gt.fullname}
        generate_msg_cpp(gt, fields, d, f_msg_cpp)
        generate_msg_h(gt, fields, d, f_msg_h)
        generate_msg_adv(gt, fields, d, f_msg_adv)
        generate_msg_pub(gt, fields, d, f_msg_pub)
        generate_msg_sub(gt, fields, d, f_msg_sub)

    for srv, (fields_in, fields_out) in sorted(srv_fields.items()):
        print('Generating code for service %s...' % srv)
        gt = TypeSpec(srv)
        d = {'norm': gt.normalized(), 'ctype': gt.ctype(), 'fn': gt.fullname}
        generate_srv_cli(gt, fields_in, fields_out, d, f_srv_cli)
        generate_srv_srv(gt, fields_in, fields_out, d, f_srv_srv)
        generate_srv_call(gt, fields_in, fields_out, d, f_srv_call)
        generate_srv_h(gt, fields_in, fields_out, d, f_srv_h)
        generate_srv_cpp(gt, fields_in, fields_out, d, f_srv_cpp)

    f_msg_h.write('''

#endif // VREP_ROS_PLUGIN__ROS_MSG_IO__H
''')
    f_srv_h.write('''

#endif // VREP_ROS_PLUGIN__ROS_SRV_IO__H
''')

    f_msg_cpp.close()
    f_msg_h.close()
    f_msg_adv.close()
    f_msg_pub.close()
    f_msg_sub.close()

    f_srv_cpp.close()
    f_srv_h.close()
    f_srv_call.close()
    f_srv_cli.close()
    f_srv_srv.close()

if __name__ == '__main__':
    main(len(argv), argv)
