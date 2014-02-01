#include "balise.hpp"




//cylindre de masse 0.1

Balise::Balise(Robot *robot, QObject* parent): Modules(parent) {
    btTransform trans;
	trans = robot->getChassisWorldTransform();
	btScalar z,y,x;
	trans.getBasis().getEulerZYX(z,y,x);
	this->position =
	btVector3(trans.getOrigin().getX()
		, trans.getOrigin().getY()
		, trans.getOrigin().getZ());
}



