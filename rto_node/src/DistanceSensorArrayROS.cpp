/*
 * DistanceSensorArrayROS.cpp
 *
 *  Created on: 07.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "DistanceSensorArrayROS.h"
#include <cmath>

DistanceSensorArrayROS::DistanceSensorArrayROS(rclcpp::Node* parent_node)
{
	distances_pub_ = parent_node->create_publisher<sensor_msgs::msg::PointCloud>("distance_sensors", 10);
}

DistanceSensorArrayROS::~DistanceSensorArrayROS()
{
}

void DistanceSensorArrayROS::setTimeStamp(rclcpp::Time stamp)
{
	stamp_ = stamp;
}

void DistanceSensorArrayROS::distancesChangedEvent(const float* distances, unsigned int size)
{
	// Build the PointCloud msg
	distances_msg_.header.stamp = stamp_;
	distances_msg_.header.frame_id = "base_link";
	distances_msg_.points.resize(size);

	for(unsigned int i = 0; i < size; ++i)
	{
		// 0.698 radians = 40 Degrees
		// 0.2 is the radius of the robot
		distances_msg_.points[i].x = ( distances[i] + 0.2 ) * cos(0.698 * i);
		distances_msg_.points[i].y = ( distances[i] + 0.2 ) * sin(0.698 * i);
		distances_msg_.points[i].z = 0.05; // 5cm above ground
	}

	// Publish the msg
	distances_pub_->publish(distances_msg_);
}
