#include "physical_calculator.hpp"

PhysicalCalculator::PhysicalCalculator(){
  _broadphase = new btDbvtBroadphase();
  _collisionConfiguration = new btDefaultCollisionConfiguration();
  _dispatcher = new btCollisionDispatcher(_collisionConfiguration);
  _solver = new btSequentialImpulseConstraintSolver;
  _scene = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration);
}

PhysicalCalculator::~PhysicalCalculator(){
  delete _scene;
  delete _solver;
  delete _dispatcher;
  delete _collisionConfiguration;
  delete _broadphase;
}

void PhysicalCalculator::empty_scene(){
  this->init();
}

btDiscreteDynamicsWorld* PhysicalCalculator::getScene(){
  return _scene ;
}

void PhysicalCalculator::simple_scene(){
  this->init();
  btCollisionShape *planeShape;
  // try with 0 in y coordonate of shape and rigid body
  // --> error, there's no plan and the sphere falls indefinitely
  
  planeShape = new btStaticPlaneShape(btVector3(0,1,0), 1);
  // equivalent : new btBoxShape(btVector3(100,1,100));
  

  //No movement for the ground
  btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));

  btRigidBody::btRigidBodyConstructionInfo groundBodyCI(0, groundMotionState, planeShape, btVector3(0,0,0));
  
  btRigidBody* groundBody = new btRigidBody(groundBodyCI);
  //groundBody->setFriction(1);
  //groundBody->setRollingFriction(1);
  _scene->addRigidBody(groundBody);
}


void PhysicalCalculator::simple_scene_walls(){
  //TODO
}

// void PhysicalCalculator::cleanWorld() {
//   
// }


//! \brief The init method set the gravity
void PhysicalCalculator::init() {
  _scene->setGravity(btVector3(0,-10,0));

}
