#include "scene.hpp"

#include "../mesh/stl_mesh.hpp"
#include "../physical_calculator.hpp"

#include <iostream>

#include <btBulletDynamicsCommon.h>

////////////////////////////////////////////////////////////////////////////////
// Private Data
////////////////////////////////////////////////////////////////////////////////

struct Scene::PrivateData {
    MyMesh* _mesh;
};

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

Scene::Scene(std::string name, std::string path)
    : PhysicalObject(name) {

    _data = new PrivateData;
    _data->_mesh = new MyStlMesh(path);

    btDefaultMotionState* ground_motion_state =
            new btDefaultMotionState(
                btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0))
                );

    btRigidBody::btRigidBodyConstructionInfo ground_body_ci(
                0,
                ground_motion_state,
                _data->_mesh->getShape(),
                btVector3(0,0,0)
                );

    btRigidBody* ground_body = new btRigidBody(ground_body_ci);
    MyPhysicalCalculator::getIntance().getWorld()->addRigidBody(ground_body);
}

Scene::~Scene(void) {
    delete _data->_mesh;
    delete _data;
}
