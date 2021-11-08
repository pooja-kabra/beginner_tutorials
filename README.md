# beginner_tutorials

This project is basic implementation of interfacing of publisher and suscriber node programmed in c++. ROS Melodic has been used. The dependencies given while building package are:
-roscpp
-rospy
-std_msgs
-message_generations
-genmsg

To run publisher and suscriber nodes, in catkin_ws:

$ catkin build 
$ source devel/setup.bash
$ roscore

Open new tab, run (publisher and subscriber at once):
$ roslaunch beginner_tutorials nodes.launch my_rate:= <your rate here>

Open new tab, run rosservice:
$ rosservice call /ChangeBaseString "<your text here>"

Open new tab, run:
$ rqt_console
