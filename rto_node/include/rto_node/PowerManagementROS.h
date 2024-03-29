/*
 * PowerManagementROS.h
 *
 *  Created on: 07.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef POWERMANAGEMENTROS_H_
#define POWERMANAGEMENTROS_H_

#include "rec/robotino/api2/PowerManagement.h"

#include "rclcpp/rclcpp.hpp"
#include "rto_msgs/msg/power_readings.hpp"

class PowerManagementROS: public rec::robotino::api2::PowerManagement
{
public:
	PowerManagementROS(rclcpp::Node* parent_node);
	~PowerManagementROS();

	void setTimeStamp(rclcpp::Time stamp);


private:
	rclcpp::Publisher<rto_msgs::msg::PowerReadings>::SharedPtr power_pub_;

	rto_msgs::msg::PowerReadings power_msg_;

	rclcpp::Time stamp_;

	void readingsEvent(float current, float voltage);
};
#endif /* POWERMANAGEMENTROS_H_ */
