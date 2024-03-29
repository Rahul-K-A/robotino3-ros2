/*
 * RTONode.h
 *
 *  Created on: 09.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef ROBOTINOODOMETRYNODE_H_
#define ROBOTINOODOMETRYNODE_H_

#include "ComROS.h"
#include "OdometryROS.h"

#include "rclcpp/rclcpp.hpp"

class RTOOdometryNode: public rclcpp::Node
{
public:
	RTOOdometryNode();
	~RTOOdometryNode();


private:
	void spin();

	rclcpp::TimerBase::SharedPtr timer_;
	std::string hostname_;

	ComROS com_;
	OdometryROS odometry_;

	void initModules();
};

#endif /* ROBOTINOODOMETRYNODE_H_ */
