#include "coordinator.hpp"
#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/wheel.hpp"
#include <cstdio>
#include <iostream>

#include "physical_coordinator.hpp"
#include "robot_coordinator.hpp"
#include "config_robot_coordinator.hpp"
#include "module_coordinator.hpp"
#include "schedule_coordinator.hpp"
#include "gui_coordinator.hpp"

PhysicalCoordinator* _phy_cdn;
ConfigRobotCoordinator* _bot_cdn;
ModuleCoordinator* _mod_cdn;
ScheduleCoordinator* _sch_cdn;
GuiCoordinator* _gui_cdn;

Coordinator* Coordinator::_instance=NULL;



Coordinator& Coordinator::getInstance(int argc, char *argv[]) {
  if(Coordinator::_instance){
    return *Coordinator::_instance;
  }
  else{
    Coordinator::_instance = new Coordinator(argc,argv);
    return *(Coordinator::_instance);
  }
}


Coordinator& Coordinator::getInstance() {
  if(Coordinator::_instance){
    return *Coordinator::_instance;
  }
  else{
    qDebug() << "Coordinator::getInstance() should not be called here";
    Coordinator::_instance = new Coordinator(0,NULL);
    return *(Coordinator::_instance);
  }
}

PhysicalCalculator& Coordinator::getPhysicalCalculatorInstance(){
  return _physic;
}


Coordinator::Coordinator(int argc, char* argv[]) :
    QApplication(argc,argv), _physic(this)/*, _gui()*/{
  _phy_cdn = new PhysicalCoordinator(&_physic);
  _mod_cdn = new ModuleCoordinator;
  _bot_cdn = new ConfigRobotCoordinator(*_phy_cdn, *_mod_cdn);
  _sch_cdn = new ScheduleCoordinator;
  _gui_cdn = new GuiCoordinator;

  _sch_cdn->addCoordinator(_phy_cdn);
  _sch_cdn->addCoordinator(_bot_cdn);
  _sch_cdn->addCoordinator(_mod_cdn);
  _sch_cdn->addCoordinator(_gui_cdn);

  qDebug() << "Ajout de tous les Coordinators au Coordinator via le SchCoord";

  // GuiCoordinator.MainWindow -> PhysicalCoordinator : load the Table
  connect(
        _gui_cdn->getMainWindow(),
        SIGNAL(tableFileXml(QString)),
        _phy_cdn,
        SLOT(loadTable(const QString&))
        );

   //PhysicalCoordinator.tableItem -> GuiCoordinator.updateTable
  connect(
          _phy_cdn,
          SIGNAL(tableItem(QGraphicsPixmapItem*)),
          _gui_cdn,
          SLOT(updateTable(QGraphicsPixmapItem*))
          );

   
   connect(
           _bot_cdn,
           SIGNAL(tableItem(QGraphicsPixmapItem*)),
           _gui_cdn,
           SLOT(updateTable(QGraphicsPixmapItem*))
           );
  


  // GuiCoordinator robotFileXml -> ConfigRobotCoordinator loadRobotConfig
  connect(
           _gui_cdn->getMainWindow(),
           SIGNAL(robotFileXml(QString,QString,PositionData)),
           _bot_cdn,
           SLOT(loadRobotConfig(const QString&, const QString&,PositionData))
            );

  //ConfigRobotCoord -> GuiCoord
  connect(
         _bot_cdn,
         SIGNAL(newRobot(QStandardItem*)),
         _gui_cdn,
         SLOT(addRobotToList(QStandardItem*))
         );
  // Device -> Module communication
  connect(
	  _bot_cdn,
	  SIGNAL(recvDeviceMessage(QString, QString)),
	  _mod_cdn,
	  SLOT(forwardDeviceMessage(QString, QString))
	  );

  // Module -> Device communication
  connect(
	  _mod_cdn,
	  SIGNAL(sendModuleMessage(QString, QString)),
	  _bot_cdn,
	  SLOT(sendModuleMessage(QString, QString))
	  );
  // GUI -> schedule play pause
  connect(
	  _gui_cdn,
	  SIGNAL(uiPlay()),
	  _sch_cdn,
	  SLOT(play())
	  );
  connect(
	  _gui_cdn,
	  SIGNAL(uiPause()),
	  _sch_cdn,
	  SLOT(pause())
	  );
  // GUI close -> this close
connect(
	  _gui_cdn,
	  SIGNAL(close()),
	  this,
	  SLOT(quit())
	  );

connect(
        _bot_cdn,
        SIGNAL(logMessage(QString)),
        _gui_cdn->getMainWindow(),
        SLOT(newLog(QString))
        );
//
connect(
        _mod_cdn,
        SIGNAL(logMessage(QString)),
        _gui_cdn->getMainWindow(),
        SLOT(newLog(QString))
        );

  // Time management
  connect(
	  _phy_cdn,
	  SIGNAL(timestamp(int)),
	  _bot_cdn,
	  SLOT(setTimestamp(int))
	  );
  connect(
	  _phy_cdn,
	  SIGNAL(timestamp(int)),
	  _gui_cdn->getMainWindow(),
	  SLOT(setTimestamp(int))
	  );


  std::cout << "Creation de la fenetre principale..." << std::endl;
  _gui_cdn->getMainWindow()->show();

}

void Coordinator::restart(){
// TODO
}

Coordinator::~Coordinator(){
  delete _phy_cdn;
  delete _bot_cdn;
}

void Coordinator::play() {
  _sch_cdn->play();
}
void Coordinator::pause() {
  _sch_cdn->pause();
}
void Coordinator::stepDone() {
}


/*void Coordinator::openRobot(const QString& XMLPath) {
    qDebug() << "Chargement des robots : Coordinator.openRobot()";
    QString name("name");

  _bot_cdn->loadRobot("bot", "./client");
}
*/

void Coordinator::CTReceived() {
}


void Coordinator::gotoNextStep() {
}

void Coordinator::update(void) {
  _sch_cdn->update();
}

