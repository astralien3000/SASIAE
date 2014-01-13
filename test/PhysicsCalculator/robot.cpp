#include "robot.hpp"

Robot::Robot(btRigidBody* chassis, btDynamicsWorld *world) 
	    : btRaycastVehicle(	btVehicleTuning(),
							chassis, 
	      new btDefaultVehicleRaycaster(world)) {
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
											    btVehicleTuning(),
											    isFrontWheel);
}

