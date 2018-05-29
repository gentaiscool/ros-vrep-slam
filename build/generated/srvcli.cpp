    else if(in->serviceType == "dynamic_reconfigure/Reconfigure")
    {
        serviceClientProxy->client = nh->serviceClient<dynamic_reconfigure::Reconfigure>(in->serviceName);
    }
    else if(in->serviceType == "roscpp/Empty")
    {
        serviceClientProxy->client = nh->serviceClient<roscpp::Empty>(in->serviceName);
    }
    else if(in->serviceType == "roscpp/GetLoggers")
    {
        serviceClientProxy->client = nh->serviceClient<roscpp::GetLoggers>(in->serviceName);
    }
    else if(in->serviceType == "roscpp/SetLoggerLevel")
    {
        serviceClientProxy->client = nh->serviceClient<roscpp::SetLoggerLevel>(in->serviceName);
    }
    else if(in->serviceType == "std_srvs/Empty")
    {
        serviceClientProxy->client = nh->serviceClient<std_srvs::Empty>(in->serviceName);
    }
    else if(in->serviceType == "std_srvs/Trigger")
    {
        serviceClientProxy->client = nh->serviceClient<std_srvs::Trigger>(in->serviceName);
    }
