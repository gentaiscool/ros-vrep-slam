    else if(serviceClientProxy->serviceType == "dynamic_reconfigure/Reconfigure")
    {
        dynamic_reconfigure::Reconfigure srv;
        read__dynamic_reconfigure__ReconfigureRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__dynamic_reconfigure__ReconfigureResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service dynamic_reconfigure/Reconfigure");
        }
    }
    else if(serviceClientProxy->serviceType == "roscpp/Empty")
    {
        roscpp::Empty srv;
        read__roscpp__EmptyRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__roscpp__EmptyResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service roscpp/Empty");
        }
    }
    else if(serviceClientProxy->serviceType == "roscpp/GetLoggers")
    {
        roscpp::GetLoggers srv;
        read__roscpp__GetLoggersRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__roscpp__GetLoggersResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service roscpp/GetLoggers");
        }
    }
    else if(serviceClientProxy->serviceType == "roscpp/SetLoggerLevel")
    {
        roscpp::SetLoggerLevel srv;
        read__roscpp__SetLoggerLevelRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__roscpp__SetLoggerLevelResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service roscpp/SetLoggerLevel");
        }
    }
    else if(serviceClientProxy->serviceType == "std_srvs/Empty")
    {
        std_srvs::Empty srv;
        read__std_srvs__EmptyRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__std_srvs__EmptyResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service std_srvs/Empty");
        }
    }
    else if(serviceClientProxy->serviceType == "std_srvs/Trigger")
    {
        std_srvs::Trigger srv;
        read__std_srvs__TriggerRequest(p->stackID, &(srv.request), &(serviceClientProxy->rd_opt));
        if(serviceClientProxy->client.call(srv))
        {
            write__std_srvs__TriggerResponse(srv.response, p->stackID, &(serviceClientProxy->wr_opt));
        }
        else
        {
            throw exception("failed to call service std_srvs/Trigger");
        }
    }
