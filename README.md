# beginner_tutorials

This project is basic implementation of interfacing of publisher and suscriber node programmed in c++. ROS Melodic has been used. The dependencies given while building package are:
-roscpp
-rospy
-std_msgs
-message_generations
-genmsg

# To run publisher and suscriber nodes, in catkin_ws:

$ catkin build 
$ source devel/setup.bash
$ roscore

# Open new tab, run (publisher and subscriber at once):
$ roslaunch beginner_tutorials nodes.launch my_rate:= <your rate here>

# Open new tab, run rosservice:
$ rosservice call /ChangeBaseString "<your text here>"

# To check logging, open new tab, run:
$ rqt_console

# to run rosservice
rosservice call /changeBaseString "<text>"

# to check logging
$ rqt_console


# to check tf: 
$ roslaunch beginner_tutorials nodes.launch $ rosrun tf tf_echo /world /talk

# to check tf tree
$ rosrun rqt_tf_tree rqt_tf_tree


# to check ros tests: 
$ rosrun beginner_tutorials publisherTest


# to record rosbag
$ source /devel/setup.bash 
$ roslaunch beginner_tutorials nodes.launch 
$ rosrun beginner_tutorials subscriber 
$ cd /src/beginner_tutorials/results 
$ rosbag record -a 
(Rename the .bag file to rosbagg.bag)


# to play rosbag: 
cd /src/beginner_tutorials/results rosbag play rosbagg.bag rosbag info rosbagg.bag
