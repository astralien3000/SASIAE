#ifndef CONFIG_ROBOT_COORDINATOR_HPP
#define CONFIG_ROBOT_COORDINATOR_HPP

#include "robot_coordinator.hpp"
#include "physical_coordinator.hpp"
#include "module_coordinator.hpp"

#include "../common/object_config.hpp"
#include <QStandardItem>

class Module;
class Robot;

//! \brief Load robot from an XML Config
/*!
  
  Load all the meshs, process, modules to simulate a robot.

 */
class ConfigRobotCoordinator : public RobotCoordinator {
  Q_OBJECT;

signals:
  //! \brief Inform that a new module has been created
  void newRobot(QStandardItem* m);

public slots:
  //! \brief Load a robot
  //! \param name : the name of the robot
  //! \param path : the path to the XML file
  bool loadRobotConfig(const QString& name, const QString& path);
  
  //! \brief Load a Robot binary, and bind it to modules
  bool bindRobot(const QString& name, const QString& path);

private:
  //! \brief Load a module
  //! \param name : The name that identify the module to be loaded
  Module* loadModule(Robot* robot, const ObjectConfig::moduleConfig* moduleConf);

public:
  //! \brief Constructor
  ConfigRobotCoordinator(PhysicalCoordinator&, ModuleCoordinator&);

private:
  PhysicalCoordinator& _phy_cdn;
  ModuleCoordinator& _mod_cdn;

  QHash<QString, Robot*> _robot_mesh;
};

#endif//CONFIG_ROBOT_COORDINATOR_HPP
