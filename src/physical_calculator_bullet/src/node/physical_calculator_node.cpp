#include "physical_calculator_node.hpp"

#include "wheel_node.hpp"

#include "../physical_calculator/physical_calculator.hpp"

#include "../physical_calculator/scene/simple_scene.hpp"
#include "../physical_calculator/scene/scene.hpp"

#include "../physical_calculator/robot/robot.hpp"
#include "../physical_calculator/robot/wheel.hpp"

static inline std::string namespace_name(std::string name) {
    std::stringstream ss;
    ss << ros::this_node::getName() << "/" << name;
    return ss.str();
}

PhysicalCalculatorNode::PhysicalCalculatorNode(void)
    : _node("~") {

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

    MyRobot* bot = new MyRobot("mmieww", req.mesh, req.mass, btVector3(req.position[0], req.position[1], req.position[2]));
    new WheelNode(new Wheel("w1", *bot, btVector3(-25,3,0), btVector3(0,-1,0), 3.0));
    new WheelNode(new Wheel("w2", *bot, btVector3(25,3,0), btVector3(0,-1,0), 3.0));

    return true;
}
