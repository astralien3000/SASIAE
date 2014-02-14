#ifndef DIST_SENSOR_HPP
#define DIST_SENSOR_HPP

#include <btBulletDynamicsCommon.h>

class DistSensor {
public:
  DistSensor(btDynamicsWorld* world, btRigidBody* chassis = NULL);
  DistSensor(btDynamicsWorld* world, btRigidBody* chassis, const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass = btScalar(0.001));
  void init(const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass = btScalar(0.001));
  double getCachedDist();
  double getDist();
  void calcDist();
private:
  btRigidBody* _chassis;
  btRigidBody* _sensor_box;
  double _cache;
  btDynamicsWorld* _world;

};
#endif
