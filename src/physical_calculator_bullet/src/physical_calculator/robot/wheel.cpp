#include "wheel.hpp"

#include "robot.hpp"
#include "../physical_calculator.hpp"

#include <vector>
#include <algorithm>

// Used to display wheel in view
extern std::vector<btRaycastVehicle*> robots;

////////////////////////////////////////////////////////////////////////////////
// Private Data
////////////////////////////////////////////////////////////////////////////////

struct Wheel::PrivateData {
    MyRobot* _robot;
    btWheelInfo* _wheel;
    btCylinderShapeX* _mesh;
    int _index;
};


////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

Wheel::Wheel(std::string name, MyRobot& robot, btVector3 position, btVector3 direction, double radius)
    : PhysicalObject(name) {

    _data = new PrivateData;
    _data->_robot = &robot;

    // Add wheel to robot
    _data->_wheel =
            &_data->_robot->getVehicle()->addWheel(
                position, direction, btVector3(-10,0,0),
                1.0,
                radius,
                *_data->_robot->getTunning(),
                true
                );

    _data->_index = _data->_robot->getVehicle()->getNumWheels() - 1;

    _data->_wheel->m_suspensionStiffness = 20.f;
    _data->_wheel->m_wheelsDampingRelaxation = 2.3f;
    _data->_wheel->m_wheelsDampingCompression = 4.4f;
    _data->_wheel->m_maxSuspensionTravelCm = 10;
    _data->_wheel->m_frictionSlip = 1000;
    _data->_wheel->m_rollInfluence = .7f;

    // WARNING: Dirty code to allow wheel render
    if(std::find(robots.begin(), robots.end(), _data->_robot->getVehicle()) == robots.end()) {
        robots.push_back(_data->_robot->getVehicle());
    }
}

Wheel::~Wheel(void) {
    delete _data;
}

double Wheel::getRotation(void) {
    return _data->_robot->getVehicle()->getWheelInfo(_data->_index).m_engineForce;
}

double Wheel::getTorque(void) {
    return _data->_robot->getVehicle()->getWheelInfo(_data->_index).m_rotation;
}

void Wheel::setTorque(double value) {
    _data->_robot->getVehicle()->applyEngineForce(value, _data->_index);
}

