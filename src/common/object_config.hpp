#ifndef OBJECT_CONFIG_HPP
#define OBJECT_CONFIG_HPP

#include "position_data.hpp"
#include <QList>
#include <QString>
#include <QHash>

namespace ObjectConfig {
  struct moduleConfig {
    QString name;
    QString type;
    PositionData position;
    QHash<QString /*name*/,QString /*value*/> parameters;
    ~moduleConfig();
  };
  
  struct microConfig {
    QString name;
    QString bin;
    QList<const moduleConfig*> modules;
    ~microConfig();
  };
  
  struct meshConfig {
    QString path;
    float scale;
    PositionData offset;
  };
  
  struct robotConfig {
    float weight;
    meshConfig mesh;
    QList<const microConfig*> microcontrollers;
    QString img_path;
    ~robotConfig();
  };
  
  struct toyConfig {
    PositionData position;
    meshConfig mesh;
    QString name;
    QString img_path;
    int weight;
  };
  
  struct tableConfig {
    meshConfig mesh;
    QString img_path;
    QList<const toyConfig*> toys;
    ~tableConfig();
  };
};

#endif
