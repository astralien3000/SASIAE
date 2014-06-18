#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "../physical_object.hpp"

#include <string>
#include <btBulletDynamicsCommon.h>

class Wheel;

class MyRobot : public PhysicalObject {
    friend class Wheel;

public:
    MyRobot(std::string name, std::string mesh, double mass, btVector3 position);
    virtual ~MyRobot(void);

private:
    struct PrivateData;
    PrivateData* _data;
};


////////////////////////////////////////////////////////////////////////////////

//#include <btBulletDynamicsCommon.h>
//#include "printable_mobile_object.hpp"
//#include "world.hpp"
//#include "mesh.hpp"
//#include "common/object_config.hpp"

////class Robot :  public PrintableMobileObject, public btRaycastVehicle {
//class Robot {
//private:
//  btRaycastVehicle::btVehicleTuning _tuning;
//  static Robot* _r;
//  //rajouter la balise
//public:

//  Robot(World& world, const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos);
//  static Robot* getRobot();
//  ~Robot();

//  /* This function is called in Wheel::init().
//   * In order to put a wheel on a robot, you must
//   * call Wheel::init() or call
//   * Wheel::Wheel(Robot*, btVector3, btVector3, btScalar, bool);
//   */
//  btWheelInfo& addWheel (const btVector3 &connectionPointCS0,
//			 const btVector3 &wheelDirectionCS0,
//			 const btVector3 &wheelAxleCS,
//			 btScalar wheelRadius,
//			 bool isFrontWheel);
//};

#endif //ROBOT_HPP
