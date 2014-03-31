#ifndef DigitalServo_FACTORY_HPP
#define DigitalServo_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class DigitalServoFactory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "digital_servo_factory.json")

  public:
  DigitalServoFactory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //DigitalServo_FACTORY_HPP
