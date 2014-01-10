#ifndef WHEEL_HPP
#define WHEEL_HPP

#include "robot.hpp"
#include <btBulletDynamicsCommon.h>

class Wheel {
public: 
  Wheel(Robot *robot);
  Wheel(Robot* robot, const btVector3 &pos,const btVector3 &direction, btScalar radius, bool motorized);
  void init(const btVector3 &pos, const btVector3 &direction, btScalar radius, bool motorized);
  //double getAngularSpeed();
  double getAngle();
  double getTorque();
  void setTorque(double f);
private:
  int _wheel_number;
  Robot* _robot;
};

#endif
