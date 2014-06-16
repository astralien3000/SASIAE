#include "view_demo.hpp"

#include "../physical_calculator/physical_calculator.hpp"

#include <btBulletDynamicsCommon.h>


BasicDemo::BasicDemo(void) {
  setTexturing(true);
  setCameraDistance(btScalar(340.));
  m_dynamicsWorld = MyPhysicalCalculator::getIntance().getWorld();
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
