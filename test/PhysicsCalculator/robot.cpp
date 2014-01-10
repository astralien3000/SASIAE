#include "Robot.hpp"

Robot::Robot(btRigidBody* chassis, btDynamicWorld *world) {
	_tuning=btRaycastVehicle::btVehicleTuning::btVehicleTuning();
	btRaycastVehicle::btRaycastVehicle(_tuning,
																			chassis,
																			btDefaultVehicleRaycaster::btDefaultVehicleRaycaster(world))
}

Robot::~Robot() {}

Robot::addWheel ( const btVector3 &connectionPointCS0,
									const btVector3 &wheelDirectionCS0,
								 	const btVector3 &wheelAxleCS,
								 	btScalar wheelRadius,
								 	bool isFrontWheel){
	addWheel (connectionPointCS0,
		 				wheelDirectionCS0,
						wheelAxleCS,
						0, //valeur complètement arbitraire de la longueur de la suspension au repos
						wheelRadius,
						_tuning,
						isFrontWheel);
}

