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


void read__bool(int stack, bool *value);
void read__int(int stack, int *value);
void read__float(int stack, float *value);
void read__double(int stack, double *value);
void read__std__string(int stack, std::string *value);
void write__bool(bool value, int stack);
void write__int(int value, int stack);
void write__float(float value, int stack);
void write__double(double value, int stack);
void write__std__string(std::string value, int stack);

bool registerScriptStuff();

struct subscribe_in
{
    std::string topicName;
    std::string topicType;
    std::string topicCallback;
    int queueSize;
    subscribe_in();
};

struct subscribe_out
{
    int subscriberHandle;
    subscribe_out();
};

void subscribe(SScriptCallBack *p, subscribe_in *in, subscribe_out *out);
int subscribe(SScriptCallBack *p, std::string topicName, std::string topicType, std::string topicCallback, int queueSize = 1);
void subscribe(SScriptCallBack *p, subscribe_out *out, std::string topicName, std::string topicType, std::string topicCallback, int queueSize = 1);
void subscribe_callback(SScriptCallBack *p);

struct shutdownSubscriber_in
{
    int subscriberHandle;
    shutdownSubscriber_in();
};

struct shutdownSubscriber_out
{
    shutdownSubscriber_out();
};

void shutdownSubscriber(SScriptCallBack *p, shutdownSubscriber_in *in, shutdownSubscriber_out *out);
void shutdownSubscriber(SScriptCallBack *p, int subscriberHandle);
void shutdownSubscriber(SScriptCallBack *p, shutdownSubscriber_out *out, int subscriberHandle);
void shutdownSubscriber_callback(SScriptCallBack *p);

struct subscriberTreatUInt8ArrayAsString_in
{
    int subscriberHandle;
    subscriberTreatUInt8ArrayAsString_in();
};

struct subscriberTreatUInt8ArrayAsString_out
{
    subscriberTreatUInt8ArrayAsString_out();
};

void subscriberTreatUInt8ArrayAsString(SScriptCallBack *p, subscriberTreatUInt8ArrayAsString_in *in, subscriberTreatUInt8ArrayAsString_out *out);
void subscriberTreatUInt8ArrayAsString(SScriptCallBack *p, int subscriberHandle);
void subscriberTreatUInt8ArrayAsString(SScriptCallBack *p, subscriberTreatUInt8ArrayAsString_out *out, int subscriberHandle);
void subscriberTreatUInt8ArrayAsString_callback(SScriptCallBack *p);

struct advertise_in
{
    std::string topicName;
    std::string topicType;
    int queueSize;
    bool latch;
    advertise_in();
};

struct advertise_out
{
    int publisherHandle;
    advertise_out();
};

void advertise(SScriptCallBack *p, advertise_in *in, advertise_out *out);
int advertise(SScriptCallBack *p, std::string topicName, std::string topicType, int queueSize = 1, bool latch = false);
void advertise(SScriptCallBack *p, advertise_out *out, std::string topicName, std::string topicType, int queueSize = 1, bool latch = false);
void advertise_callback(SScriptCallBack *p);

struct shutdownPublisher_in
{
    int publisherHandle;
    shutdownPublisher_in();
};

struct shutdownPublisher_out
{
    shutdownPublisher_out();
};

void shutdownPublisher(SScriptCallBack *p, shutdownPublisher_in *in, shutdownPublisher_out *out);
void shutdownPublisher(SScriptCallBack *p, int publisherHandle);
void shutdownPublisher(SScriptCallBack *p, shutdownPublisher_out *out, int publisherHandle);
void shutdownPublisher_callback(SScriptCallBack *p);

struct publisherTreatUInt8ArrayAsString_in
{
    int publisherHandle;
    publisherTreatUInt8ArrayAsString_in();
};

struct publisherTreatUInt8ArrayAsString_out
{
    publisherTreatUInt8ArrayAsString_out();
};

void publisherTreatUInt8ArrayAsString(SScriptCallBack *p, publisherTreatUInt8ArrayAsString_in *in, publisherTreatUInt8ArrayAsString_out *out);
void publisherTreatUInt8ArrayAsString(SScriptCallBack *p, int publisherHandle);
void publisherTreatUInt8ArrayAsString(SScriptCallBack *p, publisherTreatUInt8ArrayAsString_out *out, int publisherHandle);
void publisherTreatUInt8ArrayAsString_callback(SScriptCallBack *p);

struct publish_in
{
    int publisherHandle;
    publish_in();
};

struct publish_out
{
    publish_out();
};

void publish(SScriptCallBack *p, publish_in *in, publish_out *out);
void publish(SScriptCallBack *p, int publisherHandle);
void publish(SScriptCallBack *p, publish_out *out, int publisherHandle);
void publish_callback(SScriptCallBack *p);

struct serviceClient_in
{
    std::string serviceName;
    std::string serviceType;
    serviceClient_in();
};

struct serviceClient_out
{
    int serviceClientHandle;
    serviceClient_out();
};

void serviceClient(SScriptCallBack *p, serviceClient_in *in, serviceClient_out *out);
int serviceClient(SScriptCallBack *p, std::string serviceName, std::string serviceType);
void serviceClient(SScriptCallBack *p, serviceClient_out *out, std::string serviceName, std::string serviceType);
void serviceClient_callback(SScriptCallBack *p);

struct shutdownServiceClient_in
{
    int serviceClientHandle;
    shutdownServiceClient_in();
};

struct shutdownServiceClient_out
{
    shutdownServiceClient_out();
};

void shutdownServiceClient(SScriptCallBack *p, shutdownServiceClient_in *in, shutdownServiceClient_out *out);
void shutdownServiceClient(SScriptCallBack *p, int serviceClientHandle);
void shutdownServiceClient(SScriptCallBack *p, shutdownServiceClient_out *out, int serviceClientHandle);
void shutdownServiceClient_callback(SScriptCallBack *p);

struct serviceClientTreatUInt8ArrayAsString_in
{
    int serviceClientHandle;
    serviceClientTreatUInt8ArrayAsString_in();
};

struct serviceClientTreatUInt8ArrayAsString_out
{
    serviceClientTreatUInt8ArrayAsString_out();
};

void serviceClientTreatUInt8ArrayAsString(SScriptCallBack *p, serviceClientTreatUInt8ArrayAsString_in *in, serviceClientTreatUInt8ArrayAsString_out *out);
void serviceClientTreatUInt8ArrayAsString(SScriptCallBack *p, int serviceClientHandle);
void serviceClientTreatUInt8ArrayAsString(SScriptCallBack *p, serviceClientTreatUInt8ArrayAsString_out *out, int serviceClientHandle);
void serviceClientTreatUInt8ArrayAsString_callback(SScriptCallBack *p);

struct call_in
{
    int serviceClientHandle;
    call_in();
};

struct call_out
{
    call_out();
};

void call(SScriptCallBack *p, call_in *in, call_out *out);
void call(SScriptCallBack *p, int serviceClientHandle);
void call(SScriptCallBack *p, call_out *out, int serviceClientHandle);
void call_callback(SScriptCallBack *p);

struct advertiseService_in
{
    std::string serviceName;
    std::string serviceType;
    std::string serviceCallback;
    advertiseService_in();
};

struct advertiseService_out
{
    int serviceServerHandle;
    advertiseService_out();
};

void advertiseService(SScriptCallBack *p, advertiseService_in *in, advertiseService_out *out);
int advertiseService(SScriptCallBack *p, std::string serviceName, std::string serviceType, std::string serviceCallback);
void advertiseService(SScriptCallBack *p, advertiseService_out *out, std::string serviceName, std::string serviceType, std::string serviceCallback);
void advertiseService_callback(SScriptCallBack *p);

struct shutdownServiceServer_in
{
    int serviceServerHandle;
    shutdownServiceServer_in();
};

struct shutdownServiceServer_out
{
    shutdownServiceServer_out();
};

void shutdownServiceServer(SScriptCallBack *p, shutdownServiceServer_in *in, shutdownServiceServer_out *out);
void shutdownServiceServer(SScriptCallBack *p, int serviceServerHandle);
void shutdownServiceServer(SScriptCallBack *p, shutdownServiceServer_out *out, int serviceServerHandle);
void shutdownServiceServer_callback(SScriptCallBack *p);

struct serviceServerTreatUInt8ArrayAsString_in
{
    int serviceServerHandle;
    serviceServerTreatUInt8ArrayAsString_in();
};

struct serviceServerTreatUInt8ArrayAsString_out
{
    serviceServerTreatUInt8ArrayAsString_out();
};

void serviceServerTreatUInt8ArrayAsString(SScriptCallBack *p, serviceServerTreatUInt8ArrayAsString_in *in, serviceServerTreatUInt8ArrayAsString_out *out);
void serviceServerTreatUInt8ArrayAsString(SScriptCallBack *p, int serviceServerHandle);
void serviceServerTreatUInt8ArrayAsString(SScriptCallBack *p, serviceServerTreatUInt8ArrayAsString_out *out, int serviceServerHandle);
void serviceServerTreatUInt8ArrayAsString_callback(SScriptCallBack *p);

struct sendTransform_in
{
    sendTransform_in();
};

struct sendTransform_out
{
    sendTransform_out();
};

void sendTransform(SScriptCallBack *p, sendTransform_in *in, sendTransform_out *out);
void sendTransform(SScriptCallBack *p);
void sendTransform(SScriptCallBack *p, sendTransform_out *out);
void sendTransform_callback(SScriptCallBack *p);

struct sendTransforms_in
{
    sendTransforms_in();
};

struct sendTransforms_out
{
    sendTransforms_out();
};

void sendTransforms(SScriptCallBack *p, sendTransforms_in *in, sendTransforms_out *out);
void sendTransforms(SScriptCallBack *p);
void sendTransforms(SScriptCallBack *p, sendTransforms_out *out);
void sendTransforms_callback(SScriptCallBack *p);

struct imageTransportSubscribe_in
{
    std::string topicName;
    std::string topicCallback;
    int queueSize;
    imageTransportSubscribe_in();
};

struct imageTransportSubscribe_out
{
    int subscriberHandle;
    imageTransportSubscribe_out();
};

void imageTransportSubscribe(SScriptCallBack *p, imageTransportSubscribe_in *in, imageTransportSubscribe_out *out);
int imageTransportSubscribe(SScriptCallBack *p, std::string topicName, std::string topicCallback, int queueSize = 1);
void imageTransportSubscribe(SScriptCallBack *p, imageTransportSubscribe_out *out, std::string topicName, std::string topicCallback, int queueSize = 1);
void imageTransportSubscribe_callback(SScriptCallBack *p);

struct imageTransportShutdownSubscriber_in
{
    int subscriberHandle;
    imageTransportShutdownSubscriber_in();
};

struct imageTransportShutdownSubscriber_out
{
    imageTransportShutdownSubscriber_out();
};

void imageTransportShutdownSubscriber(SScriptCallBack *p, imageTransportShutdownSubscriber_in *in, imageTransportShutdownSubscriber_out *out);
void imageTransportShutdownSubscriber(SScriptCallBack *p, int subscriberHandle);
void imageTransportShutdownSubscriber(SScriptCallBack *p, imageTransportShutdownSubscriber_out *out, int subscriberHandle);
void imageTransportShutdownSubscriber_callback(SScriptCallBack *p);

struct imageTransportAdvertise_in
{
    std::string topicName;
    int queueSize;
    imageTransportAdvertise_in();
};

struct imageTransportAdvertise_out
{
    int publisherHandle;
    imageTransportAdvertise_out();
};

void imageTransportAdvertise(SScriptCallBack *p, imageTransportAdvertise_in *in, imageTransportAdvertise_out *out);
int imageTransportAdvertise(SScriptCallBack *p, std::string topicName, int queueSize = 1);
void imageTransportAdvertise(SScriptCallBack *p, imageTransportAdvertise_out *out, std::string topicName, int queueSize = 1);
void imageTransportAdvertise_callback(SScriptCallBack *p);

struct imageTransportShutdownPublisher_in
{
    int publisherHandle;
    imageTransportShutdownPublisher_in();
};

struct imageTransportShutdownPublisher_out
{
    imageTransportShutdownPublisher_out();
};

void imageTransportShutdownPublisher(SScriptCallBack *p, imageTransportShutdownPublisher_in *in, imageTransportShutdownPublisher_out *out);
void imageTransportShutdownPublisher(SScriptCallBack *p, int publisherHandle);
void imageTransportShutdownPublisher(SScriptCallBack *p, imageTransportShutdownPublisher_out *out, int publisherHandle);
void imageTransportShutdownPublisher_callback(SScriptCallBack *p);

struct imageTransportPublish_in
{
    int publisherHandle;
    std::string data;
    int width;
    int height;
    std::string frame_id;
    imageTransportPublish_in();
};

struct imageTransportPublish_out
{
    imageTransportPublish_out();
};

void imageTransportPublish(SScriptCallBack *p, imageTransportPublish_in *in, imageTransportPublish_out *out);
void imageTransportPublish(SScriptCallBack *p, int publisherHandle, std::string data, int width, int height, std::string frame_id);
void imageTransportPublish(SScriptCallBack *p, imageTransportPublish_out *out, int publisherHandle, std::string data, int width, int height, std::string frame_id);
void imageTransportPublish_callback(SScriptCallBack *p);

struct getTime_in
{
    int flag;
    getTime_in();
};

struct getTime_out
{
    double time;
    getTime_out();
};

void getTime(SScriptCallBack *p, getTime_in *in, getTime_out *out);
double getTime(SScriptCallBack *p, int flag = 0);
void getTime(SScriptCallBack *p, getTime_out *out, int flag = 0);
void getTime_callback(SScriptCallBack *p);

struct getParamString_in
{
    std::string name;
    std::string defaultValue;
    getParamString_in();
};

struct getParamString_out
{
    bool exists;
    std::string value;
    getParamString_out();
};

void getParamString(SScriptCallBack *p, getParamString_in *in, getParamString_out *out);
void getParamString(SScriptCallBack *p, getParamString_out *out, std::string name, std::string defaultValue = "");
void getParamString_callback(SScriptCallBack *p);

struct getParamInt_in
{
    std::string name;
    int defaultValue;
    getParamInt_in();
};

struct getParamInt_out
{
    bool exists;
    int value;
    getParamInt_out();
};

void getParamInt(SScriptCallBack *p, getParamInt_in *in, getParamInt_out *out);
void getParamInt(SScriptCallBack *p, getParamInt_out *out, std::string name, int defaultValue = 0);
void getParamInt_callback(SScriptCallBack *p);

struct getParamDouble_in
{
    std::string name;
    double defaultValue;
    getParamDouble_in();
};

struct getParamDouble_out
{
    bool exists;
    double value;
    getParamDouble_out();
};

void getParamDouble(SScriptCallBack *p, getParamDouble_in *in, getParamDouble_out *out);
void getParamDouble(SScriptCallBack *p, getParamDouble_out *out, std::string name, double defaultValue = 0.0);
void getParamDouble_callback(SScriptCallBack *p);

struct getParamBool_in
{
    std::string name;
    bool defaultValue;
    getParamBool_in();
};

struct getParamBool_out
{
    bool exists;
    bool value;
    getParamBool_out();
};

void getParamBool(SScriptCallBack *p, getParamBool_in *in, getParamBool_out *out);
void getParamBool(SScriptCallBack *p, getParamBool_out *out, std::string name, bool defaultValue = false);
void getParamBool_callback(SScriptCallBack *p);

struct setParamString_in
{
    std::string name;
    std::string value;
    setParamString_in();
};

struct setParamString_out
{
    setParamString_out();
};

void setParamString(SScriptCallBack *p, setParamString_in *in, setParamString_out *out);
void setParamString(SScriptCallBack *p, std::string name, std::string value);
void setParamString(SScriptCallBack *p, setParamString_out *out, std::string name, std::string value);
void setParamString_callback(SScriptCallBack *p);

struct setParamInt_in
{
    std::string name;
    int value;
    setParamInt_in();
};

struct setParamInt_out
{
    setParamInt_out();
};

void setParamInt(SScriptCallBack *p, setParamInt_in *in, setParamInt_out *out);
void setParamInt(SScriptCallBack *p, std::string name, int value);
void setParamInt(SScriptCallBack *p, setParamInt_out *out, std::string name, int value);
void setParamInt_callback(SScriptCallBack *p);

struct setParamDouble_in
{
    std::string name;
    double value;
    setParamDouble_in();
};

struct setParamDouble_out
{
    setParamDouble_out();
};

void setParamDouble(SScriptCallBack *p, setParamDouble_in *in, setParamDouble_out *out);
void setParamDouble(SScriptCallBack *p, std::string name, double value);
void setParamDouble(SScriptCallBack *p, setParamDouble_out *out, std::string name, double value);
void setParamDouble_callback(SScriptCallBack *p);

struct setParamBool_in
{
    std::string name;
    bool value;
    setParamBool_in();
};

struct setParamBool_out
{
    setParamBool_out();
};

void setParamBool(SScriptCallBack *p, setParamBool_in *in, setParamBool_out *out);
void setParamBool(SScriptCallBack *p, std::string name, bool value);
void setParamBool(SScriptCallBack *p, setParamBool_out *out, std::string name, bool value);
void setParamBool_callback(SScriptCallBack *p);

struct hasParam_in
{
    std::string name;
    hasParam_in();
};

struct hasParam_out
{
    bool exists;
    hasParam_out();
};

void hasParam(SScriptCallBack *p, hasParam_in *in, hasParam_out *out);
bool hasParam(SScriptCallBack *p, std::string name);
void hasParam(SScriptCallBack *p, hasParam_out *out, std::string name);
void hasParam_callback(SScriptCallBack *p);

struct deleteParam_in
{
    std::string name;
    deleteParam_in();
};

struct deleteParam_out
{
    deleteParam_out();
};

void deleteParam(SScriptCallBack *p, deleteParam_in *in, deleteParam_out *out);
void deleteParam(SScriptCallBack *p, std::string name);
void deleteParam(SScriptCallBack *p, deleteParam_out *out, std::string name);
void deleteParam_callback(SScriptCallBack *p);

struct searchParam_in
{
    std::string name;
    searchParam_in();
};

struct searchParam_out
{
    bool found;
    std::string name;
    searchParam_out();
};

void searchParam(SScriptCallBack *p, searchParam_in *in, searchParam_out *out);
void searchParam(SScriptCallBack *p, searchParam_out *out, std::string name);
void searchParam_callback(SScriptCallBack *p);

struct subscriberCallback_in
{
    subscriberCallback_in();
};

struct subscriberCallback_out
{
    subscriberCallback_out();
};

void subscriberCallback(simInt scriptId, const char *func);

bool subscriberCallback(simInt scriptId, const char *func, subscriberCallback_in *in_args, subscriberCallback_out *out_args);

struct imageTransportCallback_in
{
    std::string data;
    int width;
    int height;
    imageTransportCallback_in();
};

struct imageTransportCallback_out
{
    imageTransportCallback_out();
};

void imageTransportCallback(simInt scriptId, const char *func, std::string data, int width, int height);

bool imageTransportCallback(simInt scriptId, const char *func, imageTransportCallback_in *in_args, imageTransportCallback_out *out_args);


// following functions must be implemented in the plugin

void subscribe(SScriptCallBack *p, const char *cmd, subscribe_in *in, subscribe_out *out);
void shutdownSubscriber(SScriptCallBack *p, const char *cmd, shutdownSubscriber_in *in, shutdownSubscriber_out *out);
void subscriberTreatUInt8ArrayAsString(SScriptCallBack *p, const char *cmd, subscriberTreatUInt8ArrayAsString_in *in, subscriberTreatUInt8ArrayAsString_out *out);
void advertise(SScriptCallBack *p, const char *cmd, advertise_in *in, advertise_out *out);
void shutdownPublisher(SScriptCallBack *p, const char *cmd, shutdownPublisher_in *in, shutdownPublisher_out *out);
void publisherTreatUInt8ArrayAsString(SScriptCallBack *p, const char *cmd, publisherTreatUInt8ArrayAsString_in *in, publisherTreatUInt8ArrayAsString_out *out);
void publish(SScriptCallBack *p, const char *cmd, publish_in *in, publish_out *out);
void serviceClient(SScriptCallBack *p, const char *cmd, serviceClient_in *in, serviceClient_out *out);
void shutdownServiceClient(SScriptCallBack *p, const char *cmd, shutdownServiceClient_in *in, shutdownServiceClient_out *out);
void serviceClientTreatUInt8ArrayAsString(SScriptCallBack *p, const char *cmd, serviceClientTreatUInt8ArrayAsString_in *in, serviceClientTreatUInt8ArrayAsString_out *out);
void call(SScriptCallBack *p, const char *cmd, call_in *in, call_out *out);
void advertiseService(SScriptCallBack *p, const char *cmd, advertiseService_in *in, advertiseService_out *out);
void shutdownServiceServer(SScriptCallBack *p, const char *cmd, shutdownServiceServer_in *in, shutdownServiceServer_out *out);
void serviceServerTreatUInt8ArrayAsString(SScriptCallBack *p, const char *cmd, serviceServerTreatUInt8ArrayAsString_in *in, serviceServerTreatUInt8ArrayAsString_out *out);
void sendTransform(SScriptCallBack *p, const char *cmd, sendTransform_in *in, sendTransform_out *out);
void sendTransforms(SScriptCallBack *p, const char *cmd, sendTransforms_in *in, sendTransforms_out *out);
void imageTransportSubscribe(SScriptCallBack *p, const char *cmd, imageTransportSubscribe_in *in, imageTransportSubscribe_out *out);
void imageTransportShutdownSubscriber(SScriptCallBack *p, const char *cmd, imageTransportShutdownSubscriber_in *in, imageTransportShutdownSubscriber_out *out);
void imageTransportAdvertise(SScriptCallBack *p, const char *cmd, imageTransportAdvertise_in *in, imageTransportAdvertise_out *out);
void imageTransportShutdownPublisher(SScriptCallBack *p, const char *cmd, imageTransportShutdownPublisher_in *in, imageTransportShutdownPublisher_out *out);
void imageTransportPublish(SScriptCallBack *p, const char *cmd, imageTransportPublish_in *in, imageTransportPublish_out *out);
void getTime(SScriptCallBack *p, const char *cmd, getTime_in *in, getTime_out *out);
void getParamString(SScriptCallBack *p, const char *cmd, getParamString_in *in, getParamString_out *out);
void getParamInt(SScriptCallBack *p, const char *cmd, getParamInt_in *in, getParamInt_out *out);
void getParamDouble(SScriptCallBack *p, const char *cmd, getParamDouble_in *in, getParamDouble_out *out);
void getParamBool(SScriptCallBack *p, const char *cmd, getParamBool_in *in, getParamBool_out *out);
void setParamString(SScriptCallBack *p, const char *cmd, setParamString_in *in, setParamString_out *out);
void setParamInt(SScriptCallBack *p, const char *cmd, setParamInt_in *in, setParamInt_out *out);
void setParamDouble(SScriptCallBack *p, const char *cmd, setParamDouble_in *in, setParamDouble_out *out);
void setParamBool(SScriptCallBack *p, const char *cmd, setParamBool_in *in, setParamBool_out *out);
void hasParam(SScriptCallBack *p, const char *cmd, hasParam_in *in, hasParam_out *out);
void deleteParam(SScriptCallBack *p, const char *cmd, deleteParam_in *in, deleteParam_out *out);
void searchParam(SScriptCallBack *p, const char *cmd, searchParam_in *in, searchParam_out *out);

#endif // STUBS_H__INCLUDED
