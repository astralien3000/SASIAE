#ifndef WHEEL_NODE_HPP
#define WHEEL_NODE_HPP

#include <ros/ros.h>
#include <ros/timer.h>

#include <phy_api/set_torque.h>

#include "../physical_calculator/robot/wheel.hpp"


class WheelNode {
private:
    ros::NodeHandle _node;

    // Services
    ros::ServiceServer _set_torque_service;

    // Topics
    ros::Publisher _torque_publisher;
    ros::Publisher _rotation_publisher;

    // Timers
    ros::Timer _timer;

    Wheel* _wheel;

public:

    bool setTorqueService(phy_api::set_torque::Request& req,
                          phy_api::set_torque::Response&  res);

    void onTimerTick(const ros::TimerEvent&);

public:

    WheelNode(Wheel* wheel);
};

#endif//WHEEL_NODE_HPP
