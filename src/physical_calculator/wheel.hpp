#ifndef WHEEL_HPP
#define WHEEL_HPP

#include "robot.hpp"
#include <btBulletDynamicsCommon.h>
#include <QVector3D>

class Wheel {
public: 
  Wheel(Robot *robot = NULL);
  Wheel(Robot* robot, const QVector3D &pos,const QVector3D &direction, float radius, bool motorized);
  /* init is called in the constructor right above. 
   * But not in the first one. 
   */
  void init(const QVector3D &pos, const QVector3D &direction, float radius, bool motorized);
  double getRotation();
  double getTorque();
  void setTorque(double f);
private:
  int _wheel_number;
  Robot* _robot;
};

#endif
