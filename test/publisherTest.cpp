/**
 * @file publisherTest.cpp
 * @author Pooja Kabra
 * @brief This node runs ros test
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */
 
#include <ros/ros.h>
#include "beginner_tutorials/ChangeBaseString.h"
#include "std_msgs/String.h"
#include <ros/service_client.h>
#include <gtest/gtest.h>

/**
 * @brief tests existence of service
 */
TEST(testPublisherNode, testIfChangeBaseString) {
  ros::NodeHandle nh;
  auto client = nh.serviceClient<beginner_tutorials::ChangeBaseString>(
      "ChangeBaseString");
  EXPECT_TRUE(client.waitForExistence(ros::Duration(5)));
}
/**
 * @brief  tests if changeBaseString service replaces default text with user
 * input
 */
TEST(testPublisherNode, testPublisherDefaultMessageUpdate) {
  ros::NodeHandle nh;
  auto client = nh.serviceClient<beginner_tutorials::ChangeBaseString>(
      "ChangeBaseString");
  beginner_tutorials::ChangeBaseString srv;
  // change input string
  srv.request.inputString = "I am a test string";
  client.call(srv.request, srv.response);
  EXPECT_STREQ("I am a test string", srv.response.newString.c_str());
}
