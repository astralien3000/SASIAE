#ifndef MOTOR_WHEEL_FACTORY_HPP
#define MOTOR_WHEEL_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class MotorWheelFactory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "motor_wheel_factory.json")

  public:
  MotorWheelFactory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //MOTOR_WHEEL_FACTORY_HPP
