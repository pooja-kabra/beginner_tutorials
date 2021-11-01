# beginner_tutorials

This project is basic implementation of interfacing of publisher and suscriber node programmed in c++. ROS Melodic has been used. The dependencies given while building package are:
-roscpp
-rospy
-std_msgs


To run publisher and suscriber nodes, in catkin_ws:

$ catkin build 
$ source devel/setup.bash
$ roscore

Open new tab, run:
$ source devel/setup.bash
$ rosrun begginer_tutorials publisher

Open one more new tab, run:
$ source devel/setup.bash
$ rosrun begginer_tutorials suscriber
