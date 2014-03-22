#include "physical_coordinator.hpp"

#include "../physical_calculator/physical_calculator.hpp"
#include "../common/position_data.hpp"
#include "../common/object_config.hpp"
#include <QDebug>

////////////////////////////////////////
// PrivateData

struct PhysicalCoordinator::PrivateData {
  PhysicalCalculator* physic;
  double timeStep;
  int maxSubStep;
};

////////////////////////////////////////
// Methods

PhysicalCoordinator::PhysicalCoordinator(void) : 
  PhysicalCoordinator(new PhysicalCalculator(this))
{ }

PhysicalCoordinator::PhysicalCoordinator(PhysicalCalculator* phy) {
  _data = new PrivateData;

  //! \todo Check phy not NULL
    qDebug() << "bullet_ptr = " << phy->getScene().getScene(); 
  _data->physic = phy;

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
  qDebug() << "PhysCoor loadTable path="<< path;
  const ObjectConfig::tableConfig * tableConfig=XMLParser::parseTable(path);

  qDebug()<<"tableConfig : img path ="<< tableConfig->img_path
         << "  mesh_path ="<<tableConfig->mesh_path << " toys=" << tableConfig->toys ;


  qDebug()<<"PC.loadTable : Initialize the Table PrintableMobileObject";
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
  qDebug() << "PhysicalCoordinator emit nextStep";
    qDebug() << " Running \n";
    _data->physic->nextStep(_data->timeStep, _data->maxSubStep);
    emit timestamp(_data->physic->getTime());
    emit nextStep();
}

PhysicalCalculator* PhysicalCoordinator::getPhysicalCalculator(void) {
  return _data->physic;
}
