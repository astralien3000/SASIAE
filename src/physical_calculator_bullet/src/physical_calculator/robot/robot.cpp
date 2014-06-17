#include "robot.hpp"

#include "../mesh/stl_mesh.hpp"
#include "../physical_calculator.hpp"

#include <btBulletDynamicsCommon.h>

////////////////////////////////////////////////////////////////////////////////
// Private Data
////////////////////////////////////////////////////////////////////////////////

struct MyRobot::PrivateData {
    MyMesh* _mesh;
    btRigidBody* _body;

    btRaycastVehicle* _vehicle;
    btRaycastVehicle::btVehicleTuning* _tuning;
    btDefaultVehicleRaycaster* _raycaster;
};

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////


MyRobot::MyRobot(std::string name, std::string mesh, double mass, btVector3 position)
    : PhysicalObject(name) {

    _data = new PrivateData;
    _data->_mesh = new MyStlMesh(mesh);

    btDefaultMotionState* motion_state =
            new btDefaultMotionState(
                btTransform(btQuaternion(0,0,0,1), position)
                );

    btVector3 body_inertia(0,0,0);
    _data->_mesh->getShape()->calculateLocalInertia(mass, body_inertia);

    btRigidBody::btRigidBodyConstructionInfo body_ci(
                mass,
                motion_state,
                _data->_mesh->getShape(),
                body_inertia
                );

    _data->_body = new btRigidBody(body_ci);
    MyPhysicalCalculator::getIntance().getWorld()->addRigidBody(_data->_body);

    _data->_tuning = new btRaycastVehicle::btVehicleTuning;
    _data->_raycaster = new btDefaultVehicleRaycaster(MyPhysicalCalculator::getIntance().getWorld());
    _data->_vehicle = new btRaycastVehicle(*(_data->_tuning), _data->_body, _data->_raycaster);
    MyPhysicalCalculator::getIntance().getWorld()->addVehicle(_data->_vehicle);
}

MyRobot::~MyRobot(void) {
    delete _data;
}

btRaycastVehicle* MyRobot::getVehicle(void) {
    return _data->_vehicle;
}

btRaycastVehicle::btVehicleTuning* MyRobot::getTunning(void) {
    return _data->_tuning;
}

///////////////////////////////////////////////////////////////////////////////
//Robot* Robot::_r=NULL;

//Robot::Robot(World& world, const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos)
////  :  PrintableMobileObject(cfg,mass,start_pos,"name", "path"),
////     btRaycastVehicle(_tuning,
////		      _body,
////		      new btDefaultVehicleRaycaster(world))
//{

////  setCoordinateSystem(0,1,2);
////  _body->setDamping(0.5,0.6);
////  _body->setFriction(0.00001);
////  //_body->setRollingFriction(1);
////  btDiscreteDynamicsWorld* w = world;
////  w->addVehicle(this);
////  _r = this;
//}

//Robot* Robot::getRobot() {return _r;};

//Robot::~Robot() {
//}

//btWheelInfo& Robot::addWheel (const btVector3 &connectionPointCS0,
//			      const btVector3 &wheelDirectionCS0,
//			      const btVector3 &wheelAxleCS,
//			      btScalar wheelRadius,
//			      bool isFrontWheel) {
////  qDebug() << "ROUE " << connectionPointCS0.x() << " " << connectionPointCS0.y() << " " << connectionPointCS0.z() << " ";
////  return btRaycastVehicle::addWheel (connectionPointCS0,
////				     wheelDirectionCS0,
////				     wheelAxleCS,
////				     btScalar(0), //valeur complètement arbitraire de la longueur de la suspension au repos
////				     wheelRadius,
////				     _tuning,
////				     isFrontWheel);
//}


