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
  int n;
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
  _data->n = 0;
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
  if(tableConfig == NULL) return;
  qDebug()<<"tableConfig : img path ="<< tableConfig->img_path
         << "  mesh_path ="<<tableConfig->mesh.path << " toys=" << tableConfig->toys ;


  qDebug()<<"PC.loadTable : Initialize the Table PrintableMobileObject";
  PrintableMobileObject* pmo=new PrintableMobileObject(tableConfig->mesh, 0,
                            PositionData(0,0,0,0,0,0),QString("table"),tableConfig->img_path);
  pmo->getItem()->setZValue(-1000);
  emit(tableItem(pmo->getItem()));

  //emit tableImg(QPixmap(tableConfig->img_path,"png"));

  //QList<Mesh*> toysMeshList = new QList<Mesh *>;
  foreach (const ObjectConfig::toyConfig* it, tableConfig->toys) {
    //Creates a new PMO foreach toy on the table
    PrintableMobileObject *pmo =new PrintableMobileObject(it->mesh,(float)it->weight,
                              PositionData(it->position[0], it->position[1], it->position[2],
                                                it->position[3], it->position[4], it->position[5]),
                                            it->name,it->img_path);
    emit(tableItem(pmo->getItem()));
  }
  //_data->physic->simple_scene_walls(300);
}

void PhysicalCoordinator::update(void) {
  //qDebug() << "PhysicalCoordinator emit nextStep";
    //qDebug() << " Running \n";
    _data->physic->nextStep(_data->timeStep, _data->maxSubStep);
    emit timestamp(_data->timeStep*_data->n++*1000);
    emit nextStep();
}

PhysicalCalculator* PhysicalCoordinator::getPhysicalCalculator(void) {
  return _data->physic;
}
