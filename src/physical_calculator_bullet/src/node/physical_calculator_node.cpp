#include "physical_calculator_node.hpp"

#include "../physical_calculator/physical_calculator.hpp"

static inline std::string namespace_name(std::string name) {
  std::stringstream ss;
  ss << ros::this_node::getName() << "/" << name;
  return ss.str();
}

PhysicalCalculatorNode::PhysicalCalculatorNode(PhysicalCalculator& pc) 
  : _physical_calculator(&pc), _node("physical_calculator") {

  _create_world_service = 
    _node.advertiseService("create_world", &PhysicalCalculatorNode::createWorld, this);

  _create_robot_service = 
    _node.advertiseService("create_robot", &PhysicalCalculatorNode::createRobot, this);

  ROS_INFO("READY");
}

bool PhysicalCalculatorNode::createWorld(phy_api::create_world::Request& req, phy_api::create_world::Response&  res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create world : %s", req.mesh.c_str());

  _physical_calculator->simple_scene_walls(300);

  return true;
}

bool PhysicalCalculatorNode::createRobot(phy_api::create_robot::Request& req, phy_api::create_robot::Response&  res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create robot : %s", req.mesh.c_str());
  
  
  
  return true;
}
