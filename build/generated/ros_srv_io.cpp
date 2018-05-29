#include <ros_msg_io.h>
#include <ros_srv_io.h>
#include <v_repLib.h>


void write__dynamic_reconfigure__ReconfigureRequest(const dynamic_reconfigure::ReconfigureRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'config'
            simPushStringOntoStackE(stack, "config", 0);
            write__dynamic_reconfigure__Config(msg.config, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'config': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__ReconfigureRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__ReconfigureRequest(int stack, dynamic_reconfigure::ReconfigureRequest *msg, const ReadOptions *opt)
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
                else if(strcmp(str, "config") == 0)
                {
                    try
                    {
                        // read field 'config'
                        read__dynamic_reconfigure__Config(stack, &(msg->config), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field config: ";
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
        std::string msg = "read__dynamic_reconfigure__ReconfigureRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__dynamic_reconfigure__ReconfigureResponse(const dynamic_reconfigure::ReconfigureResponse& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'config'
            simPushStringOntoStackE(stack, "config", 0);
            write__dynamic_reconfigure__Config(msg.config, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'config': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__dynamic_reconfigure__ReconfigureResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__dynamic_reconfigure__ReconfigureResponse(int stack, dynamic_reconfigure::ReconfigureResponse *msg, const ReadOptions *opt)
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
                else if(strcmp(str, "config") == 0)
                {
                    try
                    {
                        // read field 'config'
                        read__dynamic_reconfigure__Config(stack, &(msg->config), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field config: ";
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
        std::string msg = "read__dynamic_reconfigure__ReconfigureResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__dynamic_reconfigure__Reconfigure(dynamic_reconfigure::Reconfigure::Request& req, dynamic_reconfigure::Reconfigure::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__dynamic_reconfigure__ReconfigureRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__dynamic_reconfigure__ReconfigureResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__dynamic_reconfigure__Reconfigure: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}

void write__roscpp__EmptyRequest(const roscpp::EmptyRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__EmptyRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__EmptyRequest(int stack, roscpp::EmptyRequest *msg, const ReadOptions *opt)
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
        std::string msg = "read__roscpp__EmptyRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__roscpp__EmptyResponse(const roscpp::EmptyResponse& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__EmptyResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__EmptyResponse(int stack, roscpp::EmptyResponse *msg, const ReadOptions *opt)
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
        std::string msg = "read__roscpp__EmptyResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__roscpp__Empty(roscpp::Empty::Request& req, roscpp::Empty::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__roscpp__EmptyRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__roscpp__EmptyResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__roscpp__Empty: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}

void write__roscpp__GetLoggersRequest(const roscpp::GetLoggersRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__GetLoggersRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__GetLoggersRequest(int stack, roscpp::GetLoggersRequest *msg, const ReadOptions *opt)
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
        std::string msg = "read__roscpp__GetLoggersRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__roscpp__GetLoggersResponse(const roscpp::GetLoggersResponse& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'loggers'
            simPushStringOntoStackE(stack, "loggers", 0);
            simPushTableOntoStackE(stack);
            for(int i = 0; i < msg.loggers.size(); i++)
            {
                write__int32(i + 1, stack, opt);
                write__roscpp__Logger(msg.loggers[i], stack, opt);
                simInsertDataIntoStackTableE(stack);
            }
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'loggers': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__GetLoggersResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__GetLoggersResponse(int stack, roscpp::GetLoggersResponse *msg, const ReadOptions *opt)
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
                else if(strcmp(str, "loggers") == 0)
                {
                    try
                    {
                        // read field 'loggers'
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
                            roscpp::Logger v;
                            read__roscpp__Logger(stack, &v, opt);
                            msg->loggers.push_back(v);
                        }
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field loggers: ";
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
        std::string msg = "read__roscpp__GetLoggersResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__roscpp__GetLoggers(roscpp::GetLoggers::Request& req, roscpp::GetLoggers::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__roscpp__GetLoggersRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__roscpp__GetLoggersResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__roscpp__GetLoggers: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}

void write__roscpp__SetLoggerLevelRequest(const roscpp::SetLoggerLevelRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

        try
        {
            // write field 'logger'
            simPushStringOntoStackE(stack, "logger", 0);
            write__string(msg.logger, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'logger': ";
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
        std::string msg = "write__roscpp__SetLoggerLevelRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__SetLoggerLevelRequest(int stack, roscpp::SetLoggerLevelRequest *msg, const ReadOptions *opt)
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
                else if(strcmp(str, "logger") == 0)
                {
                    try
                    {
                        // read field 'logger'
                        read__string(stack, &(msg->logger), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field logger: ";
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
        std::string msg = "read__roscpp__SetLoggerLevelRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__roscpp__SetLoggerLevelResponse(const roscpp::SetLoggerLevelResponse& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__roscpp__SetLoggerLevelResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__roscpp__SetLoggerLevelResponse(int stack, roscpp::SetLoggerLevelResponse *msg, const ReadOptions *opt)
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
        std::string msg = "read__roscpp__SetLoggerLevelResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__roscpp__SetLoggerLevel(roscpp::SetLoggerLevel::Request& req, roscpp::SetLoggerLevel::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__roscpp__SetLoggerLevelRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__roscpp__SetLoggerLevelResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__roscpp__SetLoggerLevel: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}

void write__std_srvs__EmptyRequest(const std_srvs::EmptyRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__std_srvs__EmptyRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_srvs__EmptyRequest(int stack, std_srvs::EmptyRequest *msg, const ReadOptions *opt)
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
        std::string msg = "read__std_srvs__EmptyRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__std_srvs__EmptyResponse(const std_srvs::EmptyResponse& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__std_srvs__EmptyResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_srvs__EmptyResponse(int stack, std_srvs::EmptyResponse *msg, const ReadOptions *opt)
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
        std::string msg = "read__std_srvs__EmptyResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__std_srvs__Empty(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__std_srvs__EmptyRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__std_srvs__EmptyResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__std_srvs__Empty: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}

void write__std_srvs__TriggerRequest(const std_srvs::TriggerRequest& msg, int stack, const WriteOptions *opt)
{
    try
    {
        simPushTableOntoStackE(stack);

    }
    catch(exception& ex)
    {
        std::string msg = "write__std_srvs__TriggerRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_srvs__TriggerRequest(int stack, std_srvs::TriggerRequest *msg, const ReadOptions *opt)
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
        std::string msg = "read__std_srvs__TriggerRequest: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void write__std_srvs__TriggerResponse(const std_srvs::TriggerResponse& msg, int stack, const WriteOptions *opt)
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
            // write field 'success'
            simPushStringOntoStackE(stack, "success", 0);
            write__bool(msg.success, stack, opt);
            simInsertDataIntoStackTableE(stack);
        }
        catch(exception& ex)
        {
            std::string msg = "field 'success': ";
            msg += ex.what();
            throw exception(msg);
        }
    }
    catch(exception& ex)
    {
        std::string msg = "write__std_srvs__TriggerResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


void read__std_srvs__TriggerResponse(int stack, std_srvs::TriggerResponse *msg, const ReadOptions *opt)
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
                else if(strcmp(str, "success") == 0)
                {
                    try
                    {
                        // read field 'success'
                        read__bool(stack, &(msg->success), opt);
                    }
                    catch(exception& ex)
                    {
                        std::string msg = "field success: ";
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
        std::string msg = "read__std_srvs__TriggerResponse: ";
        msg += ex.what();
        throw exception(msg);
    }
}


bool ros_srv_callback__std_srvs__Trigger(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res, ServiceServerProxy *proxy)
{
    bool ret = false;
    int stack = -1;

    try
    {
        stack = simCreateStackE();
        write__std_srvs__TriggerRequest(req, stack, &(proxy->wr_opt));
        simCallScriptFunctionExE(proxy->serviceCallback.scriptId, proxy->serviceCallback.name.c_str(), stack);
        read__std_srvs__TriggerResponse(stack, &res, &(proxy->rd_opt));
        simReleaseStackE(stack);
        stack = -1;
        return true;
    }
    catch(exception& ex)
    {
        if(stack != -1)
            simReleaseStack(stack); // don't throw
        std::string msg = "ros_srv_callback__std_srvs__Trigger: ";
        msg += ex.what();
        simSetLastError(proxy->serviceCallback.name.c_str(), msg.c_str());
        return false;
    }
}
