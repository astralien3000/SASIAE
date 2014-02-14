#include "test3d.hpp"
	void	BasicDemo::initPhysics() {
    setTexturing(true);
    setShadows(true);
    setCameraDistance(btScalar(50.));
    pc->simple_scene_walls(100);
    m_dynamicsWorld = pc->getScene();
    _robot = new Robot(pc->addBox(btVector3(2,0.5,2), btVector3(0,0,0), 8), pc->getScene());
    pc->getScene()->addVehicle(_robot);
     _MD = new Wheel(_robot, btVector3(1.5,-0.1,0),btVector3(0,-1,0),.5,true);
     _MG = new Wheel(_robot, btVector3(-1.5,-0.1,0),btVector3(0,-1,0),.5,true);
     _ED = new Wheel(_robot, btVector3(1.9,-0.1,0),btVector3(0,-1,0),.5,false);
     _EG = new Wheel(_robot, btVector3(-1.9,-0.1,0),btVector3(0,-1,0),.5,false);
    m_wheelShape = new btCylinderShapeX(btVector3(1,0.5,0.5));
}

	void	BasicDemo::exitPhysics() {}

	void BasicDemo::clientMoveAndDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float ms = getDeltaTimeMicroseconds();
    if(pc) {
      if(_MD)
      _MD->setTorque(20);
      else
      printf("Pas de roue droite\n");
      if(_MG)
      _MG->setTorque(20);
      else
      printf("Pas de roue gauche\n");
      pc->nextStep();
      printf("%lu            \r", pc->getTime());

    }
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
    printf("toto\n");
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
    pc->getScene()->getBroadphase()->getBroadphaseAabb(min,max);
    for(i=0; i<_robot->getNumWheels();i++) {
      _robot->updateWheelTransform(i, true);
      _robot->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(m);
      m_shapeDrawer->drawOpenGL(m, m_wheelShape, wheelColor,false,min,max);
    }
    DemoApplication::renderme();
  }
