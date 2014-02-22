#ifndef MODULE_COORDINATOR_HPP
#define MODULE_COORDINATOR_HPP

#include <QHash>
#include <QPair>
#include <QString>

class Module;

//! \brief Manage modules
/*!
  
  Contains the list of active modules with their names.
  Forward mesages to the right module.

 */
class ModuleCoordinator {
  Q_OBJECT;

signals:
  //! \brief Ask the update of all modules
  void updateModules(void);

  //! \brief Ask to send a message to the named robot
  void sendModuleMessage(QString,QString);

public slots:
  //! \brief Parse a message to give it to the right module
  void forwardDeviceMessage(QString);

  //! \brief Format a message to be readable by Aversive, and send it
  void forwardModuleMessage(Module*,QString);

public:
  //! \brief Default Constructor
  ModuleCoordinator(void);

  //! \brief Destructor
  ~ModuleCoordinator(void);

  //! \brief Add a robot's named module
  bool addModule(QString robot_name, QString module_name, Module* module);

  //! \brief Remove a robot's named module
  bool delModule(QString robot_name, QString module_name);

  //! \brief Remove all robot's modules
  bool delRobotModules(QString robot_name);

private:

  //! \brief first is robot's name, second is module's name
  typedef QPair<QString,QString> ModuleIdentifier;

  //! \brief modules list
  QHash<ModuleIdentifier, Module*> _modules;
};

#endif//MODULE_COORDINATOR_HPP
