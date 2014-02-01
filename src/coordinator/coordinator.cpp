#include "coordinator.hpp"


void Coordinator::CTReceived(QString message) {

  // TODO read message
  if(message == "T") // sync message
  {
    if(++_sync > _codes.size()) // calculator && all other codes are sync, need to move forward
    {
      gotoNextStep();
    }
  }
}


void Coordinator::MReceived(QString message) {
  if(sender() != 0) // shouldn't be directly called
  {
    //find which modules send the message
    if(_modules.contains(sender()))
    {
      QString code = _modulesInfo.value(sender()).first;
      QString module = _modulesInfo.value(sender()).second;
      sendDeviceMessage(modules, message, code); 
    }
  }
}

void Coordinator::play() {
  _running = true;
  if(_sync > _codes.size())
    gotoNextStep();
}

void Coordinator::pause() {
  _running = false;
}

void Coordinator::stepDone() {
   if(++_sync > _codes.size()) // all codes are sync, calculator was the last one
    {
      gotoNextStep();
    }
}

void Coordinator::openTable(const QString& XMLPath) {
//TODO really read the file

}

void Coordinator::openRobot(const QString& XMLPath, Coordinator::Slot slot) {
//TODO really read the file

}

Coordinator::Coordinator() {
  _running = false;
  _codeFactor = 1;
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
  if(_codeInfo.contains(code))
    sendDeviceMessage(name, msg, _codeInfo.value(code));
}

void Coordinator::sendDeviceMessage(QString name, QString msg, QProcess* p) {
  sendMessage(QString("D ") + name + " " + msg + "\n", p);
}

void Coordinator::sendMessage(QString msg, QProcess* p) {
  p->write(msg);
}

void sendSyncMessages() {
  emit(time(_physic.getTime());
  foreach(QProcess* code, _codesInfo) {
    sendMessage("T " + _physic.getTime() + " " + _codeFactor);
  }
  //sync UI time
  emit(calcNextStep());
}
