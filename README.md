# elec6910r-ros-project
Final project using ROS and V-REP for Robot Mapping and Localization.

## Demo video
https://youtu.be/n-XK24o42Oo

## Setup
In this project, we use Ubuntu 16.04 LTS operating system. 

Our project requires several libraries and packages as follows:
- ROS kinetic, see http://wiki.ros.org/kinetic/Installation/Ubuntu
- V-REP 3.5.0
- OpenCV
- Hector slam library

## Additional Libraries
```
# install hector-slam
sudo apt install ros-kinetic-hector-slam
```

## Prepare Workspace:
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
## Run the project:
```
roscore

# Execute V-REP
./vrep.sh

# Load keyboard controller
rosrun project key_teleop.py

# Load the launcher 
roslaunch hector.launch
```

## Features

### Ros graph
<img src="images/rosgraph.png" width="400"/>

### Keyboard control
Our code is based on key_teleop.py script. We changed the speed and the publisher node.

<img src="images/keyboard.png" width="400"/>

```
# Load keyboard controller
rosrun project key_teleop.py
```

### Visual Servo
We added some heuristics for object tracking.

<img src="images/visual_servoing.png" width="400"/>

### Face recognition
In this example, we use President Obama's face.

<img src="images/face_detection.png" width="400"/>

#### Authors
- Genta Indra Winata (gentaindrawinata@gmail.com / giwinata@connect.ust.hk)
- Lin Zhaojiang (zlinao@connect.ust.hk)

#### Acknowledgement
- Prof. LIU Ming 
- TA: HUANG Kan
- We also thank Chien-Sheng Wu for the assistance
