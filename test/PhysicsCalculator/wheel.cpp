#include"wheel.hpp"

//Wheel::Wheel(btDynamicWorld* world, btRigidBody* robot) {}
Wheel::Wheel(Robot * robot){
  _robot = robot;
  _wheel_number = -1;
}

Wheel::Wheel(Robot* robot, const btVector3 &pos, const btVector3 &direction, btScalar radius, bool motorized) {
  _robot = robot;
  init(pos, direction, radius, motorized);
}

void Wheel::init(const btVector3 &pos, const btVector3 &direction, btScalar radius, bool motorized) {
  _robot->addWheel(pos,direction, btVector3(-1,0,0),radius,motorized);
  _wheel_number = _robot->getNumWheels();
}

double Wheel::getAngle() {
  return _robot->getWheelInfo(_wheel_number).m_rotation;
}

double Wheel::getTorque() {
  return _robot->getWheelInfo(_wheel_number).m_engineForce;
}

void Wheel::setTorque(double f) {
  _robot->applyEngineForce(f,_wheel_number);
}
