#include "view_demo.hpp"



BasicDemo::BasicDemo()
{
  pc = new PhysicalCalculator;
}

static BasicDemo::DemoApplication* Create()
{
  BasicDemo* demo = new BasicDemo;
  demo->myinit();
  demo->initPhysics();
  return demo;
}

BasicDemo::~BasicDemo()
{
  delete pc;
  exitPhysics();
}

int myargc;
char** myargv;

void	BasicDemo::initPhysics() {
    setTexturing(true);
    //setShadows(true);
    setCameraDistance(btScalar(340.));
    pc->simple_scene_walls(300);
    m_dynamicsWorld = pc->getScene();
//////////////////////////
    // btCollisionShape* boxA = new btBoxShape(btVector3(1,0.25,1));
    // btCollisionShape* boxB = new btBoxShape(btVector3(15,17.25,15));
    // //btCollisionShape* boxB = new btBoxShape(btVector3(15,17.5,15));
    // btCompoundShape* cyl0 = new btCompoundShape();
    // cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(6,-17,14)),boxA);
    // cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(-6,-17,14)),boxA);
    // cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(6,-17,-14)),boxA);
    // cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(-6,-17,-14)),boxA);
    // cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(0,0.5,0)),boxB);
    //cyl0->addChildShape(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,0)),boxB);

//     btScalar mass = 100;
//     btVector3 localInertia;
//     btDefaultMotionState* MT = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,17.5,0)));
//     cyl0->calculateLocalInertia(mass,localInertia);
//     btRigidBody::btRigidBodyConstructionInfo ci(mass,MT,cyl0,localInertia);
//     //ci.m_startWorldTransform.setOrigin(btVector3(0,3,0));

//     btRigidBody* chassis = new btRigidBody(ci);//1,0,cyl0,localInertia);
//     m_dynamicsWorld->addRigidBody(chassis);
// //////////////////////////
// //btRigidBody* chassis=pc->addBox(btVector3(15,17.5,15), btVector3(0,0,0), 800);
//     //chassis->setFriction(0.020);
//     _robot = new Robot(chassis, pc->getScene());
//     pc->getScene()->addVehicle(_robot);
//      //_MD = new Wheel(pc->getScene(), chassis, btVector3(16,-17.5+4-0.01,0),btVector3(-1,0,0),4,2);
//      //_MG = new Wheel(pc->getScene(), chassis, btVector3(-16,-17.5+4-0.01,0),btVector3(1,0,0),4,2);
//      //_ED = new Wheel(pc->getScene(), chassis, btVector3(16,-17.5+3-0.01,-5),btVector3(-1,0,0),4,2);
//      //_EG = new Wheel(pc->getScene(), chassis, btVector3(-16,-17.5+3-0.01,-5),btVector3(1,0,0),4,2);
//      _MD = new Wheel(_robot, btVector3(16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
//      _MG = new Wheel(_robot, btVector3(-16,-17.5+3-0.00,0),btVector3(0,-1,0),3,true);
//      _ED = new Wheel(_robot, btVector3(19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);
//      _EG = new Wheel(_robot, btVector3(-19,-17.5+3-0.00,0),btVector3(0,-1,0),3,false);
//      /*new Wheel(_robot, btVector3(16, -17.5+0.1, -15), btVector3(0,-1,0),0.2,true);
//      new Wheel(_robot, btVector3(-16, -17.5+0.1, -15), btVector3(0,-1,0),0.2,true);
//      new Wheel(_robot, btVector3(16, -17.5+0.1, 15), btVector3(0,-1,0),0.2,true);
//      new Wheel(_robot, btVector3(-16, -17.5+0.1, 15), btVector3(0,-1,0),0.2,true);*/
//     m_wheelShape = new btCylinderShapeX(btVector3(1,3,3));
//     _dist_sensor = new DistSensor(pc->getScene(),chassis,btVector3(0,-15,14.9),btVector3(0,0,1),btVector3(4,1,1),0.000001);
//     //_dist_sensor = new DistSensor(pc->getScene(),chassis,btVector3(0,-12,15),btVector3(0,0,15),btVector3(4,1,1),0.000001);
}

void	BasicDemo::exitPhysics() {}

void BasicDemo::clientMoveAndDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float ms = getDeltaTimeMicroseconds();
    // static int i=0;
    // if(pc && i) {
    //   if(_dist_sensor->getDist() != 0 && i%500 <250) {
    //     if(_MD)
    //     _MD->setTorque(800);
    //     else
    //     printf("Pas de roue droite\n");
    //     if(_MG)
    //     _MG->setTorque(800);
    //     else
    //     printf("Pas de roue gauche\n");
    //   }
    //   else {
    //      if(_MD)
    //     _MD->setTorque(-800);
    //     else
    //     printf("Pas de roue droite\n");
    //     if(_MG)
    //     _MG->setTorque(-800);
    //     else
    //     printf("Pas de roue gauche\n");
    //   }
    //   //printf("%lf            \r", _robot->getCurrentSpeedKmHour());
    //   printf("%lf            \r", _dist_sensor->getDist());

    // }
      //pc->nextStep(1./120., 2000);
      pc->nextStep(ms/1000000.f,2000);
      //i++;
    renderme();
    glFlush();
    swapBuffers();
    int toto;


  // renderme();
  // glFlush();
  // swapBuffers();
}

	void BasicDemo::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderme();
    //pc->getScene()->debugDrawWorld();
    glFlush();
    swapBuffers();
  }
	void	BasicDemo::clientResetScene() {
    exitPhysics();
    initPhysics();
  }

  void BasicDemo::renderme() {
    if(!pc)
      return;
    btScalar m[16];
    int i;
    btVector3 min,max,wheelColor(1,0,0);
    pc->getScene().getScene()->getBroadphase()->getBroadphaseAabb(min,max);
    // for(i=0; i<_robot->getNumWheels();i++) {
    //   _robot->updateWheelTransform(i, true);
    //   _robot->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(m);
    //   m_shapeDrawer->drawOpenGL(m, m_wheelShape, wheelColor,false,min,max);
    // }
    DemoApplication::renderme();

}
