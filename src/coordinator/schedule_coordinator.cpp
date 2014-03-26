#include "schedule_coordinator.hpp"

#include <QDebug>
#include <QCoreApplication>
#include <QTimer>

ScheduleCoordinator::ScheduleCoordinator(void) {
  _running = false;
  _step = 0;
  QTimer* t = new QTimer;
  connect(t, SIGNAL(timeout()), this, SLOT(capSpeed()));
  t->start(1000/120);
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
  qDebug() << "ScheduleCoordinator loop" << endl;
  //emit nextStep();
  while(_step > 0) {
    foreach(BaseCoordinator* bc, _coords) {
      bc->update();
      QCoreApplication::processEvents();//traitement des signaux emits
    }
    _step--;
  }
  //_coords[1]->update();
}
void ScheduleCoordinator::capSpeed() {
  if(_running) {
    _step+=1;
    qDebug() << "il reste " << _step;
    if(_step == 1) //scheduler wasn't updating
      update();
  }
}
void ScheduleCoordinator::play() {
  if(_running) //nothing to do
    return;
  _running= true;
}

void ScheduleCoordinator::pause() {
  _running = false;
}
