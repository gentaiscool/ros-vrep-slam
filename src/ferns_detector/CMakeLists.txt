cmake_minimum_required(VERSION 2.8.3)
project(ferns_detector)
set(CMAKE_BUILD_TYPE debug)
find_package(catkin REQUIRED COMPONENTS std_msgs image_transport cv_bridge genmsg)

find_package(OpenCV 3.0.0 REQUIRED)
message("OpenCV version: $(OpenCV_VERSION)")

add_message_files(DIRECTORY msg FILES Detection.msg DetectedPoint.msg ModelStatus.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package()

FILE(GLOB FERNS_ALL_C src/ferns/*.cc)

include_directories(include ${catkin_INCLUDE_DIRS} src/ferns)

add_library(ferns SHARED ${FERNS_ALL_C})

add_executable(detector src/detector.cpp )

add_executable(trainer src/trainer.cpp )

add_executable(tester src/tester.cpp )

target_link_libraries(ferns ${catkin_LIBRARIES})
target_link_libraries(detector ferns ${catkin_LIBRARIES})
target_link_libraries(trainer ferns ${catkin_LIBRARIES})
target_link_libraries(tester ferns ${catkin_LIBRARIES})

target_link_libraries(ferns ${OpenCV_LIBRARIES})
target_link_libraries(detector ${OpenCV_LIBRARIES})
target_link_libraries(trainer ${OpenCV_LIBRARIES})
target_link_libraries(tester ${OpenCV_LIBRARIES})

ADD_DEPENDENCIES(detector ${${PROJECT_NAME}_EXPORTED_TARGETS})

install(TARGETS detector trainer
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

install(TARGETS ferns
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

