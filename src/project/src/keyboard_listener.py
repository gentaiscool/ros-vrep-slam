#!/usr/bin/env python
import getch
import rospy
from std_msgs.msg import String #String message 
from std_msgs.msg import Int8
from geometry_msgs.msg import Twist

speed = 2
angle = 120

PI = 3.1415926535897

# angular_speed = speed*2*PI/360
angular_speed = speed / 2
relative_angle = angle*2*PI/360

rospy.init_node('keyboard_controller', anonymous=True)
velocity_publisher = rospy.Publisher('/vrep_ros_interface/key_vel', Twist, queue_size=10)

def move(k):
	vel_msg = Twist()
	if k == 65: #up
		vel_msg.linear.x = speed
		vel_msg.linear.y = 0
		vel_msg.linear.z = 0
		vel_msg.angular.x = 0
		vel_msg.angular.y = 0
		vel_msg.angular.z = 0

		velocity_publisher.publish(vel_msg)
	elif k == 68: #left
		vel_msg.linear.x = angular_speed
		vel_msg.linear.y = 0
		vel_msg.linear.z = 0
		vel_msg.angular.x = 0
		vel_msg.angular.y = 0
		vel_msg.angular.z = relative_angle

		velocity_publisher.publish(vel_msg)
	elif k == 66: #bottom
		vel_msg.linear.x = -speed
		vel_msg.linear.y = 0
		vel_msg.linear.z = 0
		vel_msg.angular.x = 0
		vel_msg.angular.y = 0
		vel_msg.angular.z = 0

		velocity_publisher.publish(vel_msg)
	elif k == 67: #right
		vel_msg.linear.x = angular_speed
		vel_msg.linear.y = 0
		vel_msg.linear.z = 0
		vel_msg.angular.x = 0
		vel_msg.angular.y = 0
		vel_msg.angular.z = -relative_angle

		velocity_publisher.publish(vel_msg)

def keys():
    rate = rospy.Rate(10)#try removing this line ans see what happens
    while not rospy.is_shutdown():
        k=ord(getch.getch())# this is used to convert the keypress event in the keyboard or joypad , joystick to a ord value

        if ((k>=65)&(k<=68)|(k==115)|(k==97)):# to filter only the up , dowm ,left , right key /// this line can be removed or more key can be added to this
            rospy.loginfo(str(k))# to print on  terminal 
            move(k)
        elif (k==113):
        	break
        #rospy.loginfo(str(k))

        rate.sleep()

#s=115,e=101,g=103,b=98

if __name__=='__main__':
    try:
        keys()
    except rospy.ROSInterruptException:
		pass
