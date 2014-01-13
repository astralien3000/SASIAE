
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
      //les coordonnées sont pour un quart de la boite 
  btCollisionShape* boxShape = new btBoxShape(btVector3(2,0.5,2));
  btDefaultMotionState* boxMotionState = new
btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0.7,0)));
  btScalar mass = 80;
  btVector3 boxInertial(0,0,0);
  boxShape->calculateLocalInertia(mass, boxInertial);
  btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
  btRigidBody* chassis = new btRigidBody(boxBodyCI);
  myscene->addRigidBody(chassis);
  //fin chassis

  Robot* robot = new Robot(chassis, myscene);
  myscene->addVehicle(robot);
  Wheel* moteurD = new Wheel(robot, btVector3(1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  Wheel* moteurG = new Wheel(robot, btVector3(-1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  Wheel* encodeurD = new Wheel(robot, btVector3(1.9,-0.1,0),btVector3(0,-1,0),.5,false);
  Wheel* encodeurG = new Wheel(robot, btVector3(-1.9,-0.1,0),btVector3(0,-1,0),.5,false);
//robot->addWheel(btVector3(1.9,-0.1,0),btVector3(0,-1,0),btVector3(-1,0,0),0.5,true); 
 //robot->addWheel(btVector3(-1.9,-0.1,0),btVector3(0,-1,0),btVector3(-1,0,0),0.5,true); 
  
for(int i=0;i<500;i++) {
    myscene->stepSimulation(1/80.f,20);
    moteurD->setTorque(3000);
    moteurG->setTorque(3000);
    btTransform trans;
    trans = robot->getChassisWorldTransform();
    btScalar z,y,x;
	      trans.getBasis().getEulerZYX(z,y,x);
    std::cout << i 
	   //   << " "<< w1->getAngle() 
	      << " "<< trans.getOrigin().getX() 
	      << " "<< trans.getOrigin().getY() 
	      << " "<< trans.getOrigin().getZ() 
	      << " "<< moteurD->getTorque() /100

	      << " "<< encodeurD->getRotation()
	      //<< " "<< robot->getCurrentSpeedKmHour()
	      << std::endl;

  } 


  return EXIT_SUCCESS;
}

int main () {
  //return test1();
  return test2();
}

