#include "RDS_factory.hpp"

#include "../physical_calculator/balise.hpp"
#include "../physical_calculator/world.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "RDS.hpp"
#include <QVector3D>

RDSFactory::RDSFactory() : QObject(), _world(NULL) {}

Module* RDSFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle RDS en " << conf->position;
  Balise* w = new Balise(_world, robot);
  return new RDS(w, conf->name);
}

void RDSFactory::setWorld(World w) {
  Mesh::setWorld(w);
  this->_world = w;
}
