#include "coordinator.hpp"
/*TODO*/
void Coordinator::CTReceived(){
  while()
}
void Coordinator::openTable(QString XMLPath){

}
void Coordinator::play(){
}
void Coordinator::pause(){

}
void Coordinator::openRobot(QString XMLPath, Slot slot){

}

Coordinator::Coordinator() {

}
Coordinator& Coordinator::getInstance() {
  if(_instance)
    return *_instance;
  else
    return *(_instance = new Coordinator()); 
}
