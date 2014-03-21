#include "physical_coordinator.hpp"

#include "../physical_calculator/physical_calculator.hpp"
#include "../common/position_data.hpp"

#include <QDebug>

////////////////////////////////////////
// PrivateData

struct PhysicalCoordinator::PrivateData {
  PhysicalCalculator* physic;
  bool running; // Use for pause button & don't keep updata signal
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
  const XMLParser::tableConfig * tableConfig=XMLParser::parseTable(path);
  //STLReader stl_reader();
  //QList<QVector<float> > tablePointsList=stl_reader.readSTLTextFile(tableConfig->mesh_path);

  //Initialize the Table PrintableMobileObject
  new PrintableMobileObject(tableConfig->mesh_path, 0, PositionData(),"table");

  //QList<Mesh*> toysMeshList = new QList<Mesh *>;
  foreach (const XMLParser::toyConfig* it, tableConfig->toys) {
      //create a new QGraphicsItem and use the other constructor ...!!!
    //new PrintableMobileObject(it->mesh_path,it->weight,new PositionData(it->position),(const)it->name); TO BE FIXED
  }
  //_data->physic->simple_scene_walls(300);
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

PhysicalCalculator* PhysicalCoordinator::getPhysicalCalculator(void) {
  return _data->physic;
}
