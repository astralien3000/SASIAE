#include "servo_factory.hpp"

#include "../physical_calculator/dist_sensor.hpp"
#include "../physical_calculator/world.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "servo.hpp"
#include <QVector3D>

ServoFactory::ServoFactory() : QObject() {}

Module* ServoFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle Servo en " << conf->position;
  return new Servo(0, conf->name);
}

void ServoFactory::setWorld(World w) {
  Mesh::setWorld(w);
}
