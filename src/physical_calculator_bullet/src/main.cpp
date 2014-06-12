#include <ros/ros.h>
#include <phy_api/create_world.h>

#include <sstream>
#include <boost/thread.hpp>

#include "view/view_demo.hpp"
#include "node/physical_calculator_node.hpp"

PhysicalCalculator physical_calculator;
BasicDemo ccdDemo(physical_calculator);

void view_thread(void) {
  glutmain(0, NULL,1024,600,"SASIAE TEST",&ccdDemo);
}

bool go = true;

void main_thread(void) {
  while(go) {
    float ms = ccdDemo.getDeltaTimeMicroseconds();
    physical_calculator.nextStep(ms/1000000.f,2000);
  }
}

void spin_thread(void) {
  ros::spin();
}

bool createWorld(phy_api::create_world::Request& req, phy_api::create_world::Response&  res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create world : %s", req.mesh.c_str());
  //_physical_calculator->simple_scene_walls(300);
  return true;
}


int main(int argc, char* argv[]) {
  ccdDemo.myinit();

  ros::init(argc, argv, "physical_calculator");

  PhysicalCalculatorNode physical_calculator_node(physical_calculator);

  boost::thread my_spin_thread(&spin_thread);
  boost::thread my_view_thread(&view_thread);
  boost::thread my_main_thread(&main_thread);

  my_view_thread.join();
  ros::shutdown();
  my_spin_thread.join();

  return 0;
}
