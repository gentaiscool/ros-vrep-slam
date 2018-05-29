from sys import argv, exit
import re

if len(argv) != 5:
    print('usage: {} <long-plugin-name> <short-plugin-name> <lua-file> <output-cpp-file>'.format(argv[0]))
    exit(1)

longPlugName = argv[1]
shortPlugName = argv[2]
luafile = argv[3]
outfile = argv[4]

fun = None
args, rets = [], []

with open(outfile, 'w') as fout:
    def output():
        if fun:
            f, fdesc = fun
            calltip = (','.join(x[0] for x in rets)+('=' if rets else '')+'sim'+shortPlugName+'.'+f+'('+','.join(x[0] for x in args)+')')
            if fdesc:
                calltip += '\\n\\n' + fdesc
            while calltip[-2:] == '\\n': calltip = calltip[:-2]
            fout.write('simRegisterScriptCallbackFunctionE("sim{}.{}@{}", "{}", NULL);\n'.format(shortPlugName, f, longPlugName, calltip))

    with open(luafile, 'r') as f:
        for line in f:
            m = re.match(r'\s*--\s*@([^\s]+)\s+([^\s]+)(.*)$', line)
            if m:
                key, value, desc = map(lambda s: s.strip(), m.groups())
                if key == 'fun': fun = (value, desc)
                elif key == 'arg': args.append((value, desc))
                elif key == 'ret': rets.append((value, desc))
            else:
                output()
                fun = None
                args, rets = [], []
        output()

