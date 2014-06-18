#ifndef ROBOT_PRIVATE_HPP
#define ROBOT_PRIVATE_HPP

#include "robot.hpp"

#include "../mesh/stl_mesh.hpp"

#include <btBulletDynamicsCommon.h>

struct MyRobot::PrivateData {
    MyMesh* _mesh;
    btRigidBody* _body;

    btRaycastVehicle* _vehicle;
    btRaycastVehicle::btVehicleTuning* _tuning;
    btDefaultVehicleRaycaster* _raycaster;
};

#endif//ROBOT_PRIVATE_HPP
