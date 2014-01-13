
#include "robot.hpp"
#include "wheel.hpp"
#include "physical_calculator.hpp"
#include <iostream>
#include <btBulletDynamicsCommon.h>

btRigidBody * create_sphere(btDiscreteDynamicsWorld * myscene){
 /* Shapes for collision */
  btCollisionShape  *sphereShape;
  sphereShape = new btSphereShape(1);

  btDefaultMotionState* sphereMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,10,0)));
  btScalar mass = 1.5;
  btVector3 sphereInertial(0,0,0);
  btRigidBody::btRigidBodyConstructionInfo sphereBodyCI(mass, sphereMotionState, sphereShape, sphereInertial);
  btRigidBody* sphereBody = new btRigidBody(sphereBodyCI);
  myscene->addRigidBody(sphereBody);
  return sphereBody;
}

void a_sphere_goes_down(btDiscreteDynamicsWorld * myscene,btRigidBody * sphereBody){
   for(int i=0; i<500;i++){
    myscene->stepSimulation(1/80.f,20);
    btTransform transformation;
    sphereBody->getMotionState()->getWorldTransform(transformation);
    std::cout << "sphere height: " << transformation.getOrigin().getY() << std::endl;
  }  

}

int test1 () {
    std::cout << "Hello World!" << std::endl;
    PhysicalCalculator * ph_cal=new PhysicalCalculator();
    ph_cal->simple_scene();
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();

    a_sphere_goes_down(myscene,create_sphere(myscene));
    ph_cal->cleanWorld();
  return EXIT_SUCCESS;
}

int test2 () {
  PhysicalCalculator * ph_cal=new PhysicalCalculator();
  ph_cal->simple_scene();
  btDiscreteDynamicsWorld * myscene=ph_cal->getScene();
  //chassis du robot
  btCollisionShape* boxShape = new btBoxShape(btVector3(10,10,10));

  btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,5,0)));
  btScalar mass = 1.5;
  btVector3 boxInertial(0,0,0);
  boxShape->calculateLocalInertia(mass, boxInertial);
  btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
  btRigidBody* chassis = new btRigidBody(boxBodyCI);
  //myscene->addRigidBody(chassis);

  //fin chassis
  Robot* robot = new Robot(chassis, myscene);
  robot->setCoordinateSystem(0,1,2);
  Wheel* w1 = new Wheel(robot, btVector3(0,5,2),btVector3(0,-1,0),10,true);
  Wheel* w2 = new Wheel(robot, btVector3(0,-5,2),btVector3(0,-1,0),10,true);
  Wheel* w3 = new Wheel(robot, btVector3(12,5,2),btVector3(0,-1,0),10,true);
  Wheel* w4 = new Wheel(robot, btVector3(12,-5,2),btVector3(0,-1,0),10,true);
  
  myscene->addVehicle(robot);

  for(int i=0;i<500;i++) {
    myscene->stepSimulation(1/80.f,20);
    w1->setTorque(10);
    w2->setTorque(10);
    btTransform trans;
    trans = robot->getChassisWorldTransform();
    std::cout << i 
	      << " "<< w1->getAngle() 

	      << " "<< trans.getOrigin().getY() 
	      << " "<< robot->getWheelInfo(0).m_worldTransform.getOrigin().getY() 
	      << " "<< robot->getWheelInfo(1).m_worldTransform.getOrigin().getY() 
	      << " "<< robot->getWheelInfo(2).m_worldTransform.getOrigin().getY() 
	      << " "<< robot->getWheelInfo(3).m_worldTransform.getOrigin().getY() 
	      << " "<< robot->getCurrentSpeedKmHour()
	      << std::endl;

  } 



}

int main () {
  //return test1();
  return test2();
}

