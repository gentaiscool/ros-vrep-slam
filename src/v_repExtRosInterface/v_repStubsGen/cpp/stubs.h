#py from parse import parse
#py import model
#py plugin = parse(pycpp.params['xml_file'])
#ifndef STUBS_H__INCLUDED
#define STUBS_H__INCLUDED

#ifdef QT_COMPIL
#include <QThread>
#if defined(QT_DEBUG) && !defined(DEBUG)
#define DEBUG
#endif
#endif // QT_COMPIL

#include <v_repLib.h>
#include <string>
#include <vector>
#include <boost/assign/list_of.hpp>
#include <boost/lexical_cast.hpp>

struct exception : public std::exception
{
    std::string s;
    exception(std::string s_) : s(s_) {}
    ~exception() throw() {}
    const char* what() const throw() {return s.c_str();}
};

simInt simRegisterScriptCallbackFunctionE(const simChar *funcNameAtPluginName, const simChar *callTips, simVoid (*callBack)(struct SScriptCallBack *cb));
simInt simRegisterScriptVariableE(const simChar *varName, const simChar *varValue, simInt stackID);
simVoid simCallScriptFunctionExE(simInt scriptHandleOrType,const simChar* functionNameAtScriptName,simInt stackId);
simInt simCreateStackE();
simVoid simReleaseStackE(simInt stackHandle);
simInt simCopyStackE(simInt stackHandle);
simVoid simPushNullOntoStackE(simInt stackHandle);
simVoid simPushBoolOntoStackE(simInt stackHandle, simBool value);
simVoid simPushInt32OntoStackE(simInt stackHandle, simInt value);
simVoid simPushFloatOntoStackE(simInt stackHandle, simFloat value);
simVoid simPushDoubleOntoStackE(simInt stackHandle, simDouble value);
simVoid simPushStringOntoStackE(simInt stackHandle, const simChar *value, simInt stringSize);
simVoid simPushUInt8TableOntoStackE(simInt stackHandle, const simUChar *values, simInt valueCnt);
simVoid simPushInt32TableOntoStackE(simInt stackHandle, const simInt *values, simInt valueCnt);
simVoid simPushFloatTableOntoStackE(simInt stackHandle, const simFloat *values, simInt valueCnt);
simVoid simPushDoubleTableOntoStackE(simInt stackHandle, const simDouble *values, simInt valueCnt);
simVoid simPushTableOntoStackE(simInt stackHandle);
simVoid simInsertDataIntoStackTableE(simInt stackHandle);
simInt simGetStackSizeE(simInt stackHandle);
simInt simPopStackItemE(simInt stackHandle, simInt count);
simVoid simMoveStackItemToTopE(simInt stackHandle, simInt cIndex);
simInt simIsStackValueNullE(simInt stackHandle);
simInt simGetStackBoolValueE(simInt stackHandle, simBool *boolValue);
simInt simGetStackInt32ValueE(simInt stackHandle, simInt *numberValue);
simInt simGetStackFloatValueE(simInt stackHandle, simFloat *numberValue);
simInt simGetStackDoubleValueE(simInt stackHandle, simDouble *numberValue);
simChar* simGetStackStringValueE(simInt stackHandle, simInt *stringSize);
simInt simGetStackTableInfoE(simInt stackHandle, simInt infoType);
simInt simGetStackUInt8TableE(simInt stackHandle, simUChar *array, simInt count);
simInt simGetStackInt32TableE(simInt stackHandle, simInt *array, simInt count);
simInt simGetStackFloatTableE(simInt stackHandle, simFloat *array, simInt count);
simInt simGetStackDoubleTableE(simInt stackHandle, simDouble *array, simInt count);
simVoid simUnfoldStackTableE(simInt stackHandle);
simInt simGetInt32ParameterE(simInt parameter);
simChar* simCreateBufferE(simInt size);
simVoid simReleaseBufferE(simChar *buffer);

#py for struct in plugin.structs:
struct `struct.name`
{
#py for field in struct.fields:
    `field.ctype()` `field.name`;
#py endfor

    `struct.name`();
};

#py endfor
void read__bool(int stack, bool *value);
void read__int(int stack, int *value);
void read__float(int stack, float *value);
void read__double(int stack, double *value);
void read__std__string(int stack, std::string *value);
#py for struct in plugin.structs:
void read__`struct.name`(int stack, `struct.name` *value);
#py endfor
void write__bool(bool value, int stack);
void write__int(int value, int stack);
void write__float(float value, int stack);
void write__double(double value, int stack);
void write__std__string(std::string value, int stack);
#py for struct in plugin.structs:
void write__`struct.name`(`struct.name` *value, int stack);
#py endfor

bool registerScriptStuff();

#py for enum in plugin.enums:
enum `enum.name`
{
#py for i, item in enumerate(enum.items):
    sim_`plugin.name.lower()`_`enum.item_prefix``item` = `enum.base + i`,
#py if plugin.short_name and plugin.name.lower() != plugin.short_name.lower():
    sim_`plugin.short_name.lower()`_`enum.item_prefix``item` = `enum.base + i`,
#py endif
#py endfor
};

const char* `enum.name.lower()`_string(`enum.name` x);

#py endfor
#py for cmd in plugin.commands:
struct `cmd.name`_in
{
#py for p in cmd.params:
    `p.ctype()` `p.name`;
#py endfor

    `cmd.name`_in();
};

struct `cmd.name`_out
{
#py for p in cmd.returns:
    `p.ctype()` `p.name`;
#py endfor

    `cmd.name`_out();
};

void `cmd.name`(SScriptCallBack *p, `cmd.name`_in *in, `cmd.name`_out *out);
#py if len(cmd.returns) == 1:
`cmd.returns[0].ctype()` `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p'], defaults=True)`);
#py endif
#py if len(cmd.returns) == 0:
void `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p'], defaults=True)`);
#py endif
void `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p', '%s_out *out' % cmd.name], defaults=True)`);
void `cmd.name`_callback(SScriptCallBack *p);

#py endfor
#py for fn in plugin.script_functions:
struct `fn.name`_in
{
#py for p in fn.params:
    `p.ctype()` `p.name`;
#py endfor

    `fn.name`_in();
};

struct `fn.name`_out
{
#py for p in fn.returns:
    `p.ctype()` `p.name`;
#py endfor

    `fn.name`_out();
};

#py if len(fn.returns) == 1:
`fn.returns[0].ctype()` `fn.name`(`fn.c_arg_list(pre_args=['simInt scriptId', 'const char *func'], defaults=True)`);
#py endif
#py if len(fn.returns) == 0:
void `fn.name`(`fn.c_arg_list(pre_args=['simInt scriptId', 'const char *func'], defaults=True)`);
#py endif
bool `fn.name`(simInt scriptId, const char *func, `fn.name`_in *in_args, `fn.name`_out *out_args);

#py endfor
// following functions must be implemented in the plugin

#py for cmd in plugin.commands:
void `cmd.name`(SScriptCallBack *p, const char *cmd, `cmd.name`_in *in, `cmd.name`_out *out);
#py endfor

#endif // STUBS_H__INCLUDED
