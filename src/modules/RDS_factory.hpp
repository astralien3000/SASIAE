#ifndef RDS_FACTORY_HPP
#define RDS_FACTORY_HPP

#include "factory.hpp"
#include <QObject>

class RDSFactory : public QObject, public Factory {
  Q_OBJECT
  Q_INTERFACES(Factory)
  Q_PLUGIN_METADATA(IID Factory_iid FILE "RDS_factory.json")

  public:
  RDSFactory();
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf);
  virtual void setWorld(World w);
};

#endif //RDS_FACTORY_HPP
