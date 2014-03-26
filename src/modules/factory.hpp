#ifndef FACTORY_HPP
#define FACTORY_HPP

#define Factory_iid "0.1.modules.sasiae.eirbot"

#include "../common/object_config.hpp"
#include <QtPlugin>
#include <QString>

class Robot;
class Module;
class World;

class Factory {
  public:
  static const QString massXmlName; 
  virtual Module* buildModule(Robot* robot,
                              const ObjectConfig::moduleConfig* conf) = 0;
  virtual void setWorld(World w) = 0;
};
Q_DECLARE_INTERFACE(Factory, Factory_iid)

#endif //FACTORY_HPP

