#include <btBulletDynamicsCommon.h>
#include "physics_calculator.hpp"
#include <iostream>

int main () {
    std::cout << "Hello World!" << std::endl;
    PhysicsCalculator * ph_cal=new PhysicsCalculator();
    ph_cal->simple_scene();
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();

  /* Shapes for collision */
  btCollisionShape  *sphereShape;
  sphereShape = new btSphereShape(1);


  btDefaultMotionState* sphereMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,10,0)));
  
  btScalar mass = 1.5;
  btVector3 sphereInertial(0,0,0);
  
  btRigidBody::btRigidBodyConstructionInfo sphereBodyCI(mass, sphereMotionState, sphereShape, sphereInertial);
  btRigidBody* sphereBody = new btRigidBody(sphereBodyCI);
  myscene->addRigidBody(sphereBody);
  for(int i=0; i<500;i++){
    myscene->stepSimulation(1/80.f,20);
    btTransform transformation;
    sphereBody->getMotionState()->getWorldTransform(transformation);
    std::cout << "sphere height: " << transformation.getOrigin().getY() << std::endl;
  }  

  ph_cal->cleanWorld();
  return 0;
}
