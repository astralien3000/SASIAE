#include "coordinator.hpp"
#include "../modules/servo.hpp"
#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/wheel.hpp"
#include "../modules/encoder.hpp"
#include "../modules/motor_wheel.hpp"
#include "../modules/modules.hpp"

#include <cstdio>
#include <iostream>

#include "physical_coordinator.hpp"
#include "robot_coordinator.hpp"
#include "module_coordinator.hpp"
#include "schedule_coordinator.hpp"
#include "gui_coordinator.hpp"

PhysicalCoordinator* _phy_cdn;
RobotCoordinator* _bot_cdn;
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

Robot *Coordinator::getRobot(Slot robotSlot){
}

void Coordinator::startUpdateTimer(QTimer *tm){

    qDebug() << "connect timerUpdate to update";
    connect(tm, SIGNAL(timeout()), this, SLOT(update()));
    qDebug() << "Update connected";
    tm->start();
}


Coordinator::Coordinator(int argc, char* argv[]) :
    QApplication(argc,argv), _physic(this)/*, _gui()*/{
  _phy_cdn = new PhysicalCoordinator(&_physic);
  _bot_cdn = new RobotCoordinator;
  _mod_cdn = new ModuleCoordinator;
  _sch_cdn = new ScheduleCoordinator;
  _gui_cdn = new GuiCoordinator;

  _sch_cdn->addCoordinator(_phy_cdn);
  _sch_cdn->addCoordinator(_bot_cdn);
  _sch_cdn->addCoordinator(_mod_cdn);
  _sch_cdn->addCoordinator(_gui_cdn);

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

  // Time management
  connect(
	  _phy_cdn,
	  SIGNAL(timestamp(int)),
	  _bot_cdn,
	  SLOT(setTimestamp(int))
	  );

  std::cout << "Creation de la fenetre principale..." << std::endl;
  _gui_cdn->getMainWindow()->show();
  _gui_cdn->getMainWindow()->getTimer()->start();



}

Coordinator::~Coordinator(){
  delete _phy_cdn;
  delete _bot_cdn;
}


void Coordinator::play() {
  //_running = true;
  _phy_cdn->play();
}

void Coordinator::pause() {
  //_running = false;
  _phy_cdn->pause();
}

void Coordinator::stepDone() {
}

void Coordinator::openTable(const QString& XMLPath) {
  _phy_cdn->loadTable(XMLPath);
}
void Coordinator::openRobot(const QString& XMLPath, Coordinator::Slot slot) {

  (void) slot;

  //! \todo remove... only here for tests
 // _phy_cdn->loadTable("dummy");

  btDynamicsWorld* m_dynamicsWorld = _physic.getScene();

  //Mesh * robotMesh=new Mesh(...);

  //////////////////////////
  // Design robot's shape
  btCollisionShape* boxA = new btBoxShape(btVector3(1,0.25,1));
  btCollisionShape* boxB = new btBoxShape(btVector3(15,17.25,15));
  //btCollisionShape* boxB = new btBoxShape(btVector3(15,17.5,15));
  btCompoundShape* cyl0 = new btCompoundShape();
  cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(6,-17,14)),boxA);
  cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(-6,-17,14)),boxA);
  cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(6,-17,-14)),boxA);
  cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(-6,-17,-14)),boxA);
  cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(0,0.5,0)),boxB);
  
  
  btVector3 boxSize=btVector3(15,17.5,15);
  btVector3 position=btVector3(0,17.5,0);
  btScalar mass=80;
  btVector3 localInertia;
  btDefaultMotionState* MT = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,17.5,0)));
  cyl0->calculateLocalInertia(mass,localInertia);
  btRigidBody::btRigidBodyConstructionInfo ci(mass,MT,cyl0,localInertia);
  //ci.m_startWorldTransform.setOrigin(btVector3(0,3,0));

  btRigidBody* chassis = new btRigidBody(ci);//1,0,cyl0,localInertia);
  m_dynamicsWorld->addRigidBody(chassis);
  //////////////////////////
  //btRigidBody* chassis=pc->addBox(btVector3(15,17.5,15), btVector3(0,0,0), 800);
  //chassis->setFriction(0.020);
  Robot* robot = new Robot(chassis, _physic.getScene());
  _physic.getScene()->addVehicle(robot);

  _robotObject.insert(MAIN_ROBOT1,robot);

  ///////////////////////
  // Load Modules

  Wheel*     _MD = new Wheel(robot, btVector3(16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
  Wheel*     _MG = new Wheel(robot, btVector3(-16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
  Wheel*     _ED = new Wheel(robot, btVector3(19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);
  Wheel*     _EG = new Wheel(robot, btVector3(-19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);

  (_physic.getScene())->addVehicle(robot);
  /* End of robot construction */  

  /*needed for communication tests*/
  // Only the module Servo is tested right now
  QString code=XMLPath;
  Module* encd = new Encoder(_ED, "", this);
  _mod_cdn->addModule("bot", "right_encoder", encd);
  
  Module* encg = new Encoder(_EG, "", this);
  _mod_cdn->addModule("bot", "left_encoder", encg);
  
  Module* motd = new MotorWheel(_MD, "", this);
  _mod_cdn->addModule("bot", "right_motor", motd);
  
  Module* motg = new MotorWheel(_MG, "", this);
  _mod_cdn->addModule("bot", "left_motor", motg);
  
  //! \todo really read the file  

  _bot_cdn->loadRobot("bot", "./client");
}


void Coordinator::CTReceived() {
}


void Coordinator::MReceived(QString message) {
}

void Coordinator::gotoNextStep() {
}

void Coordinator::update(void) {
  _sch_cdn->update();
}

void Coordinator::sendModuleMessage(QString msg) {
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QString code) {
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QProcess* p) {
}

void Coordinator::sendMessages(QString msg, QProcess* p) {
}

 
void Coordinator::closeRobot(Slot robot){
}

void Coordinator::closeRobot(QProcess *robot){
}


QString Coordinator::readMessage(QProcess * proc)const{
}

bool Coordinator::addToRobotCode(QString name, QProcess * proc){
}

bool Coordinator::addModuleAndCodeName(Modules * key, QString code, QString module ){
  return false;
}


bool Coordinator::addModule(QString name, Modules * mod){  
  return false;
}

void Coordinator::sendSyncMessages() {
}

