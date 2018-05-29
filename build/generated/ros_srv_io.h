#ifndef VREP_ROS_PLUGIN__ROS_SRV_IO__H
#define VREP_ROS_PLUGIN__ROS_SRV_IO__H

#include <ros_msg_builtin_io.h>
#include <ros/ros.h>
#include <vrep_ros_interface.h>

#include <dynamic_reconfigure/Reconfigure.h>
#include <roscpp/Empty.h>
#include <roscpp/GetLoggers.h>
#include <roscpp/SetLoggerLevel.h>
#include <std_srvs/Empty.h>
#include <std_srvs/Trigger.h>


void write__dynamic_reconfigure__ReconfigureRequest(const dynamic_reconfigure::ReconfigureRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__ReconfigureRequest(int stack, dynamic_reconfigure::ReconfigureRequest *msg, const ReadOptions *opt = NULL);

void write__dynamic_reconfigure__ReconfigureResponse(const dynamic_reconfigure::ReconfigureResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__dynamic_reconfigure__ReconfigureResponse(int stack, dynamic_reconfigure::ReconfigureResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__dynamic_reconfigure__Reconfigure(dynamic_reconfigure::Reconfigure::Request& req, dynamic_reconfigure::Reconfigure::Response& res, ServiceServerProxy *proxy);

void write__roscpp__EmptyRequest(const roscpp::EmptyRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__EmptyRequest(int stack, roscpp::EmptyRequest *msg, const ReadOptions *opt = NULL);

void write__roscpp__EmptyResponse(const roscpp::EmptyResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__EmptyResponse(int stack, roscpp::EmptyResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__roscpp__Empty(roscpp::Empty::Request& req, roscpp::Empty::Response& res, ServiceServerProxy *proxy);

void write__roscpp__GetLoggersRequest(const roscpp::GetLoggersRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__GetLoggersRequest(int stack, roscpp::GetLoggersRequest *msg, const ReadOptions *opt = NULL);

void write__roscpp__GetLoggersResponse(const roscpp::GetLoggersResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__GetLoggersResponse(int stack, roscpp::GetLoggersResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__roscpp__GetLoggers(roscpp::GetLoggers::Request& req, roscpp::GetLoggers::Response& res, ServiceServerProxy *proxy);

void write__roscpp__SetLoggerLevelRequest(const roscpp::SetLoggerLevelRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__SetLoggerLevelRequest(int stack, roscpp::SetLoggerLevelRequest *msg, const ReadOptions *opt = NULL);

void write__roscpp__SetLoggerLevelResponse(const roscpp::SetLoggerLevelResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__roscpp__SetLoggerLevelResponse(int stack, roscpp::SetLoggerLevelResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__roscpp__SetLoggerLevel(roscpp::SetLoggerLevel::Request& req, roscpp::SetLoggerLevel::Response& res, ServiceServerProxy *proxy);

void write__std_srvs__EmptyRequest(const std_srvs::EmptyRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__std_srvs__EmptyRequest(int stack, std_srvs::EmptyRequest *msg, const ReadOptions *opt = NULL);

void write__std_srvs__EmptyResponse(const std_srvs::EmptyResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__std_srvs__EmptyResponse(int stack, std_srvs::EmptyResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__std_srvs__Empty(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res, ServiceServerProxy *proxy);

void write__std_srvs__TriggerRequest(const std_srvs::TriggerRequest& msg, int stack, const WriteOptions *opt = NULL);

void read__std_srvs__TriggerRequest(int stack, std_srvs::TriggerRequest *msg, const ReadOptions *opt = NULL);

void write__std_srvs__TriggerResponse(const std_srvs::TriggerResponse& msg, int stack, const WriteOptions *opt = NULL);

void read__std_srvs__TriggerResponse(int stack, std_srvs::TriggerResponse *msg, const ReadOptions *opt = NULL);

bool ros_srv_callback__std_srvs__Trigger(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res, ServiceServerProxy *proxy);


#endif // VREP_ROS_PLUGIN__ROS_SRV_IO__H
