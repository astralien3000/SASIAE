#include"wheel.hpp"
#include <iostream>

//Wheel::Wheel(btDynamicWorld* world, btRigidBody* robot) {}
Wheel::Wheel(Robot * robot){
  _robot = robot;
  _wheel_number = -1;
}

Wheel::Wheel(Robot* robot, const QVector3D &pos, const QVector3D &direction, float radius, bool motorized) {
  _robot = robot;
  init(pos, direction, radius, motorized);
}


//direction de la suspension donc = btVector3(0,-1,0);
//pos ne doit pas etre en dehors de l'objet
void Wheel::init(const QVector3D &pos, const QVector3D &direction, float radius, bool motorized) {
/*
 * Change QVector3D into btVector3, float into btScalar
*/

btVector3 bpos(pos.x(),pos.y(),pos.z());
btVector3 bdirection(direction.x(),direction.y(),direction.z());
btScalar bradius(radius);

//pour avancer sur l'axe Z, il faut que l'axe de la roue IE le vecteur du moment soit
//sur X
  btWheelInfo& wheel = _robot->addWheel(bpos,bdirection, btVector3(-1,0,0),bradius,motorized);
      wheel.m_suspensionStiffness = 20.f;//suspensionStiffness;
      wheel.m_wheelsDampingRelaxation = 2.3f;//suspensionDamping;
      wheel.m_wheelsDampingCompression = 4.4f;//suspensionCompression;  
      wheel.m_maxSuspensionTravelCm = 0;
      wheel.m_frictionSlip = 1000;//wheelFriction;
      wheel.m_rollInfluence = .7f;//rollInfluence;
  _wheel_number = _robot->getNumWheels() - 1;
}

double Wheel::getRotation() {
  return _robot->getWheelInfo(_wheel_number).m_rotation;
}

double Wheel::getTorque() {
  return _robot->getWheelInfo(_wheel_number).m_engineForce;
}

void Wheel::setTorque(double f) {
  if(f == 0) 
    _robot->setBrake(100000,_wheel_number);
  else
  _robot->applyEngineForce(f,_wheel_number);
}
