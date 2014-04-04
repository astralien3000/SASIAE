#include "digital_servo_factory.hpp"

#include "../physical_calculator/dist_sensor.hpp"
#include "../physical_calculator/world.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "digital_servo.hpp"
#include <QVector3D>

DigitalServoFactory::DigitalServoFactory() : QObject() {}

Module* DigitalServoFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle DigitalServo en " << conf->position;
  return new DigitalServo(conf->name);
}

void DigitalServoFactory::setWorld(World w) {
  Mesh::setWorld(w);
}
