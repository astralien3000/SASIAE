#include "coordinator.hpp"
#include "../modules/servo.hpp"

Coordinator *Coordinator::_instance=NULL;

Coordinator& Coordinator::getInstance() {
  if(Coordinator::_instance)
    return *Coordinator::_instance;
  else
    return *(Coordinator::_instance = new Coordinator()); 
}

Coordinator::Coordinator() {
  _running = false;
}

Coordinator::~Coordinator(){
   QHash<QString, QProcess*>::iterator j;
   _codeInfo.squeeze();
   for (j = _codeInfo.begin(); j != _codeInfo.end(); ++j){
     closeRobot(j.value());
   }
}




void Coordinator::play() {
  _running = true;
  if(_sync >(unsigned int) _codeInfo.size())
    gotoNextStep();
}

void Coordinator::pause() {
  _running = false;
}

void Coordinator::stepDone() {
  if(++_sync > (unsigned int)_codeInfo.size()) // all codes are sync, calculator was the last one
    {
      gotoNextStep();
    }
}

void Coordinator::openTable(const QString& XMLPath) {
  //TODO really read the file
  (void) XMLPath;
}

void Coordinator::openRobot(QProcess* proc, const QString& XMLPath, Coordinator::Slot slot) {
  //TODO really read the file
(void) XMLPath;
 (void) slot;
  /* For the tests*/
 
  Modules *mod =new Servo(0);
  QString name(XMLPath);
  if(!addToRobotCode(name,proc)){
    qDebug() << "error addToRobotCode" << '\n' ;
    return;
  }
    if(!addToRobotModule(name,mod)){
    qDebug() << "error addToRobotModule" << '\n' ;
    return;
  }
  
  proc->start("./client",QStringList());
   if(!proc->waitForStarted()) {
     qDebug() << "error starting client process" << '\n' ;
     return ;
  }
   
   qDebug() << "connecting signal..." << '\n' ;
   QObject::connect(proc,SIGNAL(readyRead()),this,SLOT(CTReceived()));
   qDebug() << "signal connected" << '\n' ;
}

<<<<<<< HEAD
void Coordinator::CTReceived() {
  QProcess * client=_codeInfo.value("client");
  QString message=readMessage(client);
  QStringList args=message.split(message);
  QString name;
  name=args[1];
  Modules * mod;

  if(_moduleInfo.contains(name)){
    mod=_moduleInfo.value(name);
    qDebug()<< "module name : " << mod << '\n';
    // the message is set to the corresponding module
    //std::cout << args[2] <<" envoyé au module " << name << std::endl;
    // Trouver un moyen de concaténer la chaine du message join ?
    //emit mod::sendMessage(args[2].join(" "));
    // savoir qui a emit le signal QObject
    // verif du bon etat du message ?
  }
  else{
    mod=NULL;
    qDebug()<<"This device's name does not correspond to a module."  << '\n';
  }
=======
Coordinator::Coordinator() {
  _running = false;
  _codeFactor = 1;
>>>>>>> 72f857d705b5633bec4ddf333239e0bee8692b16
}

void Coordinator::MReceived(QString message) {
  (void) message;
  // if(sender() != 0) // shouldn't be directly called
  //   {
  //     //find which modules send the message
  //     if(_moduleInfo.contains(sender()))
  // 	{
  // 	  QString code = _codeInfo.value(sender()).first;
  // 	  QString module = _moduleInfo.value(sender()).second;
  // 	  sendDeviceMessage(module, message, code); 
  // 	}
  //   }
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
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QProcess* p) {
  sendMessage(QString("D ") + name + " " + msg + "\n", p);
}

void Coordinator::sendMessage(QString msg, QProcess* p) {
  p->write(msg.toStdString().c_str());
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
  
}


QString Coordinator::readMessage(QProcess * proc)const{
  unsigned int i = 0;
  char c;

  QString buffer(BUFFER_SIZE);
  
  if(!proc->getChar(&c)) {
    proc->waitForReadyRead();
  }
  else {
    buffer += c;
  }
  while(proc->getChar(&c) && c != '\n') {
    buffer += c;
  }
  buffer[i] = '\0';
  if(c == '\n') {
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

bool Coordinator::addToRobotModule(QString name, Modules * mod){
  _moduleInfo.insert(name,mod);

  return (_moduleInfo.value(name)==mod);
}

void sendSyncMessages() {
  emit(time(_physic.getTime());
  foreach(QProcess* code, _codesInfo) {
    sendMessage("T " + _physic.getTime() + " " + _codeFactor);
  }
  //sync UI time
  emit(calcNextStep());
}
