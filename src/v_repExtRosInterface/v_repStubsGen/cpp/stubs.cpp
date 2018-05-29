#py from parse import parse
#py import model
#py plugin = parse(pycpp.params['xml_file'])
#include "stubs.h"

#include <cstdlib>
#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

#define CATCH_AND_RETHROW(prefix)   \
    catch(std::exception &ex)       \
    {                               \
        std::string msg = prefix;   \
        msg += ex.what();           \
        throw exception(msg);       \
    }                               \
    catch(std::string& s)           \
    {                               \
        std::string msg = prefix;   \
        msg += s;                   \
        throw exception(msg);       \
    }                               \
    catch(int& n)                   \
    {                               \
        std::stringstream msg;      \
        msg << prefix;              \
        msg << "error #" << n;      \
        throw exception(msg.str()); \
    }

bool isDebugStubsEnabled()
{
    static int enabled = -1;

    if(enabled == 0) return false;
    if(enabled == 1) return true;

    char *val = std::getenv("DEBUG_STUBS");
    if(!val) enabled = 0;
    else enabled = boost::lexical_cast<int>(val) != 0 ? 1 : 0;
    return enabled;
}

simInt simRegisterScriptCallbackFunctionE(const simChar *funcNameAtPluginName, const simChar *callTips, simVoid (*callBack)(struct SScriptCallBack *cb))
{
    simInt ret = simRegisterScriptCallbackFunction(funcNameAtPluginName, callTips, callBack);
    if(ret == 0)
    {
        std::cout << "Plugin '`plugin.name`': warning: replaced function '" << funcNameAtPluginName << "'" << std::endl;
    }
    if(ret == -1)
        throw exception("simRegisterScriptCallbackFunction: error");
    return ret;
}

simInt simRegisterScriptVariableE(const simChar *varName, const simChar *varValue, simInt stackID)
{
    simInt ret = simRegisterScriptVariable(varName, varValue, stackID);
    if(ret == 0)
    {
        std::cout << "Plugin '`plugin.name`': warning: replaced variable '" << varName << "'" << std::endl;
    }
    if(ret == -1)
        throw exception("simRegisterScriptVariable: error");
    return ret;
}

simVoid simCallScriptFunctionExE(simInt scriptHandleOrType,const simChar* functionNameAtScriptName,simInt stackId)
{
    if(simCallScriptFunctionEx(scriptHandleOrType, functionNameAtScriptName, stackId) == -1)
        throw exception("simCallScriptFunctionEx: error");
}

simInt simCreateStackE()
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simCreateStack()" << std::endl;
    }
#endif // DEBUG

    simInt ret = simCreateStack();
    if(ret == -1)
        throw exception("simCreateStack: error");
    return ret;
}

simVoid simReleaseStackE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simReleaseStack(stack)" << std::endl;
    }
#endif // DEBUG

    if(simReleaseStack(stackHandle) != 1)
        throw exception("simReleaseStack: error");
}

simInt simCopyStackE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simCopyStack(stack)" << std::endl;
    }
#endif // DEBUG

    simInt ret = simCopyStack(stackHandle);
    if(ret == -1)
        throw exception("simCopyStack: error");
    return ret;
}

simVoid simPushNullOntoStackE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushNullOntoStack(stack)" << std::endl;
    }
#endif // DEBUG

    if(simPushNullOntoStack(stackHandle) == -1)
        throw exception("simPushNullOntoStack: error");
}

simVoid simPushBoolOntoStackE(simInt stackHandle, simBool value)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushBoolOntoStack(stack, " << value << ")" << std::endl;
    }
#endif // DEBUG

    if(simPushBoolOntoStack(stackHandle, value) == -1)
        throw exception("simPushBoolOntoStack: error");
}

simVoid simPushInt32OntoStackE(simInt stackHandle, simInt value)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushInt32OntoStack(stack, " << value << ")" << std::endl;
    }
#endif // DEBUG

    if(simPushInt32OntoStack(stackHandle, value) == -1)
        throw exception("simPushInt32OntoStack: error");
}

simVoid simPushFloatOntoStackE(simInt stackHandle, simFloat value)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushFloatOntoStack(stack, " << value << ")" << std::endl;
    }
#endif // DEBUG

    if(simPushFloatOntoStack(stackHandle, value) == -1)
        throw exception("simPushFloatOntoStack: error");
}

simVoid simPushDoubleOntoStackE(simInt stackHandle, simDouble value)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushDoubleOntoStack(stack, " << value << ")" << std::endl;
    }
#endif // DEBUG

    if(simPushDoubleOntoStack(stackHandle, value) == -1)
        throw exception("simPushDoubleOntoStack: error");
}

simVoid simPushStringOntoStackE(simInt stackHandle, const simChar *value, simInt stringSize)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushStringOntoStack(stack, \"" << value << "\" [" << stringSize << "])" << std::endl;
    }
#endif // DEBUG

    if(simPushStringOntoStack(stackHandle, value, stringSize) == -1)
        throw exception("simPushStringOntoStack: error");
}

simVoid simPushUInt8TableOntoStackE(simInt stackHandle, const simUChar *values, simInt valueCnt)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushUInt8TableOntoStack(stack, <" << valueCnt << " values>)" << std::endl;
    }
#endif // DEBUG

    if(simPushUInt8TableOntoStack(stackHandle, values, valueCnt) == -1)
        throw exception("simPushUInt8TableOntoStack: error");
}

simVoid simPushInt32TableOntoStackE(simInt stackHandle, const simInt *values, simInt valueCnt)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushInt32TableOntoStack(stack, <" << valueCnt << " values>)" << std::endl;
    }
#endif // DEBUG

    if(simPushInt32TableOntoStack(stackHandle, values, valueCnt) == -1)
        throw exception("simPushInt32TableOntoStack: error");
}

simVoid simPushFloatTableOntoStackE(simInt stackHandle, const simFloat *values, simInt valueCnt)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushFloatTableOntoStack(stack, <" << valueCnt << " values>)" << std::endl;
    }
#endif // DEBUG

    if(simPushFloatTableOntoStack(stackHandle, values, valueCnt) == -1)
        throw exception("simPushFloatTableOntoStack: error");
}

simVoid simPushDoubleTableOntoStackE(simInt stackHandle, const simDouble *values, simInt valueCnt)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushDoubleTableOntoStack(stack, <" << valueCnt << " values>)" << std::endl;
    }
#endif // DEBUG

    if(simPushDoubleTableOntoStack(stackHandle, values, valueCnt) == -1)
        throw exception("simPushDoubleTableOntoStack: error");
}

simVoid simPushTableOntoStackE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPushTableOntoStack(stack)" << std::endl;
    }
#endif // DEBUG

    if(simPushTableOntoStack(stackHandle) == -1)
        throw exception("simPushTableOntoStack: error");
}

simVoid simInsertDataIntoStackTableE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simInsertDataIntoStackTable(stack)" << std::endl;
    }
#endif // DEBUG

    if(simInsertDataIntoStackTable(stackHandle) == -1)
        throw exception("simInsertDataIntoStackTable: error");
}

simInt simGetStackSizeE(simInt stackHandle)
{
    simInt ret = simGetStackSize(stackHandle);

#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simGetStackSize(stack) -> " << ret << std::endl;
    }
#endif // DEBUG

    if(ret == -1)
        throw exception("simGetStackSize: error");
    return ret;
}

simInt simPopStackItemE(simInt stackHandle, simInt count)
{
    simInt ret = simPopStackItem(stackHandle, count);

#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simPopStackItem(stack, " << count << ") -> " << ret << std::endl;
    }
#endif // DEBUG

    if(ret == -1)
        throw exception("simPopStackItem: error");
    return ret;
}

simVoid simMoveStackItemToTopE(simInt stackHandle, simInt cIndex)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simMoveStackItemToTop(stack, " << cIndex << ")" << std::endl;
    }
#endif // DEBUG

    if(simMoveStackItemToTop(stackHandle, cIndex) == -1)
        throw exception("simMoveStackItemToTop: error");
}

simInt simIsStackValueNullE(simInt stackHandle)
{
    simInt ret = simIsStackValueNull(stackHandle);
    if(ret == -1)
        throw exception("simIsStackValueNull: error");
    return ret;
}

simInt simGetStackBoolValueE(simInt stackHandle, simBool *boolValue)
{
    simInt ret = simGetStackBoolValue(stackHandle, boolValue);
    if(ret == -1)
        throw exception("simGetStackBoolValue: error");
    return ret;
}

simInt simGetStackInt32ValueE(simInt stackHandle, simInt *numberValue)
{
    simInt ret = simGetStackInt32Value(stackHandle, numberValue);
    if(ret == -1)
        throw exception("simGetStackInt32Value: error");
    return ret;
}

simInt simGetStackFloatValueE(simInt stackHandle, simFloat *numberValue)
{
    simInt ret = simGetStackFloatValue(stackHandle, numberValue);
    if(ret == -1)
        throw exception("simGetStackFloatValue: error");
    return ret;
}

simInt simGetStackDoubleValueE(simInt stackHandle, simDouble *numberValue)
{
    simInt ret = simGetStackDoubleValue(stackHandle, numberValue);
    if(ret == -1)
        throw exception("simGetStackDoubleValue: error");
    return ret;
}

simChar* simGetStackStringValueE(simInt stackHandle, simInt *stringSize)
{
    simChar *ret = simGetStackStringValue(stackHandle, stringSize);
    // if stringSize is NULL, we cannot distinguish error (-1) from type error (0)
    if(ret == NULL && stringSize && *stringSize == -1)
        throw exception("simGetStackStringValue: error");
    return ret;
}

simInt simGetStackTableInfoE(simInt stackHandle, simInt infoType)
{
    simInt ret = simGetStackTableInfo(stackHandle, infoType);

#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simGetStackTableInfo(stack, " << infoType << ") -> " << ret << std::endl;
    }
#endif // DEBUG

    if(ret == -1)
        throw exception("simGetStackTableInfo: error");
    return ret;
}

simInt simGetStackUInt8TableE(simInt stackHandle, simUChar *array, simInt count)
{
    simInt ret = simGetStackUInt8Table(stackHandle, array, count);
    if(ret == -1)
        throw exception("simGetStackUInt8Table: error");
    return ret;
}

simInt simGetStackInt32TableE(simInt stackHandle, simInt *array, simInt count)
{
    simInt ret = simGetStackInt32Table(stackHandle, array, count);
    if(ret == -1)
        throw exception("simGetStackInt32Table: error");
    return ret;
}

simInt simGetStackFloatTableE(simInt stackHandle, simFloat *array, simInt count)
{
    simInt ret = simGetStackFloatTable(stackHandle, array, count);
    if(ret == -1)
        throw exception("simGetStackFloatTable: error");
    return ret;
}

simInt simGetStackDoubleTableE(simInt stackHandle, simDouble *array, simInt count)
{
    simInt ret = simGetStackDoubleTable(stackHandle, array, count);
    if(ret == -1)
        throw exception("simGetStackDoubleTable: error");
    return ret;
}

simVoid simUnfoldStackTableE(simInt stackHandle)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: simUnfoldStackTable(stack)" << std::endl;
    }
#endif // DEBUG

    if(simUnfoldStackTable(stackHandle) == -1)
        throw exception("simUnfoldStackTable: error");
}

simInt simGetInt32ParameterE(simInt parameter)
{
    simInt ret;
    if(simGetInt32Parameter(parameter, &ret) == -1)
        throw exception("simGetInt32Parameter: error");
    return ret;
}

simChar* simCreateBufferE(simInt size)
{
    simChar *ret = simCreateBuffer(size);
    if(ret == NULL)
        throw exception("simCreateBuffer: error");
    return ret;
}

simVoid simReleaseBufferE(simChar *buffer)
{
    if(simReleaseBuffer(buffer) == -1)
        throw exception("simReleaseBuffer: error");
}

void read__bool(int stack, bool *value)
{
    simBool v;
    if(simGetStackBoolValueE(stack, &v) == 1)
    {
        *value = v;
        simPopStackItemE(stack, 1);
    }
    else
    {
        throw exception("expected bool");
    }
}

void read__int(int stack, int *value)
{
    int v;
    if(simGetStackInt32ValueE(stack, &v) == 1)
    {
        *value = v;
        simPopStackItemE(stack, 1);
    }
    else
    {
        throw exception("expected int");
    }
}

void read__float(int stack, float *value)
{
    simFloat v;
    if(simGetStackFloatValueE(stack, &v) == 1)
    {
        *value = v;
        simPopStackItemE(stack, 1);
    }
    else
    {
        throw exception("expected float");
    }
}

void read__double(int stack, double *value)
{
    simDouble v;
    if(simGetStackDoubleValueE(stack, &v) == 1)
    {
        *value = v;
        simPopStackItemE(stack, 1);
    }
    else
    {
        throw exception("expected double");
    }
}

void read__std__string(int stack, std::string *value)
{
    simChar *str;
    simInt strSize;
    if((str = simGetStackStringValueE(stack, &strSize)) != NULL && strSize >= 0)
    {
        *value = std::string(str, strSize);
        simPopStackItemE(stack, 1);
        simReleaseBufferE(str);
    }
    else
    {
        throw exception("expected string");
    }
}

#py for struct in plugin.structs:
void read__`struct.name`(int stack, `struct.name` *value)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: reading struct \"`struct.name`\"..." << std::endl;
    }
#endif // DEBUG

    try
    {
        simInt info = simGetStackTableInfoE(stack, 0);
        if(info == sim_stack_table_empty)
            return;
        if(info != sim_stack_table_map)
        {
#ifdef DEBUG
            if(isDebugStubsEnabled())
                simDebugStack(stack, -1);
#endif // DEBUG
            throw exception("expected a table");
        }

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz >= 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
#py for field in struct.fields:
                else if(strcmp(str, "`field.name`") == 0)
                {
#ifdef DEBUG
                    if(isDebugStubsEnabled())
                        std::cout << "DEBUG_STUBS: reading field \"`field.name`\"..." << std::endl;
#endif // DEBUG

                    try
                    {
#py if isinstance(field, model.ParamTable):
                        // read field '`field.name`' of type array of `field.ctype()`
                        simMoveStackItemToTopE(stack, 0);
                        int i = simGetStackTableInfoE(stack, 0);
                        if(i < 0)
                        {
#ifdef DEBUG
                            if(isDebugStubsEnabled())
                                simDebugStack(stack, -1);
#endif // DEBUG
                            throw exception((boost::format("expected array (simGetStackTableInfo(stack, 0) returned %d)") % i).str());
                        }
                        int oldsz = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int sz = (simGetStackSizeE(stack) - oldsz + 1) / 2;
                        for(int i = 0; i < sz; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz - 1);
                            int j;
                            read__int(stack, &j);
                            simMoveStackItemToTop(stack, oldsz - 1);
                            `field.ctype_normalized()` v;
                            read__`field.ctype_normalized()`(stack, &v);
                            value->`field.name`.push_back(v);
                        }
#py if field.minsize > 0 and field.minsize == field.maxsize:
                        if(value->`field.name`.size() != `field.minsize`)
                            throw exception("must have exactly `field.minsize` elements");
#py else:
#py if field.minsize > 0:
                        if(value->`field.name`.size() < `field.minsize`)
                            throw exception("must have at least `field.minsize` elements");
#py endif
#py if field.maxsize is not None:
                        if(value->`field.name`.size() > `field.maxsize`)
                            throw exception("must have at most `field.maxsize` elements");
#py endif
#py endif
#py else:
                        // read field '`field.name`' of type `field.ctype()`
                        read__`field.ctype_normalized()`(stack, &(value->`field.name`));
#py endif
                    }
                    CATCH_AND_RETHROW("field '`field.name`': ")
                }
#py endfor
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }
            }
            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    CATCH_AND_RETHROW("read__`struct.name`: ")
}

#py endfor
void write__bool(bool value, int stack)
{
    simBool v = value;
    simPushBoolOntoStackE(stack, v);
}

void write__int(int value, int stack)
{
    simInt v = value;
    simPushInt32OntoStackE(stack, v);
}

void write__float(float value, int stack)
{
    simFloat v = value;
    simPushFloatOntoStackE(stack, v);
}

void write__double(double value, int stack)
{
    simDouble v = value;
    simPushDoubleOntoStackE(stack, v);
}

void write__std__string(std::string value, int stack)
{
    const simChar *v = value.c_str();
    simPushStringOntoStackE(stack, v, value.length());
}

#py for struct in plugin.structs:
void write__`struct.name`(`struct.name` *value, int stack)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: writing struct \"`struct.name`\"..." << std::endl;
    }
#endif // DEBUG

    try
    {
        simPushTableOntoStackE(stack);

#py for field in struct.fields:
        try
        {
#ifdef DEBUG
            if(isDebugStubsEnabled())
                std::cout << "DEBUG_STUBS: writing field \"`field.name`\"..." << std::endl;
#endif // DEBUG

            simPushStringOntoStackE(stack, "`field.name`", 0);
#py if isinstance(field, model.ParamTable):
            // write field '`field.name`' of type array of `field.ctype()`
            simPushTableOntoStackE(stack);
            for(int i = 0; i < value->`field.name`.size(); i++)
            {
                write__int(i + 1, stack);
                write__`field.ctype_normalized()`(`field.argmod()`(value->`field.name`[i]), stack);
                simInsertDataIntoStackTableE(stack);
            }
#py else:
            // write field '`field.name`' of type `field.ctype()`
            write__`field.ctype_normalized()`(`field.argmod()`(value->`field.name`), stack);
#py endif
            simInsertDataIntoStackTableE(stack);
        }
        CATCH_AND_RETHROW("field '`field.name`': ")
#py endfor
    }
    CATCH_AND_RETHROW("write__`struct.name`: ")
}

#py endfor
#py for struct in plugin.structs:
`struct.name`::`struct.name`()
{
#py for field in struct.fields:
#py if field.default:
    `field.name` = `field.cdefault()`;
#py endif
#py endfor
}

#py endfor
bool registerScriptStuff()
{
    try
    {
        {
            simInt vrepVer = 0, vrepRev = 0, vrepMinVer = 30400, vrepMinRev = 9;
            simGetIntegerParameter(sim_intparam_program_version, &vrepVer);
            simGetIntegerParameter(sim_intparam_program_revision, &vrepRev);
            if(vrepVer < vrepMinVer || (vrepVer == vrepMinVer && vrepRev < vrepMinRev))
            {
                std::stringstream ss;
                ss << "this plugin requires at least V-REP " << (vrepMinVer / 10000) << "." << (vrepMinVer / 100 % 100) << "." << (vrepMinVer % 100) << " rev" << vrepMinRev;
                throw exception(ss.str());
            }
        }
        try
        {
#py if plugin.short_name:
            simRegisterScriptVariableE("sim`plugin.short_name`", "{}", 0);
            simRegisterScriptVariableE("sim`plugin.short_name`", "require('simExt`plugin.name`')", 0);
#py endif
#py if plugin.short_name:
            simRegisterScriptVariableE("sim`plugin.short_name`.reportedDeprecatedFunctionNames", "{}", -1);
            simRegisterScriptVariableE("sim`plugin.short_name`.reportDeprecatedFunction",
                    "function(oldName,newName)\n"
                    "    if sim`plugin.short_name`.reportedDeprecatedFunctionNames[oldName]~=nil then return end\n"
                    "    msg='WARNING: %s is deprecated, please use %s.'\n"
                    //"    simAddStatusbarMessage(string.format(msg, oldName, newName))\n"
                    "    sim`plugin.short_name`.reportedDeprecatedFunctionNames[oldName]=true\n"
                    "end", -1);
            simRegisterScriptVariableE("sim`plugin.short_name`.deprecated",
                    "function(oldName,newName,f)\n"
                    "    return function(...)\n"
                    "        sim`plugin.short_name`.reportDeprecatedFunction(oldName,newName)\n"
                    "        return f(...)\n"
                    "    end\n"
                    "end", -1);
#py endif

#py if plugin.short_name:
            // register new-style short-version varables
#py for enum in plugin.enums:
            simRegisterScriptVariableE("sim`plugin.short_name`.`enum.name`", "{}", 0);
#py for item in enum.items:
            simRegisterScriptVariableE("sim`plugin.short_name`.`enum.name`.`item`", (boost::lexical_cast<std::string>(sim_`plugin.short_name.lower()`_`enum.item_prefix``item`)).c_str(), 0);
#py endfor
#py endfor
            // register new-style short-version commands
#py for cmd in plugin.commands:
            simRegisterScriptCallbackFunctionE("sim`plugin.short_name`.`cmd.name`@`plugin.name`", "`cmd.help_out_args_text`sim`plugin.short_name`.`cmd.name`(`cmd.help_in_args_text`)`cmd.documentation`", `cmd.name`_callback);
#py endfor
#py endif

#py if plugin.short_name:
            // commands simExt<PLUGIN_NAME>_<COMMAND_NAME> (depreated)
#py for cmd in plugin.commands:
            simRegisterScriptVariableE("`plugin.command_prefix``cmd.name`", "sim`plugin.short_name`.deprecated('`plugin.command_prefix``cmd.name`','sim`plugin.short_name`.`cmd.name`',sim`plugin.short_name`.`cmd.name`)", -1);
            simRegisterScriptCallbackFunctionE("`plugin.command_prefix``cmd.name`@`plugin.name`", "`cmd.help_text`\n\n(DEPRECATED, please use sim`plugin.short_name`.`cmd.name`)", 0);
#py endfor
            // register variables (deprecated)
#py for enum in plugin.enums:
#py for item in enum.items:
            simRegisterScriptVariableE("sim_`plugin.name.lower()`_`enum.item_prefix``item`", (boost::lexical_cast<std::string>(sim_`plugin.name.lower()`_`enum.item_prefix``item`)).c_str(), -1);
#py endfor
#py endfor
#py else:
            // commands simExt<PLUGIN_NAME>_<COMMAND_NAME>
#py for cmd in plugin.commands:
            simRegisterScriptCallbackFunctionE("`plugin.command_prefix``cmd.name`@`plugin.name`", "`cmd.help_text``cmd.documentation`", `cmd.name`_callback);
#py endfor
            // register variables
#py for enum in plugin.enums:
#py for item in enum.items:
            simRegisterScriptVariableE("sim_`plugin.name.lower()`_`enum.item_prefix``item`", (boost::lexical_cast<std::string>(sim_`plugin.name.lower()`_`enum.item_prefix``item`)).c_str(), 0);
#py endfor
#py endfor
#py endif
        }
        CATCH_AND_RETHROW("Initialization failed (registerScriptStuff): ")
    }
    catch(exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return false;
    }
    return true;
}

#py for enum in plugin.enums:
const char* `enum.name.lower()`_string(`enum.name` x)
{
    switch(x)
    {
#py for item in enum.items:
        case sim_`plugin.name.lower()`_`enum.item_prefix``item`: return "sim_`plugin.name.lower()`_`enum.item_prefix``item`";
#py endfor
        default: return "???";
    }
}

#py endfor
#py for cmd in plugin.commands:
`cmd.name`_in::`cmd.name`_in()
{
#py for p in cmd.params:
#py if p.cdefault() is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

`cmd.name`_out::`cmd.name`_out()
{
#py for p in cmd.returns:
#py if p.cdefault() is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

void `cmd.name`(SScriptCallBack *p, `cmd.name`_in *in_args, `cmd.name`_out *out_args)
{
    `cmd.name`(p, "`plugin.command_prefix``cmd.name`", in_args, out_args);
}

#py if len(cmd.returns) == 1:
`cmd.returns[0].ctype()` `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p'])`)
{
    `cmd.name`_in in_args;
#py for p in cmd.params:
    in_args.`p.name` = `p.name`;
#py endfor
    `cmd.name`_out out_args;
    `cmd.name`(p, &in_args, &out_args);
    return out_args.`cmd.returns[0].name`;
}

#py endif
#py if len(cmd.returns) == 0:
void `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p'])`)
{
    `cmd.name`_in in_args;
#py for p in cmd.params:
    in_args.`p.name` = `p.name`;
#py endfor
    `cmd.name`_out out_args;
    `cmd.name`(p, &in_args, &out_args);
}

#py endif
void `cmd.name`(`cmd.c_arg_list(pre_args=['SScriptCallBack *p', '%s_out *out_args' % cmd.name])`)
{
    `cmd.name`_in in_args;
#py for p in cmd.params:
    in_args.`p.name` = `p.name`;
#py endfor
    `cmd.name`(p, &in_args, out_args);
}

void `cmd.name`_callback(SScriptCallBack *p)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: script callback for \"`cmd.name`\"..." << std::endl;
        std::cout << "DEBUG_STUBS: reading input arguments..." << std::endl;
        simDebugStack(p->stackID, -1);
    }
#endif // DEBUG

    const char *cmd = "`plugin.command_prefix``cmd.name`";

    `cmd.name`_in in_args;
    `cmd.name`_out out_args;

    try
    {
        // check argument count

        int numArgs = simGetStackSizeE(p->stackID);
        if(numArgs < `cmd.params_min`)
            throw exception("not enough arguments");
        if(numArgs > `cmd.params_max`)
            throw exception("too many arguments");

        // read input arguments from stack

#py for i, p in enumerate(cmd.params):
        if(numArgs >= `i+1`)
        {
#ifdef DEBUG
            if(isDebugStubsEnabled())
                std::cout << "DEBUG_STUBS: reading input argument `i+1` (`p.name`)..." << std::endl;
#endif // DEBUG

            try
            {
#py if isinstance(p, model.ParamTable):
#py if p.itype in ('float', 'double', 'int'):
                // read input argument `i+1` (`p.name`) of type array of `p.ctype()` using fast function
                simMoveStackItemToTopE(p->stackID, 0);
                int sz = simGetStackTableInfoE(p->stackID, 0);
                if(sz < 0)
                {
#ifdef DEBUG
                    if(isDebugStubsEnabled())
                        simDebugStack(p->stackID, -1);
#endif // DEBUG
                    throw exception((boost::format("expected array (simGetStackTableInfo(stack, 0) returned %d)") % sz).str());
                }
                if(simGetStackTableInfoE(p->stackID, 2) != 1)
                {
                    throw exception("fast_write_type reader exception #1 (simGetStackTableInfo(stack, 2) returned error)");
                }
                in_args.`p.name`.resize(sz);
#py if p.itype == 'float':
                simGetStackFloatTableE(p->stackID, &(in_args.`p.name`[0]), sz);
#py elif p.itype == 'double':
                simGetStackDoubleTableE(p->stackID, &(in_args.`p.name`[0]), sz);
#py elif p.itype == 'int':
                simGetStackInt32TableE(p->stackID, &(in_args.`p.name`[0]), sz);
#py endif
                simPopStackItemE(p->stackID, 1);
#py else:
                // read input argument `i+1` (`p.name`) of type array of `p.ctype()`
                simMoveStackItemToTopE(p->stackID, 0);
                int i = simGetStackTableInfoE(p->stackID, 0);
                if(i < 0)
                {
#ifdef DEBUG
                    if(isDebugStubsEnabled())
                        simDebugStack(p->stackID, -1);
#endif // DEBUG
                    throw exception((boost::format("expected array (simGetStackTableInfo(stack, 0) returned %d)") % i).str());
                }
                int oldsz = simGetStackSizeE(p->stackID);
                simUnfoldStackTableE(p->stackID);
                int sz = (simGetStackSizeE(p->stackID) - oldsz + 1) / 2;
                for(int i = 0; i < sz; i++)
                {
                    simMoveStackItemToTopE(p->stackID, oldsz - 1);
                    int j;
                    read__int(p->stackID, &j);
                    simMoveStackItemToTop(p->stackID, oldsz - 1);
                    `p.item_dummy().ctype()` v;
                    read__`p.ctype_normalized()`(p->stackID, &v);
                    in_args.`p.name`.push_back(v);
                }
#py endif

#py if p.minsize > 0 and p.minsize == p.maxsize:
                if(in_args.`p.name`.size() != `p.minsize`)
                    throw exception("must have exactly `p.minsize` elements");
#py else:
#py if p.minsize > 0:
                if(in_args.`p.name`.size() < `p.minsize`)
                    throw exception("must have at least `p.minsize` elements");
#py endif
#py if p.maxsize is not None:
                if(in_args.`p.name`.size() > `p.maxsize`)
                    throw exception("must have at most `p.maxsize` elements");
#py endif
#py endif
#py else:
                // read input argument `i+1` (`p.name`) of type `p.ctype()`
                simMoveStackItemToTopE(p->stackID, 0);
                read__`p.ctype_normalized()`(p->stackID, &(in_args.`p.name`));
#py endif
            }
            CATCH_AND_RETHROW("read in arg `i+1` (`p.name`): ")
        }

#py endfor

#ifdef DEBUG
        if(isDebugStubsEnabled())
            simDebugStack(p->stackID, -1);
#endif // DEBUG

#py if cmd.clear_stack_after_reading_input:
        // clear stack
        simPopStackItemE(p->stackID, 0);

#py endif
        `cmd.name`(p, cmd, &in_args, &out_args);
    }
    catch(std::exception& e)
    {
#ifdef DEBUG
        std::cerr << cmd << ": " << e.what() << std::endl;
#endif
        simSetLastError(cmd, e.what());
    }
    catch(std::string& s)
    {
#ifdef DEBUG
        std::cerr << cmd << ": " << s << std::endl;
#endif
        simSetLastError(cmd, s.c_str());
    }
    catch(int& n)
    {
        std::stringstream ss;
        ss << "error #" << n;
#ifdef DEBUG
        std::cerr << cmd << ": " << ss.str() << std::endl;
#endif
        simSetLastError(cmd, ss.str().c_str());
    }

    try
    {
#ifdef DEBUG
        if(isDebugStubsEnabled())
        {
            std::cout << "DEBUG_STUBS: writing output arguments..." << std::endl;
            simDebugStack(p->stackID, -1);
        }
#endif // DEBUG

#py if cmd.clear_stack_before_writing_output:
        // clear stack
        simPopStackItemE(p->stackID, 0);

#py endif

        // write output arguments to stack

#py for i, p in enumerate(cmd.returns):
        try
        {
#ifdef DEBUG
            if(isDebugStubsEnabled())
                std::cout << "DEBUG_STUBS: writing output argument `i+1` (`p.name`)..." << std::endl;
#endif // DEBUG

#py if isinstance(p, model.ParamTable):
            // write output argument `i+1` (`p.name`) of type array of `p.ctype()`
            simPushTableOntoStackE(p->stackID);
            for(int i = 0; i < out_args.`p.name`.size(); i++)
            {
                write__int(i + 1, p->stackID);
                write__`p.ctype_normalized()`(`p.argmod()`(out_args.`p.name`[i]), p->stackID);
                simInsertDataIntoStackTableE(p->stackID);
            }
#py else:
            // write output argument `i+1` (`p.name`) of type `p.ctype()`
            write__`p.ctype_normalized()`(`p.argmod()`(out_args.`p.name`), p->stackID);
#py endif
        }
        CATCH_AND_RETHROW("write out arg `i+1` (`p.name`): ")
#py endfor

#ifdef DEBUG
        if(isDebugStubsEnabled())
            simDebugStack(p->stackID, -1);
#endif // DEBUG
    }
    catch(std::exception& e)
    {
#ifdef DEBUG
        std::cerr << cmd << ": " << e.what() << std::endl;
#endif
        simSetLastError(cmd, e.what());
        // clear stack
        simPopStackItem(p->stackID, 0); // don't throw
    }
    catch(std::string& s)
    {
#ifdef DEBUG
        std::cerr << cmd << ": " << s << std::endl;
#endif
        simSetLastError(cmd, s.c_str());
        // clear stack
        simPopStackItem(p->stackID, 0); // don't throw
    }
    catch(int& n)
    {
        std::stringstream ss;
        ss << "error #" << n;
#ifdef DEBUG
        std::cerr << cmd << ": " << ss.str() << std::endl;
#endif
        simSetLastError(cmd, ss.str().c_str());
        // clear stack
        simPopStackItem(p->stackID, 0); // don't throw
    }
}

#py endfor
#py for fn in plugin.script_functions:
`fn.name`_in::`fn.name`_in()
{
#py for p in fn.params:
#py if p.default is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

`fn.name`_out::`fn.name`_out()
{
#py for p in fn.returns:
#py if p.default is not None:
    `p.name` = `p.cdefault()`;
#py endif
#py endfor
}

bool `fn.name`(simInt scriptId, const char *func, `fn.name`_in *in_args, `fn.name`_out *out_args)
{
#ifdef DEBUG
    if(isDebugStubsEnabled())
    {
        std::cout << "DEBUG_STUBS: script callback function for \"`fn.name`\"..." << std::endl;
        std::cout << "DEBUG_STUBS: writing input arguments..." << std::endl;
    }
#endif // DEBUG

    int stackID = -1;

    try
    {
        stackID = simCreateStackE();

        // write input arguments to stack

#py for i, p in enumerate(fn.params):
        try
        {
#py if isinstance(p, model.ParamTable):
            // write input argument `i+1` (`p.name`) of type array of `p.ctype()`
            simPushTableOntoStackE(stackID);
            for(int i = 0; i < in_args->`p.name`.size(); i++)
            {
                write__int(i + 1, stackID);
                write__`p.ctype_normalized()`(`p.argmod()`(in_args->`p.name`[i]), stackID);
                simInsertDataIntoStackTableE(stackID);
            }
#py else:
            // write input argument `i+1` (`p.name`) of type `p.ctype()`
            write__`p.ctype_normalized()`(`p.argmod()`(in_args->`p.name`), stackID);
#py endif
        }
        CATCH_AND_RETHROW("writing input argument `i+1` (`p.name`): ")
#py endfor

#ifdef DEBUG
        if(isDebugStubsEnabled())
            simDebugStack(stackID, -1);
#endif // DEBUG

        simCallScriptFunctionExE(scriptId, func, stackID);

        // read output arguments from stack

#ifdef DEBUG
        if(isDebugStubsEnabled())
            std::cout << "DEBUG_STUBS: reading output arguments..." << std::endl;
#endif // DEBUG

#py for i, p in enumerate(fn.returns):
        try
        {
#py if isinstance(p, model.ParamTable):
            // read output argument `i+1` (`p.name`) of type array of `p.ctype()`
            simMoveStackItemToTopE(stackID, 0);
            int i = simGetStackTableInfoE(stackID, 0);
            if(i < 0)
            {
#ifdef DEBUG
                if(isDebugStubsEnabled())
                    simDebugStack(stackID, -1);
#endif // DEBUG
                throw exception((boost::format("expected array (simGetStackTableInfo(stack, 0) returned %d)") % i).str());
            }
            int oldsz = simGetStackSizeE(stackID);
            simUnfoldStackTableE(stackID);
            int sz = (simGetStackSizeE(stackID) - oldsz + 1) / 2;
            for(int i = 0; i < sz; i++)
            {
                simMoveStackItemToTopE(stackID, oldsz - 1);
                int j;
                read__int(stackID, &j);
                simMoveStackItemToTop(stackID, oldsz - 1);
                `p.ctype_normalized()` v;
                read__`p.ctype_normalized()`(stackID, &v);
                out_args->`p.name`.push_back(v);
            }
#py if p.minsize > 0 and p.minsize == p.maxsize:
            if(out_args->`p.name`.size() != `p.minsize`)
                throw exception("must have exactly `p.minsize` elements");
#py else:
#py if p.minsize > 0:
            if(out_args->`p.name`.size() < `p.minsize`)
                throw exception("must have at least `p.minsize` elements");
#py endif
#py if p.maxsize is not None:
            if(out_args->`p.name`.size() > `p.maxsize`)
                throw exception("must have at most `p.maxsize` elements");
#py endif
#py endif
#py else:
            // read output argument `i+1` (`p.name`) of type `p.ctype()`
            read__`p.ctype_normalized()`(stackID, &(out_args->`p.name`));
#py endif
        }
        CATCH_AND_RETHROW("read out arg `i+1` (`p.name`): ")
#py endfor

#ifdef DEBUG
        if(isDebugStubsEnabled())
            simDebugStack(stackID, -1);
#endif // DEBUG

        simReleaseStackE(stackID);
        stackID = -1;
    }
    catch(std::exception& ex)
    {
        if(stackID != -1)
            simReleaseStack(stackID); // don't throw
        simSetLastError(func, ex.what());
        return false;
    }
    catch(std::string& s)
    {
        if(stackID != -1)
            simReleaseStack(stackID); // don't throw
        simSetLastError(func, s.c_str());
        return false;
    }
    catch(int& n)
    {
        if(stackID != -1)
            simReleaseStack(stackID); // don't throw
        std::stringstream ss;
        ss << "error #" << n;
        simSetLastError(func, ss.str().c_str());
        return false;
    }

    return true;
}

#py endfor
