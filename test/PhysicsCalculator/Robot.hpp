#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <btDynamicsWorld.h>

class Robot: btRaycastVehicle {

	btVehicleTuning _tuning;

	public:
		Robot(btRigidBody* chassis, btDynamicWorld *world);
		~Robot();
		addWheel (const btVector3 &connectionPointCS0,
			 				const btVector3 &wheelDirectionCS0,
						 	const btVector3 &wheelAxleCS,
						 	btScalar wheelRadius,
						 	bool isFrontWheel);
};
#endif //ROBOT_HPP
