cmake_minimum_required(VERSION 2.8.3)
project(dlib_detector)

find_package(catkin REQUIRED COMPONENTS
  roscpp rospy std_msgs sensor_msgs genmsg geometry_msgs visualization_msgs nodelet tf image_geometry cv_bridge detection_msgs
)

catkin_package(
   CATKIN_DEPENDS message_runtime
)
SET(DBUILD_TIFF "ON")
SET(DLIB_VERSION "18.18")

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/dlib/cmake")
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/dlib-extracted")
    file(DOWNLOAD "http://dlib.net/files/dlib-${DLIB_VERSION}.tar.bz2" "${CMAKE_CURRENT_SOURCE_DIR}/dlib.tar.bz2")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xjf ${CMAKE_CURRENT_SOURCE_DIR}/dlib.tar.bz2
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/dlib-extracted"
    )
    file(REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/dlib.tar.bz2")
    file(RENAME "${CMAKE_CURRENT_SOURCE_DIR}/dlib-extracted/dlib-${DLIB_VERSION}/dlib" "${CMAKE_CURRENT_SOURCE_DIR}/dlib")
    file(REMOVE_RECURSE "${CMAKE_CURRENT_SOURCE_DIR}/dlib-extracted")
endif()

include(dlib/cmake)

include_directories(include
	${catkin_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS}
)

option(USE_AVX_INSTRUCTIONS  "Compile your program with AVX instructions" OFF)

IF(USE_AVX_INSTRUCTIONS)
  add_definitions(-mavx)
  add_definitions(-march=native)
ENDIF()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(object_detector src/object_detector.cpp)
target_link_libraries(object_detector ${catkin_LIBRARIES} dlib )
target_link_libraries(object_detector /usr/lib/x86_64-linux-gnu/libtiff.so.5)

add_executable(face_detector src/face_detector.cpp)
target_link_libraries(face_detector ${catkin_LIBRARIES} dlib)
target_link_libraries(face_detector /usr/lib/x86_64-linux-gnu/libtiff.so.5)

add_executable(object_detector_trainer src/object_detector_trainer.cpp)
target_link_libraries(object_detector_trainer ${catkin_LIBRARIES} dlib)
