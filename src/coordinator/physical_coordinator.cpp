#include "physical_coordinator.hpp"

#include "../physical_calculator/physical_calculator.hpp"
#include "../common/position_data.hpp"
#include "../common/object_config.hpp"
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
{ _data->running = false;}

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



void PhysicalCoordinator::loadTable(const QString& path) {
  const ObjectConfig::tableConfig * tableConfig=XMLParser::parseTable(path);
  //STLReader stl_reader();
  //QList<QVector<float> > tablePointsList=stl_reader.readSTLTextFile(tableConfig->mesh_path);

  //Initialize the Table PrintableMobileObject
  new PrintableMobileObject(tableConfig->mesh_path, 0, PositionData(0,0,0,0,0,0),QString("table"));

  //QList<Mesh*> toysMeshList = new QList<Mesh *>;
  foreach (const ObjectConfig::toyConfig* it, tableConfig->toys) {
    //Creates a new PMO foreach toy on the table
    /*PrintableMobileObject pmo =*/new PrintableMobileObject(it->mesh_path,(float)it->weight,
                              PositionData(it->position[0], it->position[1], it->position[2],
                                                it->position[3], it->position[4], it->position[5]),/*name*/"mesh");
  //t.getQGraphicsItem();
  }
  //_data->physic->simple_scene_walls(300);
}

void PhysicalCoordinator::update(void) {
  qDebug() << "PhysicalCoord\n";
  if(_data->running == true) {
    qDebug() << " Running \n";
    _data->physic->nextStep(_data->timeStep, _data->maxSubStep);
    emit timestamp(_data->physic->getTime());
    emit nextStep();
  }

  //emit nextStepAnimation(); 
}

PhysicalCalculator* PhysicalCoordinator::getPhysicalCalculator(void) {
  return _data->physic;
}
