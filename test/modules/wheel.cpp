#include"wheel.hpp"

//Wheel::Wheel(btDynamicWorld* world, btRigidBody* robot) {}
Wheel::Wheel(btDiscreteDynamicsWorld * world, btRigidBody * robot){}

void Wheel::init() {
}

void Wheel::init(double x, double y, double z, double d, double l) {
  init();
  
  btCollisionShape* wheel = new btCylinderShape(btVector3(0.5,1,0.5));
  btMotionState* wheelMotion = new btDefaultMotionState(btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,3,0))));
  btScalar mass = 1;
  btVector3 wheelInertia(0,0,0);
  wheel->calculateLocalInertia(mass,wheelInertia);
  //btRigidBody::btRigidBodyConstructionInfo wheelRigidBodyCI(mass,fallMotionState,fallShape,fallInertia);
  //_wheel = new btRigidBody(wheelRigidBodyCI);

}
