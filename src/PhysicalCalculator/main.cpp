#include "robot.hpp"
#include "wheel.hpp"
#include "physical_calculator.hpp"
#include <iostream>
#include <btBulletDynamicsCommon.h>


#define SIZE 100
#define ITERATION_NUMBER 400

btRigidBody * create_sphere(btDiscreteDynamicsWorld * myscene, int size, btVector3 position, btScalar mass){
   btCollisionShape  *sphereShape;
    btDefaultMotionState* sphereMotionState;
    btRigidBody* sphereBody;

 /* Shapes for collision */
  sphereShape = new btSphereShape(size);
  sphereMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),position));
  btVector3 sphereInertial(0,0,0);
  btRigidBody::btRigidBodyConstructionInfo sphereBodyCI(mass, sphereMotionState, sphereShape, sphereInertial);
  sphereBody = new btRigidBody(sphereBodyCI);
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


int test_fall_of_a_sphere() {
    std::cout << "physical calculator initialisation" << std::endl;
    PhysicalCalculator * ph_cal=new PhysicalCalculator();
    std::cout << "Simple scene creation ..." << std::endl;
    ph_cal->simple_scene((btScalar)SIZE);
    std::cout << "test getScene() ..." << std::endl;
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();
    std::cout << "Test sphere going down to the ground ..." << std::endl;
 
    a_sphere_goes_down(myscene,create_sphere(myscene,1,btVector3(50,10,50),1.5));
    std::cout << "Test destructor of physical calculator ..." << std::endl;
  
    delete ph_cal;
    
    return EXIT_SUCCESS;
}


//! \brief test2 creates a simple scene
//  and a robot with 4 wheels.
//
int test_robot_moves () {
  PhysicalCalculator * ph_cal=new PhysicalCalculator();
  ph_cal->simple_scene_walls((btScalar)SIZE);
  btDiscreteDynamicsWorld * myscene=ph_cal->getScene();


  //chassis du robot
      //les coordonnées sont pour un quart de la boite 
  btCollisionShape* boxShape = new btBoxShape(btVector3(2,0.5,2));
  btDefaultMotionState* boxMotionState = new
btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0.7,0)));
  btScalar mass = 8;
  btVector3 boxInertial(0,0,0);
  boxShape->calculateLocalInertia(mass, boxInertial);
  btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
  btRigidBody* chassis = new btRigidBody(boxBodyCI);
  myscene->addRigidBody(chassis);
  //fin chassis

  //Ajout d'une boite devant le robot
  ph_cal->addBox(btVector3(5,5,5),btVector3(0,5,10),2000);

  /*
    C'est pas encore totalement concluant. La pièce est très 
    lourde ( 2000 >> 8 ) mais le robot la déplace quand même.
    Il faut se pencher sur les frottements peut être.
   */


  Robot* robot = new Robot(chassis, myscene);
  myscene->addVehicle(robot);
  Wheel* moteurD = new Wheel(robot, btVector3(1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  Wheel* moteurG = new Wheel(robot, btVector3(-1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  Wheel* encodeurD = new Wheel(robot, btVector3(1.9,-0.1,0),btVector3(0,-1,0),.5,false);
  Wheel* encodeurG = new Wheel(robot, btVector3(-1.9,-0.1,0),btVector3(0,-1,0),.5,false);
//robot->addWheel(btVector3(1.9,-0.1,0),btVector3(0,-1,0),btVector3(-1,0,0),0.5,true); 
 //robot->addWheel(btVector3(-1.9,-0.1,0),btVector3(0,-1,0),btVector3(-1,0,0),0.5,true); 
  
for(int i=0;i<ITERATION_NUMBER;i++) {
    myscene->stepSimulation(1/80.f,20);
    moteurD->setTorque(3000);
    moteurG->setTorque(3000);
    btTransform trans;
    trans = robot->getChassisWorldTransform();
    btScalar z,y,x;
	      trans.getBasis().getEulerZYX(z,y,x);
    std::cout << i 
	      << "| X :"<< trans.getOrigin().getX() 
	      << "|  Y:"<< trans.getOrigin().getY() 
	      << "|  Z:"<< trans.getOrigin().getZ() 
	      << "| "<< moteurD->getTorque() /SIZE

	      << " "<< encodeurD->getRotation()
	      //<< " "<< robot->getCurrentSpeedKmHour()
	      << std::endl;

  } 


  return EXIT_SUCCESS;
}

int main () {
  //valgrind shows some leaks on test1
  //return test_fall_of_a_sphere();
  return test_robot_moves();
  

}

