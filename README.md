# elec6910r-ros-project
Final project using ROS and V-REP for Robot Mapping and Localization

## Setup
Our project requires several libraries and packages as follows:
- ROS kinetic, see http://wiki.ros.org/kinetic/Installation/Ubuntu
- V-REP 3.5.0
- OpenCV
- Hector slam library
\end{itemize}

In this project, we use Ubuntu 16.04 LTS operating system. 
### Prepare Workspace:
```
# install ROS kinetic from http://wiki.ros.org/kinetic/Installation/Ubuntu
# install V-REP 3.5.0 from http://www.coppeliarobotics.com/downloads.html
Prepare the workspace
# To prepare the workspace
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
source ~/.bashrc
```
### Run the project:
```
roscore

# Execute V-REP
./vrep.sh

# Load keyboard controller
rosrun project key_teleop.py

# Load the launcher 
roslaunch hector.launch
```

Demo video: https://youtu.be/n-XK24o42Oo

By
- Genta Indra Winata
- Lin Zhaojiang

Acknowledgement: 
- Prof. LIU Ming 
- TA: HUANG Kan
