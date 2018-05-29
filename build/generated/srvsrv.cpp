    else if(in->serviceType == "dynamic_reconfigure/Reconfigure")
    {
        serviceServerProxy->server = nh->advertiseService<dynamic_reconfigure::Reconfigure::Request, dynamic_reconfigure::Reconfigure::Response>(in->serviceName, boost::bind(ros_srv_callback__dynamic_reconfigure__Reconfigure, _1, _2, serviceServerProxy));
    }
    else if(in->serviceType == "roscpp/Empty")
    {
        serviceServerProxy->server = nh->advertiseService<roscpp::Empty::Request, roscpp::Empty::Response>(in->serviceName, boost::bind(ros_srv_callback__roscpp__Empty, _1, _2, serviceServerProxy));
    }
    else if(in->serviceType == "roscpp/GetLoggers")
    {
        serviceServerProxy->server = nh->advertiseService<roscpp::GetLoggers::Request, roscpp::GetLoggers::Response>(in->serviceName, boost::bind(ros_srv_callback__roscpp__GetLoggers, _1, _2, serviceServerProxy));
    }
    else if(in->serviceType == "roscpp/SetLoggerLevel")
    {
        serviceServerProxy->server = nh->advertiseService<roscpp::SetLoggerLevel::Request, roscpp::SetLoggerLevel::Response>(in->serviceName, boost::bind(ros_srv_callback__roscpp__SetLoggerLevel, _1, _2, serviceServerProxy));
    }
    else if(in->serviceType == "std_srvs/Empty")
    {
        serviceServerProxy->server = nh->advertiseService<std_srvs::Empty::Request, std_srvs::Empty::Response>(in->serviceName, boost::bind(ros_srv_callback__std_srvs__Empty, _1, _2, serviceServerProxy));
    }
    else if(in->serviceType == "std_srvs/Trigger")
    {
        serviceServerProxy->server = nh->advertiseService<std_srvs::Trigger::Request, std_srvs::Trigger::Response>(in->serviceName, boost::bind(ros_srv_callback__std_srvs__Trigger, _1, _2, serviceServerProxy));
    }
