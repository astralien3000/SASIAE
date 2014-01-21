#include "wheel.hpp"
//Wheel::Wheel(btDynamicWorld* world, btRigidBody* robot) {}
Wheel::Wheel(){
  _rotation = 0;
  _torque = 0;
}

double Wheel::getRotation() {
  return _rotation;
}

double Wheel::getTorque() {
  return _torque;
}

void Wheel::setTorque(double f) {
  _torque = f;
}

