#ifndef DIST_SENSOR_HPP
#define DIST_SENSOR_HPP

#include <btBulletDynamicsCommon.h>
#include "world.hpp"
#include "robot.hpp"
#include "mesh.hpp"
#include <QVector3D>

class DistSensor {
  static int MAX_DIST;

public:
  DistSensor(World world, Robot* chassis);
  DistSensor(World world, Robot* chassis, const PositionData pos, const PositionData direction, const QVector3D & box, float mass = 0.001);
  void init(const PositionData pos, const PositionData direction, const QVector3D& boxSize, float mass = .001);
  double getCachedDist();
  double getDist();
  void calcDist();

private:
  Robot* _chassis;
  Mesh* _sensor_box;
  float _box_depth;
  double _cache;
  World _world;

};
#endif
