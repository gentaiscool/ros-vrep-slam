// This file is part of the ROS PLUGIN for V-REP
// 
// Copyright 2006-2017 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// A big thanks to Svetlin Penkov for his precious help!
// 
// The ROS PLUGIN is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The ROS PLUGIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// THE ROS PLUGIN IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the ROS PLUGIN.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.4.0 rev. 1 on April 5th 2017

#ifndef V_REPEXTROS_H
#define V_REPEXTROS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <boost/lexical_cast.hpp>

#include <ros/ros.h>
#include <image_transport/image_transport.h>

#define VREP_DLLEXPORT extern "C"

// The 3 required entry points of the V-REP plugin:
VREP_DLLEXPORT unsigned char v_repStart(void* reservedPointer,int reservedInt);
VREP_DLLEXPORT void v_repEnd();
VREP_DLLEXPORT void* v_repMessage(int message,int* auxiliaryData,void* customData,int* replyData);

struct ScriptCallback
{
    int scriptId;
    std::string name;
};

struct Proxy
{
    bool destroyAfterSimulationStop;
};

#include <ros_msg_builtin_io.h>

struct SubscriberProxy : Proxy
{
    int handle;
    std::string topicName;
    std::string topicType;
    ScriptCallback topicCallback;
    ros::Subscriber subscriber;
    image_transport::Subscriber imageTransportSubscriber;
    WriteOptions wr_opt;
};

struct PublisherProxy : Proxy
{
    int handle;
    std::string topicName;
    std::string topicType;
    ros::Publisher publisher;
    image_transport::Publisher imageTransportPublisher;
    ReadOptions rd_opt;
};

struct ServiceClientProxy : Proxy
{
    int handle;
    std::string serviceName;
    std::string serviceType;
    ros::ServiceClient client;
    ReadOptions rd_opt;
    WriteOptions wr_opt;
};

struct ServiceServerProxy : Proxy
{
    int handle;
    std::string serviceName;
    std::string serviceType;
    ScriptCallback serviceCallback;
    ros::ServiceServer server;
    ReadOptions rd_opt;
    WriteOptions wr_opt;
};

#include <stubs.h>
#include <ros_msg_io.h>
#include <ros_srv_io.h>

#include <v_repLib.h>

#endif
