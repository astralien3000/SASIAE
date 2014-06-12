#include "view_demo.hpp"

BasicDemo::BasicDemo(PhysicalCalculator& pc) {
  setTexturing(true);
  setCameraDistance(btScalar(340.));
  m_dynamicsWorld = pc.getScene();
}

BasicDemo::~BasicDemo() {
}

void BasicDemo::initPhysics() {
  
}

void BasicDemo::clientMoveAndDisplay() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  renderme();
  glFlush();
  swapBuffers();
}

void BasicDemo::displayCallback() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  renderme();
  glFlush();
  swapBuffers();
}

void BasicDemo::renderme() {
  DemoApplication::renderme();
}
