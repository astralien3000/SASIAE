#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <btBulletDynamicsCommon.h>

class Robot : public btRaycastVehicle {
private:
  btRaycastVehicle::btVehicleTuning _tuning;
public:
  Robot(btRigidBody* chassis, btDynamicsWorld *world);
  ~Robot();
  btWheelInfo& addWheel (const btVector3 &connectionPointCS0,
			 const btVector3 &wheelDirectionCS0,
			 const btVector3 &wheelAxleCS,
			 btScalar wheelRadius,
			 bool isFrontWheel);
};
#endif //ROBOT_HPP
