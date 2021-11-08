/**
 * @file publisher.cpp
 * @author Pooja Kabra
 * @brief This file publishes the data in string format
 * @version 0.1
 * @date 2021-11-01
 *
 * @copyright Copyright (c) 2021
 *
 */

/**
 * including ros headers
 */
#include <ros/ros.h>

#include <std_msgs/String.h>
#include "../include/publisher.hpp"
#include "beginner_tutorials/ChangeBaseString.h"
#include <sstream>

DefaultString obj;

bool newMessage(beginner_tutorials::ChangeBaseString::Request &requestService, beginner_tutorials::ChangeBaseString::Response &responseClient) {
  obj.default_msg = requestService.inputString;
  ROS_WARN_STREAM("The user changed the string");
  responseClient.newString = requestService.inputString;
  return true;
}
/**
 * @brief This is the main function where node is created named publisher.
 * @brief It publishes data on chatter topic in the string format
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  auto server = n.advertiseService("ChangeBaseString", newMessage);


  double rate;
  n.getParam("/my_rate", rate);
  if(rate <= 500 && rate > 0)
  {
    ROS_DEBUG_STREAM("Loop Rate Received from roslaunch argument is " << rate);
  }
  else if(rate > 500){
    ROS_ERROR_STREAM("Loop Rate is too high");
    ROS_WARN_STREAM("Setting the loop rate to default value of 10 Hz");
    rate = 10;
  }
  else if(rate < 0){
    ROS_ERROR_STREAM("Loop Rate cannot be negative");
    ROS_WARN_STREAM("Setting the loop rate to default value of 10 Hz");
    rate = 10;
  }
  else if(rate == 0){
    ROS_FATAL_STREAM("Loop Rate cannot be zero");
    ROS_WARN_STREAM("Setting the loop rate to default value of 10 Hz");
    rate = 10;
  }
  ros::Rate loop_rate(rate);
  
  while (ros::ok()) {

  	std_msgs::String msg;

  	std::string msg_data;
    msg_data = obj.default_msg;
    msg.data = msg_data;
    ROS_INFO_STREAM(msg_data);
    chatter_pub.publish(msg);



    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

