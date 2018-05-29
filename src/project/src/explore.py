#!/usr/bin/env python

import rospy
import random
from std_msgs.msg import String, Bool, Float32
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
import numpy as np

if __name__ == '__main__':
    rospy.init_node('visual_servo')
    while(True):
	
	if random.random() < 0.7:
	    angular = 3
            linear = 0
        else:
	    angular = -3
            linear = 1
	twist = Twist()
        
	twist.linear.x = linear
        twist.angular.z = angular
	self._pub_cmd.publish(twist)

	
    rospy.spin()

