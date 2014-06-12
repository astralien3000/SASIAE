#include <ros/ros.h>
#include <phy_api/create_world.h>

#include <sstream>
#include <boost/thread.hpp>

#include "view_demo.hpp"

std::string namespace_name(std::string name) {
  std::stringstream ss;
  ss << ros::this_node::getName() << "/" << name;
  return ss.str();
}

BasicDemo ccdDemo;

bool create_world(phy_api::create_world::Request&  req,
		  phy_api::create_world::Response& res) {
  res.state = std::string("OK");
  ROS_INFO("Try to create world : %s", req.mesh.c_str());
  ccdDemo.initPhysics();
  return true;
}

extern int myargc;
extern char** myargv;

void spin_thread(void) {
  ros::spin();
}

int main(int argc, char* argv[]) {
  myargc = argc;
  myargv = argv;

  fprintf(stderr,"after declaration");
  ccdDemo.myinit();
  //ccdDemo.initPhysics();

  ros::init(argc, argv, "physical_calculator");

  ros::NodeHandle node;
  
  ros::ServiceServer create_world_service = 
    node.advertiseService(namespace_name("create_world"), create_world);
  
  ROS_INFO("READY !!");
  boost::thread my_spin_thread(&spin_thread);

  glutmain(argc, argv,1024,600,"SASIAE TEST",&ccdDemo);

  ros::shutdown();
  my_spin_thread.join();

  return 0;
}
