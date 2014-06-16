#include "simple_scene.hpp"

#include "physical_calculator.hpp"

#include <btBulletDynamicsCommon.h>

SimpleScene::SimpleScene(std::string name, double size)
    : PhysicalObject(name) {

    btCollisionShape *plane_shape;

    plane_shape = new btBoxShape(btVector3(size,1,size));


    //No movement for the ground
    btDefaultMotionState* ground_motion_state = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));

    btRigidBody::btRigidBodyConstructionInfo ground_body_ci(0, ground_motion_state, plane_shape, btVector3(0,0,0));

    btRigidBody* ground_body = new btRigidBody(ground_body_ci);
    MyPhysicalCalculator::getIntance().getWorld()->addRigidBody(ground_body);
}

SimpleScene::~SimpleScene(void) {

}
