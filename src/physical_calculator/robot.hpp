#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <btBulletDynamicsCommon.h>
#include "printable_mobile_object.hpp"

class Robot : public btRaycastVehicle, public PrintableMobileObject {
private:
  btRaycastVehicle::btVehicleTuning _tuning;
  //rajouter la balise
public:
  Robot(btRigidBody* chassis, btDynamicsWorld *world);
  Robot(btRigidBody* chassis, btDynamicsWorld *world, QString name); 
  ~Robot();

  /* This function is called in Wheel::init().
   * In order to put a wheel on a robot, you must 
   * call Wheel::init() or call 
   * Wheel::Wheel(Robot*, btVector3, btVector3, btScalar, bool);
   */
  btWheelInfo& addWheel (const btVector3 &connectionPointCS0,
			 const btVector3 &wheelDirectionCS0,
			 const btVector3 &wheelAxleCS,
			 btScalar wheelRadius,
			 bool isFrontWheel);
};
#endif //ROBOT_HPP
