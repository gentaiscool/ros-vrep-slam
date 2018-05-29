cmake_minimum_required(VERSION 2.8.3)
project(opencv_detector)

find_package(catkin REQUIRED COMPONENTS
  roscpp rospy std_msgs sensor_msgs image_transport cv_bridge genmsg geometry_msgs visualization_msgs tf detection_msgs
)

catkin_python_setup()

catkin_package(CATKIN_DEPENDS message_runtime)

install(PROGRAMS src/detector DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

