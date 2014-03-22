#include "config_robot_coordinator.hpp"

#include "xml_parser/xml_parser.hpp"

#include "../modules/motor_wheel.hpp"
#include "../modules/encoder.hpp"

#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/physical_calculator.hpp"

ConfigRobotCoordinator::ConfigRobotCoordinator(PhysicalCoordinator& phy_cdn, ModuleCoordinator& mod_cdn)
  : _phy_cdn(phy_cdn), _mod_cdn(mod_cdn) {
  
}

bool ConfigRobotCoordinator::loadRobotConfig(const QString& name, const QString& path) {
  const ObjectConfig::robotConfig* robot_cfg = XMLParser::parseRobot(path);

  // Loading mesh
//Merge
 /*A float or an int for the weight ? See bullet*/
  //World w(_phy_cdn.getPhysicalCalculator()->getScene());
  //_robot_mesh[name] = new Robot(path,(float)robot_cfg->weight, PositionData(0,0,0,0,0,0),name,w);
  _robot_mesh[name] = new Robot(path,robot_cfg->weight, PositionData(), name, _phy_cdn.getPhysicalCalculator()->getScene());

  // Loading microcontrollers
  foreach (const ObjectConfig::microConfig* mi,robot_cfg->microcontrollers) {
    // Loading modules
    foreach (const ObjectConfig::moduleConfig* mo,mi->modules) {
      Module* mod = loadModule(mo);
      _mod_cdn.addModule(name, mo->name, mod);
    }
  }
  return true;
}

Module* ConfigRobotCoordinator::loadModule(const ObjectConfig::moduleConfig* moduleConf) {
  Module* ret = 0;
  
  

  return ret;
}

bool ConfigRobotCoordinator::bindRobot(const QString& name, const QString& path){
    //TODO
    return true;
}
