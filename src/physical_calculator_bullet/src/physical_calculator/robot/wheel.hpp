#ifndef WHEEL_HPP
#define WHEEL_HPP

#include "../physical_object.hpp"

#include <string>
#include <btBulletDynamicsCommon.h>

class MyRobot;

class Wheel : public PhysicalObject {
public:
    Wheel(std::string name, MyRobot& robot, btVector3 position, btVector3 direction, double radius);
    virtual ~Wheel(void);

    double getRotation(void);
    double getTorque(void);

    void setTorque(double);

private:
    struct PrivateData;
    PrivateData* _data;
};

#endif//WHEEL_HPP
