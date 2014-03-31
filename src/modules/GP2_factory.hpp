#ifndef GP2_FACTORY_HPP
#define GP2_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class GP2Factory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "GP2_factory.json")

  public:
  GP2Factory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //GP2_FACTORY_HPP
