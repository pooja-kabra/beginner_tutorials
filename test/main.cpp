 /**
 * @file main.cpp
 * @author Pooja Kabra
 * @brief This file runs all tests
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <ros/ros.h>
#include <gtest/gtest.h>

/**
 * @brief  main function for calling tests
 * @param  argc int
 * @param  argv character array
 * @return 0 on successful exit
 */

int main(int argc, char** argv) {
    ros::init(argc, argv, "publisherTest");
    testing::InitGoogleTest(&argc, argv);
    ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}
