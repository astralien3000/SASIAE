#include "config_robot_coordinator.hpp"

#include "xml_parser/xml_parser.hpp"

#include "../modules/motor_wheel.hpp"
#include "../modules/encoder.hpp"

ConfigRobotCoordinator::ConfigRobotCoordinator(PhysicalCoordinator& phy_cdn, ModuleCoordinator& mod_cdn)
  : _phy_cdn(phy_cdn), _mod_cdn(mod_cdn) {
  
}

bool ConfigRobotCoordinator::loadRobotConfig(const QString& name, const QString& path) {
  auto robot_cfg = XMLParser::parseRobot(path);

  // Loading mesh
  // TODO : transform mesh into robot !
  _robot_mesh[name] = _phy_cdn.loadMesh(robot_cfg->mesh_path);
  
  // Loading microcontrollers
  for(auto mi = robot_cfg->microcontrollers->begin() ; mi != robot_cfg->microcontrollers->end() ; ++mi) {
    // Loading modules
    for(auto mo = (*mi)->modules->begin() ; mo != (*mi)->modules->end() ; ++mo) {
      Module* mod = loadModule((*mo)->name);
      _mod_cdn.addModule(name, (*mo)->name, mod);
    }
  }
}

Module* ConfigRobotCoordinator::loadModule(const QString& name) {
  Module* ret = 0;

  if(name == "motor") {
    Wheel* w = new Wheel(_robot_mesh[name], btVector3(16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
    ret = new MotorWheel(w, "", this);
  }
  else if(name == "encoder") {
    Wheel* w = new Wheel(_robot_mesh[name], btVector3(19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);
    ret = new Encoder(w, "", this);
  }

  return ret;
}
