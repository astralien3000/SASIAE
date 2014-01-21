#include "robot.hpp"

Robot::Robot(btRigidBody* chassis, btDynamicsWorld *world) 
	    : btRaycastVehicle(	_tuning,
							chassis, 
	      new btDefaultVehicleRaycaster(world)) {
  setCoordinateSystem(0,1,2);
  
}

Robot::~Robot() {
}

btWheelInfo& Robot::addWheel (const btVector3 &connectionPointCS0,
							  const btVector3 &wheelDirectionCS0,
							  const btVector3 &wheelAxleCS,
							  btScalar wheelRadius,
							  bool isFrontWheel) {
			 return btRaycastVehicle::addWheel (connectionPointCS0,
											    wheelDirectionCS0,
											    wheelAxleCS,
											    btScalar(0), //valeur complètement arbitraire de la longueur de la suspension au repos
											    wheelRadius,
											    _tuning,
											    isFrontWheel);
}

