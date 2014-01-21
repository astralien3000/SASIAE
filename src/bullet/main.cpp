#include <iostream>
#include <btBulletDynamicsCommon.h>

int main(int argc, char* argv[]) {
  /* Init */
  btBroadphaseInterface* b = new btDbvtBroadphase();
  btDefaultCollisionConfiguration* cc = new btDefaultCollisionConfiguration();
  btCollisionDispatcher* cd = new btCollisionDispatcher(cc);

  btSequentialImpulseConstraintSolver* s = new btSequentialImpulseConstraintSolver;

  btDiscreteDynamicsWorld* w = new btDiscreteDynamicsWorld(cd, b, s, cc);
  w->setGravity(btVector3(0,-9.8,0));

  /* Shapes for collision */
  btCollisionShape *planeShape, *sphereShape;
  planeShape = new btStaticPlaneShape(btVector3(0,1,0), 1);
  sphereShape = new btSphereShape(1);

  /* Bodies */
  btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));
  btRigidBody::btRigidBodyConstructionInfo groundBodyCI(0, groundMotionState, planeShape, btVector3(0,0,0));
  btRigidBody* groundBody = new btRigidBody(groundBodyCI);

  w->addRigidBody(groundBody);

  btDefaultMotionState* sphereMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,10,0)));
  
  btScalar mass = 1.5;
  btVector3 sphereInertial(0,0,0);
  
  btRigidBody::btRigidBodyConstructionInfo sphereBodyCI(mass, sphereMotionState, sphereShape, sphereInertial);
  btRigidBody* sphereBody = new btRigidBody(sphereBodyCI);
  w->addRigidBody(sphereBody);
  for(int i=0; i<500;i++){
    w->stepSimulation(1/80.f,20);
    btTransform transformation;
    sphereBody->getMotionState()->getWorldTransform(transformation);
    std::cout << "sphere height: " << transformation.getOrigin().getY() << std::endl;
  }  
  delete w;  
  delete b;
  delete cc;
  delete cd;
  delete s;

  return 0;
}
