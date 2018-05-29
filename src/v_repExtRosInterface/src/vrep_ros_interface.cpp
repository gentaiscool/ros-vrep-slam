#include <vrep_ros_interface.h>

#include <tf/transform_broadcaster.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#define PLUGIN_VERSION 5 // 5 since 3.3.1 (using stacks to exchange data with scripts)

#define CONCAT(x,y,z) x y z
#define strConCat(x,y,z) CONCAT(x,y,z)

LIBRARY vrepLib; // the V-REP library that we will dynamically load and bind

ros::NodeHandle *nh = NULL;

tf::TransformBroadcaster *tfbr = NULL;
image_transport::ImageTransport *imtr = NULL;

int subscriberProxyNextHandle = 3562;
int publisherProxyNextHandle = 7980;
int serviceClientProxyNextHandle = 26856;
int serviceServerProxyNextHandle = 53749;

std::map<int, SubscriberProxy *> subscriberProxies;
std::map<int, PublisherProxy *> publisherProxies;
std::map<int, ServiceClientProxy *> serviceClientProxies;
std::map<int, ServiceServerProxy *> serviceServerProxies;

bool shouldProxyBeDestroyedAfterSimulationStop(SScriptCallBack *p)
{
    if(simGetSimulationState() == sim_simulation_stopped)
        return false;
    int property;
    int associatedObject;
    if(simGetScriptProperty(p->scriptID, &property, &associatedObject) == -1)
        return false;
    if(property & sim_scripttype_threaded)
        property -= sim_scripttype_threaded;
    if(property == sim_scripttype_addonscript || property == sim_scripttype_addonfunction || property == sim_scripttype_customizationscript)
        return false;
    return true;
}

void ros_imtr_callback(const sensor_msgs::ImageConstPtr& msg, SubscriberProxy *subscriberProxy)
{
    if(msg->is_bigendian)
    {
        std::cerr << "ros_imtr_callback: error: big endian image not supported" << std::endl;
        return;
    }

    int data_len = msg->step * msg->height;

    imageTransportCallback_in in_args;
    imageTransportCallback_out out_args;

    in_args.width = msg->width;
    in_args.height = msg->height;
    in_args.data.resize(data_len);

    for(unsigned int i = 0; i < msg->height; i++)
    {
        int msg_idx = (msg->height - i - 1) * msg->step;
        int buf_idx = i * msg->step;
        for(unsigned int j = 0; j < msg->step; j++)
        {
            in_args.data[buf_idx + j] = msg->data[msg_idx + j];
        }
    }

    if(!imageTransportCallback(subscriberProxy->topicCallback.scriptId, subscriberProxy->topicCallback.name.c_str(), &in_args, &out_args))
    {
        std::cerr << "ros_imtr_callback: error: failed to call callback" << std::endl;
        return;
    }
}

void subscribe(SScriptCallBack * p, const char * cmd, subscribe_in * in, subscribe_out * out)
{
    SubscriberProxy *subscriberProxy = new SubscriberProxy();
    subscriberProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    subscriberProxy->handle = subscriberProxyNextHandle++;
    subscriberProxy->topicName = in->topicName;
    subscriberProxy->topicType = in->topicType;
    subscriberProxy->topicCallback.scriptId = p->scriptID;
    subscriberProxy->topicCallback.name = in->topicCallback;
    subscriberProxies[subscriberProxy->handle] = subscriberProxy;

    if(0) {}
#include <sub.cpp>
    else
    {
        throw exception("unsupported message type. please edit and recompile ROS plugin");
    }

    if(!subscriberProxy->subscriber)
    {
        throw exception("failed creation of ROS subscriber");
    }

    out->subscriberHandle = subscriberProxy->handle;
}

void shutdownSubscriber(SScriptCallBack * p, const char * cmd, shutdownSubscriber_in * in, shutdownSubscriber_out * out)
{
    if(subscriberProxies.find(in->subscriberHandle) == subscriberProxies.end())
    {
        throw exception("invalid subscriber handle");
    }

    SubscriberProxy *subscriberProxy = subscriberProxies[in->subscriberHandle];
    subscriberProxy->subscriber.shutdown();
    subscriberProxies.erase(subscriberProxy->handle);
    delete subscriberProxy;
}

void subscriberTreatUInt8ArrayAsString(SScriptCallBack * p, const char * cmd, subscriberTreatUInt8ArrayAsString_in * in, subscriberTreatUInt8ArrayAsString_out * out)
{
    if(subscriberProxies.find(in->subscriberHandle) == subscriberProxies.end())
    {
        throw exception("invalid subscriber handle");
    }

    SubscriberProxy *subscriberProxy = subscriberProxies[in->subscriberHandle];
    subscriberProxy->wr_opt.uint8array_as_string = true;
}

void advertise(SScriptCallBack * p, const char * cmd, advertise_in * in, advertise_out * out)
{
    PublisherProxy *publisherProxy = new PublisherProxy();
    publisherProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    publisherProxy->handle = publisherProxyNextHandle++;
    publisherProxy->topicName = in->topicName;
    publisherProxy->topicType = in->topicType;
    publisherProxies[publisherProxy->handle] = publisherProxy;

    if(0) {}
#include <adv.cpp>
    else
    {
        throw exception("unsupported message type. please edit and recompile ROS plugin");
    }

    if(!publisherProxy->publisher)
    {
        throw exception("failed creation of ROS publisher");
    }

    out->publisherHandle = publisherProxy->handle;
}

void shutdownPublisher(SScriptCallBack * p, const char * cmd, shutdownPublisher_in * in, shutdownPublisher_out * out)
{
    if(publisherProxies.find(in->publisherHandle) == publisherProxies.end())
    {
        throw exception("invalid publisher handle");
    }

    PublisherProxy *publisherProxy = publisherProxies[in->publisherHandle];
    publisherProxy->publisher.shutdown();
    publisherProxies.erase(publisherProxy->handle);
    delete publisherProxy;
}

void publisherTreatUInt8ArrayAsString(SScriptCallBack * p, const char * cmd, publisherTreatUInt8ArrayAsString_in * in, publisherTreatUInt8ArrayAsString_out * out)
{
    if(publisherProxies.find(in->publisherHandle) == publisherProxies.end())
    {
        throw exception("invalid publisher handle");
    }

    PublisherProxy *publisherProxy = publisherProxies[in->publisherHandle];
    publisherProxy->rd_opt.uint8array_as_string = true;
}

void publish(SScriptCallBack * p, const char * cmd, publish_in * in, publish_out * out)
{
    if(publisherProxies.find(in->publisherHandle) == publisherProxies.end())
    {
        throw exception("invalid publisher handle");
    }

    PublisherProxy *publisherProxy = publisherProxies[in->publisherHandle];

    simMoveStackItemToTop(p->stackID, 0);

    if(0) {}
#include <pub.cpp>
    else
    {
        throw exception("unsupported message type. please edit and recompile ROS plugin");
    }
}

void serviceClient(SScriptCallBack * p, const char * cmd, serviceClient_in * in, serviceClient_out * out)
{
    ServiceClientProxy *serviceClientProxy = new ServiceClientProxy();
    serviceClientProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    serviceClientProxy->handle = serviceClientProxyNextHandle++;
    serviceClientProxy->serviceName = in->serviceName;
    serviceClientProxy->serviceType = in->serviceType;
    serviceClientProxies[serviceClientProxy->handle] = serviceClientProxy;

    if(0) {}
#include <srvcli.cpp>
    else
    {
        throw exception("unsupported service type. please edit and recompile ROS plugin");
    }

    if(!serviceClientProxy->client)
    {
        throw exception("failed creation of ROS service client");
    }

    out->serviceClientHandle = serviceClientProxy->handle;
}

void shutdownServiceClient(SScriptCallBack * p, const char * cmd, shutdownServiceClient_in * in, shutdownServiceClient_out * out)
{
    if(serviceClientProxies.find(in->serviceClientHandle) == serviceClientProxies.end())
    {
        throw exception("invalid service client handle");
    }

    ServiceClientProxy *serviceClientProxy = serviceClientProxies[in->serviceClientHandle];
    serviceClientProxy->client.shutdown();
    serviceClientProxies.erase(serviceClientProxy->handle);
    delete serviceClientProxy;
}

void serviceClientTreatUInt8ArrayAsString(SScriptCallBack * p, const char * cmd, serviceClientTreatUInt8ArrayAsString_in * in, serviceClientTreatUInt8ArrayAsString_out * out)
{
    if(serviceClientProxies.find(in->serviceClientHandle) == serviceClientProxies.end())
    {
        throw exception("invalid service client handle");
    }

    ServiceClientProxy *serviceClientProxy = serviceClientProxies[in->serviceClientHandle];
    serviceClientProxy->rd_opt.uint8array_as_string = true;
    serviceClientProxy->wr_opt.uint8array_as_string = true;
}

void call(SScriptCallBack * p, const char * cmd, call_in * in, call_out * out)
{
    if(serviceClientProxies.find(in->serviceClientHandle) == serviceClientProxies.end())
    {
        throw exception("invalid service client handle");
    }

    ServiceClientProxy *serviceClientProxy = serviceClientProxies[in->serviceClientHandle];

    simMoveStackItemToTop(p->stackID, 0);

    if(0) {}
#include <srvcall.cpp>
    else
    {
        throw exception("unsupported service type. please edit and recompile ROS plugin");
    }
}

void advertiseService(SScriptCallBack * p, const char * cmd, advertiseService_in * in, advertiseService_out * out)
{
    ServiceServerProxy *serviceServerProxy = new ServiceServerProxy();
    serviceServerProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    serviceServerProxy->handle = serviceServerProxyNextHandle++;
    serviceServerProxy->serviceName = in->serviceName;
    serviceServerProxy->serviceType = in->serviceType;
    serviceServerProxy->serviceCallback.scriptId = p->scriptID;
    serviceServerProxy->serviceCallback.name = in->serviceCallback;
    serviceServerProxies[serviceServerProxy->handle] = serviceServerProxy;

    if(0) {}
#include <srvsrv.cpp>
    else
    {
        throw exception("unsupported service type. please edit and recompile ROS plugin");
    }

    if(!serviceServerProxy->server)
    {
        throw exception("failed creation of ROS service server");
    }

    out->serviceServerHandle = serviceServerProxy->handle;
}

void shutdownServiceServer(SScriptCallBack * p, const char * cmd, shutdownServiceServer_in * in, shutdownServiceServer_out * out)
{
    if(serviceServerProxies.find(in->serviceServerHandle) == serviceServerProxies.end())
    {
        throw exception("invalid service server handle");
    }

    ServiceServerProxy *serviceServerProxy = serviceServerProxies[in->serviceServerHandle];
    serviceServerProxy->server.shutdown();
    serviceServerProxies.erase(serviceServerProxy->handle);
    delete serviceServerProxy;
}

void serviceServerTreatUInt8ArrayAsString(SScriptCallBack * p, const char * cmd, serviceServerTreatUInt8ArrayAsString_in * in, serviceServerTreatUInt8ArrayAsString_out * out)
{
    if(serviceServerProxies.find(in->serviceServerHandle) == serviceServerProxies.end())
    {
        throw exception("invalid service server handle");
    }

    ServiceServerProxy *serviceServerProxy = serviceServerProxies[in->serviceServerHandle];
    serviceServerProxy->rd_opt.uint8array_as_string = true;
    serviceServerProxy->wr_opt.uint8array_as_string = true;
}

void sendTransform(SScriptCallBack * p, const char * cmd, sendTransform_in * in, sendTransform_out * out)
{
    geometry_msgs::TransformStamped t;
    read__geometry_msgs__TransformStamped(p->stackID, &t);
    tfbr->sendTransform(t);
}

void sendTransforms(SScriptCallBack * p, const char * cmd, sendTransforms_in * in, sendTransforms_out * out)
{
    std::vector<geometry_msgs::TransformStamped> v;

    simMoveStackItemToTopE(p->stackID, 0);
    int i = simGetStackTableInfoE(p->stackID, 0);
    if(i < 0)
        throw exception("error reading input argument 1 (origin): expected array");
    int oldsz = simGetStackSizeE(p->stackID);
    simUnfoldStackTableE(p->stackID);
    int sz = (simGetStackSizeE(p->stackID) - oldsz + 1) / 2;
    for(int i = 0; i < sz; i++)
    {
        simMoveStackItemToTopE(p->stackID, oldsz - 1);
        int j;
        read__int(p->stackID, &j);
        simMoveStackItemToTop(p->stackID, oldsz - 1);
        geometry_msgs::TransformStamped t;
        read__geometry_msgs__TransformStamped(p->stackID, &t);
        v.push_back(t);
    }
    
    tfbr->sendTransform(v);
}

void imageTransportSubscribe(SScriptCallBack *p, const char *cmd, imageTransportSubscribe_in *in, imageTransportSubscribe_out *out)
{
    SubscriberProxy *subscriberProxy = new SubscriberProxy();
    subscriberProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    subscriberProxy->handle = subscriberProxyNextHandle++;
    subscriberProxy->topicName = in->topicName;
    subscriberProxy->topicType = "@image_transport";
    subscriberProxy->topicCallback.scriptId = p->scriptID;
    subscriberProxy->topicCallback.name = in->topicCallback;
    subscriberProxies[subscriberProxy->handle] = subscriberProxy;

    subscriberProxy->imageTransportSubscriber = imtr->subscribe(in->topicName, in->queueSize, boost::bind(ros_imtr_callback, _1, subscriberProxy));

    if(!subscriberProxy->imageTransportSubscriber)
    {
        throw exception("failed creation of ROS ImageTransport subscriber");
    }

    out->subscriberHandle = subscriberProxy->handle;
}

void imageTransportShutdownSubscriber(SScriptCallBack *p, const char *cmd, imageTransportShutdownSubscriber_in *in, imageTransportShutdownSubscriber_out *out)
{
    if(subscriberProxies.find(in->subscriberHandle) == subscriberProxies.end())
    {
        throw exception("invalid subscriber handle");
    }

    SubscriberProxy *subscriberProxy = subscriberProxies[in->subscriberHandle];
    subscriberProxy->imageTransportSubscriber.shutdown();
    subscriberProxies.erase(subscriberProxy->handle);
    delete subscriberProxy;
}

void imageTransportAdvertise(SScriptCallBack *p, const char *cmd, imageTransportAdvertise_in *in, imageTransportAdvertise_out *out)
{
    PublisherProxy *publisherProxy = new PublisherProxy();
    publisherProxy->destroyAfterSimulationStop = shouldProxyBeDestroyedAfterSimulationStop(p);
    publisherProxy->handle = publisherProxyNextHandle++;
    publisherProxy->topicName = in->topicName;
    publisherProxy->topicType = "@image_transport";
    publisherProxies[publisherProxy->handle] = publisherProxy;

    publisherProxy->imageTransportPublisher = imtr->advertise(in->topicName, in->queueSize);

    if(!publisherProxy->imageTransportPublisher)
    {
        throw exception("failed creation of ROS ImageTransport publisher");
    }

    out->publisherHandle = publisherProxy->handle;
}

void imageTransportShutdownPublisher(SScriptCallBack *p, const char *cmd, imageTransportShutdownPublisher_in *in, imageTransportShutdownPublisher_out *out)
{
    if(publisherProxies.find(in->publisherHandle) == publisherProxies.end())
    {
        throw exception("invalid publisher handle");
    }

    PublisherProxy *publisherProxy = publisherProxies[in->publisherHandle];
    publisherProxy->imageTransportPublisher.shutdown();
    publisherProxies.erase(publisherProxy->handle);
    delete publisherProxy;
}

void imageTransportPublish(SScriptCallBack *p, const char *cmd, imageTransportPublish_in *in, imageTransportPublish_out *out)
{
    if(publisherProxies.find(in->publisherHandle) == publisherProxies.end())
    {
        throw exception("invalid publisher handle");
    }

    PublisherProxy *publisherProxy = publisherProxies[in->publisherHandle];

    sensor_msgs::Image image_msg;
    image_msg.header.stamp = ros::Time::now();
    image_msg.header.frame_id = in->frame_id;
    image_msg.encoding = sensor_msgs::image_encodings::RGB8;
    image_msg.width = in->width;
    image_msg.height = in->height;
    image_msg.step = image_msg.width * 3;

    int data_len = image_msg.step * image_msg.height;
    image_msg.data.resize(data_len);
    image_msg.is_bigendian = 0;

    for(unsigned int i = 0; i < image_msg.height; i++)
    {
        int msg_idx = (image_msg.height - i - 1) * image_msg.step;
        int buf_idx = i * image_msg.step;
        for(unsigned int j = 0; j < image_msg.step; j++)
        {
            image_msg.data[msg_idx + j] = in->data[buf_idx + j];
        }
    }

    publisherProxy->imageTransportPublisher.publish(image_msg);
}

void getTime(SScriptCallBack *p, const char *cmd, getTime_in *in, getTime_out *out)
{
    if(in->flag == 0)
        out->time = ros::Time::now().toSec();
}

void getParamString(SScriptCallBack *p, const char *cmd, getParamString_in *in, getParamString_out *out)
{
    out->value = in->defaultValue;
    out->exists = ros::param::get(in->name, out->value);
}

void getParamInt(SScriptCallBack *p, const char *cmd, getParamInt_in *in, getParamInt_out *out)
{
    out->value = in->defaultValue;
    out->exists = ros::param::get(in->name, out->value);
}

void getParamDouble(SScriptCallBack *p, const char *cmd, getParamDouble_in *in, getParamDouble_out *out)
{
    out->value = in->defaultValue;
    out->exists = ros::param::get(in->name, out->value);
}

void getParamBool(SScriptCallBack *p, const char *cmd, getParamBool_in *in, getParamBool_out *out)
{
    out->value = in->defaultValue;
    out->exists = ros::param::get(in->name, out->value);
}

void setParamString(SScriptCallBack *p, const char *cmd, setParamString_in *in, setParamString_out *out)
{
    ros::param::set(in->name, in->value);
}

void setParamInt(SScriptCallBack *p, const char *cmd, setParamInt_in *in, setParamInt_out *out)
{
    ros::param::set(in->name, in->value);
}

void setParamDouble(SScriptCallBack *p, const char *cmd, setParamDouble_in *in, setParamDouble_out *out)
{
    ros::param::set(in->name, in->value);
}

void setParamBool(SScriptCallBack *p, const char *cmd, setParamBool_in *in, setParamBool_out *out)
{
    ros::param::set(in->name, in->value);
}

void hasParam(SScriptCallBack *p, const char *cmd, hasParam_in *in, hasParam_out *out)
{
    out->exists = ros::param::has(in->name);
}

void deleteParam(SScriptCallBack *p, const char *cmd, deleteParam_in *in, deleteParam_out *out)
{
    ros::param::del(in->name);
}

void searchParam(SScriptCallBack *p, const char *cmd, searchParam_in *in, searchParam_out *out)
{
    out->found = ros::param::search(in->name, out->name);
}

bool initialize()
{
    int argc = 0;
    char *argv[] = {};
    ros::init(argc, argv, "vrep_ros_interface");

    if(!ros::master::check())
        return false;

    nh = new ros::NodeHandle("~");
    tfbr = new tf::TransformBroadcaster();
    imtr = new image_transport::ImageTransport(*nh);

    return true;
}

void shutdown()
{
    ros::shutdown();

    delete imtr;
    delete tfbr;
    delete nh;
}

void shutdownTransientSubscribers(SScriptCallBack *p)
{
    std::vector<int> handles;

    for(std::map<int, SubscriberProxy *>::iterator it = subscriberProxies.begin(); it != subscriberProxies.end(); ++it)
    {
        if(it->second->destroyAfterSimulationStop)
        {
            handles.push_back(it->first);
        }
    }

    for(std::vector<int>::iterator it = handles.begin(); it != handles.end(); ++it)
    {
        SubscriberProxy *proxy = subscriberProxies[*it];
        if(proxy->subscriber)
            shutdownSubscriber(p, *it);
        if(proxy->imageTransportSubscriber)
            imageTransportShutdownSubscriber(p, *it);
    }
}

void shutdownTransientPublishers(SScriptCallBack *p)
{
    std::vector<int> handles;

    for(std::map<int, PublisherProxy *>::iterator it = publisherProxies.begin(); it != publisherProxies.end(); ++it)
    {
        if(it->second->destroyAfterSimulationStop)
        {
            handles.push_back(it->first);
        }
    }

    for(std::vector<int>::iterator it = handles.begin(); it != handles.end(); ++it)
    {
        PublisherProxy *proxy = publisherProxies[*it];
        if(proxy->publisher)
            shutdownPublisher(p, *it);
        if(proxy->imageTransportPublisher)
            imageTransportShutdownPublisher(p, *it);
    }
}

void shutdownTransientServiceClients(SScriptCallBack *p)
{
    std::vector<int> handles;

    for(std::map<int, ServiceClientProxy *>::iterator it = serviceClientProxies.begin(); it != serviceClientProxies.end(); ++it)
    {
        if(it->second->destroyAfterSimulationStop)
        {
            handles.push_back(it->first);
        }
    }

    for(std::vector<int>::iterator it = handles.begin(); it != handles.end(); ++it)
    {
        shutdownServiceClient(p, *it);
    }
}

void shutdownTransientServiceServers(SScriptCallBack *p)
{
    std::vector<int> handles;

    for(std::map<int, ServiceServerProxy *>::iterator it = serviceServerProxies.begin(); it != serviceServerProxies.end(); ++it)
    {
        if(it->second->destroyAfterSimulationStop)
        {
            handles.push_back(it->first);
        }
    }

    for(std::vector<int>::iterator it = handles.begin(); it != handles.end(); ++it)
    {
        shutdownServiceServer(p, *it);
    }
}

void shutdownTransientProxies(SScriptCallBack *p)
{
    shutdownTransientSubscribers(p);
    shutdownTransientPublishers(p);
    shutdownTransientServiceClients(p);
    shutdownTransientServiceServers(p);
}

// This is the plugin start routine (called just once, just after the plugin was loaded):
VREP_DLLEXPORT unsigned char v_repStart(void* reservedPointer,int reservedInt)
{
    // Dynamically load and bind V-REP functions:
    // ******************************************
    // 1. Figure out this plugin's directory:
    char curDirAndFile[1024];
    getcwd(curDirAndFile, sizeof(curDirAndFile));

    std::string currentDirAndPath(curDirAndFile);
    // 2. Append the V-REP library's name:
    std::string temp(currentDirAndPath);
    #ifdef _WIN32
        temp+="\\v_rep.dll";
    #elif defined (__linux)
        temp+="/libv_rep.so";
    #elif defined (__APPLE__)
        temp+="/libv_rep.dylib";
    #endif

    // 3. Load the V-REP library:
    vrepLib=loadVrepLibrary(temp.c_str());
    if (vrepLib==NULL)
    {
        std::cout << "Error, could not find or correctly load the V-REP library. Cannot start 'ROS' plugin.\n";
        return 0; // Means error, V-REP will unload this plugin
    }
    if (getVrepProcAddresses(vrepLib)==0)
    {
        std::cout << "Error, could not find all required functions in the V-REP library. Cannot start 'ROS' plugin.\n";
        unloadVrepLibrary(vrepLib);
        return 0; // Means error, V-REP will unload this plugin
    }
    // ******************************************

    // Check the version of V-REP:
    // ******************************************
    int vrepVer;
    simGetIntegerParameter(sim_intparam_program_version,&vrepVer);
    if (vrepVer<20605) // if V-REP version is smaller than 2.06.04
    {
        std::cout << "Sorry, your V-REP copy is somewhat old. Cannot start 'ROS' plugin.\n";
        unloadVrepLibrary(vrepLib);
        return 0; // Means error, V-REP will unload this plugin
    }
    // ******************************************
    

    if(!initialize()) 
    {
        std::cout << "ROS master is not running. Cannot start 'ROS' plugin.\n";
        return 0; //If the master is not running then the plugin is not loaded.
    }
    
    // Register script functions and variables:
    if(!registerScriptStuff())
    {
        return 0;
    }

    return PLUGIN_VERSION; // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
}

// This is the plugin end routine (called just once, when V-REP is ending, i.e. releasing this plugin):
VREP_DLLEXPORT void v_repEnd()
{
    shutdown();
    unloadVrepLibrary(vrepLib); // release the library
}

VREP_DLLEXPORT void * v_repMessage(int message, int *auxiliaryData, void *customData, int *replyData)
{
    static int previousStopSimulationRequestCounter = -1;
    int errorModeSaved;
    simGetIntegerParameter(sim_intparam_error_report_mode, &errorModeSaved);
    simSetIntegerParameter(sim_intparam_error_report_mode, sim_api_errormessage_ignore);
    void* retVal=NULL;

    if(message == sim_message_eventcallback_instancepass)
    {
        ros::spinOnce();
    }

    if(message == sim_message_eventcallback_mainscriptabouttobecalled)
    {
        int stopSimulationRequestCounter;
        simGetIntegerParameter(sim_intparam_stop_request_counter, &stopSimulationRequestCounter);
        simBool doNotRun = simGetBoolParameter(sim_boolparam_rosinterface_donotrunmainscript);
        if(doNotRun>0)
        {
            if(previousStopSimulationRequestCounter == -1)
                previousStopSimulationRequestCounter = stopSimulationRequestCounter;
            if(previousStopSimulationRequestCounter == stopSimulationRequestCounter)
                replyData[0] = 0; // this tells V-REP that we don't wanna execute the main script
        }
        else
            previousStopSimulationRequestCounter=-1;
    }

    if(message == sim_message_eventcallback_simulationabouttostart)
    {
        previousStopSimulationRequestCounter=-1;
    }

    if(message == sim_message_eventcallback_simulationended)
    {
        // Simulation just ended
        shutdownTransientProxies(NULL /* XXX: which SScriptCallBack struct? */);
    }

    // restore previous settings
    simSetIntegerParameter(sim_intparam_error_report_mode, errorModeSaved); 
    return retVal;
}

