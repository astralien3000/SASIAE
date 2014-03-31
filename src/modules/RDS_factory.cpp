#include "RDS_factory.hpp"

#include "../physical_calculator/dist_sensor.hpp"
#include "../physical_calculator/world.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "RDS.hpp"
#include <QVector3D>

RDSFactory::RDSFactory() : QObject() {}

Module* RDSFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle RDS en " << conf->position;
  if(!conf->parameters.contains(RDS::maxDistXmlName) && 
     !conf->parameters.contains(DistSensor::widthXmlName) && 
     !conf->parameters.contains(DistSensor::heightXmlName) &&
     !conf->parameters.contains(DistSensor::depthXmlName) &&
     !conf->parameters.contains(Factory::massXmlName)
     ) {
    qDebug() <<"Impossible de cree un RDS, des parametres sont manquant";
    return NULL;
  }
  DistSensor* w = new DistSensor(robot, conf->position, PositionData(0,0,1,0,0,0), 
                            QVector3D(conf->parameters.value(DistSensor::widthXmlName).toFloat(),
                            conf->parameters.value(DistSensor::heightXmlName).toFloat(),
                            conf->parameters.value(DistSensor::depthXmlName).toFloat()),
                            conf->parameters.value(Factory::massXmlName).toFloat());
  return new RDS(w,conf->parameters.value(RDS::maxDistXmlName).toInt(),
                          conf->name);
}

void RDSFactory::setWorld(World w) {
  Mesh::setWorld(w);
}
