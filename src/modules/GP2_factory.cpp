#include "GP2_factory.hpp"

#include "../physical_calculator/dist_sensor.hpp"
#include "../physical_calculator/world.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "GP2.hpp"
#include <QVector3D>

GP2Factory::GP2Factory() : QObject() {}

Module* GP2Factory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle GP2 en " << conf->position;
  if(!conf->parameters.contains(GP2::maxDistXmlName) && 
     !conf->parameters.contains(DistSensor::widthXmlName) && 
     !conf->parameters.contains(DistSensor::heightXmlName) &&
     !conf->parameters.contains(DistSensor::depthXmlName) &&
     !conf->parameters.contains(Factory::massXmlName)
     ) {
    qDebug() <<"Impossible de cree un GP2, des parametres sont manquant";
    return NULL;
  }
  DistSensor* w = new DistSensor(robot, conf->position, PositionData(0,0,1,0,0,0), 
                            QVector3D(conf->parameters.value(DistSensor::widthXmlName).toFloat(),
                            conf->parameters.value(DistSensor::heightXmlName).toFloat(),
                            conf->parameters.value(DistSensor::depthXmlName).toFloat()),
                            conf->parameters.value(Factory::massXmlName).toFloat());
  return new GP2(w,conf->parameters.value(GP2::maxDistXmlName).toInt(),
                          conf->name);
}

void GP2Factory::setWorld(World w) {
  Mesh::setWorld(w);
}
