#include "module_coordinator.hpp"

#include <QDebug>

#include "../modules/module.hpp"

ModuleCoordinator::ModuleCoordinator(void) {
  qDebug() << "moduleCoordinator Constructor";
}

ModuleCoordinator::~ModuleCoordinator(void) {

}

void ModuleCoordinator::forwardDeviceMessage(QString rname, QString msg) {
  QStringList args = msg.split(" ");

  Module* mod = _modules.value(QPair<QString, QString>(rname, args[1]));
  if(!mod) {
    qDebug() << "ERROR : No module with this name : " << args[1] << "\n";
    return;
  }

  args.removeFirst(); // Remove D
  args.removeFirst(); // Remove device's name

  mod->received(args.join(" "));
}

void ModuleCoordinator::forwardModuleMessage(QString msg) {
  Module* mod = (Module*)sender();

  QPair<QString, QString> mod_id = _modules.key(mod);

  emit sendModuleMessage(
			 mod_id.first, 
			 QString("D %1 %2\n")
			 .arg(mod_id.second)
			 .arg(msg)
			 );
}

bool ModuleCoordinator::addModule(QString rname, QString mname, Module* mod) {
  _modules.insert(QPair<QString,QString>(rname, mname), mod);

  connect(this, SIGNAL(updateModules()), mod, SLOT(update()));
  connect(mod, SIGNAL(send(QString)), this, SLOT(forwardModuleMessage(QString)));
  return true;
}

bool ModuleCoordinator::delModule(QString rname, QString mname) {
    /*TODO*/
    return false;
}

bool ModuleCoordinator::delRobotModules(QString rname) {
  /*TODO*/
  return false;
}

void ModuleCoordinator::update(void) {
  //! \todo Two calls per update ? fix it
  //qDebug() << "Modules\n";
  //TODO call them manually, les signaux slots ne garantice pas d'etre executé avant le prochain pas emit updateModules();
  qDebug() << "module emit nextStep()";
  emit nextStep();
}
