#include "coordinator.hpp"
#include "../modules/servo.hpp"
#include "../physical_calculator/robot.hpp"
#include "../physical_calculator/wheel.hpp"
#include "../modules/encoder.hpp"
#include "../modules/motor_wheel.hpp"
#include "../modules/modules.hpp"
#include<cstdio>

Coordinator* Coordinator::_instance=NULL;


Coordinator& Coordinator::getInstance() {
  if(Coordinator::_instance){
    return *Coordinator::_instance;
  }
  else{
    Coordinator::_instance = new Coordinator();
    return *(Coordinator::_instance); 
  }
}

PhysicalCalculator& Coordinator::getPhysicalCalculatorInstance(){
  return _physic;
}

Robot *Coordinator::getRobot(Slot robotSlot){
  Robot * robot=_robotObject.value(robotSlot);
  return robot;
}

Coordinator::Coordinator() : _physic(this)/*, _gui()*/{
  _running = false;
  _codeFactor = 1;
  _sync = 1;
  _codeFactor = 1;
  _timeStep = 1./120.;
  _maxSubStep = 20;
  connect(this, SIGNAL(calcNextStep(double,int)), &_physic, SLOT(nextStep(double,int)));
}

Coordinator::~Coordinator(){
  QHash<QString, QProcess*>::iterator j;
  _codeInfo.squeeze();
  for (j = _codeInfo.begin(); j != _codeInfo.end(); ++j){
    closeRobot(j.value());
    j.value()=NULL;
  }
}


void Coordinator::play() {
  _running = true;
  if(_sync > _codeInfo.size())
    gotoNextStep();
}

void Coordinator::pause() {
  _running = false;
}

void Coordinator::stepDone() {
  if(++_sync > _codeInfo.size()) // all codeInfo.are sync, calculator was the last one
    {
      gotoNextStep();
    }
}

void Coordinator::openTable(const QString& XMLPath) {
  //TODO really read the file
  (void) XMLPath;
  _physic.simple_scene_walls(400);
}
void Coordinator::openRobot(const QString& XMLPath, Coordinator::Slot slot) {

  (void) slot;
  /* For the tests*/
  
  
  
  /*needed for test3dCoordinator*/
  //setCameraDistance(btScalar(340.));
  _physic.simple_scene_walls(300);
  btDynamicsWorld* m_dynamicsWorld = _physic.getScene();
  //////////////////////////
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

Wheel*     _MD = new Wheel(robot, btVector3(16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
Wheel*     _MG = new Wheel(robot, btVector3(-16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
Wheel*     _ED = new Wheel(robot, btVector3(19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);
Wheel*     _EG = new Wheel(robot, btVector3(-19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);

  (_physic.getScene())->addVehicle(robot);
  /* End of robot construction */  

  /*needed for communication tests*/
  // Only the module Servo is tested right now
  QString code=XMLPath;
  Modules *encd = new Encoder(_ED, "", this);
  _moduleFromName.insert("right_encoder",encd);
  _moduleInfo.insert(encd, QPair<QString,QString>(XMLPath,"right_encoder"));
  connect(this, SIGNAL(modulesNextStep()), encd, SLOT(simulStep())); 
  Modules *encg = new Encoder(_EG, "", this);
  _moduleFromName.insert("left_encoder",encg);
  _moduleInfo.insert(encg, QPair<QString,QString>(XMLPath,"left_encoder"));
connect(this, SIGNAL(modulesNextStep()), encg, SLOT(simulStep())); 
  Modules *motd = new MotorWheel(_MD, "", this);
  _moduleFromName.insert("right_motor",motd);
  _moduleInfo.insert(motd, QPair<QString,QString>(XMLPath,"right_motor"));
  connect(this, SIGNAL(modulesNextStep()), motd, SLOT(simulStep())); 
  Modules *motg = new MotorWheel(_MG, "", this);
  _moduleFromName.insert("left_motor",motg);
  _moduleInfo.insert(motg, QPair<QString,QString>(XMLPath,"left_motor"));
  connect(this, SIGNAL(modulesNextStep()), motg, SLOT(simulStep())); 

  _MG->setTorque(1600);
  //TODO really read the file  

  /* 
   * The addModule function takes a concatenation of
   * the robot code name and the module name in order to 
   * differentiate two identical modules in two different robots.
   */
  /*if(!addModule(code+modName,mod)){
    qDebug() << "error addToRobotModule" << '\n' ;
    return;
  }*/

  QProcess* proc=new QProcess(this);
  
  if(!addToRobotCode(code,proc)){
    qDebug() << "error addToRobotCode" << '\n' ;
    return;
  }
/*
  if(!addModuleAndCodeName(mod, code, modName )){
    qDebug() << "error addModuleAndCodeName" << '\n' ;
    return;
  }*/

  /*
   * The coordinator launches the processus robot
   * which launches the ClientThread.
   * /!\ En dur pour l'instant. /!\ 
   */
  qDebug() << "connecting signal..." << '\n' ;
  QObject::connect(proc,SIGNAL(readyRead()),this,SLOT(CTReceived()));
  qDebug() << "signal connected" << '\n' ;
  

	proc->start("./client",QStringList());

  if(!proc->waitForStarted()) {
    qDebug() << "error starting client process" << '\n' ;
    return ;
  }

  //sendSyncMessages();
   
}


void Coordinator::CTReceived() {
  if(NULL==sender()) {
    qDebug() << "sender null in CTReceived";
    return ;
  } 
  /* catch the processus sender */
  QProcess * client=(QProcess*)sender();
  /* obtain the robot code name corresponding */  
  QString code=_codeInfo.key(client);
  
  while(client->canReadLine()) {
    QString message=readMessage(client);
    qDebug() << "Message : " << message;
    QStringList args=message.split(" ");
    QString name;
    if(args.size()>1)
      name=args[1];

    switch((args[0].toStdString())[0]/*catch message first letter*/){
    case('S'):
      sendMessages("S",client);
      client->closeWriteChannel();
      qDebug() << "client closed" ;
      if(client->waitForFinished())
	qDebug() << "client closed" ;
      QCoreApplication::exit();

      break;
    case('D'): /* device message */
      Modules * mod;
      name = code+name; /* Cf note in openRobot */
      qDebug() << "name : " << name ;

      if(_moduleFromName.contains(name)){
	mod=_moduleFromName.value(name);
	args.removeFirst(); /* remove destination from the message */
	args.removeFirst(); /* remove name from the message */
	qDebug()<< "Message (" << args.join(" ") << ")send to module "<< mod << " named " <<  _moduleFromName.key(mod) << '\n';
      
	mod->received(args.join(" "));
      }
      else{
	mod=NULL;
	qDebug()<<"This device's name does not correspond to a module."  << '\n';
      }
      break;
    case('T'): /* Synchronisation message */
      if(++_sync>_codeInfo.size()) /* all modules are synchronised */
	gotoNextStep();
      break;
    case('M'): /* other message (GUI) */
      args.removeFirst();
      qDebug() << "message to GUI : " << args.join(" ") << '\n';
      // Ne fonctionne pas encore
      //emit(GUISend(args.join(" ")));
    
      break;
    default:
      qDebug() << "Unrecognized message header" << endl;
    }
  }
}


void Coordinator::MReceived(QString message) {
  if(sender() != 0) 
    {
      /* find which modules send the message */
      if(_moduleInfo.contains(sender()))
  	{
  	  QString code = _moduleInfo.value(sender()).first;
  	  QString module = _moduleInfo.value(sender()).second;
  	  sendDeviceMessage(module, message, code); 
	  
	}
      else 
	qDebug() << "module does not exist";
    }
}

void Coordinator::gotoNextStep() {
  if(_running) 
    {
      _sync = 0;
      sendSyncMessages(); 
    }
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QString code) {
  if(_codeInfo.contains(code))
    sendDeviceMessage(name, msg, _codeInfo.value(code));
  else 
    qDebug() << "error sendDeviceMessage : robot code name unknown";
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QProcess* p) {
  sendMessages(QString("D ") + name + " " + msg + "\n", p);
}

void Coordinator::sendMessages(QString msg, QProcess* p) {
  p->write(msg.toUtf8());
}

 
void Coordinator::closeRobot(Slot robot){
  QString robotName=_robotInfo.value(robot);
  QProcess * robotProcess=_codeInfo.value(robotName);
  closeRobot(robotProcess);
}

void Coordinator::closeRobot(QProcess *robot){
  robot->closeWriteChannel();
  if(!robot->waitForFinished()) {
    qDebug() << "error waitForFinished closeRobot" << '\n';
    return ;
  }
  delete robot;  
}


QString Coordinator::readMessage(QProcess * proc)const{
  char c;

  //TODO utiliser QBuffer au lieu de QString !
  QString buffer(COORD_BUFFER_SIZE);

  /*
    Attention source de bug : 
    Si le message ne contient pas de saut de ligne 
    le message n'est pas transmis et le processus est tué.
    Cela peut arriver si un message est lu avant d'être 
    entièrement écrit.
  */
  
  if(!proc->getChar(&c)) {
    proc->waitForReadyRead();
  }
  else {
    qDebug() << c << "char before reading \n";
    buffer = c;
  }
  while(proc->getChar(&c) && c != '\n') {
    buffer += c;
  }
  if(c == '\n') {
    qDebug() << buffer << "message before sending\n";
    return buffer;
  }
  else {
    proc->kill();
    proc->waitForFinished();
    return "Process killed";
  }
}

bool Coordinator::addToRobotCode(QString name, QProcess * proc){
  _codeInfo.insert(name,proc);
  return (_codeInfo.value(name)==proc);
}

bool Coordinator::addModuleAndCodeName(Modules * key, QString code, QString module ){
  QPair<QString,QString> p(code,module);
  _moduleInfo.insert(key,p);
  
  return (_moduleInfo.contains(key));
}


bool Coordinator::addModule(QString name, Modules * mod){
  _moduleFromName.insert(name,mod);
  
  return (_moduleFromName.contains(name));
}

void Coordinator::sendSyncMessages() {
  //sync UI time
  emit(timer(_physic.getTime()));
  foreach(QProcess* code, _codeInfo) {
    sendMessages(QString("T %1 %2").arg((int)_physic.getTime()*1000).arg((int)_codeFactor), code);
    //qDebug() << QString("T %1 %2").arg((int)_physic.getTime()*1000).arg((int)_codeFactor) << endl;
  }
  emit(calcNextStep(_timeStep,_maxSubStep));  
}
/*
void stopSimulation(){
  sendDeviceMessage("TESTER", "Stop", client);

}

void stopRobotSimulated(Slot robotSlot){
  

}
*/

/*btDiscreteDynamicWorlds* Coordinator::getPhysicalCalculatorScene()const {
  return _physic.getScene();
}
*/
