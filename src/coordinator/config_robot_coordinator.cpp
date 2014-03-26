#include "config_robot_coordinator.hpp"

#include "../xml_parser/xml_parser.hpp"
#include "../modules/module.hpp"
#include "../modules/factory.hpp"
//#include "../modules/motor_wheel.hpp"
//#include "../modules/encoder.hpp"

#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/physical_calculator.hpp"
#include <QDir>
#include <QPluginLoader>

ConfigRobotCoordinator::ConfigRobotCoordinator(PhysicalCoordinator& phy_cdn, ModuleCoordinator& mod_cdn)
  : _phy_cdn(phy_cdn), _mod_cdn(mod_cdn) {

}

bool ConfigRobotCoordinator::loadRobotConfig(const QString& name, const QString& path) {
  qDebug() << "config_robot_coordinator loadRobotConfig path="<< path;
  const ObjectConfig::robotConfig* robot_cfg = XMLParser::parseRobot(path);


  QStandardItem* item = new QStandardItem(name);
  // Loading mesh
//Merge
 /*A float or an int for the weight ? See bullet*/
  //World w(_phy_cdn.getPhysicalCalculator()->getScene());
  qDebug() << "creation du robot avec nom et mesh ="<< name <<robot_cfg->mesh_path;
  //_robot_mesh[name] = new Robot(path,(float)robot_cfg->weight, PositionData(0,0,0,0,0,0),name,w);
  _robot_mesh[name] = new Robot(robot_cfg->mesh_path,robot_cfg->weight, PositionData(), name, _phy_cdn.getPhysicalCalculator()->getScene());
  int i=0;
   // Here the PMO is also created.
  // Loading microcontrollers
  foreach (const ObjectConfig::microConfig* mi,robot_cfg->microcontrollers) {
    qDebug() << "Micro " << mi->name;
    // Loading modules
    foreach (const ObjectConfig::moduleConfig* mo,mi->modules) {
      qDebug() << "Nouveau module "<< mo->name;
      Module* mod = loadModule(_robot_mesh[name], mo);
      if(mod != NULL) {
        _mod_cdn.addModule(name, mo->name, mod);
        item->setChild(i++,mod->getGuiItem());
      }
    }
  }
  emit newRobot(item); // add the robot to the gui list of robots.
  return true;
}

Module* ConfigRobotCoordinator::loadModule(Robot* robot, const ObjectConfig::moduleConfig* moduleConf) {
  Module* ret = 0;

  QDir plugDir = QDir("./");
  QString file = QString("lib")+moduleConf->type+".so";
  qDebug() << file << plugDir.exists(file);
  if(plugDir.exists(file)) {
    qDebug() << "Factory " << moduleConf->type << "trouvé";
    QPluginLoader loader(plugDir.absoluteFilePath(file));
    QObject* plugin = loader.instance();
    qDebug() << plugin << plugDir.absoluteFilePath(file) << loader.errorString();
    if(plugin) {
      Factory* m = qobject_cast<Factory*>(plugin);
      m->setWorld(Mesh::getWorld());
      ret = m->buildModule(robot, moduleConf);
    }
  }
  return ret;
}

bool ConfigRobotCoordinator::bindRobot(const QString& name, const QString& path){
    //TODO
    return true;
}
