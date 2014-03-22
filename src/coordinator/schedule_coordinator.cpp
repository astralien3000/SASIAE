#include "schedule_coordinator.hpp"

#include <QDebug>
#include <QCoreApplication>

ScheduleCoordinator::ScheduleCoordinator(void) {
  _running = false;
  //_coords.append(this);
  //connect(_coords.last(), SIGNAL(nextStep()), this, SLOT(update()));
}

ScheduleCoordinator::~ScheduleCoordinator(void) {
  
}

void ScheduleCoordinator::addCoordinator(BaseCoordinator* coor) {
  //disconnect(_coords.last(), SIGNAL(nextStep()), this, SLOT(update()));
  //connect(_coords.last(), SIGNAL(nextStep()), coor, SLOT(update()));
  //connect(coor, SIGNAL(nextStep()), this, SLOT(update()));
  _coords.append(coor);
}

void ScheduleCoordinator::update(void) {
  qDebug() << "Schedule loop\n" << endl;
  //emit nextStep();
  while(_running) {
    foreach(BaseCoordinator* bc, _coords) {
      bc->update();
      QCoreApplication::processEvents();//traitement des signaux emits
    }
  }
  //_coords[1]->update();
}
void ScheduleCoordinator::play() {
  if(_running) //nothing to do
    return;
  _running= true;
  update();
}

void ScheduleCoordinator::pause() {
  _running = false;
}
