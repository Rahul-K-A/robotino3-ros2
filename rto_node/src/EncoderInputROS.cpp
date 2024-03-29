/*
 * EncoderInputROS.cpp
 *
 *  Created on: 09.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "EncoderInputROS.h"
using std::placeholders::_1;
using std::placeholders::_2;


EncoderInputROS::EncoderInputROS(rclcpp::Node* parent_node)
{
	encoder_pub_ = parent_node->create_publisher<rto_msgs::msg::EncoderReadings>("encoder_readings", 10);
	encoder_position_server_ = parent_node->create_service<rto_msgs::srv::SetEncoderPosition>("set_encoder_position", std::bind(&EncoderInputROS::setEncoderPositionCallback, this, _1, _2));
}


EncoderInputROS::~EncoderInputROS()
{
}

void EncoderInputROS::setTimeStamp(rclcpp::Time stamp)
{
	stamp_ = stamp;
}

void EncoderInputROS::readingsChangedEvent( int velocity, int position, float current )
{
	// Build the EncoderReadings msg
	encoder_msg_.stamp = stamp_;
	encoder_msg_.velocity = velocity;
	encoder_msg_.position = position;
	encoder_msg_.current = current;

	// Publish the msg
	encoder_pub_->publish( encoder_msg_ );
}

void EncoderInputROS::setEncoderPositionCallback(
		const rto_msgs::srv::SetEncoderPosition::Request::SharedPtr req,
		const rto_msgs::srv::SetEncoderPosition::Response::SharedPtr res)
{
	setPosition( req->position, req->velocity );

}
