#ifndef ENCODER_FACTORY_HPP
#define ENCODER_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class EncoderFactory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "encoder_factory.json")

  public:
  EncoderFactory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //ENCODER_FACTORY_HPP
