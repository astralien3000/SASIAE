#include "encoder_factory.hpp"

#include "../physical_calculator/wheel.hpp"
#include "../common/position_data.hpp"
#include "module.hpp"
#include "encoder.hpp"

EncoderFactory::EncoderFactory() : QObject() {}

Module* EncoderFactory::buildModule(Robot* robot,const ObjectConfig::moduleConfig* conf)
{
  qDebug() << "creation d'une nouvelle Encoder en " << conf->position;
  if(!conf->parameters.contains(Wheel::xmlRadiusName) && 
     !conf->parameters.contains(Encoder::xmlAccuracyName)) {
    qDebug() <<"Impossible de cree une roue codeuse, des parametres sont manquant";
    return NULL;
  }
  Wheel* w = new Wheel(robot, conf->position, PositionData(0,-1,0,0,0,0), conf->parameters.value(Wheel::xmlRadiusName).toFloat(), true);
  return new Encoder(w,conf->parameters.value(Encoder::xmlAccuracyName).toInt(),
                          conf->name);


}
void EncoderFactory::setWorld(World w) {
  Q_UNUSED(w);
}
