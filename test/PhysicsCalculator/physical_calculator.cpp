#include "physical_calculator.hpp"

PhysicalCalculator::PhysicalCalculator(){
  _broadphase = new btDbvtBroadphase();
  _collisionConfiguration = new btDefaultCollisionConfiguration();
  _dispatcher = new btCollisionDispatcher(_collisionConfiguration);
  _solver = new btSequentialImpulseConstraintSolver;
  _scene = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration);
  _scene->setGravity(btVector3(0,-10,0));
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
  btCollisionShape *planeShape;//, *sphereShape;
  // TODO try with 0 in y coordonate of shape and rigid body 
  //planeShape = new btStaticPlaneShape(btVector3(0,1,0), 1);
  
  planeShape = new btBoxShape(btVector3(100,1,100));
  //No movement for the ground
  
  btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));
  btRigidBody::btRigidBodyConstructionInfo groundBodyCI(0, groundMotionState, planeShape, btVector3(0,0,0));
  btRigidBody* groundBody = new btRigidBody(groundBodyCI);

  _scene->addRigidBody(groundBody);
}

void PhysicalCalculator::cleanWorld() {
  //TODO
}
void PhysicalCalculator::init() {
  // TODO
}
