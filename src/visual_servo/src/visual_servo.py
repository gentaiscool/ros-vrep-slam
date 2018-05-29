#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

## Simple talker demo that listens to std_msgs/Strings published 
## to the 'chatter' topic
import cv2
import rospy
import random
from std_msgs.msg import String, Bool, Float32
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from geometry_msgs.msg import Twist
import numpy as np


class visual_servo():
    def __init__(self):
    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
        self.lowerBound = np.array([16,39,50])
        self.upperBound = np.array([45,255,255])    

        self.app = SimpleKeyTeleop()
        rospy.Subscriber('vrep/image', Image, self.callback, queue_size=1)
        pub = rospy.Publisher('/vrep/laser_switch', Bool, queue_size=1)
        pub.publish("true")
        self.bridge = CvBridge()


    def callback(self, data):
        #rospy.loginfo(rospy.get_caller_id() + 'I got image')
        cv_img = self.bridge.imgmsg_to_cv2(data, "bgr8")

        m_x, m_y, ar = self.image_info(cv_img)
        linear, angular = self.imginfo_movement(m_x, m_y, ar)
        self.app._set_velocity(linear, angular)
        self.app._publish()

    def image_info(self, img): 
        m_x = 0.0
        m_y = 0.0
        area_ratio = 0.0
        counter = 0
        imgHSV = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(imgHSV,self.lowerBound,self.upperBound)

        kernelOpen=np.ones((8,8))
        kernelClose=np.ones((25,25))
        maskOpen=cv2.morphologyEx(mask,cv2.MORPH_OPEN,kernelOpen)
        maskClose=cv2.morphologyEx(maskOpen,cv2.MORPH_CLOSE,kernelClose)
        cv2.imshow("Mask Camera",maskClose)
        cv2.waitKey(1)
	maskFinal=maskClose
	img3,conts,hi =cv2.findContours(maskFinal.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_NONE)
        img1=img

        h = 0
        w = 0
    	if conts:
             x,y,w,h=cv2.boundingRect(conts[0])
    	     cv2.rectangle(img1,(x,y),(x+w,y+h),(0,0,255), 2)
             m_x2 = (x+w+x)/2
             m_y2 = (y+y+h)/2
             area_ratio = (float(h*w))/(512*512)
        else:
             m_x2 = 0
             m_y2 = 0

        cv2.imshow("Camera",img1)
        cv2.waitKey(1)

        if area_ratio:
            print("ball is found! go to the ball, area_ratio:", area_ratio)
        return m_x2, m_y2, area_ratio

    def imginfo_movement(self, m_x, m_y, ar):    
        linear = 0.0
        angular = 0.0

        if ar:
            angular = float(m_x - 256)*(0.7)/256
	    if ar < 0.05:
		linear = 0.6
		if angular > 0:
			angular = 0.1
		else:
			angular = -0.1
	    elif ar > 0.1:
                linear = -2
	else:
	    if random.random() < 0.5:
		angular = 3
		linear = 0
            else:
		angular = -3
                linear = 1
	
        print("m_x", m_x, "angular", angular, "linear", linear)
        return linear, angular 

class SimpleKeyTeleop():
    def __init__(self):
        self._pub_cmd = rospy.Publisher('/vrep_ros_interface/key_vel', Twist, queue_size=1)

        self._forward_rate = rospy.get_param('~forward_rate', 8)
        self._backward_rate = rospy.get_param('~backward_rate', 5)
        self._rotation_rate = rospy.get_param('~rotation_rate', 1.0)
        self._angular = 0
        self._linear = 0


    def run(self):
        self._running = True
        while self._running:
            #self._set_velocity()
            self._publish()
            rate.sleep()

    def _get_twist(self, linear, angular):
        twist = Twist()
        twist.linear.x = linear
        twist.angular.z = angular
        return twist

    def _set_velocity(self, linear, angular):
        self._angular = angular
        self._linear = linear

    def _publish(self):
        twist = self._get_twist(self._linear, self._angular)
        self._pub_cmd.publish(twist)


if __name__ == '__main__':
    rospy.init_node('visual_servo')
    vs = visual_servo()
    rospy.spin()

