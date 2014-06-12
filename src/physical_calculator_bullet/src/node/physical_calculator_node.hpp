#ifndef PHYSICAL_CALCULATOR_NODE_HPP
#define PHYSICAL_CALCULATOR_NODE_HPP

#include <ros/ros.h>

#include <phy_api/create_world.h>
#include <phy_api/create_robot.h>
#include <phy_api/create_wheel.h>

class PhysicalCalculator;


class PhysicalCalculatorNode {
private:
  PhysicalCalculator* _physical_calculator;

  ros::NodeHandle _node;

  ros::ServiceServer _create_world_service;
  ros::ServiceServer _create_robot_service;
  ros::ServiceServer _create_wheel_service;

public:

  bool createWorld(phy_api::create_world::Request& req,
		   phy_api::create_world::Response&  res);

  bool createRobot(phy_api::create_robot::Request& req,
		   phy_api::create_robot::Response&  res);
  
  bool createWheel(phy_api::create_wheel::Request& req,
		   phy_api::create_wheel::Response&  res);

public:
  PhysicalCalculatorNode(PhysicalCalculator& pc);
};

#endif//PHYSICAL_CALCULATOR_NODE_HPP
