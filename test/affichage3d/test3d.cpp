#include "test3d.hpp"
	void	BasicDemo::initPhysics() {
    setTexturing(true);
    setShadows(true);
    setCameraDistance(btScalar(50.));
    pc->simple_scene_walls(100);
    m_dynamicsWorld = pc->getScene();
btRigidBody* chassis =pc->addBox(btVector3(15,17.5,15), btVector3(0,0,0), 8);
    chassis->setFriction(0.000000000001);
    _robot = new Robot(chassis, pc->getScene());
    pc->getScene()->addVehicle(_robot);
     _MD = new Wheel(_robot, btVector3(16,-17.5+3-0.01,0),btVector3(0,-1,0),3,true);
     _MG = new Wheel(_robot, btVector3(-16,-17.5+3-0.01,0),btVector3(0,-1,0),3,true);
     //_ED = new Wheel(_robot, btVector3(19,-17.5+3,0),btVector3(0,-1,0),3,false);
     //_EG = new Wheel(_robot, btVector3(-19,-17.5+3,0),btVector3(0,-1,0),3,false);
    m_wheelShape = new btCylinderShapeX(btVector3(1,3,3));
    _dist_sensor = new DistSensor(pc->getScene(),chassis,btVector3(0,-16,15),btVector3(0,0,15),btVector3(4,1,1),0.000001);
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
      printf("%lf            \r", _dist_sensor->getDist());

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
