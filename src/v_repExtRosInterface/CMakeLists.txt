cmake_minimum_required(VERSION 2.8.3)
project(vrep_ros_interface)

find_package(
	catkin
	REQUIRED COMPONENTS
	roscpp
	rosmsg
	image_transport
	tf
	cv_bridge
	control_msgs
	diagnostic_msgs
	map_msgs
	nav_msgs
	pcl_msgs
	shape_msgs
	tf2_geometry_msgs
	tf2_sensor_msgs
	visualization_msgs
	)

if(NOT DEFINED ENV{VREP_ROOT})
	message(FATAL_ERROR "Environment variable \$VREP_ROOT is not set. Please set it to point to the root directory of V-REP.")
endif()

catkin_package(
	CATKIN_DEPENDS
	roscpp
	rosconsole
	cv_bridge
	image_transport
	tf
	#brics_actuator
	roslib
	actionlib_msgs
	control_msgs
	diagnostic_msgs
	geometry_msgs
	map_msgs
	nav_msgs
	pcl_msgs
	sensor_msgs
	shape_msgs
	std_msgs
	tf2_geometry_msgs
	tf2_msgs
	tf2_sensor_msgs 
	trajectory_msgs
	visualization_msgs
	DEPENDS
	roscpp
	rosconsole
	cv_bridge
	image_transport
	tf
	#brics_actuator
	roslib
	actionlib_msgs
	control_msgs
	diagnostic_msgs
	geometry_msgs
	map_msgs
	nav_msgs
	pcl_msgs
	sensor_msgs
	shape_msgs
	std_msgs
	tf2_geometry_msgs
	tf2_msgs
	tf2_sensor_msgs
	trajectory_msgs
	visualization_msgs
	)

file(
	MAKE_DIRECTORY
	${CMAKE_BINARY_DIR}/generated
	)
# file(
# 	MAKE_DIRECTORY
# 	${CMAKE_BINARY_DIR}/doc
# 	)

include_directories(
	include
	${CMAKE_BINARY_DIR}/generated
	${catkin_INCLUDE_DIRS}
	$ENV{VREP_ROOT}/programming/include
	$ENV{VREP_ROOT}/programming/common
	)

#link_directories("/opt/ros/fuerte/lib")
#link_directories("/opt/ros/groovy/lib")
#link_directories("/opt/ros/hydro/lib")
#link_directories("/opt/ros/indigo/lib")
#link_directories("/opt/ros/jade/lib")
link_directories("/opt/ros/kinetic/lib")

add_custom_command(
	OUTPUT
    ${CMAKE_BINARY_DIR}/generated/adv.cpp
	${CMAKE_BINARY_DIR}/generated/pub.cpp
	${CMAKE_BINARY_DIR}/generated/ros_msg_io.cpp
	${CMAKE_BINARY_DIR}/generated/ros_msg_io.h
	${CMAKE_BINARY_DIR}/generated/ros_srv_io.cpp
	${CMAKE_BINARY_DIR}/generated/ros_srv_io.h
	${CMAKE_BINARY_DIR}/generated/srvcall.cpp
	${CMAKE_BINARY_DIR}/generated/srvcli.cpp
	${CMAKE_BINARY_DIR}/generated/srvsrv.cpp
	${CMAKE_BINARY_DIR}/generated/sub.cpp
    COMMAND
	python
	${CMAKE_CURRENT_SOURCE_DIR}/tools/generate_ros_stuff.py
	${CMAKE_CURRENT_SOURCE_DIR}/meta/messages.txt
	${CMAKE_CURRENT_SOURCE_DIR}/meta/services.txt
	${CMAKE_BINARY_DIR}/generated/
    DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/meta/messages.txt
	${CMAKE_CURRENT_SOURCE_DIR}/meta/services.txt
	${CMAKE_CURRENT_SOURCE_DIR}/tools/generate_ros_stuff.py
	)

if((EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include/stubs.h) AND (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/stubs.cpp))
	MESSAGE(STATUS "*** Using the prebuilt stubs (stubs.h and stubs.cpp) ***")
	add_library(
		v_repExtRosInterface
		src/vrep_ros_interface.cpp
		src/stubs.cpp
		src/ros_msg_builtin_io.cpp
		${CMAKE_BINARY_DIR}/generated/ros_msg_io.cpp
		${CMAKE_BINARY_DIR}/generated/ros_srv_io.cpp
		src/v_repLib_inc.cpp
		)
else()
	MESSAGE(STATUS "*** Generating the stubs (stubs.h and stubs.cpp) ***")
	add_custom_command(
		OUTPUT
		${CMAKE_BINARY_DIR}/generated/stubs.cpp 
		${CMAKE_BINARY_DIR}/generated/stubs.h
		COMMAND 
		python -m ${CMAKE_CURRENT_SOURCE_DIR}/v_repStubsGen 
		-H ${CMAKE_BINARY_DIR}/generated/stubs.h 
		-C ${CMAKE_BINARY_DIR}/generated/stubs.cpp 
		${CMAKE_CURRENT_SOURCE_DIR}/meta/callbacks.xml
		DEPENDS 
		${CMAKE_CURRENT_SOURCE_DIR}/meta/callbacks.xml
		)
	add_library(
		v_repExtRosInterface 
		src/vrep_ros_interface.cpp 
		generated/stubs.cpp 
		src/ros_msg_builtin_io.cpp 
		generated/ros_msg_io.cpp 
		generated/ros_srv_io.cpp 
		src/v_repLib_inc.cpp
		)
endif()

# we don't generate documentation
#if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/doc/reference.html)
	#find_program(SAXON_PROGRAM saxon)
	#if(SAXON_PROGRAM)
		#MESSAGE(STATUS "*** Generating doc/reference.html ***")
		#add_custom_command(
			#OUTPUT
			#${CMAKE_BINARY_DIR}/doc/reference.html
			#COMMAND 
			#${SAXON_PROGRAM} 
			#-s:${CMAKE_CURRENT_SOURCE_DIR}/meta/callbacks.xml 
			#-a:on -o:${CMAKE_BINARY_DIR}/doc/reference.html
			#DEPENDS 
			#${CMAKE_CURRENT_SOURCE_DIR}/meta/callbacks.xml
			#)
		#add_custom_target(
			#gendoc 
			#ALL 
			#DEPENDS 
			#${CMAKE_BINARY_DIR}/doc/reference.html
			#)
	#else()
		#MESSAGE(WARNING "'saxon' not available - will not generate documentation.")
	#endif()
#endif()

add_dependencies(
	v_repExtRosInterface 
	${catkin_EXPORTED_TARGETS}
	)
target_link_libraries(
	v_repExtRosInterface
    pthread
    dl
    roslib
    rosconsole
    rostime
    rospack
    roscpp_serialization
    roscpp
    tf
    image_transport
    boost_system
	${catkin_LIBRARIES}
	)
