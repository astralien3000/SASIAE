#include "view_demo.hpp"

#include "../physical_calculator/physical_calculator.hpp"

#include <btBulletDynamicsCommon.h>

#include <vector>
#include <iostream>

// WARNING : used elsewhere in the code without include !!
std::vector<btRaycastVehicle*> robots;

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
    btScalar m[16];
    btVector3 min(-1000,-1000,-1000), max(1000,1000,1000), color(1,0,0);

    for(int i = 0 ; i < robots.size() ; i++) {
        for(int j = 0 ; j < robots[i]->getNumWheels() ; j++) {
            double radius = robots[i]->getWheelInfo(j).m_wheelsRadius;
            btCylinderShapeX* wheel_shape = new btCylinderShapeX(btVector3(0.1,radius,radius));

            robots[i]->updateWheelTransform(j, true);
            robots[i]->getWheelInfo(j).m_worldTransform.getOpenGLMatrix(m);
            m_shapeDrawer->drawOpenGL(m, wheel_shape, color, false, min, max);

            delete wheel_shape;
        }
    }

    DemoApplication::renderme();
}
