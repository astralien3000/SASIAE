#include "coordinator.hpp"


Coordinator* Coordinator::_instance=NULL;

void Coordinator::CTReceived() {
  QString message("je suis toto");
  // TODO read message
  if(message == "T") // sync message
  {
    if(++_sync > _codesInfo.size()) // calculator && all other codesInfo.are sync, need to move forward
    {
      gotoNextStep();
    }
  }
}


void Coordinator::MReceived(QString message) {
  if(sender() != 0) // shouldn't be directly called
  {
    //find which modules send the message
    if(_modulesInfo.contains(sender()))
    {
      QString code = _modulesInfo.value(sender()).first;
      QString module = _modulesInfo.value(sender()).second;
      sendDeviceMessage(module, message, code); 
    }
  }
}

void Coordinator::play() {
  _running = true;
  if(_sync > _codesInfo.size())
    gotoNextStep();
}

void Coordinator::pause() {
  _running = false;
}

void Coordinator::stepDone() {
   if(++_sync > _codesInfo.size()) // all codesInfo.are sync, calculator was the last one
    {
      gotoNextStep();
    }
}

void Coordinator::openTable(const QString& XMLPath) {
//TODO really read the file

}

void Coordinator::openRobot(const QString& XMLPath, Slot slot) {
//TODO really read the file

}

Coordinator::Coordinator() : _physic(this){
  _running = false;
  _codeFactor = 1;
  _sync = 1;
  _timeStep = 1./120.;
  _maxSubStep = 20;
  connect(this, SIGNAL(calcNextStep(double,int)), &_physic, SLOT(nextStep(double,int)));
}
Coordinator::~Coordinator() {
}
Coordinator& Coordinator::getInstance() {
  if(_instance)
    return *_instance;
  else
    return *(_instance = new Coordinator()); 
}

void Coordinator::gotoNextStep() {
  if(_running) 
  {
    _sync = 0;
    sendSyncMessages();
  }
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QString code) {
  if(_codesInfo.contains(code))
    sendDeviceMessage(name, msg, _codesInfo.value(code));
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QProcess* p) {
  sendMessages(QString("D ") + name + " " + msg + "\n", p);
}

void Coordinator::sendMessages(QString msg, QProcess* p) {
  p->write(msg.toUtf8());
}

void Coordinator::sendSyncMessages() {
  //sync UI time
  emit(timer(_physic.getTime()));
  foreach(QProcess* code, _codesInfo) {
    sendMessages(QString("T ") + _physic.getTime() + " " + _codeFactor, code);
  }
  emit(calcNextStep(_timeStep,_maxSubStep));
}
