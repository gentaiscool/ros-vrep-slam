#include <ros_msg_io.h>
#include <v_repLib.h>
#include <stubs.h>
#include <cstring>


void write__control_msgs__JointControllerState(const control_msgs::JointControllerState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'process_value'
            simPushStringOntoStackE(stack, "process_value", 0);
            write__float64(msg.process_value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'process_value': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'process_value_dot'
            simPushStringOntoStackE(stack, "process_value_dot", 0);
            write__float64(msg.process_value_dot, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'process_value_dot': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'd'
            simPushStringOntoStackE(stack, "d", 0);
            write__float64(msg.d, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'd': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'p'
            simPushStringOntoStackE(stack, "p", 0);
            write__float64(msg.p, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'p': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'i'
            simPushStringOntoStackE(stack, "i", 0);
            write__float64(msg.i, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'i': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'set_point'
            simPushStringOntoStackE(stack, "set_point", 0);
            write__float64(msg.set_point, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'set_point': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'command'
            simPushStringOntoStackE(stack, "command", 0);
            write__float64(msg.command, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'command': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'i_clamp'
            simPushStringOntoStackE(stack, "i_clamp", 0);
            write__float64(msg.i_clamp, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'i_clamp': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'error'
            simPushStringOntoStackE(stack, "error", 0);
            write__float64(msg.error, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'error': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_step'
            simPushStringOntoStackE(stack, "time_step", 0);
            write__float64(msg.time_step, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_step': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'antiwindup'
            simPushStringOntoStackE(stack, "antiwindup", 0);
            write__bool(msg.antiwindup, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'antiwindup': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__control_msgs__JointControllerState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__control_msgs__JointControllerState(int stack, control_msgs::JointControllerState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "process_value") == 0)
                {
                    try
                    {
                        // read field 'process_value'
                        read__float64(stack, &(msg->process_value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field process_value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "process_value_dot") == 0)
                {
                    try
                    {
                        // read field 'process_value_dot'
                        read__float64(stack, &(msg->process_value_dot), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field process_value_dot: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "d") == 0)
                {
                    try
                    {
                        // read field 'd'
                        read__float64(stack, &(msg->d), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field d: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "p") == 0)
                {
                    try
                    {
                        // read field 'p'
                        read__float64(stack, &(msg->p), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field p: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "i") == 0)
                {
                    try
                    {
                        // read field 'i'
                        read__float64(stack, &(msg->i), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field i: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "set_point") == 0)
                {
                    try
                    {
                        // read field 'set_point'
                        read__float64(stack, &(msg->set_point), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field set_point: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "command") == 0)
                {
                    try
                    {
                        // read field 'command'
                        read__float64(stack, &(msg->command), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field command: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "i_clamp") == 0)
                {
                    try
                    {
                        // read field 'i_clamp'
                        read__float64(stack, &(msg->i_clamp), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field i_clamp: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "error") == 0)
                {
                    try
                    {
                        // read field 'error'
                        read__float64(stack, &(msg->error), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field error: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_step") == 0)
                {
                    try
                    {
                        // read field 'time_step'
                        read__float64(stack, &(msg->time_step), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_step: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "antiwindup") == 0)
                {
                    try
                    {
                        // read field 'antiwindup'
                        read__bool(stack, &(msg->antiwindup), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field antiwindup: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__control_msgs__JointControllerState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__control_msgs__JointControllerState(const boost::shared_ptr<control_msgs::JointControllerState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__control_msgs__JointControllerState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__control_msgs__JointControllerState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__control_msgs__JointTolerance(const control_msgs::JointTolerance& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'acceleration'
            simPushStringOntoStackE(stack, "acceleration", 0);
            write__float64(msg.acceleration, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'acceleration': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'position'
            simPushStringOntoStackE(stack, "position", 0);
            write__float64(msg.position, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'velocity'
            simPushStringOntoStackE(stack, "velocity", 0);
            write__float64(msg.velocity, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'velocity': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__control_msgs__JointTolerance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__control_msgs__JointTolerance(int stack, control_msgs::JointTolerance *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "acceleration") == 0)
                {
                    try
                    {
                        // read field 'acceleration'
                        read__float64(stack, &(msg->acceleration), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field acceleration: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "position") == 0)
                {
                    try
                    {
                        // read field 'position'
                        read__float64(stack, &(msg->position), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "velocity") == 0)
                {
                    try
                    {
                        // read field 'velocity'
                        read__float64(stack, &(msg->velocity), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field velocity: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__control_msgs__JointTolerance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__control_msgs__JointTolerance(const boost::shared_ptr<control_msgs::JointTolerance const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__control_msgs__JointTolerance(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__control_msgs__JointTolerance: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__diagnostic_msgs__DiagnosticArray(const diagnostic_msgs::DiagnosticArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'status'
            simPushStringOntoStackE(stack, "status", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.status.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__diagnostic_msgs__DiagnosticStatus(msg.status[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'status': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__diagnostic_msgs__DiagnosticArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__diagnostic_msgs__DiagnosticArray(int stack, diagnostic_msgs::DiagnosticArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "status") == 0)
                {
                    try
                    {
                        // read field 'status'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            diagnostic_msgs::DiagnosticStatus v;
                            read__diagnostic_msgs__DiagnosticStatus(stack, &v, opt);
                            msg->status.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field status: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__diagnostic_msgs__DiagnosticArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__diagnostic_msgs__DiagnosticArray(const boost::shared_ptr<diagnostic_msgs::DiagnosticArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__diagnostic_msgs__DiagnosticArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__diagnostic_msgs__DiagnosticArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__diagnostic_msgs__DiagnosticStatus(const diagnostic_msgs::DiagnosticStatus& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'message'
            simPushStringOntoStackE(stack, "message", 0);
            write__string(msg.message, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'message': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'hardware_id'
            simPushStringOntoStackE(stack, "hardware_id", 0);
            write__string(msg.hardware_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'hardware_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'values'
            simPushStringOntoStackE(stack, "values", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.values.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__diagnostic_msgs__KeyValue(msg.values[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'values': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'level'
            simPushStringOntoStackE(stack, "level", 0);
            write__int8(msg.level, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'level': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__diagnostic_msgs__DiagnosticStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__diagnostic_msgs__DiagnosticStatus(int stack, diagnostic_msgs::DiagnosticStatus *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "message") == 0)
                {
                    try
                    {
                        // read field 'message'
                        read__string(stack, &(msg->message), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field message: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "hardware_id") == 0)
                {
                    try
                    {
                        // read field 'hardware_id'
                        read__string(stack, &(msg->hardware_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field hardware_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "values") == 0)
                {
                    try
                    {
                        // read field 'values'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            diagnostic_msgs::KeyValue v;
                            read__diagnostic_msgs__KeyValue(stack, &v, opt);
                            msg->values.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field values: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "level") == 0)
                {
                    try
                    {
                        // read field 'level'
                        read__int8(stack, &(msg->level), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field level: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__diagnostic_msgs__DiagnosticStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__diagnostic_msgs__DiagnosticStatus(const boost::shared_ptr<diagnostic_msgs::DiagnosticStatus const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__diagnostic_msgs__DiagnosticStatus(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__diagnostic_msgs__DiagnosticStatus: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__diagnostic_msgs__KeyValue(const diagnostic_msgs::KeyValue& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'value'
            simPushStringOntoStackE(stack, "value", 0);
            write__string(msg.value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'value': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'key'
            simPushStringOntoStackE(stack, "key", 0);
            write__string(msg.key, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'key': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__diagnostic_msgs__KeyValue: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__diagnostic_msgs__KeyValue(int stack, diagnostic_msgs::KeyValue *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "value") == 0)
                {
                    try
                    {
                        // read field 'value'
                        read__string(stack, &(msg->value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "key") == 0)
                {
                    try
                    {
                        // read field 'key'
                        read__string(stack, &(msg->key), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field key: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__diagnostic_msgs__KeyValue: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__diagnostic_msgs__KeyValue(const boost::shared_ptr<diagnostic_msgs::KeyValue const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__diagnostic_msgs__KeyValue(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__diagnostic_msgs__KeyValue: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__BoolParameter(const dynamic_reconfigure::BoolParameter& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'value'
            simPushStringOntoStackE(stack, "value", 0);
            write__bool(msg.value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'value': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__BoolParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__BoolParameter(int stack, dynamic_reconfigure::BoolParameter *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "value") == 0)
                {
                    try
                    {
                        // read field 'value'
                        read__bool(stack, &(msg->value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__BoolParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__BoolParameter(const boost::shared_ptr<dynamic_reconfigure::BoolParameter const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__BoolParameter(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__BoolParameter: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__Config(const dynamic_reconfigure::Config& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'strs'
            simPushStringOntoStackE(stack, "strs", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.strs.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__StrParameter(msg.strs[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'strs': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'doubles'
            simPushStringOntoStackE(stack, "doubles", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.doubles.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__DoubleParameter(msg.doubles[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'doubles': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'groups'
            simPushStringOntoStackE(stack, "groups", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.groups.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__GroupState(msg.groups[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'groups': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ints'
            simPushStringOntoStackE(stack, "ints", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.ints.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__IntParameter(msg.ints[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ints': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'bools'
            simPushStringOntoStackE(stack, "bools", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.bools.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__BoolParameter(msg.bools[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'bools': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__Config: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__Config(int stack, dynamic_reconfigure::Config *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "strs") == 0)
                {
                    try
                    {
                        // read field 'strs'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::StrParameter v;
                            read__dynamic_reconfigure__StrParameter(stack, &v, opt);
                            msg->strs.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field strs: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "doubles") == 0)
                {
                    try
                    {
                        // read field 'doubles'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::DoubleParameter v;
                            read__dynamic_reconfigure__DoubleParameter(stack, &v, opt);
                            msg->doubles.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field doubles: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "groups") == 0)
                {
                    try
                    {
                        // read field 'groups'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::GroupState v;
                            read__dynamic_reconfigure__GroupState(stack, &v, opt);
                            msg->groups.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field groups: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ints") == 0)
                {
                    try
                    {
                        // read field 'ints'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::IntParameter v;
                            read__dynamic_reconfigure__IntParameter(stack, &v, opt);
                            msg->ints.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ints: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "bools") == 0)
                {
                    try
                    {
                        // read field 'bools'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::BoolParameter v;
                            read__dynamic_reconfigure__BoolParameter(stack, &v, opt);
                            msg->bools.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field bools: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__Config: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__Config(const boost::shared_ptr<dynamic_reconfigure::Config const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__Config(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__Config: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__ConfigDescription(const dynamic_reconfigure::ConfigDescription& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'max'
            simPushStringOntoStackE(stack, "max", 0);
            write__dynamic_reconfigure__Config(msg.max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'dflt'
            simPushStringOntoStackE(stack, "dflt", 0);
            write__dynamic_reconfigure__Config(msg.dflt, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'dflt': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'groups'
            simPushStringOntoStackE(stack, "groups", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.groups.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__Group(msg.groups[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'groups': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'min'
            simPushStringOntoStackE(stack, "min", 0);
            write__dynamic_reconfigure__Config(msg.min, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'min': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__ConfigDescription: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__ConfigDescription(int stack, dynamic_reconfigure::ConfigDescription *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "max") == 0)
                {
                    try
                    {
                        // read field 'max'
                        read__dynamic_reconfigure__Config(stack, &(msg->max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "dflt") == 0)
                {
                    try
                    {
                        // read field 'dflt'
                        read__dynamic_reconfigure__Config(stack, &(msg->dflt), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field dflt: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "groups") == 0)
                {
                    try
                    {
                        // read field 'groups'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::Group v;
                            read__dynamic_reconfigure__Group(stack, &v, opt);
                            msg->groups.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field groups: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "min") == 0)
                {
                    try
                    {
                        // read field 'min'
                        read__dynamic_reconfigure__Config(stack, &(msg->min), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field min: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__ConfigDescription: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__ConfigDescription(const boost::shared_ptr<dynamic_reconfigure::ConfigDescription const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__ConfigDescription(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__ConfigDescription: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__DoubleParameter(const dynamic_reconfigure::DoubleParameter& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'value'
            simPushStringOntoStackE(stack, "value", 0);
            write__float64(msg.value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'value': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__DoubleParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__DoubleParameter(int stack, dynamic_reconfigure::DoubleParameter *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "value") == 0)
                {
                    try
                    {
                        // read field 'value'
                        read__float64(stack, &(msg->value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__DoubleParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__DoubleParameter(const boost::shared_ptr<dynamic_reconfigure::DoubleParameter const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__DoubleParameter(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__DoubleParameter: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__Group(const dynamic_reconfigure::Group& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'parent'
            simPushStringOntoStackE(stack, "parent", 0);
            write__int32(msg.parent, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'parent': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__string(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'parameters'
            simPushStringOntoStackE(stack, "parameters", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.parameters.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__dynamic_reconfigure__ParamDescription(msg.parameters[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'parameters': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__int32(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__Group: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__Group(int stack, dynamic_reconfigure::Group *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "parent") == 0)
                {
                    try
                    {
                        // read field 'parent'
                        read__int32(stack, &(msg->parent), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field parent: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__string(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "parameters") == 0)
                {
                    try
                    {
                        // read field 'parameters'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            dynamic_reconfigure::ParamDescription v;
                            read__dynamic_reconfigure__ParamDescription(stack, &v, opt);
                            msg->parameters.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field parameters: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__int32(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__Group: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__Group(const boost::shared_ptr<dynamic_reconfigure::Group const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__Group(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__Group: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__GroupState(const dynamic_reconfigure::GroupState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'state'
            simPushStringOntoStackE(stack, "state", 0);
            write__bool(msg.state, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'state': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'parent'
            simPushStringOntoStackE(stack, "parent", 0);
            write__int32(msg.parent, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'parent': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__int32(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__GroupState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__GroupState(int stack, dynamic_reconfigure::GroupState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "state") == 0)
                {
                    try
                    {
                        // read field 'state'
                        read__bool(stack, &(msg->state), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field state: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "parent") == 0)
                {
                    try
                    {
                        // read field 'parent'
                        read__int32(stack, &(msg->parent), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field parent: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__int32(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__GroupState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__GroupState(const boost::shared_ptr<dynamic_reconfigure::GroupState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__GroupState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__GroupState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__IntParameter(const dynamic_reconfigure::IntParameter& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'value'
            simPushStringOntoStackE(stack, "value", 0);
            write__int32(msg.value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'value': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__IntParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__IntParameter(int stack, dynamic_reconfigure::IntParameter *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "value") == 0)
                {
                    try
                    {
                        // read field 'value'
                        read__int32(stack, &(msg->value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__IntParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__IntParameter(const boost::shared_ptr<dynamic_reconfigure::IntParameter const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__IntParameter(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__IntParameter: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__ParamDescription(const dynamic_reconfigure::ParamDescription& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'description'
            simPushStringOntoStackE(stack, "description", 0);
            write__string(msg.description, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'description': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'edit_method'
            simPushStringOntoStackE(stack, "edit_method", 0);
            write__string(msg.edit_method, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'edit_method': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__string(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'level'
            simPushStringOntoStackE(stack, "level", 0);
            write__uint32(msg.level, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'level': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__ParamDescription: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__ParamDescription(int stack, dynamic_reconfigure::ParamDescription *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "description") == 0)
                {
                    try
                    {
                        // read field 'description'
                        read__string(stack, &(msg->description), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field description: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "edit_method") == 0)
                {
                    try
                    {
                        // read field 'edit_method'
                        read__string(stack, &(msg->edit_method), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field edit_method: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__string(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "level") == 0)
                {
                    try
                    {
                        // read field 'level'
                        read__uint32(stack, &(msg->level), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field level: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__ParamDescription: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__ParamDescription(const boost::shared_ptr<dynamic_reconfigure::ParamDescription const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__ParamDescription(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__ParamDescription: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__SensorLevels(const dynamic_reconfigure::SensorLevels& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__SensorLevels: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__SensorLevels(int stack, dynamic_reconfigure::SensorLevels *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__SensorLevels: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__SensorLevels(const boost::shared_ptr<dynamic_reconfigure::SensorLevels const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__SensorLevels(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__SensorLevels: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__dynamic_reconfigure__StrParameter(const dynamic_reconfigure::StrParameter& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'value'
            simPushStringOntoStackE(stack, "value", 0);
            write__string(msg.value, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'value': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__StrParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__StrParameter(int stack, dynamic_reconfigure::StrParameter *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "value") == 0)
                {
                    try
                    {
                        // read field 'value'
                        read__string(stack, &(msg->value), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field value: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__dynamic_reconfigure__StrParameter: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__dynamic_reconfigure__StrParameter(const boost::shared_ptr<dynamic_reconfigure::StrParameter const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__StrParameter(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__dynamic_reconfigure__StrParameter: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ContactState(const gazebo_msgs::ContactState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'info'
            simPushStringOntoStackE(stack, "info", 0);
            write__string(msg.info, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'info': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'collision2_name'
            simPushStringOntoStackE(stack, "collision2_name", 0);
            write__string(msg.collision2_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'collision2_name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'contact_normals'
            simPushStringOntoStackE(stack, "contact_normals", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.contact_normals.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Vector3(msg.contact_normals[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'contact_normals': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'contact_positions'
            simPushStringOntoStackE(stack, "contact_positions", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.contact_positions.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Vector3(msg.contact_positions[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'contact_positions': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'total_wrench'
            simPushStringOntoStackE(stack, "total_wrench", 0);
            write__geometry_msgs__Wrench(msg.total_wrench, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'total_wrench': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'wrenches'
            simPushStringOntoStackE(stack, "wrenches", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.wrenches.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Wrench(msg.wrenches[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'wrenches': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'depths' (using fast specialized function)
            simPushStringOntoStackE(stack, "depths", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.depths[0]), msg.depths.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'depths': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'collision1_name'
            simPushStringOntoStackE(stack, "collision1_name", 0);
            write__string(msg.collision1_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'collision1_name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ContactState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ContactState(int stack, gazebo_msgs::ContactState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "info") == 0)
                {
                    try
                    {
                        // read field 'info'
                        read__string(stack, &(msg->info), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field info: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "collision2_name") == 0)
                {
                    try
                    {
                        // read field 'collision2_name'
                        read__string(stack, &(msg->collision2_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field collision2_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "contact_normals") == 0)
                {
                    try
                    {
                        // read field 'contact_normals'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Vector3 v;
                            read__geometry_msgs__Vector3(stack, &v, opt);
                            msg->contact_normals.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field contact_normals: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "contact_positions") == 0)
                {
                    try
                    {
                        // read field 'contact_positions'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Vector3 v;
                            read__geometry_msgs__Vector3(stack, &v, opt);
                            msg->contact_positions.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field contact_positions: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "total_wrench") == 0)
                {
                    try
                    {
                        // read field 'total_wrench'
                        read__geometry_msgs__Wrench(stack, &(msg->total_wrench), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field total_wrench: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "wrenches") == 0)
                {
                    try
                    {
                        // read field 'wrenches'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Wrench v;
                            read__geometry_msgs__Wrench(stack, &v, opt);
                            msg->wrenches.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field wrenches: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "depths") == 0)
                {
                    try
                    {
                        // read field 'depths' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->depths.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->depths[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field depths: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "collision1_name") == 0)
                {
                    try
                    {
                        // read field 'collision1_name'
                        read__string(stack, &(msg->collision1_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field collision1_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ContactState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ContactState(const boost::shared_ptr<gazebo_msgs::ContactState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ContactState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ContactState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ContactsState(const gazebo_msgs::ContactsState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'states'
            simPushStringOntoStackE(stack, "states", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.states.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__gazebo_msgs__ContactState(msg.states[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'states': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ContactsState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ContactsState(int stack, gazebo_msgs::ContactsState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "states") == 0)
                {
                    try
                    {
                        // read field 'states'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            gazebo_msgs::ContactState v;
                            read__gazebo_msgs__ContactState(stack, &v, opt);
                            msg->states.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field states: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ContactsState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ContactsState(const boost::shared_ptr<gazebo_msgs::ContactsState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ContactsState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ContactsState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__LinkState(const gazebo_msgs::LinkState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__Twist(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'reference_frame'
            simPushStringOntoStackE(stack, "reference_frame", 0);
            write__string(msg.reference_frame, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'reference_frame': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'link_name'
            simPushStringOntoStackE(stack, "link_name", 0);
            write__string(msg.link_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'link_name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__LinkState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__LinkState(int stack, gazebo_msgs::LinkState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__Twist(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "reference_frame") == 0)
                {
                    try
                    {
                        // read field 'reference_frame'
                        read__string(stack, &(msg->reference_frame), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field reference_frame: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "link_name") == 0)
                {
                    try
                    {
                        // read field 'link_name'
                        read__string(stack, &(msg->link_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field link_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__LinkState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__LinkState(const boost::shared_ptr<gazebo_msgs::LinkState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__LinkState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__LinkState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__LinkStates(const gazebo_msgs::LinkStates& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.twist.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.twist[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.pose.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Pose(msg.pose[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.name.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.name[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__LinkStates: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__LinkStates(int stack, gazebo_msgs::LinkStates *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->twist.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Pose v;
                            read__geometry_msgs__Pose(stack, &v, opt);
                            msg->pose.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->name.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__LinkStates: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__LinkStates(const boost::shared_ptr<gazebo_msgs::LinkStates const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__LinkStates(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__LinkStates: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ModelState(const gazebo_msgs::ModelState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__Twist(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'reference_frame'
            simPushStringOntoStackE(stack, "reference_frame", 0);
            write__string(msg.reference_frame, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'reference_frame': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'model_name'
            simPushStringOntoStackE(stack, "model_name", 0);
            write__string(msg.model_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'model_name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ModelState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ModelState(int stack, gazebo_msgs::ModelState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__Twist(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "reference_frame") == 0)
                {
                    try
                    {
                        // read field 'reference_frame'
                        read__string(stack, &(msg->reference_frame), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field reference_frame: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "model_name") == 0)
                {
                    try
                    {
                        // read field 'model_name'
                        read__string(stack, &(msg->model_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field model_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ModelState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ModelState(const boost::shared_ptr<gazebo_msgs::ModelState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ModelState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ModelState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ModelStates(const gazebo_msgs::ModelStates& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.twist.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.twist[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.pose.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Pose(msg.pose[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.name.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.name[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ModelStates: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ModelStates(int stack, gazebo_msgs::ModelStates *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->twist.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Pose v;
                            read__geometry_msgs__Pose(stack, &v, opt);
                            msg->pose.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->name.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ModelStates: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ModelStates(const boost::shared_ptr<gazebo_msgs::ModelStates const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ModelStates(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ModelStates: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ODEJointProperties(const gazebo_msgs::ODEJointProperties& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'fudge_factor' (using fast specialized function)
            simPushStringOntoStackE(stack, "fudge_factor", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.fudge_factor[0]), msg.fudge_factor.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'fudge_factor': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'cfm' (using fast specialized function)
            simPushStringOntoStackE(stack, "cfm", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.cfm[0]), msg.cfm.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'cfm': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'erp' (using fast specialized function)
            simPushStringOntoStackE(stack, "erp", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.erp[0]), msg.erp.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'erp': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'fmax' (using fast specialized function)
            simPushStringOntoStackE(stack, "fmax", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.fmax[0]), msg.fmax.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'fmax': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'stop_cfm' (using fast specialized function)
            simPushStringOntoStackE(stack, "stop_cfm", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.stop_cfm[0]), msg.stop_cfm.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stop_cfm': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'loStop' (using fast specialized function)
            simPushStringOntoStackE(stack, "loStop", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.loStop[0]), msg.loStop.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'loStop': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'hiStop' (using fast specialized function)
            simPushStringOntoStackE(stack, "hiStop", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.hiStop[0]), msg.hiStop.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'hiStop': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'damping' (using fast specialized function)
            simPushStringOntoStackE(stack, "damping", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.damping[0]), msg.damping.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'damping': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'vel' (using fast specialized function)
            simPushStringOntoStackE(stack, "vel", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.vel[0]), msg.vel.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'vel': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'stop_erp' (using fast specialized function)
            simPushStringOntoStackE(stack, "stop_erp", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.stop_erp[0]), msg.stop_erp.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stop_erp': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ODEJointProperties: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ODEJointProperties(int stack, gazebo_msgs::ODEJointProperties *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "fudge_factor") == 0)
                {
                    try
                    {
                        // read field 'fudge_factor' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->fudge_factor.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->fudge_factor[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field fudge_factor: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "cfm") == 0)
                {
                    try
                    {
                        // read field 'cfm' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->cfm.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->cfm[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field cfm: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "erp") == 0)
                {
                    try
                    {
                        // read field 'erp' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->erp.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->erp[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field erp: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "fmax") == 0)
                {
                    try
                    {
                        // read field 'fmax' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->fmax.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->fmax[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field fmax: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "stop_cfm") == 0)
                {
                    try
                    {
                        // read field 'stop_cfm' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->stop_cfm.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->stop_cfm[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stop_cfm: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "loStop") == 0)
                {
                    try
                    {
                        // read field 'loStop' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->loStop.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->loStop[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field loStop: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "hiStop") == 0)
                {
                    try
                    {
                        // read field 'hiStop' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->hiStop.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->hiStop[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field hiStop: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "damping") == 0)
                {
                    try
                    {
                        // read field 'damping' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->damping.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->damping[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field damping: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "vel") == 0)
                {
                    try
                    {
                        // read field 'vel' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->vel.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->vel[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field vel: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "stop_erp") == 0)
                {
                    try
                    {
                        // read field 'stop_erp' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->stop_erp.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->stop_erp[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stop_erp: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ODEJointProperties: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ODEJointProperties(const boost::shared_ptr<gazebo_msgs::ODEJointProperties const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ODEJointProperties(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ODEJointProperties: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__ODEPhysics(const gazebo_msgs::ODEPhysics& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'cfm'
            simPushStringOntoStackE(stack, "cfm", 0);
            write__float64(msg.cfm, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'cfm': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'erp'
            simPushStringOntoStackE(stack, "erp", 0);
            write__float64(msg.erp, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'erp': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'contact_max_correcting_vel'
            simPushStringOntoStackE(stack, "contact_max_correcting_vel", 0);
            write__float64(msg.contact_max_correcting_vel, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'contact_max_correcting_vel': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'sor_pgs_iters'
            simPushStringOntoStackE(stack, "sor_pgs_iters", 0);
            write__uint32(msg.sor_pgs_iters, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'sor_pgs_iters': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'sor_pgs_precon_iters'
            simPushStringOntoStackE(stack, "sor_pgs_precon_iters", 0);
            write__uint32(msg.sor_pgs_precon_iters, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'sor_pgs_precon_iters': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'auto_disable_bodies'
            simPushStringOntoStackE(stack, "auto_disable_bodies", 0);
            write__bool(msg.auto_disable_bodies, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'auto_disable_bodies': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'contact_surface_layer'
            simPushStringOntoStackE(stack, "contact_surface_layer", 0);
            write__float64(msg.contact_surface_layer, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'contact_surface_layer': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'sor_pgs_rms_error_tol'
            simPushStringOntoStackE(stack, "sor_pgs_rms_error_tol", 0);
            write__float64(msg.sor_pgs_rms_error_tol, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'sor_pgs_rms_error_tol': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'max_contacts'
            simPushStringOntoStackE(stack, "max_contacts", 0);
            write__uint32(msg.max_contacts, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'max_contacts': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'sor_pgs_w'
            simPushStringOntoStackE(stack, "sor_pgs_w", 0);
            write__float64(msg.sor_pgs_w, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'sor_pgs_w': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__ODEPhysics: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__ODEPhysics(int stack, gazebo_msgs::ODEPhysics *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "cfm") == 0)
                {
                    try
                    {
                        // read field 'cfm'
                        read__float64(stack, &(msg->cfm), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field cfm: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "erp") == 0)
                {
                    try
                    {
                        // read field 'erp'
                        read__float64(stack, &(msg->erp), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field erp: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "contact_max_correcting_vel") == 0)
                {
                    try
                    {
                        // read field 'contact_max_correcting_vel'
                        read__float64(stack, &(msg->contact_max_correcting_vel), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field contact_max_correcting_vel: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "sor_pgs_iters") == 0)
                {
                    try
                    {
                        // read field 'sor_pgs_iters'
                        read__uint32(stack, &(msg->sor_pgs_iters), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field sor_pgs_iters: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "sor_pgs_precon_iters") == 0)
                {
                    try
                    {
                        // read field 'sor_pgs_precon_iters'
                        read__uint32(stack, &(msg->sor_pgs_precon_iters), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field sor_pgs_precon_iters: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "auto_disable_bodies") == 0)
                {
                    try
                    {
                        // read field 'auto_disable_bodies'
                        read__bool(stack, &(msg->auto_disable_bodies), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field auto_disable_bodies: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "contact_surface_layer") == 0)
                {
                    try
                    {
                        // read field 'contact_surface_layer'
                        read__float64(stack, &(msg->contact_surface_layer), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field contact_surface_layer: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "sor_pgs_rms_error_tol") == 0)
                {
                    try
                    {
                        // read field 'sor_pgs_rms_error_tol'
                        read__float64(stack, &(msg->sor_pgs_rms_error_tol), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field sor_pgs_rms_error_tol: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "max_contacts") == 0)
                {
                    try
                    {
                        // read field 'max_contacts'
                        read__uint32(stack, &(msg->max_contacts), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field max_contacts: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "sor_pgs_w") == 0)
                {
                    try
                    {
                        // read field 'sor_pgs_w'
                        read__float64(stack, &(msg->sor_pgs_w), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field sor_pgs_w: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__ODEPhysics: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__ODEPhysics(const boost::shared_ptr<gazebo_msgs::ODEPhysics const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__ODEPhysics(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__ODEPhysics: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__gazebo_msgs__WorldState(const gazebo_msgs::WorldState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.twist.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.twist[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.pose.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Pose(msg.pose[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.name.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.name[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'wrench'
            simPushStringOntoStackE(stack, "wrench", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.wrench.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Wrench(msg.wrench[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'wrench': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__gazebo_msgs__WorldState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__gazebo_msgs__WorldState(int stack, gazebo_msgs::WorldState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->twist.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Pose v;
                            read__geometry_msgs__Pose(stack, &v, opt);
                            msg->pose.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->name.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "wrench") == 0)
                {
                    try
                    {
                        // read field 'wrench'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Wrench v;
                            read__geometry_msgs__Wrench(stack, &v, opt);
                            msg->wrench.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field wrench: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__gazebo_msgs__WorldState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__gazebo_msgs__WorldState(const boost::shared_ptr<gazebo_msgs::WorldState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__gazebo_msgs__WorldState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__gazebo_msgs__WorldState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Accel(const geometry_msgs::Accel& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'linear'
            simPushStringOntoStackE(stack, "linear", 0);
            write__geometry_msgs__Vector3(msg.linear, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'linear': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angular'
            simPushStringOntoStackE(stack, "angular", 0);
            write__geometry_msgs__Vector3(msg.angular, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angular': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Accel: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Accel(int stack, geometry_msgs::Accel *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "linear") == 0)
                {
                    try
                    {
                        // read field 'linear'
                        read__geometry_msgs__Vector3(stack, &(msg->linear), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field linear: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angular") == 0)
                {
                    try
                    {
                        // read field 'angular'
                        read__geometry_msgs__Vector3(stack, &(msg->angular), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angular: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Accel: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Accel(const boost::shared_ptr<geometry_msgs::Accel const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Accel(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Accel: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__AccelStamped(const geometry_msgs::AccelStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'accel'
            simPushStringOntoStackE(stack, "accel", 0);
            write__geometry_msgs__Accel(msg.accel, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'accel': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__AccelStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__AccelStamped(int stack, geometry_msgs::AccelStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "accel") == 0)
                {
                    try
                    {
                        // read field 'accel'
                        read__geometry_msgs__Accel(stack, &(msg->accel), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field accel: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__AccelStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__AccelStamped(const boost::shared_ptr<geometry_msgs::AccelStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__AccelStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__AccelStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__AccelWithCovariance(const geometry_msgs::AccelWithCovariance& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'accel'
            simPushStringOntoStackE(stack, "accel", 0);
            write__geometry_msgs__Accel(msg.accel, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'accel': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.covariance[0]), msg.covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__AccelWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__AccelWithCovariance(int stack, geometry_msgs::AccelWithCovariance *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "accel") == 0)
                {
                    try
                    {
                        // read field 'accel'
                        read__geometry_msgs__Accel(stack, &(msg->accel), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field accel: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "covariance") == 0)
                {
                    try
                    {
                        // read field 'covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__AccelWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__AccelWithCovariance(const boost::shared_ptr<geometry_msgs::AccelWithCovariance const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__AccelWithCovariance(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__AccelWithCovariance: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__AccelWithCovarianceStamped(const geometry_msgs::AccelWithCovarianceStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'accel'
            simPushStringOntoStackE(stack, "accel", 0);
            write__geometry_msgs__AccelWithCovariance(msg.accel, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'accel': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__AccelWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__AccelWithCovarianceStamped(int stack, geometry_msgs::AccelWithCovarianceStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "accel") == 0)
                {
                    try
                    {
                        // read field 'accel'
                        read__geometry_msgs__AccelWithCovariance(stack, &(msg->accel), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field accel: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__AccelWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__AccelWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::AccelWithCovarianceStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__AccelWithCovarianceStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__AccelWithCovarianceStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Inertia(const geometry_msgs::Inertia& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'iyy'
            simPushStringOntoStackE(stack, "iyy", 0);
            write__float64(msg.iyy, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'iyy': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'm'
            simPushStringOntoStackE(stack, "m", 0);
            write__float64(msg.m, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'm': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ixz'
            simPushStringOntoStackE(stack, "ixz", 0);
            write__float64(msg.ixz, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ixz': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ixx'
            simPushStringOntoStackE(stack, "ixx", 0);
            write__float64(msg.ixx, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ixx': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ixy'
            simPushStringOntoStackE(stack, "ixy", 0);
            write__float64(msg.ixy, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ixy': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'izz'
            simPushStringOntoStackE(stack, "izz", 0);
            write__float64(msg.izz, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'izz': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'com'
            simPushStringOntoStackE(stack, "com", 0);
            write__geometry_msgs__Vector3(msg.com, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'com': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'iyz'
            simPushStringOntoStackE(stack, "iyz", 0);
            write__float64(msg.iyz, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'iyz': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Inertia: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Inertia(int stack, geometry_msgs::Inertia *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "iyy") == 0)
                {
                    try
                    {
                        // read field 'iyy'
                        read__float64(stack, &(msg->iyy), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field iyy: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "m") == 0)
                {
                    try
                    {
                        // read field 'm'
                        read__float64(stack, &(msg->m), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field m: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ixz") == 0)
                {
                    try
                    {
                        // read field 'ixz'
                        read__float64(stack, &(msg->ixz), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ixz: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ixx") == 0)
                {
                    try
                    {
                        // read field 'ixx'
                        read__float64(stack, &(msg->ixx), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ixx: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ixy") == 0)
                {
                    try
                    {
                        // read field 'ixy'
                        read__float64(stack, &(msg->ixy), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ixy: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "izz") == 0)
                {
                    try
                    {
                        // read field 'izz'
                        read__float64(stack, &(msg->izz), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field izz: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "com") == 0)
                {
                    try
                    {
                        // read field 'com'
                        read__geometry_msgs__Vector3(stack, &(msg->com), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field com: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "iyz") == 0)
                {
                    try
                    {
                        // read field 'iyz'
                        read__float64(stack, &(msg->iyz), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field iyz: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Inertia: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Inertia(const boost::shared_ptr<geometry_msgs::Inertia const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Inertia(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Inertia: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__InertiaStamped(const geometry_msgs::InertiaStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'inertia'
            simPushStringOntoStackE(stack, "inertia", 0);
            write__geometry_msgs__Inertia(msg.inertia, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'inertia': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__InertiaStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__InertiaStamped(int stack, geometry_msgs::InertiaStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "inertia") == 0)
                {
                    try
                    {
                        // read field 'inertia'
                        read__geometry_msgs__Inertia(stack, &(msg->inertia), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field inertia: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__InertiaStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__InertiaStamped(const boost::shared_ptr<geometry_msgs::InertiaStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__InertiaStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__InertiaStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Point(const geometry_msgs::Point& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float64(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float64(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'z'
            simPushStringOntoStackE(stack, "z", 0);
            write__float64(msg.z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'z': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Point: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Point(int stack, geometry_msgs::Point *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float64(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float64(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "z") == 0)
                {
                    try
                    {
                        // read field 'z'
                        read__float64(stack, &(msg->z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Point: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Point(const boost::shared_ptr<geometry_msgs::Point const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Point(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Point: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Point32(const geometry_msgs::Point32& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float32(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float32(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'z'
            simPushStringOntoStackE(stack, "z", 0);
            write__float32(msg.z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'z': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Point32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Point32(int stack, geometry_msgs::Point32 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float32(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float32(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "z") == 0)
                {
                    try
                    {
                        // read field 'z'
                        read__float32(stack, &(msg->z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Point32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Point32(const boost::shared_ptr<geometry_msgs::Point32 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Point32(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Point32: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PointStamped(const geometry_msgs::PointStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'point'
            simPushStringOntoStackE(stack, "point", 0);
            write__geometry_msgs__Point(msg.point, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'point': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PointStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PointStamped(int stack, geometry_msgs::PointStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "point") == 0)
                {
                    try
                    {
                        // read field 'point'
                        read__geometry_msgs__Point(stack, &(msg->point), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field point: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PointStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PointStamped(const boost::shared_ptr<geometry_msgs::PointStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PointStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PointStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Polygon(const geometry_msgs::Polygon& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point32(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Polygon: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Polygon(int stack, geometry_msgs::Polygon *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point32 v;
                            read__geometry_msgs__Point32(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Polygon: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Polygon(const boost::shared_ptr<geometry_msgs::Polygon const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Polygon(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Polygon: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PolygonStamped(const geometry_msgs::PolygonStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'polygon'
            simPushStringOntoStackE(stack, "polygon", 0);
            write__geometry_msgs__Polygon(msg.polygon, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'polygon': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PolygonStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PolygonStamped(int stack, geometry_msgs::PolygonStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "polygon") == 0)
                {
                    try
                    {
                        // read field 'polygon'
                        read__geometry_msgs__Polygon(stack, &(msg->polygon), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field polygon: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PolygonStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PolygonStamped(const boost::shared_ptr<geometry_msgs::PolygonStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PolygonStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PolygonStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Pose(const geometry_msgs::Pose& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'position'
            simPushStringOntoStackE(stack, "position", 0);
            write__geometry_msgs__Point(msg.position, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'orientation'
            simPushStringOntoStackE(stack, "orientation", 0);
            write__geometry_msgs__Quaternion(msg.orientation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'orientation': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Pose: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Pose(int stack, geometry_msgs::Pose *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "position") == 0)
                {
                    try
                    {
                        // read field 'position'
                        read__geometry_msgs__Point(stack, &(msg->position), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "orientation") == 0)
                {
                    try
                    {
                        // read field 'orientation'
                        read__geometry_msgs__Quaternion(stack, &(msg->orientation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field orientation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Pose: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Pose(const boost::shared_ptr<geometry_msgs::Pose const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Pose(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Pose: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Pose2D(const geometry_msgs::Pose2D& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float64(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float64(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'theta'
            simPushStringOntoStackE(stack, "theta", 0);
            write__float64(msg.theta, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'theta': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Pose2D: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Pose2D(int stack, geometry_msgs::Pose2D *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float64(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float64(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "theta") == 0)
                {
                    try
                    {
                        // read field 'theta'
                        read__float64(stack, &(msg->theta), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field theta: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Pose2D: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Pose2D(const boost::shared_ptr<geometry_msgs::Pose2D const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Pose2D(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Pose2D: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PoseArray(const geometry_msgs::PoseArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'poses'
            simPushStringOntoStackE(stack, "poses", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.poses.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Pose(msg.poses[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'poses': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PoseArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PoseArray(int stack, geometry_msgs::PoseArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "poses") == 0)
                {
                    try
                    {
                        // read field 'poses'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Pose v;
                            read__geometry_msgs__Pose(stack, &v, opt);
                            msg->poses.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field poses: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PoseArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PoseArray(const boost::shared_ptr<geometry_msgs::PoseArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PoseArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PoseArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PoseStamped(const geometry_msgs::PoseStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PoseStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PoseStamped(int stack, geometry_msgs::PoseStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PoseStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PoseStamped(const boost::shared_ptr<geometry_msgs::PoseStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PoseStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PoseStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PoseWithCovariance(const geometry_msgs::PoseWithCovariance& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.covariance[0]), msg.covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PoseWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PoseWithCovariance(int stack, geometry_msgs::PoseWithCovariance *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "covariance") == 0)
                {
                    try
                    {
                        // read field 'covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PoseWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PoseWithCovariance(const boost::shared_ptr<geometry_msgs::PoseWithCovariance const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PoseWithCovariance(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PoseWithCovariance: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__PoseWithCovarianceStamped(const geometry_msgs::PoseWithCovarianceStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__PoseWithCovariance(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__PoseWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__PoseWithCovarianceStamped(int stack, geometry_msgs::PoseWithCovarianceStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__PoseWithCovariance(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__PoseWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__PoseWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__PoseWithCovarianceStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__PoseWithCovarianceStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Quaternion(const geometry_msgs::Quaternion& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float64(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float64(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'z'
            simPushStringOntoStackE(stack, "z", 0);
            write__float64(msg.z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'z': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'w'
            simPushStringOntoStackE(stack, "w", 0);
            write__float64(msg.w, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'w': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Quaternion: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Quaternion(int stack, geometry_msgs::Quaternion *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float64(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float64(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "z") == 0)
                {
                    try
                    {
                        // read field 'z'
                        read__float64(stack, &(msg->z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "w") == 0)
                {
                    try
                    {
                        // read field 'w'
                        read__float64(stack, &(msg->w), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field w: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Quaternion: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Quaternion(const boost::shared_ptr<geometry_msgs::Quaternion const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Quaternion(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Quaternion: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__QuaternionStamped(const geometry_msgs::QuaternionStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'quaternion'
            simPushStringOntoStackE(stack, "quaternion", 0);
            write__geometry_msgs__Quaternion(msg.quaternion, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'quaternion': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__QuaternionStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__QuaternionStamped(int stack, geometry_msgs::QuaternionStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "quaternion") == 0)
                {
                    try
                    {
                        // read field 'quaternion'
                        read__geometry_msgs__Quaternion(stack, &(msg->quaternion), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field quaternion: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__QuaternionStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__QuaternionStamped(const boost::shared_ptr<geometry_msgs::QuaternionStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__QuaternionStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__QuaternionStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Transform(const geometry_msgs::Transform& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'translation'
            simPushStringOntoStackE(stack, "translation", 0);
            write__geometry_msgs__Vector3(msg.translation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'translation': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'rotation'
            simPushStringOntoStackE(stack, "rotation", 0);
            write__geometry_msgs__Quaternion(msg.rotation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'rotation': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Transform: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Transform(int stack, geometry_msgs::Transform *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "translation") == 0)
                {
                    try
                    {
                        // read field 'translation'
                        read__geometry_msgs__Vector3(stack, &(msg->translation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field translation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "rotation") == 0)
                {
                    try
                    {
                        // read field 'rotation'
                        read__geometry_msgs__Quaternion(stack, &(msg->rotation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field rotation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Transform: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Transform(const boost::shared_ptr<geometry_msgs::Transform const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Transform(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Transform: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__TransformStamped(const geometry_msgs::TransformStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'transform'
            simPushStringOntoStackE(stack, "transform", 0);
            write__geometry_msgs__Transform(msg.transform, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'transform': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'child_frame_id'
            simPushStringOntoStackE(stack, "child_frame_id", 0);
            write__string(msg.child_frame_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'child_frame_id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__TransformStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__TransformStamped(int stack, geometry_msgs::TransformStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "transform") == 0)
                {
                    try
                    {
                        // read field 'transform'
                        read__geometry_msgs__Transform(stack, &(msg->transform), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field transform: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "child_frame_id") == 0)
                {
                    try
                    {
                        // read field 'child_frame_id'
                        read__string(stack, &(msg->child_frame_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field child_frame_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__TransformStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__TransformStamped(const boost::shared_ptr<geometry_msgs::TransformStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__TransformStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__TransformStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Twist(const geometry_msgs::Twist& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'linear'
            simPushStringOntoStackE(stack, "linear", 0);
            write__geometry_msgs__Vector3(msg.linear, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'linear': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angular'
            simPushStringOntoStackE(stack, "angular", 0);
            write__geometry_msgs__Vector3(msg.angular, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angular': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Twist: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Twist(int stack, geometry_msgs::Twist *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "linear") == 0)
                {
                    try
                    {
                        // read field 'linear'
                        read__geometry_msgs__Vector3(stack, &(msg->linear), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field linear: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angular") == 0)
                {
                    try
                    {
                        // read field 'angular'
                        read__geometry_msgs__Vector3(stack, &(msg->angular), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angular: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Twist: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Twist(const boost::shared_ptr<geometry_msgs::Twist const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Twist(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Twist: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__TwistStamped(const geometry_msgs::TwistStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__Twist(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__TwistStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__TwistStamped(int stack, geometry_msgs::TwistStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__Twist(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__TwistStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__TwistStamped(const boost::shared_ptr<geometry_msgs::TwistStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__TwistStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__TwistStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__TwistWithCovariance(const geometry_msgs::TwistWithCovariance& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__Twist(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.covariance[0]), msg.covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__TwistWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__TwistWithCovariance(int stack, geometry_msgs::TwistWithCovariance *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__Twist(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "covariance") == 0)
                {
                    try
                    {
                        // read field 'covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__TwistWithCovariance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__TwistWithCovariance(const boost::shared_ptr<geometry_msgs::TwistWithCovariance const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__TwistWithCovariance(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__TwistWithCovariance: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__TwistWithCovarianceStamped(const geometry_msgs::TwistWithCovarianceStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__TwistWithCovariance(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__TwistWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__TwistWithCovarianceStamped(int stack, geometry_msgs::TwistWithCovarianceStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__TwistWithCovariance(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__TwistWithCovarianceStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__TwistWithCovarianceStamped(const boost::shared_ptr<geometry_msgs::TwistWithCovarianceStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__TwistWithCovarianceStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__TwistWithCovarianceStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Vector3(const geometry_msgs::Vector3& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float64(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float64(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'z'
            simPushStringOntoStackE(stack, "z", 0);
            write__float64(msg.z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'z': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Vector3: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Vector3(int stack, geometry_msgs::Vector3 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float64(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float64(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "z") == 0)
                {
                    try
                    {
                        // read field 'z'
                        read__float64(stack, &(msg->z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Vector3: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Vector3(const boost::shared_ptr<geometry_msgs::Vector3 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Vector3(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Vector3: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Vector3Stamped(const geometry_msgs::Vector3Stamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'vector'
            simPushStringOntoStackE(stack, "vector", 0);
            write__geometry_msgs__Vector3(msg.vector, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'vector': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Vector3Stamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Vector3Stamped(int stack, geometry_msgs::Vector3Stamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "vector") == 0)
                {
                    try
                    {
                        // read field 'vector'
                        read__geometry_msgs__Vector3(stack, &(msg->vector), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field vector: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Vector3Stamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Vector3Stamped(const boost::shared_ptr<geometry_msgs::Vector3Stamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Vector3Stamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Vector3Stamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__Wrench(const geometry_msgs::Wrench& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'torque'
            simPushStringOntoStackE(stack, "torque", 0);
            write__geometry_msgs__Vector3(msg.torque, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'torque': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'force'
            simPushStringOntoStackE(stack, "force", 0);
            write__geometry_msgs__Vector3(msg.force, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'force': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__Wrench: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__Wrench(int stack, geometry_msgs::Wrench *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "torque") == 0)
                {
                    try
                    {
                        // read field 'torque'
                        read__geometry_msgs__Vector3(stack, &(msg->torque), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field torque: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "force") == 0)
                {
                    try
                    {
                        // read field 'force'
                        read__geometry_msgs__Vector3(stack, &(msg->force), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field force: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__Wrench: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__Wrench(const boost::shared_ptr<geometry_msgs::Wrench const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__Wrench(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__Wrench: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__geometry_msgs__WrenchStamped(const geometry_msgs::WrenchStamped& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'wrench'
            simPushStringOntoStackE(stack, "wrench", 0);
            write__geometry_msgs__Wrench(msg.wrench, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'wrench': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__geometry_msgs__WrenchStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__geometry_msgs__WrenchStamped(int stack, geometry_msgs::WrenchStamped *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "wrench") == 0)
                {
                    try
                    {
                        // read field 'wrench'
                        read__geometry_msgs__Wrench(stack, &(msg->wrench), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field wrench: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__geometry_msgs__WrenchStamped: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__geometry_msgs__WrenchStamped(const boost::shared_ptr<geometry_msgs::WrenchStamped const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__geometry_msgs__WrenchStamped(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__geometry_msgs__WrenchStamped: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__map_msgs__OccupancyGridUpdate(const map_msgs::OccupancyGridUpdate& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__int32(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__int32(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int8(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__map_msgs__OccupancyGridUpdate: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__map_msgs__OccupancyGridUpdate(int stack, map_msgs::OccupancyGridUpdate *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__int32(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__int32(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int8_t v;
                            read__int8(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__map_msgs__OccupancyGridUpdate: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__map_msgs__OccupancyGridUpdate(const boost::shared_ptr<map_msgs::OccupancyGridUpdate const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__map_msgs__OccupancyGridUpdate(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__map_msgs__OccupancyGridUpdate: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__map_msgs__PointCloud2Update(const map_msgs::PointCloud2Update& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            write__sensor_msgs__PointCloud2(msg.points, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__uint32(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__map_msgs__PointCloud2Update: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__map_msgs__PointCloud2Update(int stack, map_msgs::PointCloud2Update *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        read__sensor_msgs__PointCloud2(stack, &(msg->points), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__uint32(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__map_msgs__PointCloud2Update: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__map_msgs__PointCloud2Update(const boost::shared_ptr<map_msgs::PointCloud2Update const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__map_msgs__PointCloud2Update(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__map_msgs__PointCloud2Update: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__map_msgs__ProjectedMap(const map_msgs::ProjectedMap& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'map'
            simPushStringOntoStackE(stack, "map", 0);
            write__nav_msgs__OccupancyGrid(msg.map, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'map': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'max_z'
            simPushStringOntoStackE(stack, "max_z", 0);
            write__float64(msg.max_z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'max_z': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'min_z'
            simPushStringOntoStackE(stack, "min_z", 0);
            write__float64(msg.min_z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'min_z': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__map_msgs__ProjectedMap: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__map_msgs__ProjectedMap(int stack, map_msgs::ProjectedMap *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "map") == 0)
                {
                    try
                    {
                        // read field 'map'
                        read__nav_msgs__OccupancyGrid(stack, &(msg->map), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field map: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "max_z") == 0)
                {
                    try
                    {
                        // read field 'max_z'
                        read__float64(stack, &(msg->max_z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field max_z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "min_z") == 0)
                {
                    try
                    {
                        // read field 'min_z'
                        read__float64(stack, &(msg->min_z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field min_z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__map_msgs__ProjectedMap: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__map_msgs__ProjectedMap(const boost::shared_ptr<map_msgs::ProjectedMap const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__map_msgs__ProjectedMap(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__map_msgs__ProjectedMap: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__map_msgs__ProjectedMapInfo(const map_msgs::ProjectedMapInfo& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'min_z'
            simPushStringOntoStackE(stack, "min_z", 0);
            write__float64(msg.min_z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'min_z': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__float64(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__float64(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'frame_id'
            simPushStringOntoStackE(stack, "frame_id", 0);
            write__string(msg.frame_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'frame_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'y'
            simPushStringOntoStackE(stack, "y", 0);
            write__float64(msg.y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x'
            simPushStringOntoStackE(stack, "x", 0);
            write__float64(msg.x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'max_z'
            simPushStringOntoStackE(stack, "max_z", 0);
            write__float64(msg.max_z, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'max_z': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__map_msgs__ProjectedMapInfo: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__map_msgs__ProjectedMapInfo(int stack, map_msgs::ProjectedMapInfo *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "min_z") == 0)
                {
                    try
                    {
                        // read field 'min_z'
                        read__float64(stack, &(msg->min_z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field min_z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__float64(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__float64(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "frame_id") == 0)
                {
                    try
                    {
                        // read field 'frame_id'
                        read__string(stack, &(msg->frame_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field frame_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "y") == 0)
                {
                    try
                    {
                        // read field 'y'
                        read__float64(stack, &(msg->y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x") == 0)
                {
                    try
                    {
                        // read field 'x'
                        read__float64(stack, &(msg->x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "max_z") == 0)
                {
                    try
                    {
                        // read field 'max_z'
                        read__float64(stack, &(msg->max_z), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field max_z: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__map_msgs__ProjectedMapInfo: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__map_msgs__ProjectedMapInfo(const boost::shared_ptr<map_msgs::ProjectedMapInfo const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__map_msgs__ProjectedMapInfo(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__map_msgs__ProjectedMapInfo: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__nav_msgs__GridCells(const nav_msgs::GridCells& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'cells'
            simPushStringOntoStackE(stack, "cells", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.cells.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point(msg.cells[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'cells': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'cell_width'
            simPushStringOntoStackE(stack, "cell_width", 0);
            write__float32(msg.cell_width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'cell_width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'cell_height'
            simPushStringOntoStackE(stack, "cell_height", 0);
            write__float32(msg.cell_height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'cell_height': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__nav_msgs__GridCells: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__nav_msgs__GridCells(int stack, nav_msgs::GridCells *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "cells") == 0)
                {
                    try
                    {
                        // read field 'cells'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point v;
                            read__geometry_msgs__Point(stack, &v, opt);
                            msg->cells.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field cells: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "cell_width") == 0)
                {
                    try
                    {
                        // read field 'cell_width'
                        read__float32(stack, &(msg->cell_width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field cell_width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "cell_height") == 0)
                {
                    try
                    {
                        // read field 'cell_height'
                        read__float32(stack, &(msg->cell_height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field cell_height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__nav_msgs__GridCells: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__nav_msgs__GridCells(const boost::shared_ptr<nav_msgs::GridCells const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__nav_msgs__GridCells(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__nav_msgs__GridCells: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__nav_msgs__MapMetaData(const nav_msgs::MapMetaData& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'origin'
            simPushStringOntoStackE(stack, "origin", 0);
            write__geometry_msgs__Pose(msg.origin, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'origin': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'map_load_time'
            simPushStringOntoStackE(stack, "map_load_time", 0);
            write__time(msg.map_load_time, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'map_load_time': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'resolution'
            simPushStringOntoStackE(stack, "resolution", 0);
            write__float32(msg.resolution, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'resolution': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__nav_msgs__MapMetaData: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__nav_msgs__MapMetaData(int stack, nav_msgs::MapMetaData *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "origin") == 0)
                {
                    try
                    {
                        // read field 'origin'
                        read__geometry_msgs__Pose(stack, &(msg->origin), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field origin: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "map_load_time") == 0)
                {
                    try
                    {
                        // read field 'map_load_time'
                        read__time(stack, &(msg->map_load_time), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field map_load_time: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "resolution") == 0)
                {
                    try
                    {
                        // read field 'resolution'
                        read__float32(stack, &(msg->resolution), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field resolution: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__nav_msgs__MapMetaData: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__nav_msgs__MapMetaData(const boost::shared_ptr<nav_msgs::MapMetaData const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__nav_msgs__MapMetaData(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__nav_msgs__MapMetaData: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__nav_msgs__OccupancyGrid(const nav_msgs::OccupancyGrid& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'info'
            simPushStringOntoStackE(stack, "info", 0);
            write__nav_msgs__MapMetaData(msg.info, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'info': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int8(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__nav_msgs__OccupancyGrid: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__nav_msgs__OccupancyGrid(int stack, nav_msgs::OccupancyGrid *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "info") == 0)
                {
                    try
                    {
                        // read field 'info'
                        read__nav_msgs__MapMetaData(stack, &(msg->info), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field info: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int8_t v;
                            read__int8(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__nav_msgs__OccupancyGrid: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__nav_msgs__OccupancyGrid(const boost::shared_ptr<nav_msgs::OccupancyGrid const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__nav_msgs__OccupancyGrid(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__nav_msgs__OccupancyGrid: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__nav_msgs__Odometry(const nav_msgs::Odometry& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            write__geometry_msgs__TwistWithCovariance(msg.twist, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__PoseWithCovariance(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'child_frame_id'
            simPushStringOntoStackE(stack, "child_frame_id", 0);
            write__string(msg.child_frame_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'child_frame_id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__nav_msgs__Odometry: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__nav_msgs__Odometry(int stack, nav_msgs::Odometry *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        read__geometry_msgs__TwistWithCovariance(stack, &(msg->twist), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__PoseWithCovariance(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "child_frame_id") == 0)
                {
                    try
                    {
                        // read field 'child_frame_id'
                        read__string(stack, &(msg->child_frame_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field child_frame_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__nav_msgs__Odometry: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__nav_msgs__Odometry(const boost::shared_ptr<nav_msgs::Odometry const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__nav_msgs__Odometry(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__nav_msgs__Odometry: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__nav_msgs__Path(const nav_msgs::Path& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'poses'
            simPushStringOntoStackE(stack, "poses", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.poses.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__PoseStamped(msg.poses[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'poses': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__nav_msgs__Path: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__nav_msgs__Path(int stack, nav_msgs::Path *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "poses") == 0)
                {
                    try
                    {
                        // read field 'poses'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::PoseStamped v;
                            read__geometry_msgs__PoseStamped(stack, &v, opt);
                            msg->poses.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field poses: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__nav_msgs__Path: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__nav_msgs__Path(const boost::shared_ptr<nav_msgs::Path const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__nav_msgs__Path(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__nav_msgs__Path: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__roscpp__Logger(const roscpp::Logger& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'level'
            simPushStringOntoStackE(stack, "level", 0);
            write__string(msg.level, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'level': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__Logger: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__Logger(int stack, roscpp::Logger *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "level") == 0)
                {
                    try
                    {
                        // read field 'level'
                        read__string(stack, &(msg->level), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field level: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__roscpp__Logger: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__roscpp__Logger(const boost::shared_ptr<roscpp::Logger const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__roscpp__Logger(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__roscpp__Logger: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__rosgraph_msgs__Clock(const rosgraph_msgs::Clock& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'clock'
            simPushStringOntoStackE(stack, "clock", 0);
            write__time(msg.clock, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'clock': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__rosgraph_msgs__Clock: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__rosgraph_msgs__Clock(int stack, rosgraph_msgs::Clock *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "clock") == 0)
                {
                    try
                    {
                        // read field 'clock'
                        read__time(stack, &(msg->clock), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field clock: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__rosgraph_msgs__Clock: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__rosgraph_msgs__Clock(const boost::shared_ptr<rosgraph_msgs::Clock const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__rosgraph_msgs__Clock(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__rosgraph_msgs__Clock: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__rosgraph_msgs__Log(const rosgraph_msgs::Log& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'function'
            simPushStringOntoStackE(stack, "function", 0);
            write__string(msg.function, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'function': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'level'
            simPushStringOntoStackE(stack, "level", 0);
            write__int8(msg.level, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'level': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'topics'
            simPushStringOntoStackE(stack, "topics", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.topics.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.topics[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'topics': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'file'
            simPushStringOntoStackE(stack, "file", 0);
            write__string(msg.file, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'file': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'msg'
            simPushStringOntoStackE(stack, "msg", 0);
            write__string(msg.msg, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'msg': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'line'
            simPushStringOntoStackE(stack, "line", 0);
            write__uint32(msg.line, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'line': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__rosgraph_msgs__Log: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__rosgraph_msgs__Log(int stack, rosgraph_msgs::Log *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "function") == 0)
                {
                    try
                    {
                        // read field 'function'
                        read__string(stack, &(msg->function), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field function: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "level") == 0)
                {
                    try
                    {
                        // read field 'level'
                        read__int8(stack, &(msg->level), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field level: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "topics") == 0)
                {
                    try
                    {
                        // read field 'topics'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->topics.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field topics: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "file") == 0)
                {
                    try
                    {
                        // read field 'file'
                        read__string(stack, &(msg->file), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field file: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "msg") == 0)
                {
                    try
                    {
                        // read field 'msg'
                        read__string(stack, &(msg->msg), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field msg: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "line") == 0)
                {
                    try
                    {
                        // read field 'line'
                        read__uint32(stack, &(msg->line), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field line: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__rosgraph_msgs__Log: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__rosgraph_msgs__Log(const boost::shared_ptr<rosgraph_msgs::Log const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__rosgraph_msgs__Log(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__rosgraph_msgs__Log: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__rosgraph_msgs__TopicStatistics(const rosgraph_msgs::TopicStatistics& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'node_pub'
            simPushStringOntoStackE(stack, "node_pub", 0);
            write__string(msg.node_pub, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'node_pub': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'dropped_msgs'
            simPushStringOntoStackE(stack, "dropped_msgs", 0);
            write__int32(msg.dropped_msgs, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'dropped_msgs': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'window_start'
            simPushStringOntoStackE(stack, "window_start", 0);
            write__time(msg.window_start, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'window_start': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'period_mean'
            simPushStringOntoStackE(stack, "period_mean", 0);
            write__duration(msg.period_mean, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'period_mean': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'node_sub'
            simPushStringOntoStackE(stack, "node_sub", 0);
            write__string(msg.node_sub, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'node_sub': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'topic'
            simPushStringOntoStackE(stack, "topic", 0);
            write__string(msg.topic, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'topic': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'stamp_age_mean'
            simPushStringOntoStackE(stack, "stamp_age_mean", 0);
            write__duration(msg.stamp_age_mean, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stamp_age_mean': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'period_stddev'
            simPushStringOntoStackE(stack, "period_stddev", 0);
            write__duration(msg.period_stddev, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'period_stddev': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'traffic'
            simPushStringOntoStackE(stack, "traffic", 0);
            write__int32(msg.traffic, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'traffic': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'window_stop'
            simPushStringOntoStackE(stack, "window_stop", 0);
            write__time(msg.window_stop, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'window_stop': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'stamp_age_stddev'
            simPushStringOntoStackE(stack, "stamp_age_stddev", 0);
            write__duration(msg.stamp_age_stddev, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stamp_age_stddev': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'stamp_age_max'
            simPushStringOntoStackE(stack, "stamp_age_max", 0);
            write__duration(msg.stamp_age_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stamp_age_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'period_max'
            simPushStringOntoStackE(stack, "period_max", 0);
            write__duration(msg.period_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'period_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'delivered_msgs'
            simPushStringOntoStackE(stack, "delivered_msgs", 0);
            write__int32(msg.delivered_msgs, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'delivered_msgs': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__rosgraph_msgs__TopicStatistics: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__rosgraph_msgs__TopicStatistics(int stack, rosgraph_msgs::TopicStatistics *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "node_pub") == 0)
                {
                    try
                    {
                        // read field 'node_pub'
                        read__string(stack, &(msg->node_pub), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field node_pub: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "dropped_msgs") == 0)
                {
                    try
                    {
                        // read field 'dropped_msgs'
                        read__int32(stack, &(msg->dropped_msgs), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field dropped_msgs: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "window_start") == 0)
                {
                    try
                    {
                        // read field 'window_start'
                        read__time(stack, &(msg->window_start), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field window_start: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "period_mean") == 0)
                {
                    try
                    {
                        // read field 'period_mean'
                        read__duration(stack, &(msg->period_mean), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field period_mean: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "node_sub") == 0)
                {
                    try
                    {
                        // read field 'node_sub'
                        read__string(stack, &(msg->node_sub), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field node_sub: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "topic") == 0)
                {
                    try
                    {
                        // read field 'topic'
                        read__string(stack, &(msg->topic), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field topic: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "stamp_age_mean") == 0)
                {
                    try
                    {
                        // read field 'stamp_age_mean'
                        read__duration(stack, &(msg->stamp_age_mean), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stamp_age_mean: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "period_stddev") == 0)
                {
                    try
                    {
                        // read field 'period_stddev'
                        read__duration(stack, &(msg->period_stddev), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field period_stddev: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "traffic") == 0)
                {
                    try
                    {
                        // read field 'traffic'
                        read__int32(stack, &(msg->traffic), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field traffic: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "window_stop") == 0)
                {
                    try
                    {
                        // read field 'window_stop'
                        read__time(stack, &(msg->window_stop), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field window_stop: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "stamp_age_stddev") == 0)
                {
                    try
                    {
                        // read field 'stamp_age_stddev'
                        read__duration(stack, &(msg->stamp_age_stddev), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stamp_age_stddev: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "stamp_age_max") == 0)
                {
                    try
                    {
                        // read field 'stamp_age_max'
                        read__duration(stack, &(msg->stamp_age_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stamp_age_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "period_max") == 0)
                {
                    try
                    {
                        // read field 'period_max'
                        read__duration(stack, &(msg->period_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field period_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "delivered_msgs") == 0)
                {
                    try
                    {
                        // read field 'delivered_msgs'
                        read__int32(stack, &(msg->delivered_msgs), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field delivered_msgs: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__rosgraph_msgs__TopicStatistics: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__rosgraph_msgs__TopicStatistics(const boost::shared_ptr<rosgraph_msgs::TopicStatistics const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__rosgraph_msgs__TopicStatistics(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__rosgraph_msgs__TopicStatistics: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__CameraInfo(const sensor_msgs::CameraInfo& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'roi'
            simPushStringOntoStackE(stack, "roi", 0);
            write__sensor_msgs__RegionOfInterest(msg.roi, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'roi': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'D' (using fast specialized function)
            simPushStringOntoStackE(stack, "D", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.D[0]), msg.D.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'D': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'P' (using fast specialized function)
            simPushStringOntoStackE(stack, "P", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.P[0]), msg.P.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'P': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'K' (using fast specialized function)
            simPushStringOntoStackE(stack, "K", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.K[0]), msg.K.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'K': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'R' (using fast specialized function)
            simPushStringOntoStackE(stack, "R", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.R[0]), msg.R.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'R': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'binning_y'
            simPushStringOntoStackE(stack, "binning_y", 0);
            write__uint32(msg.binning_y, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'binning_y': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'binning_x'
            simPushStringOntoStackE(stack, "binning_x", 0);
            write__uint32(msg.binning_x, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'binning_x': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'distortion_model'
            simPushStringOntoStackE(stack, "distortion_model", 0);
            write__string(msg.distortion_model, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'distortion_model': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__CameraInfo: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__CameraInfo(int stack, sensor_msgs::CameraInfo *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "roi") == 0)
                {
                    try
                    {
                        // read field 'roi'
                        read__sensor_msgs__RegionOfInterest(stack, &(msg->roi), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field roi: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "D") == 0)
                {
                    try
                    {
                        // read field 'D' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->D.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->D[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field D: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "P") == 0)
                {
                    try
                    {
                        // read field 'P' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->P[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field P: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "K") == 0)
                {
                    try
                    {
                        // read field 'K' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->K[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field K: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "R") == 0)
                {
                    try
                    {
                        // read field 'R' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->R[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field R: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "binning_y") == 0)
                {
                    try
                    {
                        // read field 'binning_y'
                        read__uint32(stack, &(msg->binning_y), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field binning_y: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "binning_x") == 0)
                {
                    try
                    {
                        // read field 'binning_x'
                        read__uint32(stack, &(msg->binning_x), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field binning_x: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "distortion_model") == 0)
                {
                    try
                    {
                        // read field 'distortion_model'
                        read__string(stack, &(msg->distortion_model), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field distortion_model: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__CameraInfo: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__CameraInfo(const boost::shared_ptr<sensor_msgs::CameraInfo const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__CameraInfo(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__CameraInfo: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__ChannelFloat32(const sensor_msgs::ChannelFloat32& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'values' (using fast specialized function)
            simPushStringOntoStackE(stack, "values", 0);
            simPushFloatTableOntoStackE(stack, &(msg.values[0]), msg.values.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'values': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__ChannelFloat32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__ChannelFloat32(int stack, sensor_msgs::ChannelFloat32 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "values") == 0)
                {
                    try
                    {
                        // read field 'values' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->values.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->values[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field values: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__ChannelFloat32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__ChannelFloat32(const boost::shared_ptr<sensor_msgs::ChannelFloat32 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__ChannelFloat32(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__ChannelFloat32: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__CompressedImage(const sensor_msgs::CompressedImage& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            if(opt && opt->uint8array_as_string)
                simPushStringOntoStackE(stack, (simChar*)&(msg.data[0]), msg.data.size());
            else
                simPushUInt8TableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'format'
            simPushStringOntoStackE(stack, "format", 0);
            write__string(msg.format, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'format': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__CompressedImage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__CompressedImage(int stack, sensor_msgs::CompressedImage *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        if(opt && opt->uint8array_as_string)
                        {
                            // read field 'data' (uint8[]) as string
                            simChar *str;
                            simInt sz;
                            if((str = simGetStackStringValueE(stack, &sz)) != NULL && sz > 0)
                            {
                                /*
                                 * XXX: if an alternative version of simGetStackStringValue woudl exist
                                 * working on an externally allocated buffer, we won't need this memcpy:
                                 */
                                msg->data.resize(sz);
                                std::memcpy(&(msg->data[0]), str, sz);
                                simReleaseBufferE(str);
                            }
                            else throw exception("string read error when trying to read uint8[]");
                        }
                        else
			{
                            // read field 'data' (using fast specialized function)
                            int sz = simGetStackTableInfoE(stack, 0);
                            if(sz < 0)
                                throw exception("expected uint8 array");
                            if(simGetStackTableInfoE(stack, 2) != 1)
                                throw exception("fast_write_type uint8[] reader exception #1");
                            msg->data.resize(sz);
                            simGetStackUInt8TableE(stack, &(msg->data[0]), sz);
                            simPopStackItemE(stack, 1);
			}
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "format") == 0)
                {
                    try
                    {
                        // read field 'format'
                        read__string(stack, &(msg->format), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field format: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__CompressedImage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__CompressedImage(const boost::shared_ptr<sensor_msgs::CompressedImage const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__CompressedImage(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__CompressedImage: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__FluidPressure(const sensor_msgs::FluidPressure& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'fluid_pressure'
            simPushStringOntoStackE(stack, "fluid_pressure", 0);
            write__float64(msg.fluid_pressure, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'fluid_pressure': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'variance'
            simPushStringOntoStackE(stack, "variance", 0);
            write__float64(msg.variance, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'variance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__FluidPressure: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__FluidPressure(int stack, sensor_msgs::FluidPressure *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "fluid_pressure") == 0)
                {
                    try
                    {
                        // read field 'fluid_pressure'
                        read__float64(stack, &(msg->fluid_pressure), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field fluid_pressure: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "variance") == 0)
                {
                    try
                    {
                        // read field 'variance'
                        read__float64(stack, &(msg->variance), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field variance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__FluidPressure: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__FluidPressure(const boost::shared_ptr<sensor_msgs::FluidPressure const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__FluidPressure(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__FluidPressure: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Illuminance(const sensor_msgs::Illuminance& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'illuminance'
            simPushStringOntoStackE(stack, "illuminance", 0);
            write__float64(msg.illuminance, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'illuminance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'variance'
            simPushStringOntoStackE(stack, "variance", 0);
            write__float64(msg.variance, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'variance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Illuminance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Illuminance(int stack, sensor_msgs::Illuminance *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "illuminance") == 0)
                {
                    try
                    {
                        // read field 'illuminance'
                        read__float64(stack, &(msg->illuminance), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field illuminance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "variance") == 0)
                {
                    try
                    {
                        // read field 'variance'
                        read__float64(stack, &(msg->variance), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field variance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Illuminance: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Illuminance(const boost::shared_ptr<sensor_msgs::Illuminance const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Illuminance(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Illuminance: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Image(const sensor_msgs::Image& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'encoding'
            simPushStringOntoStackE(stack, "encoding", 0);
            write__string(msg.encoding, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'encoding': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'step'
            simPushStringOntoStackE(stack, "step", 0);
            write__uint32(msg.step, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'step': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            if(opt && opt->uint8array_as_string)
                simPushStringOntoStackE(stack, (simChar*)&(msg.data[0]), msg.data.size());
            else
                simPushUInt8TableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'is_bigendian'
            simPushStringOntoStackE(stack, "is_bigendian", 0);
            write__uint8(msg.is_bigendian, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'is_bigendian': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Image: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Image(int stack, sensor_msgs::Image *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "encoding") == 0)
                {
                    try
                    {
                        // read field 'encoding'
                        read__string(stack, &(msg->encoding), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field encoding: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "step") == 0)
                {
                    try
                    {
                        // read field 'step'
                        read__uint32(stack, &(msg->step), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field step: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        if(opt && opt->uint8array_as_string)
                        {
                            // read field 'data' (uint8[]) as string
                            simChar *str;
                            simInt sz;
                            if((str = simGetStackStringValueE(stack, &sz)) != NULL && sz > 0)
                            {
                                /*
                                 * XXX: if an alternative version of simGetStackStringValue woudl exist
                                 * working on an externally allocated buffer, we won't need this memcpy:
                                 */
                                msg->data.resize(sz);
                                std::memcpy(&(msg->data[0]), str, sz);
                                simReleaseBufferE(str);
                            }
                            else throw exception("string read error when trying to read uint8[]");
                        }
                        else
			{
                            // read field 'data' (using fast specialized function)
                            int sz = simGetStackTableInfoE(stack, 0);
                            if(sz < 0)
                                throw exception("expected uint8 array");
                            if(simGetStackTableInfoE(stack, 2) != 1)
                                throw exception("fast_write_type uint8[] reader exception #1");
                            msg->data.resize(sz);
                            simGetStackUInt8TableE(stack, &(msg->data[0]), sz);
                            simPopStackItemE(stack, 1);
			}
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "is_bigendian") == 0)
                {
                    try
                    {
                        // read field 'is_bigendian'
                        read__uint8(stack, &(msg->is_bigendian), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field is_bigendian: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Image: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Image(const boost::shared_ptr<sensor_msgs::Image const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Image(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Image: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Imu(const sensor_msgs::Imu& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'linear_acceleration_covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "linear_acceleration_covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.linear_acceleration_covariance[0]), msg.linear_acceleration_covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'linear_acceleration_covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'orientation'
            simPushStringOntoStackE(stack, "orientation", 0);
            write__geometry_msgs__Quaternion(msg.orientation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'orientation': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angular_velocity_covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "angular_velocity_covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.angular_velocity_covariance[0]), msg.angular_velocity_covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angular_velocity_covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'orientation_covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "orientation_covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.orientation_covariance[0]), msg.orientation_covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'orientation_covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'linear_acceleration'
            simPushStringOntoStackE(stack, "linear_acceleration", 0);
            write__geometry_msgs__Vector3(msg.linear_acceleration, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'linear_acceleration': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angular_velocity'
            simPushStringOntoStackE(stack, "angular_velocity", 0);
            write__geometry_msgs__Vector3(msg.angular_velocity, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angular_velocity': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Imu: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Imu(int stack, sensor_msgs::Imu *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "linear_acceleration_covariance") == 0)
                {
                    try
                    {
                        // read field 'linear_acceleration_covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->linear_acceleration_covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field linear_acceleration_covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "orientation") == 0)
                {
                    try
                    {
                        // read field 'orientation'
                        read__geometry_msgs__Quaternion(stack, &(msg->orientation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field orientation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angular_velocity_covariance") == 0)
                {
                    try
                    {
                        // read field 'angular_velocity_covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->angular_velocity_covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angular_velocity_covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "orientation_covariance") == 0)
                {
                    try
                    {
                        // read field 'orientation_covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->orientation_covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field orientation_covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "linear_acceleration") == 0)
                {
                    try
                    {
                        // read field 'linear_acceleration'
                        read__geometry_msgs__Vector3(stack, &(msg->linear_acceleration), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field linear_acceleration: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angular_velocity") == 0)
                {
                    try
                    {
                        // read field 'angular_velocity'
                        read__geometry_msgs__Vector3(stack, &(msg->angular_velocity), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angular_velocity: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Imu: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Imu(const boost::shared_ptr<sensor_msgs::Imu const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Imu(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Imu: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__JointState(const sensor_msgs::JointState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'velocity' (using fast specialized function)
            simPushStringOntoStackE(stack, "velocity", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.velocity[0]), msg.velocity.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'velocity': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'effort' (using fast specialized function)
            simPushStringOntoStackE(stack, "effort", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.effort[0]), msg.effort.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'effort': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.name.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.name[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'position' (using fast specialized function)
            simPushStringOntoStackE(stack, "position", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.position[0]), msg.position.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__JointState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__JointState(int stack, sensor_msgs::JointState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "velocity") == 0)
                {
                    try
                    {
                        // read field 'velocity' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->velocity.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->velocity[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field velocity: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "effort") == 0)
                {
                    try
                    {
                        // read field 'effort' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->effort.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->effort[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field effort: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->name.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "position") == 0)
                {
                    try
                    {
                        // read field 'position' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->position.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->position[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__JointState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__JointState(const boost::shared_ptr<sensor_msgs::JointState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__JointState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__JointState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Joy(const sensor_msgs::Joy& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'buttons' (using fast specialized function)
            simPushStringOntoStackE(stack, "buttons", 0);
            simPushInt32TableOntoStackE(stack, &(msg.buttons[0]), msg.buttons.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'buttons': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'axes' (using fast specialized function)
            simPushStringOntoStackE(stack, "axes", 0);
            simPushFloatTableOntoStackE(stack, &(msg.axes[0]), msg.axes.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'axes': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Joy: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Joy(int stack, sensor_msgs::Joy *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "buttons") == 0)
                {
                    try
                    {
                        // read field 'buttons' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->buttons.resize(sz);
                        simGetStackInt32TableE(stack, &(msg->buttons[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field buttons: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "axes") == 0)
                {
                    try
                    {
                        // read field 'axes' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->axes.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->axes[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field axes: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Joy: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Joy(const boost::shared_ptr<sensor_msgs::Joy const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Joy(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Joy: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__JoyFeedback(const sensor_msgs::JoyFeedback& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'intensity'
            simPushStringOntoStackE(stack, "intensity", 0);
            write__float32(msg.intensity, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'intensity': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__uint8(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__uint8(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__JoyFeedback: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__JoyFeedback(int stack, sensor_msgs::JoyFeedback *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "intensity") == 0)
                {
                    try
                    {
                        // read field 'intensity'
                        read__float32(stack, &(msg->intensity), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field intensity: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__uint8(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__uint8(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__JoyFeedback: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__JoyFeedback(const boost::shared_ptr<sensor_msgs::JoyFeedback const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__JoyFeedback(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__JoyFeedback: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__JoyFeedbackArray(const sensor_msgs::JoyFeedbackArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'array'
            simPushStringOntoStackE(stack, "array", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.array.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__sensor_msgs__JoyFeedback(msg.array[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'array': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__JoyFeedbackArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__JoyFeedbackArray(int stack, sensor_msgs::JoyFeedbackArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "array") == 0)
                {
                    try
                    {
                        // read field 'array'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            sensor_msgs::JoyFeedback v;
                            read__sensor_msgs__JoyFeedback(stack, &v, opt);
                            msg->array.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field array: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__JoyFeedbackArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__JoyFeedbackArray(const boost::shared_ptr<sensor_msgs::JoyFeedbackArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__JoyFeedbackArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__JoyFeedbackArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__LaserEcho(const sensor_msgs::LaserEcho& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'echoes' (using fast specialized function)
            simPushStringOntoStackE(stack, "echoes", 0);
            simPushFloatTableOntoStackE(stack, &(msg.echoes[0]), msg.echoes.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'echoes': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__LaserEcho: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__LaserEcho(int stack, sensor_msgs::LaserEcho *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "echoes") == 0)
                {
                    try
                    {
                        // read field 'echoes' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->echoes.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->echoes[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field echoes: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__LaserEcho: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__LaserEcho(const boost::shared_ptr<sensor_msgs::LaserEcho const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__LaserEcho(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__LaserEcho: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__LaserScan(const sensor_msgs::LaserScan& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'angle_min'
            simPushStringOntoStackE(stack, "angle_min", 0);
            write__float32(msg.angle_min, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_min': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'range_min'
            simPushStringOntoStackE(stack, "range_min", 0);
            write__float32(msg.range_min, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'range_min': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'scan_time'
            simPushStringOntoStackE(stack, "scan_time", 0);
            write__float32(msg.scan_time, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'scan_time': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'range_max'
            simPushStringOntoStackE(stack, "range_max", 0);
            write__float32(msg.range_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'range_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angle_increment'
            simPushStringOntoStackE(stack, "angle_increment", 0);
            write__float32(msg.angle_increment, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_increment': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angle_max'
            simPushStringOntoStackE(stack, "angle_max", 0);
            write__float32(msg.angle_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ranges' (using fast specialized function)
            simPushStringOntoStackE(stack, "ranges", 0);
            simPushFloatTableOntoStackE(stack, &(msg.ranges[0]), msg.ranges.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ranges': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'intensities' (using fast specialized function)
            simPushStringOntoStackE(stack, "intensities", 0);
            simPushFloatTableOntoStackE(stack, &(msg.intensities[0]), msg.intensities.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'intensities': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_increment'
            simPushStringOntoStackE(stack, "time_increment", 0);
            write__float32(msg.time_increment, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_increment': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__LaserScan: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__LaserScan(int stack, sensor_msgs::LaserScan *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "angle_min") == 0)
                {
                    try
                    {
                        // read field 'angle_min'
                        read__float32(stack, &(msg->angle_min), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_min: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "range_min") == 0)
                {
                    try
                    {
                        // read field 'range_min'
                        read__float32(stack, &(msg->range_min), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field range_min: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "scan_time") == 0)
                {
                    try
                    {
                        // read field 'scan_time'
                        read__float32(stack, &(msg->scan_time), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field scan_time: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "range_max") == 0)
                {
                    try
                    {
                        // read field 'range_max'
                        read__float32(stack, &(msg->range_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field range_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angle_increment") == 0)
                {
                    try
                    {
                        // read field 'angle_increment'
                        read__float32(stack, &(msg->angle_increment), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_increment: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angle_max") == 0)
                {
                    try
                    {
                        // read field 'angle_max'
                        read__float32(stack, &(msg->angle_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ranges") == 0)
                {
                    try
                    {
                        // read field 'ranges' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->ranges.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->ranges[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ranges: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "intensities") == 0)
                {
                    try
                    {
                        // read field 'intensities' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->intensities.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->intensities[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field intensities: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_increment") == 0)
                {
                    try
                    {
                        // read field 'time_increment'
                        read__float32(stack, &(msg->time_increment), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_increment: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__LaserScan: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__LaserScan(const boost::shared_ptr<sensor_msgs::LaserScan const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__LaserScan(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__LaserScan: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__MagneticField(const sensor_msgs::MagneticField& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'magnetic_field_covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "magnetic_field_covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.magnetic_field_covariance[0]), msg.magnetic_field_covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'magnetic_field_covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'magnetic_field'
            simPushStringOntoStackE(stack, "magnetic_field", 0);
            write__geometry_msgs__Vector3(msg.magnetic_field, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'magnetic_field': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__MagneticField: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__MagneticField(int stack, sensor_msgs::MagneticField *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "magnetic_field_covariance") == 0)
                {
                    try
                    {
                        // read field 'magnetic_field_covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->magnetic_field_covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field magnetic_field_covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "magnetic_field") == 0)
                {
                    try
                    {
                        // read field 'magnetic_field'
                        read__geometry_msgs__Vector3(stack, &(msg->magnetic_field), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field magnetic_field: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__MagneticField: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__MagneticField(const boost::shared_ptr<sensor_msgs::MagneticField const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__MagneticField(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__MagneticField: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__MultiDOFJointState(const sensor_msgs::MultiDOFJointState& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'twist'
            simPushStringOntoStackE(stack, "twist", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.twist.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.twist[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'twist': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'joint_names'
            simPushStringOntoStackE(stack, "joint_names", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.joint_names.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.joint_names[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'joint_names': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'transforms'
            simPushStringOntoStackE(stack, "transforms", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.transforms.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Transform(msg.transforms[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'transforms': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'wrench'
            simPushStringOntoStackE(stack, "wrench", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.wrench.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Wrench(msg.wrench[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'wrench': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__MultiDOFJointState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__MultiDOFJointState(int stack, sensor_msgs::MultiDOFJointState *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "twist") == 0)
                {
                    try
                    {
                        // read field 'twist'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->twist.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field twist: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "joint_names") == 0)
                {
                    try
                    {
                        // read field 'joint_names'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->joint_names.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field joint_names: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "transforms") == 0)
                {
                    try
                    {
                        // read field 'transforms'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Transform v;
                            read__geometry_msgs__Transform(stack, &v, opt);
                            msg->transforms.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field transforms: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "wrench") == 0)
                {
                    try
                    {
                        // read field 'wrench'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Wrench v;
                            read__geometry_msgs__Wrench(stack, &v, opt);
                            msg->wrench.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field wrench: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__MultiDOFJointState: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__MultiDOFJointState(const boost::shared_ptr<sensor_msgs::MultiDOFJointState const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__MultiDOFJointState(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__MultiDOFJointState: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__MultiEchoLaserScan(const sensor_msgs::MultiEchoLaserScan& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'angle_min'
            simPushStringOntoStackE(stack, "angle_min", 0);
            write__float32(msg.angle_min, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_min': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'range_min'
            simPushStringOntoStackE(stack, "range_min", 0);
            write__float32(msg.range_min, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'range_min': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'scan_time'
            simPushStringOntoStackE(stack, "scan_time", 0);
            write__float32(msg.scan_time, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'scan_time': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'range_max'
            simPushStringOntoStackE(stack, "range_max", 0);
            write__float32(msg.range_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'range_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angle_increment'
            simPushStringOntoStackE(stack, "angle_increment", 0);
            write__float32(msg.angle_increment, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_increment': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'angle_max'
            simPushStringOntoStackE(stack, "angle_max", 0);
            write__float32(msg.angle_max, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'angle_max': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ranges'
            simPushStringOntoStackE(stack, "ranges", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.ranges.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__sensor_msgs__LaserEcho(msg.ranges[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ranges': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'intensities'
            simPushStringOntoStackE(stack, "intensities", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.intensities.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__sensor_msgs__LaserEcho(msg.intensities[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'intensities': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_increment'
            simPushStringOntoStackE(stack, "time_increment", 0);
            write__float32(msg.time_increment, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_increment': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__MultiEchoLaserScan: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__MultiEchoLaserScan(int stack, sensor_msgs::MultiEchoLaserScan *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "angle_min") == 0)
                {
                    try
                    {
                        // read field 'angle_min'
                        read__float32(stack, &(msg->angle_min), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_min: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "range_min") == 0)
                {
                    try
                    {
                        // read field 'range_min'
                        read__float32(stack, &(msg->range_min), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field range_min: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "scan_time") == 0)
                {
                    try
                    {
                        // read field 'scan_time'
                        read__float32(stack, &(msg->scan_time), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field scan_time: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "range_max") == 0)
                {
                    try
                    {
                        // read field 'range_max'
                        read__float32(stack, &(msg->range_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field range_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angle_increment") == 0)
                {
                    try
                    {
                        // read field 'angle_increment'
                        read__float32(stack, &(msg->angle_increment), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_increment: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "angle_max") == 0)
                {
                    try
                    {
                        // read field 'angle_max'
                        read__float32(stack, &(msg->angle_max), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field angle_max: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ranges") == 0)
                {
                    try
                    {
                        // read field 'ranges'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            sensor_msgs::LaserEcho v;
                            read__sensor_msgs__LaserEcho(stack, &v, opt);
                            msg->ranges.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ranges: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "intensities") == 0)
                {
                    try
                    {
                        // read field 'intensities'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            sensor_msgs::LaserEcho v;
                            read__sensor_msgs__LaserEcho(stack, &v, opt);
                            msg->intensities.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field intensities: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_increment") == 0)
                {
                    try
                    {
                        // read field 'time_increment'
                        read__float32(stack, &(msg->time_increment), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_increment: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__MultiEchoLaserScan: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__MultiEchoLaserScan(const boost::shared_ptr<sensor_msgs::MultiEchoLaserScan const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__MultiEchoLaserScan(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__MultiEchoLaserScan: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__NavSatFix(const sensor_msgs::NavSatFix& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'status'
            simPushStringOntoStackE(stack, "status", 0);
            write__sensor_msgs__NavSatStatus(msg.status, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'status': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'altitude'
            simPushStringOntoStackE(stack, "altitude", 0);
            write__float64(msg.altitude, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'altitude': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'longitude'
            simPushStringOntoStackE(stack, "longitude", 0);
            write__float64(msg.longitude, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'longitude': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'position_covariance' (using fast specialized function)
            simPushStringOntoStackE(stack, "position_covariance", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.position_covariance[0]), msg.position_covariance.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position_covariance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'latitude'
            simPushStringOntoStackE(stack, "latitude", 0);
            write__float64(msg.latitude, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'latitude': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'position_covariance_type'
            simPushStringOntoStackE(stack, "position_covariance_type", 0);
            write__uint8(msg.position_covariance_type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position_covariance_type': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__NavSatFix: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__NavSatFix(int stack, sensor_msgs::NavSatFix *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "status") == 0)
                {
                    try
                    {
                        // read field 'status'
                        read__sensor_msgs__NavSatStatus(stack, &(msg->status), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field status: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "altitude") == 0)
                {
                    try
                    {
                        // read field 'altitude'
                        read__float64(stack, &(msg->altitude), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field altitude: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "longitude") == 0)
                {
                    try
                    {
                        // read field 'longitude'
                        read__float64(stack, &(msg->longitude), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field longitude: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "position_covariance") == 0)
                {
                    try
                    {
                        // read field 'position_covariance' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->position_covariance[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position_covariance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "latitude") == 0)
                {
                    try
                    {
                        // read field 'latitude'
                        read__float64(stack, &(msg->latitude), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field latitude: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "position_covariance_type") == 0)
                {
                    try
                    {
                        // read field 'position_covariance_type'
                        read__uint8(stack, &(msg->position_covariance_type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position_covariance_type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__NavSatFix: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__NavSatFix(const boost::shared_ptr<sensor_msgs::NavSatFix const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__NavSatFix(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__NavSatFix: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__NavSatStatus(const sensor_msgs::NavSatStatus& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'status'
            simPushStringOntoStackE(stack, "status", 0);
            write__int8(msg.status, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'status': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'service'
            simPushStringOntoStackE(stack, "service", 0);
            write__uint16(msg.service, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'service': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__NavSatStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__NavSatStatus(int stack, sensor_msgs::NavSatStatus *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "status") == 0)
                {
                    try
                    {
                        // read field 'status'
                        read__int8(stack, &(msg->status), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field status: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "service") == 0)
                {
                    try
                    {
                        // read field 'service'
                        read__uint16(stack, &(msg->service), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field service: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__NavSatStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__NavSatStatus(const boost::shared_ptr<sensor_msgs::NavSatStatus const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__NavSatStatus(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__NavSatStatus: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__PointCloud(const sensor_msgs::PointCloud& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'channels'
            simPushStringOntoStackE(stack, "channels", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.channels.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__sensor_msgs__ChannelFloat32(msg.channels[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'channels': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point32(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__PointCloud: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__PointCloud(int stack, sensor_msgs::PointCloud *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "channels") == 0)
                {
                    try
                    {
                        // read field 'channels'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            sensor_msgs::ChannelFloat32 v;
                            read__sensor_msgs__ChannelFloat32(stack, &v, opt);
                            msg->channels.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field channels: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point32 v;
                            read__geometry_msgs__Point32(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__PointCloud: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__PointCloud(const boost::shared_ptr<sensor_msgs::PointCloud const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__PointCloud(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__PointCloud: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__PointCloud2(const sensor_msgs::PointCloud2& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'is_dense'
            simPushStringOntoStackE(stack, "is_dense", 0);
            write__bool(msg.is_dense, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'is_dense': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'point_step'
            simPushStringOntoStackE(stack, "point_step", 0);
            write__uint32(msg.point_step, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'point_step': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            if(opt && opt->uint8array_as_string)
                simPushStringOntoStackE(stack, (simChar*)&(msg.data[0]), msg.data.size());
            else
                simPushUInt8TableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'fields'
            simPushStringOntoStackE(stack, "fields", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.fields.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__sensor_msgs__PointField(msg.fields[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'fields': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'row_step'
            simPushStringOntoStackE(stack, "row_step", 0);
            write__uint32(msg.row_step, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'row_step': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'is_bigendian'
            simPushStringOntoStackE(stack, "is_bigendian", 0);
            write__bool(msg.is_bigendian, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'is_bigendian': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__PointCloud2: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__PointCloud2(int stack, sensor_msgs::PointCloud2 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "is_dense") == 0)
                {
                    try
                    {
                        // read field 'is_dense'
                        read__bool(stack, &(msg->is_dense), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field is_dense: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "point_step") == 0)
                {
                    try
                    {
                        // read field 'point_step'
                        read__uint32(stack, &(msg->point_step), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field point_step: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        if(opt && opt->uint8array_as_string)
                        {
                            // read field 'data' (uint8[]) as string
                            simChar *str;
                            simInt sz;
                            if((str = simGetStackStringValueE(stack, &sz)) != NULL && sz > 0)
                            {
                                /*
                                 * XXX: if an alternative version of simGetStackStringValue woudl exist
                                 * working on an externally allocated buffer, we won't need this memcpy:
                                 */
                                msg->data.resize(sz);
                                std::memcpy(&(msg->data[0]), str, sz);
                                simReleaseBufferE(str);
                            }
                            else throw exception("string read error when trying to read uint8[]");
                        }
                        else
			{
                            // read field 'data' (using fast specialized function)
                            int sz = simGetStackTableInfoE(stack, 0);
                            if(sz < 0)
                                throw exception("expected uint8 array");
                            if(simGetStackTableInfoE(stack, 2) != 1)
                                throw exception("fast_write_type uint8[] reader exception #1");
                            msg->data.resize(sz);
                            simGetStackUInt8TableE(stack, &(msg->data[0]), sz);
                            simPopStackItemE(stack, 1);
			}
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "fields") == 0)
                {
                    try
                    {
                        // read field 'fields'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            sensor_msgs::PointField v;
                            read__sensor_msgs__PointField(stack, &v, opt);
                            msg->fields.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field fields: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "row_step") == 0)
                {
                    try
                    {
                        // read field 'row_step'
                        read__uint32(stack, &(msg->row_step), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field row_step: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "is_bigendian") == 0)
                {
                    try
                    {
                        // read field 'is_bigendian'
                        read__bool(stack, &(msg->is_bigendian), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field is_bigendian: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__PointCloud2: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__PointCloud2(const boost::shared_ptr<sensor_msgs::PointCloud2 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__PointCloud2(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__PointCloud2: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__PointField(const sensor_msgs::PointField& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'datatype'
            simPushStringOntoStackE(stack, "datatype", 0);
            write__uint8(msg.datatype, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'datatype': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'count'
            simPushStringOntoStackE(stack, "count", 0);
            write__uint32(msg.count, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'count': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'offset'
            simPushStringOntoStackE(stack, "offset", 0);
            write__uint32(msg.offset, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'offset': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__PointField: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__PointField(int stack, sensor_msgs::PointField *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "datatype") == 0)
                {
                    try
                    {
                        // read field 'datatype'
                        read__uint8(stack, &(msg->datatype), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field datatype: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "count") == 0)
                {
                    try
                    {
                        // read field 'count'
                        read__uint32(stack, &(msg->count), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field count: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "offset") == 0)
                {
                    try
                    {
                        // read field 'offset'
                        read__uint32(stack, &(msg->offset), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field offset: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__PointField: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__PointField(const boost::shared_ptr<sensor_msgs::PointField const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__PointField(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__PointField: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Range(const sensor_msgs::Range& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'max_range'
            simPushStringOntoStackE(stack, "max_range", 0);
            write__float32(msg.max_range, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'max_range': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'radiation_type'
            simPushStringOntoStackE(stack, "radiation_type", 0);
            write__uint8(msg.radiation_type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'radiation_type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'field_of_view'
            simPushStringOntoStackE(stack, "field_of_view", 0);
            write__float32(msg.field_of_view, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'field_of_view': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'min_range'
            simPushStringOntoStackE(stack, "min_range", 0);
            write__float32(msg.min_range, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'min_range': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'range'
            simPushStringOntoStackE(stack, "range", 0);
            write__float32(msg.range, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'range': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Range: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Range(int stack, sensor_msgs::Range *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "max_range") == 0)
                {
                    try
                    {
                        // read field 'max_range'
                        read__float32(stack, &(msg->max_range), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field max_range: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "radiation_type") == 0)
                {
                    try
                    {
                        // read field 'radiation_type'
                        read__uint8(stack, &(msg->radiation_type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field radiation_type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "field_of_view") == 0)
                {
                    try
                    {
                        // read field 'field_of_view'
                        read__float32(stack, &(msg->field_of_view), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field field_of_view: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "min_range") == 0)
                {
                    try
                    {
                        // read field 'min_range'
                        read__float32(stack, &(msg->min_range), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field min_range: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "range") == 0)
                {
                    try
                    {
                        // read field 'range'
                        read__float32(stack, &(msg->range), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field range: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Range: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Range(const boost::shared_ptr<sensor_msgs::Range const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Range(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Range: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__RegionOfInterest(const sensor_msgs::RegionOfInterest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'width'
            simPushStringOntoStackE(stack, "width", 0);
            write__uint32(msg.width, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'width': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'do_rectify'
            simPushStringOntoStackE(stack, "do_rectify", 0);
            write__bool(msg.do_rectify, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'do_rectify': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'y_offset'
            simPushStringOntoStackE(stack, "y_offset", 0);
            write__uint32(msg.y_offset, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'y_offset': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'x_offset'
            simPushStringOntoStackE(stack, "x_offset", 0);
            write__uint32(msg.x_offset, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'x_offset': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'height'
            simPushStringOntoStackE(stack, "height", 0);
            write__uint32(msg.height, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'height': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__RegionOfInterest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__RegionOfInterest(int stack, sensor_msgs::RegionOfInterest *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "width") == 0)
                {
                    try
                    {
                        // read field 'width'
                        read__uint32(stack, &(msg->width), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field width: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "do_rectify") == 0)
                {
                    try
                    {
                        // read field 'do_rectify'
                        read__bool(stack, &(msg->do_rectify), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field do_rectify: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "y_offset") == 0)
                {
                    try
                    {
                        // read field 'y_offset'
                        read__uint32(stack, &(msg->y_offset), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field y_offset: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "x_offset") == 0)
                {
                    try
                    {
                        // read field 'x_offset'
                        read__uint32(stack, &(msg->x_offset), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field x_offset: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "height") == 0)
                {
                    try
                    {
                        // read field 'height'
                        read__uint32(stack, &(msg->height), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field height: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__RegionOfInterest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__RegionOfInterest(const boost::shared_ptr<sensor_msgs::RegionOfInterest const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__RegionOfInterest(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__RegionOfInterest: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__RelativeHumidity(const sensor_msgs::RelativeHumidity& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'variance'
            simPushStringOntoStackE(stack, "variance", 0);
            write__float64(msg.variance, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'variance': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'relative_humidity'
            simPushStringOntoStackE(stack, "relative_humidity", 0);
            write__float64(msg.relative_humidity, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'relative_humidity': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__RelativeHumidity: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__RelativeHumidity(int stack, sensor_msgs::RelativeHumidity *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "variance") == 0)
                {
                    try
                    {
                        // read field 'variance'
                        read__float64(stack, &(msg->variance), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field variance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "relative_humidity") == 0)
                {
                    try
                    {
                        // read field 'relative_humidity'
                        read__float64(stack, &(msg->relative_humidity), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field relative_humidity: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__RelativeHumidity: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__RelativeHumidity(const boost::shared_ptr<sensor_msgs::RelativeHumidity const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__RelativeHumidity(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__RelativeHumidity: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__Temperature(const sensor_msgs::Temperature& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'temperature'
            simPushStringOntoStackE(stack, "temperature", 0);
            write__float64(msg.temperature, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'temperature': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'variance'
            simPushStringOntoStackE(stack, "variance", 0);
            write__float64(msg.variance, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'variance': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__Temperature: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__Temperature(int stack, sensor_msgs::Temperature *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "temperature") == 0)
                {
                    try
                    {
                        // read field 'temperature'
                        read__float64(stack, &(msg->temperature), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field temperature: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "variance") == 0)
                {
                    try
                    {
                        // read field 'variance'
                        read__float64(stack, &(msg->variance), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field variance: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__Temperature: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__Temperature(const boost::shared_ptr<sensor_msgs::Temperature const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__Temperature(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__Temperature: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__sensor_msgs__TimeReference(const sensor_msgs::TimeReference& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'source'
            simPushStringOntoStackE(stack, "source", 0);
            write__string(msg.source, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'source': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_ref'
            simPushStringOntoStackE(stack, "time_ref", 0);
            write__time(msg.time_ref, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_ref': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__sensor_msgs__TimeReference: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__sensor_msgs__TimeReference(int stack, sensor_msgs::TimeReference *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "source") == 0)
                {
                    try
                    {
                        // read field 'source'
                        read__string(stack, &(msg->source), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field source: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_ref") == 0)
                {
                    try
                    {
                        // read field 'time_ref'
                        read__time(stack, &(msg->time_ref), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_ref: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__sensor_msgs__TimeReference: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__sensor_msgs__TimeReference(const boost::shared_ptr<sensor_msgs::TimeReference const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__sensor_msgs__TimeReference(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__sensor_msgs__TimeReference: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__shape_msgs__Mesh(const shape_msgs::Mesh& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'vertices'
            simPushStringOntoStackE(stack, "vertices", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.vertices.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point(msg.vertices[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'vertices': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'triangles'
            simPushStringOntoStackE(stack, "triangles", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.triangles.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__shape_msgs__MeshTriangle(msg.triangles[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'triangles': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__shape_msgs__Mesh: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__shape_msgs__Mesh(int stack, shape_msgs::Mesh *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "vertices") == 0)
                {
                    try
                    {
                        // read field 'vertices'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point v;
                            read__geometry_msgs__Point(stack, &v, opt);
                            msg->vertices.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field vertices: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "triangles") == 0)
                {
                    try
                    {
                        // read field 'triangles'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            shape_msgs::MeshTriangle v;
                            read__shape_msgs__MeshTriangle(stack, &v, opt);
                            msg->triangles.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field triangles: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__shape_msgs__Mesh: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__shape_msgs__Mesh(const boost::shared_ptr<shape_msgs::Mesh const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__shape_msgs__Mesh(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__shape_msgs__Mesh: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__shape_msgs__MeshTriangle(const shape_msgs::MeshTriangle& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'vertex_indices'
            simPushStringOntoStackE(stack, "vertex_indices", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.vertex_indices.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__uint32(msg.vertex_indices[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'vertex_indices': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__shape_msgs__MeshTriangle: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__shape_msgs__MeshTriangle(int stack, shape_msgs::MeshTriangle *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "vertex_indices") == 0)
                {
                    try
                    {
                        // read field 'vertex_indices'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            uint32_t v;
                            read__uint32(stack, &v, opt);
                            msg->vertex_indices[i] = (v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field vertex_indices: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__shape_msgs__MeshTriangle: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__shape_msgs__MeshTriangle(const boost::shared_ptr<shape_msgs::MeshTriangle const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__shape_msgs__MeshTriangle(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__shape_msgs__MeshTriangle: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__shape_msgs__Plane(const shape_msgs::Plane& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'coef' (using fast specialized function)
            simPushStringOntoStackE(stack, "coef", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.coef[0]), msg.coef.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'coef': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__shape_msgs__Plane: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__shape_msgs__Plane(int stack, shape_msgs::Plane *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "coef") == 0)
                {
                    try
                    {
                        // read field 'coef' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        // field has fixed size -> no need to reserve space into vector
                        simGetStackDoubleTableE(stack, &(msg->coef[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field coef: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__shape_msgs__Plane: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__shape_msgs__Plane(const boost::shared_ptr<shape_msgs::Plane const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__shape_msgs__Plane(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__shape_msgs__Plane: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__shape_msgs__SolidPrimitive(const shape_msgs::SolidPrimitive& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__uint8(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'dimensions' (using fast specialized function)
            simPushStringOntoStackE(stack, "dimensions", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.dimensions[0]), msg.dimensions.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'dimensions': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__shape_msgs__SolidPrimitive: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__shape_msgs__SolidPrimitive(int stack, shape_msgs::SolidPrimitive *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__uint8(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "dimensions") == 0)
                {
                    try
                    {
                        // read field 'dimensions' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->dimensions.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->dimensions[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field dimensions: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__shape_msgs__SolidPrimitive: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__shape_msgs__SolidPrimitive(const boost::shared_ptr<shape_msgs::SolidPrimitive const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__shape_msgs__SolidPrimitive(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__shape_msgs__SolidPrimitive: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__smach_msgs__SmachContainerInitialStatusCmd(const smach_msgs::SmachContainerInitialStatusCmd& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'path'
            simPushStringOntoStackE(stack, "path", 0);
            write__string(msg.path, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'path': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'local_data'
            simPushStringOntoStackE(stack, "local_data", 0);
            write__string(msg.local_data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'local_data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'initial_states'
            simPushStringOntoStackE(stack, "initial_states", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.initial_states.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.initial_states[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'initial_states': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__smach_msgs__SmachContainerInitialStatusCmd: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__smach_msgs__SmachContainerInitialStatusCmd(int stack, smach_msgs::SmachContainerInitialStatusCmd *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "path") == 0)
                {
                    try
                    {
                        // read field 'path'
                        read__string(stack, &(msg->path), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field path: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "local_data") == 0)
                {
                    try
                    {
                        // read field 'local_data'
                        read__string(stack, &(msg->local_data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field local_data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "initial_states") == 0)
                {
                    try
                    {
                        // read field 'initial_states'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->initial_states.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field initial_states: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__smach_msgs__SmachContainerInitialStatusCmd: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__smach_msgs__SmachContainerInitialStatusCmd(const boost::shared_ptr<smach_msgs::SmachContainerInitialStatusCmd const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__smach_msgs__SmachContainerInitialStatusCmd(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__smach_msgs__SmachContainerInitialStatusCmd: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__smach_msgs__SmachContainerStatus(const smach_msgs::SmachContainerStatus& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'info'
            simPushStringOntoStackE(stack, "info", 0);
            write__string(msg.info, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'info': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'local_data'
            simPushStringOntoStackE(stack, "local_data", 0);
            write__string(msg.local_data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'local_data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'path'
            simPushStringOntoStackE(stack, "path", 0);
            write__string(msg.path, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'path': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'active_states'
            simPushStringOntoStackE(stack, "active_states", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.active_states.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.active_states[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'active_states': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'initial_states'
            simPushStringOntoStackE(stack, "initial_states", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.initial_states.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.initial_states[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'initial_states': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__smach_msgs__SmachContainerStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__smach_msgs__SmachContainerStatus(int stack, smach_msgs::SmachContainerStatus *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "info") == 0)
                {
                    try
                    {
                        // read field 'info'
                        read__string(stack, &(msg->info), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field info: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "local_data") == 0)
                {
                    try
                    {
                        // read field 'local_data'
                        read__string(stack, &(msg->local_data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field local_data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "path") == 0)
                {
                    try
                    {
                        // read field 'path'
                        read__string(stack, &(msg->path), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field path: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "active_states") == 0)
                {
                    try
                    {
                        // read field 'active_states'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->active_states.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field active_states: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "initial_states") == 0)
                {
                    try
                    {
                        // read field 'initial_states'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->initial_states.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field initial_states: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__smach_msgs__SmachContainerStatus: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__smach_msgs__SmachContainerStatus(const boost::shared_ptr<smach_msgs::SmachContainerStatus const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__smach_msgs__SmachContainerStatus(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__smach_msgs__SmachContainerStatus: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__smach_msgs__SmachContainerStructure(const smach_msgs::SmachContainerStructure& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'outcomes_from'
            simPushStringOntoStackE(stack, "outcomes_from", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.outcomes_from.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.outcomes_from[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'outcomes_from': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'internal_outcomes'
            simPushStringOntoStackE(stack, "internal_outcomes", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.internal_outcomes.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.internal_outcomes[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'internal_outcomes': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'container_outcomes'
            simPushStringOntoStackE(stack, "container_outcomes", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.container_outcomes.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.container_outcomes[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'container_outcomes': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'path'
            simPushStringOntoStackE(stack, "path", 0);
            write__string(msg.path, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'path': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'outcomes_to'
            simPushStringOntoStackE(stack, "outcomes_to", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.outcomes_to.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.outcomes_to[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'outcomes_to': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'children'
            simPushStringOntoStackE(stack, "children", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.children.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.children[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'children': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__smach_msgs__SmachContainerStructure: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__smach_msgs__SmachContainerStructure(int stack, smach_msgs::SmachContainerStructure *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "outcomes_from") == 0)
                {
                    try
                    {
                        // read field 'outcomes_from'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->outcomes_from.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field outcomes_from: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "internal_outcomes") == 0)
                {
                    try
                    {
                        // read field 'internal_outcomes'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->internal_outcomes.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field internal_outcomes: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "container_outcomes") == 0)
                {
                    try
                    {
                        // read field 'container_outcomes'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->container_outcomes.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field container_outcomes: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "path") == 0)
                {
                    try
                    {
                        // read field 'path'
                        read__string(stack, &(msg->path), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field path: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "outcomes_to") == 0)
                {
                    try
                    {
                        // read field 'outcomes_to'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->outcomes_to.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field outcomes_to: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "children") == 0)
                {
                    try
                    {
                        // read field 'children'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->children.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field children: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__smach_msgs__SmachContainerStructure: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__smach_msgs__SmachContainerStructure(const boost::shared_ptr<smach_msgs::SmachContainerStructure const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__smach_msgs__SmachContainerStructure(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__smach_msgs__SmachContainerStructure: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Bool(const std_msgs::Bool& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__bool(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Bool: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Bool(int stack, std_msgs::Bool *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__bool(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Bool: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Bool(const boost::shared_ptr<std_msgs::Bool const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Bool(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Bool: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Byte(const std_msgs::Byte& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__int8(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Byte: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Byte(int stack, std_msgs::Byte *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__int8(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Byte: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Byte(const boost::shared_ptr<std_msgs::Byte const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Byte(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Byte: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__ByteMultiArray(const std_msgs::ByteMultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int8(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__ByteMultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__ByteMultiArray(int stack, std_msgs::ByteMultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int8_t v;
                            read__int8(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__ByteMultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__ByteMultiArray(const boost::shared_ptr<std_msgs::ByteMultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__ByteMultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__ByteMultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Char(const std_msgs::Char& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__uint8(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Char: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Char(int stack, std_msgs::Char *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__uint8(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Char: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Char(const boost::shared_ptr<std_msgs::Char const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Char(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Char: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__ColorRGBA(const std_msgs::ColorRGBA& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'a'
            simPushStringOntoStackE(stack, "a", 0);
            write__float32(msg.a, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'a': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'r'
            simPushStringOntoStackE(stack, "r", 0);
            write__float32(msg.r, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'r': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'b'
            simPushStringOntoStackE(stack, "b", 0);
            write__float32(msg.b, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'b': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'g'
            simPushStringOntoStackE(stack, "g", 0);
            write__float32(msg.g, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'g': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__ColorRGBA: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__ColorRGBA(int stack, std_msgs::ColorRGBA *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "a") == 0)
                {
                    try
                    {
                        // read field 'a'
                        read__float32(stack, &(msg->a), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field a: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "r") == 0)
                {
                    try
                    {
                        // read field 'r'
                        read__float32(stack, &(msg->r), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field r: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "b") == 0)
                {
                    try
                    {
                        // read field 'b'
                        read__float32(stack, &(msg->b), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field b: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "g") == 0)
                {
                    try
                    {
                        // read field 'g'
                        read__float32(stack, &(msg->g), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field g: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__ColorRGBA: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__ColorRGBA(const boost::shared_ptr<std_msgs::ColorRGBA const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__ColorRGBA(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__ColorRGBA: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Duration(const std_msgs::Duration& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__duration(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Duration: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Duration(int stack, std_msgs::Duration *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__duration(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Duration: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Duration(const boost::shared_ptr<std_msgs::Duration const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Duration(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Duration: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Empty(const std_msgs::Empty& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Empty: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Empty(int stack, std_msgs::Empty *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Empty: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Empty(const boost::shared_ptr<std_msgs::Empty const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Empty(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Empty: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Float32(const std_msgs::Float32& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__float32(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Float32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Float32(int stack, std_msgs::Float32 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__float32(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Float32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Float32(const boost::shared_ptr<std_msgs::Float32 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Float32(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Float32: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Float32MultiArray(const std_msgs::Float32MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            simPushFloatTableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Float32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Float32MultiArray(int stack, std_msgs::Float32MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->data.resize(sz);
                        simGetStackFloatTableE(stack, &(msg->data[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Float32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Float32MultiArray(const boost::shared_ptr<std_msgs::Float32MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Float32MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Float32MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Float64(const std_msgs::Float64& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__float64(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Float64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Float64(int stack, std_msgs::Float64 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__float64(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Float64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Float64(const boost::shared_ptr<std_msgs::Float64 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Float64(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Float64: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Float64MultiArray(const std_msgs::Float64MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Float64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Float64MultiArray(int stack, std_msgs::Float64MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->data.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->data[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Float64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Float64MultiArray(const boost::shared_ptr<std_msgs::Float64MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Float64MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Float64MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Header(const std_msgs::Header& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'stamp'
            simPushStringOntoStackE(stack, "stamp", 0);
            write__time(msg.stamp, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stamp': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'frame_id'
            simPushStringOntoStackE(stack, "frame_id", 0);
            write__string(msg.frame_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'frame_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'seq'
            simPushStringOntoStackE(stack, "seq", 0);
            write__uint32(msg.seq, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'seq': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Header: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Header(int stack, std_msgs::Header *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "stamp") == 0)
                {
                    try
                    {
                        // read field 'stamp'
                        read__time(stack, &(msg->stamp), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stamp: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "frame_id") == 0)
                {
                    try
                    {
                        // read field 'frame_id'
                        read__string(stack, &(msg->frame_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field frame_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "seq") == 0)
                {
                    try
                    {
                        // read field 'seq'
                        read__uint32(stack, &(msg->seq), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field seq: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Header: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Header(const boost::shared_ptr<std_msgs::Header const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Header(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Header: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int16(const std_msgs::Int16& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__int16(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int16: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int16(int stack, std_msgs::Int16 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__int16(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int16: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int16(const boost::shared_ptr<std_msgs::Int16 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int16(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int16: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int16MultiArray(const std_msgs::Int16MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int16(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int16MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int16MultiArray(int stack, std_msgs::Int16MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int16_t v;
                            read__int16(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int16MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int16MultiArray(const boost::shared_ptr<std_msgs::Int16MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int16MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int16MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int32(const std_msgs::Int32& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__int32(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int32(int stack, std_msgs::Int32 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__int32(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int32(const boost::shared_ptr<std_msgs::Int32 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int32(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int32: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int32MultiArray(const std_msgs::Int32MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            simPushInt32TableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int32MultiArray(int stack, std_msgs::Int32MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->data.resize(sz);
                        simGetStackInt32TableE(stack, &(msg->data[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int32MultiArray(const boost::shared_ptr<std_msgs::Int32MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int32MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int32MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int64(const std_msgs::Int64& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__int64(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int64(int stack, std_msgs::Int64 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__int64(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int64(const boost::shared_ptr<std_msgs::Int64 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int64(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int64: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int64MultiArray(const std_msgs::Int64MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int64(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int64MultiArray(int stack, std_msgs::Int64MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int64_t v;
                            read__int64(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int64MultiArray(const boost::shared_ptr<std_msgs::Int64MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int64MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int64MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int8(const std_msgs::Int8& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__int8(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int8: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int8(int stack, std_msgs::Int8 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__int8(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int8: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int8(const boost::shared_ptr<std_msgs::Int8 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int8(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int8: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Int8MultiArray(const std_msgs::Int8MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__int8(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Int8MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Int8MultiArray(int stack, std_msgs::Int8MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            int8_t v;
                            read__int8(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Int8MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Int8MultiArray(const boost::shared_ptr<std_msgs::Int8MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Int8MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Int8MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__MultiArrayDimension(const std_msgs::MultiArrayDimension& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'stride'
            simPushStringOntoStackE(stack, "stride", 0);
            write__uint32(msg.stride, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'stride': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'size'
            simPushStringOntoStackE(stack, "size", 0);
            write__uint32(msg.size, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'size': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'label'
            simPushStringOntoStackE(stack, "label", 0);
            write__string(msg.label, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'label': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__MultiArrayDimension: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__MultiArrayDimension(int stack, std_msgs::MultiArrayDimension *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "stride") == 0)
                {
                    try
                    {
                        // read field 'stride'
                        read__uint32(stack, &(msg->stride), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field stride: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "size") == 0)
                {
                    try
                    {
                        // read field 'size'
                        read__uint32(stack, &(msg->size), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field size: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "label") == 0)
                {
                    try
                    {
                        // read field 'label'
                        read__string(stack, &(msg->label), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field label: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__MultiArrayDimension: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__MultiArrayDimension(const boost::shared_ptr<std_msgs::MultiArrayDimension const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__MultiArrayDimension(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__MultiArrayDimension: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__MultiArrayLayout(const std_msgs::MultiArrayLayout& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'dim'
            simPushStringOntoStackE(stack, "dim", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.dim.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__std_msgs__MultiArrayDimension(msg.dim[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'dim': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'data_offset'
            simPushStringOntoStackE(stack, "data_offset", 0);
            write__uint32(msg.data_offset, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data_offset': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__MultiArrayLayout: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__MultiArrayLayout(int stack, std_msgs::MultiArrayLayout *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "dim") == 0)
                {
                    try
                    {
                        // read field 'dim'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std_msgs::MultiArrayDimension v;
                            read__std_msgs__MultiArrayDimension(stack, &v, opt);
                            msg->dim.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field dim: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "data_offset") == 0)
                {
                    try
                    {
                        // read field 'data_offset'
                        read__uint32(stack, &(msg->data_offset), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data_offset: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__MultiArrayLayout: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__MultiArrayLayout(const boost::shared_ptr<std_msgs::MultiArrayLayout const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__MultiArrayLayout(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__MultiArrayLayout: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__String(const std_msgs::String& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__string(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__String: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__String(int stack, std_msgs::String *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__string(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__String: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__String(const boost::shared_ptr<std_msgs::String const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__String(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__String: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__Time(const std_msgs::Time& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__time(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__Time: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__Time(int stack, std_msgs::Time *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__time(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__Time: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__Time(const boost::shared_ptr<std_msgs::Time const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__Time(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__Time: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt16(const std_msgs::UInt16& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__uint16(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt16: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt16(int stack, std_msgs::UInt16 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__uint16(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt16: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt16(const boost::shared_ptr<std_msgs::UInt16 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt16(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt16: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt16MultiArray(const std_msgs::UInt16MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__uint16(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt16MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt16MultiArray(int stack, std_msgs::UInt16MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            uint16_t v;
                            read__uint16(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt16MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt16MultiArray(const boost::shared_ptr<std_msgs::UInt16MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt16MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt16MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt32(const std_msgs::UInt32& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__uint32(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt32(int stack, std_msgs::UInt32 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__uint32(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt32: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt32(const boost::shared_ptr<std_msgs::UInt32 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt32(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt32: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt32MultiArray(const std_msgs::UInt32MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__uint32(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt32MultiArray(int stack, std_msgs::UInt32MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            uint32_t v;
                            read__uint32(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt32MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt32MultiArray(const boost::shared_ptr<std_msgs::UInt32MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt32MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt32MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt64(const std_msgs::UInt64& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__uint64(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt64(int stack, std_msgs::UInt64 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__uint64(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt64: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt64(const boost::shared_ptr<std_msgs::UInt64 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt64(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt64: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt64MultiArray(const std_msgs::UInt64MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.data.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__uint64(msg.data[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt64MultiArray(int stack, std_msgs::UInt64MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            uint64_t v;
                            read__uint64(stack, &v, opt);
                            msg->data.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt64MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt64MultiArray(const boost::shared_ptr<std_msgs::UInt64MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt64MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt64MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt8(const std_msgs::UInt8& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data'
            simPushStringOntoStackE(stack, "data", 0);
            write__uint8(msg.data, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt8: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt8(int stack, std_msgs::UInt8 *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        // read field 'data'
                        read__uint8(stack, &(msg->data), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt8: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt8(const boost::shared_ptr<std_msgs::UInt8 const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt8(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt8: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__std_msgs__UInt8MultiArray(const std_msgs::UInt8MultiArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'data' (using fast specialized function)
            simPushStringOntoStackE(stack, "data", 0);
            if(opt && opt->uint8array_as_string)
                simPushStringOntoStackE(stack, (simChar*)&(msg.data[0]), msg.data.size());
            else
                simPushUInt8TableOntoStackE(stack, &(msg.data[0]), msg.data.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'data': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'layout'
            simPushStringOntoStackE(stack, "layout", 0);
            write__std_msgs__MultiArrayLayout(msg.layout, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'layout': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_msgs__UInt8MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_msgs__UInt8MultiArray(int stack, std_msgs::UInt8MultiArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "data") == 0)
                {
                    try
                    {
                        if(opt && opt->uint8array_as_string)
                        {
                            // read field 'data' (uint8[]) as string
                            simChar *str;
                            simInt sz;
                            if((str = simGetStackStringValueE(stack, &sz)) != NULL && sz > 0)
                            {
                                /*
                                 * XXX: if an alternative version of simGetStackStringValue woudl exist
                                 * working on an externally allocated buffer, we won't need this memcpy:
                                 */
                                msg->data.resize(sz);
                                std::memcpy(&(msg->data[0]), str, sz);
                                simReleaseBufferE(str);
                            }
                            else throw exception("string read error when trying to read uint8[]");
                        }
                        else
			{
                            // read field 'data' (using fast specialized function)
                            int sz = simGetStackTableInfoE(stack, 0);
                            if(sz < 0)
                                throw exception("expected uint8 array");
                            if(simGetStackTableInfoE(stack, 2) != 1)
                                throw exception("fast_write_type uint8[] reader exception #1");
                            msg->data.resize(sz);
                            simGetStackUInt8TableE(stack, &(msg->data[0]), sz);
                            simPopStackItemE(stack, 1);
			}
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field data: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "layout") == 0)
                {
                    try
                    {
                        // read field 'layout'
                        read__std_msgs__MultiArrayLayout(stack, &(msg->layout), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field layout: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__std_msgs__UInt8MultiArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__std_msgs__UInt8MultiArray(const boost::shared_ptr<std_msgs::UInt8MultiArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__std_msgs__UInt8MultiArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__std_msgs__UInt8MultiArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__tf__tfMessage(const tf::tfMessage& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'transforms'
            simPushStringOntoStackE(stack, "transforms", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.transforms.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__TransformStamped(msg.transforms[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'transforms': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__tf__tfMessage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__tf__tfMessage(int stack, tf::tfMessage *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "transforms") == 0)
                {
                    try
                    {
                        // read field 'transforms'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::TransformStamped v;
                            read__geometry_msgs__TransformStamped(stack, &v, opt);
                            msg->transforms.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field transforms: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__tf__tfMessage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__tf__tfMessage(const boost::shared_ptr<tf::tfMessage const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__tf__tfMessage(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__tf__tfMessage: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__tf2_msgs__TF2Error(const tf2_msgs::TF2Error& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'error_string'
            simPushStringOntoStackE(stack, "error_string", 0);
            write__string(msg.error_string, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'error_string': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'error'
            simPushStringOntoStackE(stack, "error", 0);
            write__uint8(msg.error, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'error': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__tf2_msgs__TF2Error: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__tf2_msgs__TF2Error(int stack, tf2_msgs::TF2Error *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "error_string") == 0)
                {
                    try
                    {
                        // read field 'error_string'
                        read__string(stack, &(msg->error_string), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field error_string: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "error") == 0)
                {
                    try
                    {
                        // read field 'error'
                        read__uint8(stack, &(msg->error), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field error: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__tf2_msgs__TF2Error: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__tf2_msgs__TF2Error(const boost::shared_ptr<tf2_msgs::TF2Error const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__tf2_msgs__TF2Error(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__tf2_msgs__TF2Error: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__tf2_msgs__TFMessage(const tf2_msgs::TFMessage& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'transforms'
            simPushStringOntoStackE(stack, "transforms", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.transforms.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__TransformStamped(msg.transforms[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'transforms': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__tf2_msgs__TFMessage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__tf2_msgs__TFMessage(int stack, tf2_msgs::TFMessage *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "transforms") == 0)
                {
                    try
                    {
                        // read field 'transforms'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::TransformStamped v;
                            read__geometry_msgs__TransformStamped(stack, &v, opt);
                            msg->transforms.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field transforms: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__tf2_msgs__TFMessage: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__tf2_msgs__TFMessage(const boost::shared_ptr<tf2_msgs::TFMessage const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__tf2_msgs__TFMessage(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__tf2_msgs__TFMessage: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__trajectory_msgs__JointTrajectory(const trajectory_msgs::JointTrajectory& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'joint_names'
            simPushStringOntoStackE(stack, "joint_names", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.joint_names.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.joint_names[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'joint_names': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__trajectory_msgs__JointTrajectoryPoint(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__trajectory_msgs__JointTrajectory: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__trajectory_msgs__JointTrajectory(int stack, trajectory_msgs::JointTrajectory *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "joint_names") == 0)
                {
                    try
                    {
                        // read field 'joint_names'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->joint_names.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field joint_names: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            trajectory_msgs::JointTrajectoryPoint v;
                            read__trajectory_msgs__JointTrajectoryPoint(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__trajectory_msgs__JointTrajectory: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__trajectory_msgs__JointTrajectory(const boost::shared_ptr<trajectory_msgs::JointTrajectory const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__trajectory_msgs__JointTrajectory(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__trajectory_msgs__JointTrajectory: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__trajectory_msgs__JointTrajectoryPoint(const trajectory_msgs::JointTrajectoryPoint& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'positions' (using fast specialized function)
            simPushStringOntoStackE(stack, "positions", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.positions[0]), msg.positions.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'positions': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'accelerations' (using fast specialized function)
            simPushStringOntoStackE(stack, "accelerations", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.accelerations[0]), msg.accelerations.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'accelerations': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'velocities' (using fast specialized function)
            simPushStringOntoStackE(stack, "velocities", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.velocities[0]), msg.velocities.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'velocities': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'effort' (using fast specialized function)
            simPushStringOntoStackE(stack, "effort", 0);
            simPushDoubleTableOntoStackE(stack, &(msg.effort[0]), msg.effort.size());
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'effort': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_from_start'
            simPushStringOntoStackE(stack, "time_from_start", 0);
            write__duration(msg.time_from_start, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_from_start': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__trajectory_msgs__JointTrajectoryPoint: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__trajectory_msgs__JointTrajectoryPoint(int stack, trajectory_msgs::JointTrajectoryPoint *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "positions") == 0)
                {
                    try
                    {
                        // read field 'positions' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->positions.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->positions[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field positions: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "accelerations") == 0)
                {
                    try
                    {
                        // read field 'accelerations' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->accelerations.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->accelerations[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field accelerations: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "velocities") == 0)
                {
                    try
                    {
                        // read field 'velocities' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->velocities.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->velocities[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field velocities: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "effort") == 0)
                {
                    try
                    {
                        // read field 'effort' (using fast specialized function)
                        int sz = simGetStackTableInfoE(stack, 0);
                        if(sz < 0)
                            throw exception("expected array");
                        if(simGetStackTableInfoE(stack, 2) != 1)
                            throw exception("fast_write_type reader exception #1");
                        msg->effort.resize(sz);
                        simGetStackDoubleTableE(stack, &(msg->effort[0]), sz);
                        simPopStackItemE(stack, 1);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field effort: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_from_start") == 0)
                {
                    try
                    {
                        // read field 'time_from_start'
                        read__duration(stack, &(msg->time_from_start), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_from_start: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__trajectory_msgs__JointTrajectoryPoint: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__trajectory_msgs__JointTrajectoryPoint(const boost::shared_ptr<trajectory_msgs::JointTrajectoryPoint const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__trajectory_msgs__JointTrajectoryPoint(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__trajectory_msgs__JointTrajectoryPoint: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__trajectory_msgs__MultiDOFJointTrajectory(const trajectory_msgs::MultiDOFJointTrajectory& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'joint_names'
            simPushStringOntoStackE(stack, "joint_names", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.joint_names.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.joint_names[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'joint_names': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__trajectory_msgs__MultiDOFJointTrajectoryPoint(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__trajectory_msgs__MultiDOFJointTrajectory: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__trajectory_msgs__MultiDOFJointTrajectory(int stack, trajectory_msgs::MultiDOFJointTrajectory *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "joint_names") == 0)
                {
                    try
                    {
                        // read field 'joint_names'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->joint_names.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field joint_names: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            trajectory_msgs::MultiDOFJointTrajectoryPoint v;
                            read__trajectory_msgs__MultiDOFJointTrajectoryPoint(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__trajectory_msgs__MultiDOFJointTrajectory: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__trajectory_msgs__MultiDOFJointTrajectory(const boost::shared_ptr<trajectory_msgs::MultiDOFJointTrajectory const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__trajectory_msgs__MultiDOFJointTrajectory(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__trajectory_msgs__MultiDOFJointTrajectory: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__trajectory_msgs__MultiDOFJointTrajectoryPoint(const trajectory_msgs::MultiDOFJointTrajectoryPoint& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'accelerations'
            simPushStringOntoStackE(stack, "accelerations", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.accelerations.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.accelerations[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'accelerations': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'velocities'
            simPushStringOntoStackE(stack, "velocities", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.velocities.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Twist(msg.velocities[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'velocities': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'time_from_start'
            simPushStringOntoStackE(stack, "time_from_start", 0);
            write__duration(msg.time_from_start, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'time_from_start': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'transforms'
            simPushStringOntoStackE(stack, "transforms", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.transforms.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Transform(msg.transforms[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'transforms': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__trajectory_msgs__MultiDOFJointTrajectoryPoint: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__trajectory_msgs__MultiDOFJointTrajectoryPoint(int stack, trajectory_msgs::MultiDOFJointTrajectoryPoint *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "accelerations") == 0)
                {
                    try
                    {
                        // read field 'accelerations'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->accelerations.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field accelerations: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "velocities") == 0)
                {
                    try
                    {
                        // read field 'velocities'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Twist v;
                            read__geometry_msgs__Twist(stack, &v, opt);
                            msg->velocities.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field velocities: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "time_from_start") == 0)
                {
                    try
                    {
                        // read field 'time_from_start'
                        read__duration(stack, &(msg->time_from_start), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field time_from_start: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "transforms") == 0)
                {
                    try
                    {
                        // read field 'transforms'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Transform v;
                            read__geometry_msgs__Transform(stack, &v, opt);
                            msg->transforms.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field transforms: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__trajectory_msgs__MultiDOFJointTrajectoryPoint: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__trajectory_msgs__MultiDOFJointTrajectoryPoint(const boost::shared_ptr<trajectory_msgs::MultiDOFJointTrajectoryPoint const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__trajectory_msgs__MultiDOFJointTrajectoryPoint(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__trajectory_msgs__MultiDOFJointTrajectoryPoint: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__ImageMarker(const visualization_msgs::ImageMarker& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'scale'
            simPushStringOntoStackE(stack, "scale", 0);
            write__float32(msg.scale, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'scale': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'fill_color'
            simPushStringOntoStackE(stack, "fill_color", 0);
            write__std_msgs__ColorRGBA(msg.fill_color, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'fill_color': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'outline_colors'
            simPushStringOntoStackE(stack, "outline_colors", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.outline_colors.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__std_msgs__ColorRGBA(msg.outline_colors[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'outline_colors': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'outline_color'
            simPushStringOntoStackE(stack, "outline_color", 0);
            write__std_msgs__ColorRGBA(msg.outline_color, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'outline_color': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'lifetime'
            simPushStringOntoStackE(stack, "lifetime", 0);
            write__duration(msg.lifetime, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'lifetime': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'action'
            simPushStringOntoStackE(stack, "action", 0);
            write__int32(msg.action, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'action': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'position'
            simPushStringOntoStackE(stack, "position", 0);
            write__geometry_msgs__Point(msg.position, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'position': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ns'
            simPushStringOntoStackE(stack, "ns", 0);
            write__string(msg.ns, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ns': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__int32(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__int32(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'filled'
            simPushStringOntoStackE(stack, "filled", 0);
            write__uint8(msg.filled, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'filled': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__ImageMarker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__ImageMarker(int stack, visualization_msgs::ImageMarker *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "scale") == 0)
                {
                    try
                    {
                        // read field 'scale'
                        read__float32(stack, &(msg->scale), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field scale: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "fill_color") == 0)
                {
                    try
                    {
                        // read field 'fill_color'
                        read__std_msgs__ColorRGBA(stack, &(msg->fill_color), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field fill_color: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "outline_colors") == 0)
                {
                    try
                    {
                        // read field 'outline_colors'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std_msgs::ColorRGBA v;
                            read__std_msgs__ColorRGBA(stack, &v, opt);
                            msg->outline_colors.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field outline_colors: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "outline_color") == 0)
                {
                    try
                    {
                        // read field 'outline_color'
                        read__std_msgs__ColorRGBA(stack, &(msg->outline_color), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field outline_color: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "lifetime") == 0)
                {
                    try
                    {
                        // read field 'lifetime'
                        read__duration(stack, &(msg->lifetime), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field lifetime: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "action") == 0)
                {
                    try
                    {
                        // read field 'action'
                        read__int32(stack, &(msg->action), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field action: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "position") == 0)
                {
                    try
                    {
                        // read field 'position'
                        read__geometry_msgs__Point(stack, &(msg->position), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field position: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ns") == 0)
                {
                    try
                    {
                        // read field 'ns'
                        read__string(stack, &(msg->ns), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ns: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__int32(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__int32(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "filled") == 0)
                {
                    try
                    {
                        // read field 'filled'
                        read__uint8(stack, &(msg->filled), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field filled: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point v;
                            read__geometry_msgs__Point(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__ImageMarker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__ImageMarker(const boost::shared_ptr<visualization_msgs::ImageMarker const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__ImageMarker(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__ImageMarker: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarker(const visualization_msgs::InteractiveMarker& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'scale'
            simPushStringOntoStackE(stack, "scale", 0);
            write__float32(msg.scale, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'scale': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'controls'
            simPushStringOntoStackE(stack, "controls", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.controls.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__InteractiveMarkerControl(msg.controls[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'controls': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'menu_entries'
            simPushStringOntoStackE(stack, "menu_entries", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.menu_entries.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__MenuEntry(msg.menu_entries[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'menu_entries': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'description'
            simPushStringOntoStackE(stack, "description", 0);
            write__string(msg.description, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'description': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarker(int stack, visualization_msgs::InteractiveMarker *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "scale") == 0)
                {
                    try
                    {
                        // read field 'scale'
                        read__float32(stack, &(msg->scale), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field scale: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "controls") == 0)
                {
                    try
                    {
                        // read field 'controls'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::InteractiveMarkerControl v;
                            read__visualization_msgs__InteractiveMarkerControl(stack, &v, opt);
                            msg->controls.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field controls: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "menu_entries") == 0)
                {
                    try
                    {
                        // read field 'menu_entries'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::MenuEntry v;
                            read__visualization_msgs__MenuEntry(stack, &v, opt);
                            msg->menu_entries.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field menu_entries: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "description") == 0)
                {
                    try
                    {
                        // read field 'description'
                        read__string(stack, &(msg->description), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field description: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarker(const boost::shared_ptr<visualization_msgs::InteractiveMarker const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarker(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarker: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarkerControl(const visualization_msgs::InteractiveMarkerControl& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'interaction_mode'
            simPushStringOntoStackE(stack, "interaction_mode", 0);
            write__uint8(msg.interaction_mode, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'interaction_mode': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'description'
            simPushStringOntoStackE(stack, "description", 0);
            write__string(msg.description, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'description': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'markers'
            simPushStringOntoStackE(stack, "markers", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.markers.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__Marker(msg.markers[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'markers': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'always_visible'
            simPushStringOntoStackE(stack, "always_visible", 0);
            write__bool(msg.always_visible, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'always_visible': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'orientation_mode'
            simPushStringOntoStackE(stack, "orientation_mode", 0);
            write__uint8(msg.orientation_mode, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'orientation_mode': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'independent_marker_orientation'
            simPushStringOntoStackE(stack, "independent_marker_orientation", 0);
            write__bool(msg.independent_marker_orientation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'independent_marker_orientation': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'orientation'
            simPushStringOntoStackE(stack, "orientation", 0);
            write__geometry_msgs__Quaternion(msg.orientation, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'orientation': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarkerControl: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarkerControl(int stack, visualization_msgs::InteractiveMarkerControl *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "interaction_mode") == 0)
                {
                    try
                    {
                        // read field 'interaction_mode'
                        read__uint8(stack, &(msg->interaction_mode), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field interaction_mode: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "description") == 0)
                {
                    try
                    {
                        // read field 'description'
                        read__string(stack, &(msg->description), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field description: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "markers") == 0)
                {
                    try
                    {
                        // read field 'markers'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::Marker v;
                            read__visualization_msgs__Marker(stack, &v, opt);
                            msg->markers.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field markers: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "always_visible") == 0)
                {
                    try
                    {
                        // read field 'always_visible'
                        read__bool(stack, &(msg->always_visible), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field always_visible: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "orientation_mode") == 0)
                {
                    try
                    {
                        // read field 'orientation_mode'
                        read__uint8(stack, &(msg->orientation_mode), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field orientation_mode: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "independent_marker_orientation") == 0)
                {
                    try
                    {
                        // read field 'independent_marker_orientation'
                        read__bool(stack, &(msg->independent_marker_orientation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field independent_marker_orientation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "orientation") == 0)
                {
                    try
                    {
                        // read field 'orientation'
                        read__geometry_msgs__Quaternion(stack, &(msg->orientation), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field orientation: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarkerControl: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarkerControl(const boost::shared_ptr<visualization_msgs::InteractiveMarkerControl const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarkerControl(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarkerControl: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarkerFeedback(const visualization_msgs::InteractiveMarkerFeedback& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'event_type'
            simPushStringOntoStackE(stack, "event_type", 0);
            write__uint8(msg.event_type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'event_type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'marker_name'
            simPushStringOntoStackE(stack, "marker_name", 0);
            write__string(msg.marker_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'marker_name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'mouse_point_valid'
            simPushStringOntoStackE(stack, "mouse_point_valid", 0);
            write__bool(msg.mouse_point_valid, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'mouse_point_valid': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'control_name'
            simPushStringOntoStackE(stack, "control_name", 0);
            write__string(msg.control_name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'control_name': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'client_id'
            simPushStringOntoStackE(stack, "client_id", 0);
            write__string(msg.client_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'client_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'menu_entry_id'
            simPushStringOntoStackE(stack, "menu_entry_id", 0);
            write__uint32(msg.menu_entry_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'menu_entry_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'mouse_point'
            simPushStringOntoStackE(stack, "mouse_point", 0);
            write__geometry_msgs__Point(msg.mouse_point, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'mouse_point': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarkerFeedback: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarkerFeedback(int stack, visualization_msgs::InteractiveMarkerFeedback *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "event_type") == 0)
                {
                    try
                    {
                        // read field 'event_type'
                        read__uint8(stack, &(msg->event_type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field event_type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "marker_name") == 0)
                {
                    try
                    {
                        // read field 'marker_name'
                        read__string(stack, &(msg->marker_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field marker_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "mouse_point_valid") == 0)
                {
                    try
                    {
                        // read field 'mouse_point_valid'
                        read__bool(stack, &(msg->mouse_point_valid), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field mouse_point_valid: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "control_name") == 0)
                {
                    try
                    {
                        // read field 'control_name'
                        read__string(stack, &(msg->control_name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field control_name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "client_id") == 0)
                {
                    try
                    {
                        // read field 'client_id'
                        read__string(stack, &(msg->client_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field client_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "menu_entry_id") == 0)
                {
                    try
                    {
                        // read field 'menu_entry_id'
                        read__uint32(stack, &(msg->menu_entry_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field menu_entry_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "mouse_point") == 0)
                {
                    try
                    {
                        // read field 'mouse_point'
                        read__geometry_msgs__Point(stack, &(msg->mouse_point), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field mouse_point: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarkerFeedback: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarkerFeedback(const boost::shared_ptr<visualization_msgs::InteractiveMarkerFeedback const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarkerFeedback(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarkerFeedback: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarkerInit(const visualization_msgs::InteractiveMarkerInit& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'server_id'
            simPushStringOntoStackE(stack, "server_id", 0);
            write__string(msg.server_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'server_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'markers'
            simPushStringOntoStackE(stack, "markers", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.markers.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__InteractiveMarker(msg.markers[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'markers': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'seq_num'
            simPushStringOntoStackE(stack, "seq_num", 0);
            write__uint64(msg.seq_num, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'seq_num': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarkerInit: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarkerInit(int stack, visualization_msgs::InteractiveMarkerInit *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "server_id") == 0)
                {
                    try
                    {
                        // read field 'server_id'
                        read__string(stack, &(msg->server_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field server_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "markers") == 0)
                {
                    try
                    {
                        // read field 'markers'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::InteractiveMarker v;
                            read__visualization_msgs__InteractiveMarker(stack, &v, opt);
                            msg->markers.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field markers: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "seq_num") == 0)
                {
                    try
                    {
                        // read field 'seq_num'
                        read__uint64(stack, &(msg->seq_num), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field seq_num: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarkerInit: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarkerInit(const boost::shared_ptr<visualization_msgs::InteractiveMarkerInit const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarkerInit(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarkerInit: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarkerPose(const visualization_msgs::InteractiveMarkerPose& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'name'
            simPushStringOntoStackE(stack, "name", 0);
            write__string(msg.name, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'name': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarkerPose: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarkerPose(int stack, visualization_msgs::InteractiveMarkerPose *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "name") == 0)
                {
                    try
                    {
                        // read field 'name'
                        read__string(stack, &(msg->name), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field name: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarkerPose: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarkerPose(const boost::shared_ptr<visualization_msgs::InteractiveMarkerPose const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarkerPose(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarkerPose: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__InteractiveMarkerUpdate(const visualization_msgs::InteractiveMarkerUpdate& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'server_id'
            simPushStringOntoStackE(stack, "server_id", 0);
            write__string(msg.server_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'server_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'seq_num'
            simPushStringOntoStackE(stack, "seq_num", 0);
            write__uint64(msg.seq_num, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'seq_num': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'markers'
            simPushStringOntoStackE(stack, "markers", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.markers.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__InteractiveMarker(msg.markers[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'markers': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'erases'
            simPushStringOntoStackE(stack, "erases", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.erases.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__string(msg.erases[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'erases': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'poses'
            simPushStringOntoStackE(stack, "poses", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.poses.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__InteractiveMarkerPose(msg.poses[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'poses': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__uint8(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__InteractiveMarkerUpdate: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__InteractiveMarkerUpdate(int stack, visualization_msgs::InteractiveMarkerUpdate *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "server_id") == 0)
                {
                    try
                    {
                        // read field 'server_id'
                        read__string(stack, &(msg->server_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field server_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "seq_num") == 0)
                {
                    try
                    {
                        // read field 'seq_num'
                        read__uint64(stack, &(msg->seq_num), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field seq_num: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "markers") == 0)
                {
                    try
                    {
                        // read field 'markers'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::InteractiveMarker v;
                            read__visualization_msgs__InteractiveMarker(stack, &v, opt);
                            msg->markers.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field markers: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "erases") == 0)
                {
                    try
                    {
                        // read field 'erases'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std::string v;
                            read__string(stack, &v, opt);
                            msg->erases.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field erases: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "poses") == 0)
                {
                    try
                    {
                        // read field 'poses'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::InteractiveMarkerPose v;
                            read__visualization_msgs__InteractiveMarkerPose(stack, &v, opt);
                            msg->poses.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field poses: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__uint8(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__InteractiveMarkerUpdate: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__InteractiveMarkerUpdate(const boost::shared_ptr<visualization_msgs::InteractiveMarkerUpdate const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__InteractiveMarkerUpdate(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__InteractiveMarkerUpdate: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__Marker(const visualization_msgs::Marker& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'mesh_use_embedded_materials'
            simPushStringOntoStackE(stack, "mesh_use_embedded_materials", 0);
            write__bool(msg.mesh_use_embedded_materials, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'mesh_use_embedded_materials': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'scale'
            simPushStringOntoStackE(stack, "scale", 0);
            write__geometry_msgs__Vector3(msg.scale, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'scale': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'frame_locked'
            simPushStringOntoStackE(stack, "frame_locked", 0);
            write__bool(msg.frame_locked, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'frame_locked': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'color'
            simPushStringOntoStackE(stack, "color", 0);
            write__std_msgs__ColorRGBA(msg.color, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'color': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'text'
            simPushStringOntoStackE(stack, "text", 0);
            write__string(msg.text, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'text': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'pose'
            simPushStringOntoStackE(stack, "pose", 0);
            write__geometry_msgs__Pose(msg.pose, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'pose': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'mesh_resource'
            simPushStringOntoStackE(stack, "mesh_resource", 0);
            write__string(msg.mesh_resource, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'mesh_resource': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'header'
            simPushStringOntoStackE(stack, "header", 0);
            write__std_msgs__Header(msg.header, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'header': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'colors'
            simPushStringOntoStackE(stack, "colors", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.colors.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__std_msgs__ColorRGBA(msg.colors[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'colors': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'points'
            simPushStringOntoStackE(stack, "points", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.points.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__geometry_msgs__Point(msg.points[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'points': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'action'
            simPushStringOntoStackE(stack, "action", 0);
            write__int32(msg.action, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'action': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'lifetime'
            simPushStringOntoStackE(stack, "lifetime", 0);
            write__duration(msg.lifetime, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'lifetime': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'ns'
            simPushStringOntoStackE(stack, "ns", 0);
            write__string(msg.ns, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'ns': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'type'
            simPushStringOntoStackE(stack, "type", 0);
            write__int32(msg.type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__int32(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__Marker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__Marker(int stack, visualization_msgs::Marker *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "mesh_use_embedded_materials") == 0)
                {
                    try
                    {
                        // read field 'mesh_use_embedded_materials'
                        read__bool(stack, &(msg->mesh_use_embedded_materials), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field mesh_use_embedded_materials: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "scale") == 0)
                {
                    try
                    {
                        // read field 'scale'
                        read__geometry_msgs__Vector3(stack, &(msg->scale), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field scale: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "frame_locked") == 0)
                {
                    try
                    {
                        // read field 'frame_locked'
                        read__bool(stack, &(msg->frame_locked), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field frame_locked: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "color") == 0)
                {
                    try
                    {
                        // read field 'color'
                        read__std_msgs__ColorRGBA(stack, &(msg->color), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field color: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "text") == 0)
                {
                    try
                    {
                        // read field 'text'
                        read__string(stack, &(msg->text), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field text: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "pose") == 0)
                {
                    try
                    {
                        // read field 'pose'
                        read__geometry_msgs__Pose(stack, &(msg->pose), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field pose: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "mesh_resource") == 0)
                {
                    try
                    {
                        // read field 'mesh_resource'
                        read__string(stack, &(msg->mesh_resource), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field mesh_resource: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "header") == 0)
                {
                    try
                    {
                        // read field 'header'
                        read__std_msgs__Header(stack, &(msg->header), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field header: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "colors") == 0)
                {
                    try
                    {
                        // read field 'colors'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            std_msgs::ColorRGBA v;
                            read__std_msgs__ColorRGBA(stack, &v, opt);
                            msg->colors.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field colors: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "points") == 0)
                {
                    try
                    {
                        // read field 'points'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            geometry_msgs::Point v;
                            read__geometry_msgs__Point(stack, &v, opt);
                            msg->points.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field points: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "action") == 0)
                {
                    try
                    {
                        // read field 'action'
                        read__int32(stack, &(msg->action), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field action: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "lifetime") == 0)
                {
                    try
                    {
                        // read field 'lifetime'
                        read__duration(stack, &(msg->lifetime), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field lifetime: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "ns") == 0)
                {
                    try
                    {
                        // read field 'ns'
                        read__string(stack, &(msg->ns), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field ns: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "type") == 0)
                {
                    try
                    {
                        // read field 'type'
                        read__int32(stack, &(msg->type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__int32(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__Marker: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__Marker(const boost::shared_ptr<visualization_msgs::Marker const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__Marker(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__Marker: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__MarkerArray(const visualization_msgs::MarkerArray& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'markers'
            simPushStringOntoStackE(stack, "markers", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.markers.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__visualization_msgs__Marker(msg.markers[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'markers': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__MarkerArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__MarkerArray(int stack, visualization_msgs::MarkerArray *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "markers") == 0)
                {
                    try
                    {
                        // read field 'markers'
                        if(simGetStackTableInfoE(stack, 0) < 0)
                            throw exception("expected array");
                        int oldsz1 = simGetStackSizeE(stack);
                        simUnfoldStackTableE(stack);
                        int numItems1 = (simGetStackSizeE(stack) - oldsz1 + 1) / 2;
                        for(int i = 0; i < numItems1; i++)
                        {
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move key to top
                            int j;
                            read__int32(stack, &j, opt);
                            simMoveStackItemToTopE(stack, oldsz1 - 1); // move value to top
                            visualization_msgs::Marker v;
                            read__visualization_msgs__Marker(stack, &v, opt);
                            msg->markers.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field markers: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__MarkerArray: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__MarkerArray(const boost::shared_ptr<visualization_msgs::MarkerArray const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__MarkerArray(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__MarkerArray: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}


void write__visualization_msgs__MenuEntry(const visualization_msgs::MenuEntry& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'parent_id'
            simPushStringOntoStackE(stack, "parent_id", 0);
            write__uint32(msg.parent_id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'parent_id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'command_type'
            simPushStringOntoStackE(stack, "command_type", 0);
            write__uint8(msg.command_type, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'command_type': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'command'
            simPushStringOntoStackE(stack, "command", 0);
            write__string(msg.command, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'command': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'id'
            simPushStringOntoStackE(stack, "id", 0);
            write__uint32(msg.id, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'id': ";
            msg += ex.what();
            throw exception(msg);
        }
        try
        {
            // write field 'title'
            simPushStringOntoStackE(stack, "title", 0);
            write__string(msg.title, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'title': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__visualization_msgs__MenuEntry: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__visualization_msgs__MenuEntry(int stack, visualization_msgs::MenuEntry *msg, const ReadOptions *opt)
{
    try
    {
        int r = simGetStackTableInfoE(stack, 0);
        if(r != sim_stack_table_map && r != sim_stack_table_empty)
            throw exception("expected a table");

        int oldsz = simGetStackSizeE(stack);
        simUnfoldStackTableE(stack);
        int numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;

        char *str;
        int strSz;

        while(numItems >= 1)
        {
            simMoveStackItemToTopE(stack, oldsz - 1); // move key to top
            if((str = simGetStackStringValueE(stack, &strSz)) != NULL && strSz > 0)
            {
                simPopStackItemE(stack, 1);

                simMoveStackItemToTopE(stack, oldsz - 1); // move value to top

                if(0) {}
                else if(strcmp(str, "parent_id") == 0)
                {
                    try
                    {
                        // read field 'parent_id'
                        read__uint32(stack, &(msg->parent_id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field parent_id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "command_type") == 0)
                {
                    try
                    {
                        // read field 'command_type'
                        read__uint8(stack, &(msg->command_type), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field command_type: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "command") == 0)
                {
                    try
                    {
                        // read field 'command'
                        read__string(stack, &(msg->command), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field command: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "id") == 0)
                {
                    try
                    {
                        // read field 'id'
                        read__uint32(stack, &(msg->id), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field id: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else if(strcmp(str, "title") == 0)
                {
                    try
                    {
                        // read field 'title'
                        read__string(stack, &(msg->title), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field title: ";
                        msg += ex.what();
                        throw exception(msg);
                    }
                }
                else
                {
                    std::string msg = "unexpected key: ";
                    msg += str;
                    throw exception(msg);
                }

                simReleaseBuffer(str);
            }
            else
            {
                throw exception("malformed table (bad key type)");
            }

            numItems = (simGetStackSizeE(stack) - oldsz + 1) / 2;
        }
    }
    catch(exception& ex)
    {
        std::string msg = "read__visualization_msgs__MenuEntry: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void ros_callback__visualization_msgs__MenuEntry(const boost::shared_ptr<visualization_msgs::MenuEntry const>& msg, SubscriberProxy *proxy)
{
    int stack = -1;
    try
    {
        stack = simCreateStackE();
        write__visualization_msgs__MenuEntry(*msg, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->topicCallback.scriptId, proxy->topicCallback.name.c_str(), stack);
        simReleaseStackE(stack);
        stack = -1;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_callback__visualization_msgs__MenuEntry: ";
        msg += ex.what();
        simSetLastError(proxy->topicCallback.name.c_str(), msg.c_str());
    }
}

