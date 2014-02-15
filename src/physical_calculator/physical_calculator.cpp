#include "physical_calculator.hpp"


PhysicalCalculator::PhysicalCalculator(QObject* parent):QObject(parent){
  _broadphase = new btDbvtBroadphase();
  _collisionConfiguration = new btDefaultCollisionConfiguration();
  _dispatcher = new btCollisionDispatcher(_collisionConfiguration);
  _solver = new btSequentialImpulseConstraintSolver;
  _scene = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration);
  _clock= new btClock();
}

PhysicalCalculator::~PhysicalCalculator(){
  delete _scene;
  delete _clock;
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
btRigidBody* PhysicalCalculator::addBox(btVector3 size, btVector3 position, btScalar mass){
  btDiscreteDynamicsWorld * myscene=getScene();
  //everything's divided by two : the vector goes from the center.
  btCollisionShape* boxShape = new btBoxShape(size);
  btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),position));
  btVector3 boxInertial(0,0,0);
  boxShape->calculateLocalInertia(mass, boxInertial);
  btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
  btRigidBody* newbox = new btRigidBody(boxBodyCI);
  myscene->addRigidBody(newbox);
  return newbox;
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
  //planeShape = new btBoxShape(btVector3(50,50,50));
  

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
  addBox(btVector3(size,10,2),btVector3(0,10,size+2),0);
  addBox(btVector3(2,10,size),btVector3(size+2,10,0),0);
  addBox(btVector3(size,10,2),btVector3(0,10,-size-2),0);
  addBox(btVector3(2,10,size),btVector3(-size-2,10,0),0);
  
}

void PhysicalCalculator::nextStep(float time, int addedoperations){
  _scene->stepSimulation(time,addedoperations);
}

unsigned long int PhysicalCalculator::getTime() const{
  return _clock->getTimeMilliseconds();
}

void PhysicalCalculator::init() {
  _scene->setGravity(btVector3(0,-10,0));

}
