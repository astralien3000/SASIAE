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


/*
  The position vector points to the center of
  the box. The size vector goes from the position 
  to a vertex of the box.
 */
void PhysicalCalculator::addBox(btVector3 size, btVector3 position, btScalar mass){
  btDiscreteDynamicsWorld * myscene=getScene();
  //everything's divided by two : the vector goes from the center.
  btCollisionShape* boxShape = new btBoxShape(size);
  btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),position));
  btVector3 boxInertial(0,0,0);
  boxShape->calculateLocalInertia(mass, boxInertial);
  btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
  btRigidBody* newbox = new btRigidBody(boxBodyCI);
  myscene->addRigidBody(newbox);
}

void PhysicalCalculator::empty_scene(){
  this->init();
}

btDiscreteDynamicsWorld* PhysicalCalculator::getScene(){
  return _scene ;
}

void PhysicalCalculator::simple_scene(btScalar size){
  this->init();
  btCollisionShape *planeShape;
  
  //new btStaticPlaneShape(btVector3(0,1,0), 1);
  planeShape = new btBoxShape(btVector3(size,1,size));
  

  //No movement for the ground
  btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));

  btRigidBody::btRigidBodyConstructionInfo groundBodyCI(0, groundMotionState, planeShape, btVector3(0,0,0));
  
  btRigidBody* groundBody = new btRigidBody(groundBodyCI);
  //groundBody->setFriction(1);
  //groundBody->setRollingFriction(1);
  _scene->addRigidBody(groundBody);
}


void PhysicalCalculator::simple_scene_walls(btScalar size){
  simple_scene(size);
  addBox(btVector3(size,1,2),btVector3(size-4,1,0),80);
  addBox(btVector3(size,1,2),btVector3(0,1,size-4),80);
  addBox(btVector3(size,1,2),btVector3(-(size-4),1,0),80);
  addBox(btVector3(size,1,2),btVector3(0,1,-(size-4)),80);
  
}

void PhysicalCalculator::nextStep(float time=1/80.f, int addedoperations=20){
  _scene->stepSimulation(time,addedoperations);
}

void PhysicalCalculator::init() {
  _scene->setGravity(btVector3(0,-10,0));

}