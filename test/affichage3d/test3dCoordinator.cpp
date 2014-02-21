#include "test3dCoordinator.hpp"

BasicDemo::BasicDemo()
{
  cdn = &Coordinator::getInstance();
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
  exitPhysics();
}

void	BasicDemo::initPhysics() {
  setTexturing(true);
  setShadows(true);
  setCameraDistance(btScalar(50.));
  int a = 0;
  _app = new QApplication(a,NULL);
  /* this function ( in src/coordinator/coordinator/coorcinator.cpp )
   * creates 4 wheels, one robot's body and merges them together.
   *
   *
   */
  m_wheelShape = new btCylinderShapeX(btVector3(1,3,3));
  m_dynamicsWorld =(cdn->getPhysicalCalculatorInstance()).getScene();

  cdn->openTable("coucou");
  cdn->openRobot("Le robot",Coordinator::MAIN_ROBOT1);
  /*
    pc->simple_scene_walls(100);
  */
  //m_dynamicsWorld = cdn->getPhysicalCalculatorScene();
  /*_robot = new Robot(pc->addBox(btVector3(2,0.5,2), btVector3(0,0,0), 8), pc->getScene());
    pc->getScene()->addVehicle(_robot);*/

  // _MD = new Wheel(_robot, btVector3(1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  // _MG = new Wheel(_robot, btVector3(-1.5,-0.1,0),btVector3(0,-1,0),.5,true);
  // _ED = new Wheel(_robot, btVector3(1.9,-0.1,0),btVector3(0,-1,0),.5,false);
  // _EG = new Wheel(_robot, btVector3(-1.9,-0.1,0),btVector3(0,-1,0),.5,false);
}

void	BasicDemo::exitPhysics() {}

void BasicDemo::clientMoveAndDisplay() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //float ms = getDeltaTimeMicroseconds();
  /*if(pc) {
    if(_MD)
    _MD->setTorque(20);
    else
    printf("Pas de roue droite\n");
    if(_MG)
    _MG->setTorque(20);
    else
    printf("Pas de roue gauche\n");
  */
  //cdn->calcNextStep(1/80.f,20);
  cdn->play();
  cdn->pause();
  _app->processEvents();
  /* the function getPhysicalCalculatorInstance is static. Is it wrong ?*/
  printf("%lu            \r", (cdn->getPhysicalCalculatorInstance()).getTime());
  
  
  renderme();
  glFlush();
  swapBuffers();
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
  PhysicalCalculator* pc= &(cdn->getPhysicalCalculatorInstance());
  if(!pc)
    return;
  btScalar m[16];
  int i;
  btVector3 min,max,wheelColor(1,0,0);
  pc->getScene()->getBroadphase()->getBroadphaseAabb(min,max);
  
  /*
    This is very dirty but I don't know how to
    do otherwise.
  */
  Robot *_robot=cdn->getRobot(Coordinator::MAIN_ROBOT1);

  for(i=0; i<_robot->getNumWheels();i++) {
    /*
      this step makes the wheel visible.
      We don't want to use the pc in test3dCoordinator.
      The work need to be done in the class PhysicalCalculator.
    */
    _robot->updateWheelTransform(i, true);
    _robot->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(m);
    m_shapeDrawer->drawOpenGL(m, m_wheelShape, wheelColor,false,min,max);
  }
  DemoApplication::renderme();
}
