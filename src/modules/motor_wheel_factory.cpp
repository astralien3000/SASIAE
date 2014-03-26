#include "motor_wheel_factory.hpp"

#include "../physical_calculator/wheel.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "motor_wheel.hpp"

MotorWheelFactory::MotorWheelFactory() : QObject() {}

Module* MotorWheelFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'un nouveau motorwheel en " << conf->position;
  if(!conf->parameters.contains(Wheel::xmlRadiusName) && 
     !conf->parameters.contains(MotorWheel::xmlTorqueName) && 
     !conf->parameters.contains(MotorWheel::xmlGearName)) {
    qDebug() <<"Impossible de cree une roue motrice, des parametres sont manquant";
    return NULL;
  }
  Wheel* w = new Wheel(robot, conf->position, PositionData(0,-1,0,0,0,0), conf->parameters.value(Wheel::xmlRadiusName).toFloat(), true);
  return new MotorWheel(w,conf->parameters.value(MotorWheel::xmlTorqueName).toDouble(),
                          conf->parameters.value(MotorWheel::xmlGearName).toDouble(),
                          conf->name);
}
void MotorWheelFactory::setWorld(World w) {
  Q_UNUSED(w);
}
