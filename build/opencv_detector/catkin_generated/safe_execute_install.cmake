execute_process(COMMAND "/home/genta/Desktop/robotics_project/catkin_ws/build/opencv_detector/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/genta/Desktop/robotics_project/catkin_ws/build/opencv_detector/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
