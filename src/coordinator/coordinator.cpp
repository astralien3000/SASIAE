#include "coordinator.hpp"


void Coordinator::CTReceived() {
}


void Coordinator::play() {
  _running = true;
  emit(calcNextStep());
}

void Coordinator::pause() {
  _running = false;
}

void Coordinator::stepDone() {
  
}

void Coordinator::openTable(const QString& XMLPath) {

}

void Coordinator::openRobot(const QString& XMLPath, Coordinator::Slot slot) {

}

Coordinator::Coordinator() {
  _running = false;
}

Coordinator& Coordinator::getInstance() {
  if(_instance)
    return *_instance;
  else
    return *(_instance = new Coordinator()); 
}

