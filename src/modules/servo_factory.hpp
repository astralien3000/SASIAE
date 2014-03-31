#ifndef Servo_FACTORY_HPP
#define Servo_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class ServoFactory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "servo_factory.json")

  public:
  ServoFactory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //Servo_FACTORY_HPP
