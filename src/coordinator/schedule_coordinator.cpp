#include "schedule_coordinator.hpp"

#include <QDebug>

ScheduleCoordinator::ScheduleCoordinator(void) {
  _coords.append(this);
  //connect(_coords.last(), SIGNAL(nextStep()), this, SLOT(update()));
}

ScheduleCoordinator::~ScheduleCoordinator(void) {
  
}

void ScheduleCoordinator::addCoordinator(BaseCoordinator* coor) {
  connect(_coords.last(), SIGNAL(nextStep()), coor, SLOT(update()));
  _coords.append(coor);
}

void ScheduleCoordinator::update(void) {
  //qDebug() << "Schedule\n" << endl;
  emit nextStep();
}

