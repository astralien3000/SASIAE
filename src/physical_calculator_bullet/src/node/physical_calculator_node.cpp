#include "physical_calculator_node.hpp"

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/scene/simple_scene.hpp"
#include "../physical_calculator/scene/scene.hpp"

static inline std::string namespace_name(std::string name) {
  std::stringstream ss;
  ss << ros::this_node::getName() << "/" << name;
  return ss.str();
}

PhysicalCalculatorNode::PhysicalCalculatorNode(void)
  : _node("physical_calculator") {

  _create_world_service = 
    _node.advertiseService("create_world", &PhysicalCalculatorNode::createWorld, this);

  _create_robot_service = 
    _node.advertiseService("create_robot", &PhysicalCalculatorNode::createRobot, this);

  ROS_INFO("READY");
}

bool PhysicalCalculatorNode::createWorld(phy_api::create_world::Request& req, phy_api::create_world::Response&  res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create world : %s", req.mesh.c_str());

//  _physical_calculator->simple_scene_walls(300);
  new SimpleScene("test", 300);
  MyPhysicalCalculator::getIntance().start();

  return true;
}

bool PhysicalCalculatorNode::createRobot(phy_api::create_robot::Request& req, phy_api::create_robot::Response&  res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create robot : %s", req.mesh.c_str());
  
//  PositionData pos;
//  pos.x = 0.0;
//  pos.y = 0.0;
//  pos.z = 0.0;
//  pos.alpha = 0.0;
//  pos.beta  = 0.0;
//  pos.gamma = 0.0;

//  ObjectConfig::meshConfig cfg = {
//    "/home/astralien3000/SASIAE/ressources/stl/robot1.stl",
//    0.1,
//    pos
//  };

//  World w = _physical_calculator->getScene();
//  Mesh::setWorld(w);

//  Robot* robot = new Robot(w, cfg, 1.0, pos);

  new Scene("mmieww", "/home/astralien3000/SASIAE/ressources/stl/robot1.stl");
  
  return true;
}
