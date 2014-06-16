#ifndef OBJECT_CONFIG_HPP
#define OBJECT_CONFIG_HPP

#include "position_data.hpp"
#include <QList>
#include <QString>
#include <QHash>

namespace ObjectConfig {
  struct meshConfig {
    QString path;
    float scale;
    PositionData offset;
  };

  struct robotConfig {
    float weight;
    meshConfig mesh;
    //QList<const microConfig*> microcontrollers;
    QString img_path;
  };
};

#endif
