#include "wheel.h"

Wheel::Wheel(btDynamicsWorld* world, btRigidBody* robot) : _world(world), _robot(robot) {

}
Wheel::~Wheel() {
  if(_wheel != NULL) {
    _world->removeRigidBody(_wheel);
    delete _wheel->getMotionState();
    delete _wheel;
    delete _wheelShape;
  }
}
void Wheel::init() {
}
btVector3 Wheel::getPos() {
  btTransform trans;
  _wheel->getMotionState()->getWorldTransform(trans);
  return trans.getOrigin();  
}
void Wheel::init(double x, double y, double z, double r, double l) {
  init();
  
  btCollisionShape* _wheelShape = new btCylinderShapeZ(btVector3(r,l,r));
  btMotionState* wheelMotion = new
btDefaultMotionState(btDefaultMotionState(btTransform(btQuaternion(),btVector3(x,y,z))));
  btScalar mass = 1;
  btVector3 wheelInertia(0,0,0);
  _wheelShape->calculateLocalInertia(mass,wheelInertia);
  btRigidBody::btRigidBodyConstructionInfo wheelRigidBodyCI(mass,wheelMotion,_wheelShape,wheelInertia);
  _wheel = new btRigidBody(wheelRigidBodyCI);
	_wheel->setFriction(1.);
	_wheel->setRollingFriction(0.3);
  _world->addRigidBody(_wheel);

}

double Wheel::getAngle() {
  btTransform trans;
  _wheel->getMotionState()->getWorldTransform(trans);
  btQuaternion q = trans.getRotation();
  //return q.getAngle();  
  btScalar z,y,x;
  trans.getBasis().getEulerYPR(x,y,z);
  return x;
  
  //return trans.getRotation().angle(btQuaternion(0,0,1,1));  
}

double Wheel::getTorque() {
  return _wheel->getTotalTorque().getZ();
}

void Wheel::setTorque(double f) {
  _wheel->applyTorque(btVector3(0,0,f));
}
