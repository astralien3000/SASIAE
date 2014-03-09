#include "physical_coordinator.hpp"

#include "../physical_calculator/physical_calculator.hpp"

#include <QDebug>

////////////////////////////////////////
// PrivateData

struct PhysicalCoordinator::PrivateData {
  PhysicalCalculator* physic;
  bool running; // Useful ?
  double timeStep;
  int maxSubStep;
};

////////////////////////////////////////
// Methods

PhysicalCoordinator::PhysicalCoordinator(void) : 
  PhysicalCoordinator(new PhysicalCalculator(this))
{}

PhysicalCoordinator::PhysicalCoordinator(PhysicalCalculator* phy) {
  _data = new PrivateData;

  //! \todo Check phy not NULL
  _data->physic = phy;

  _data->running = false;
  _data->timeStep = 1./120.;
  _data->maxSubStep = 20;

  connect(
	  this, 
	  SIGNAL(calcNextStep(double,int)), 
	  _data->physic, 
	  SLOT(nextStep(double,int))
	  );
}

PhysicalCoordinator::~PhysicalCoordinator() {
  delete _data->physic;
}

void PhysicalCoordinator::play() {
  _data->running = true;
}

void PhysicalCoordinator::pause() {
  _data->running = false;
}

void PhysicalCoordinator::loadTable(const QString& path) {
  //! \warning default table loaded instead
  //! \todo really load the file
  (void)path;
  _data->physic->simple_scene_walls(300);
}

Mesh* PhysicalCoordinator::loadMesh(const QString& path) {
  //! \todo call STL parser
  return 0;
}

void PhysicalCoordinator::update(void) {
  //qDebug() << "Bullet\n";
  _data->physic->nextStep(_data->timeStep, _data->maxSubStep);
  emit timestamp(_data->physic->getTime());
  emit nextStep();
  //emit nextStepAnimation(); 
}
