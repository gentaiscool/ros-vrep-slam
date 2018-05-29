Building the ROS plugin:
=========================

What you need:
    - C++ compiler
    - v_repStubsGen (available from https://github.com/fferri/v_repStubsGen)
        - Python interpreter (2.7 or greater)
        - lxml package for Python
        - tempita package for Python
    - An XSLT Processor, such as SAXON (needed for generating documentation)

Build steps:

    NOTE: the directory containing all files (i.e. package.xml etc) must be called
          vrep_ros_interface, otherwise build will fail.

    1) Edit meta/messages.txt and meta/services.txt if you need to include more ROS messages/services.
       You need to specify the full message/service type, i.e. geometry_msgs/Twist rather than Twist.

    2) obtain v_repStubsGen:

        > mkdir external
        > cd external
        > git clone https://github.com/fferri/v_repStubsGen.git
        > export PYTHONPATH=$PYTHONPATH:$PWD

    2) Compile the plugin using catkin tools:

        > catkin build

    3) (optional) generate documentation with an XSLT processor:

        > saxon -s:callbacks.xml -a:on -o:reference.html

        The callbacks.xml document can be viewed directly into the browser.
        Any modern browser will do the XSLT processing automatically.


