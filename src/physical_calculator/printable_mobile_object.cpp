#include "printable_mobile_object.hpp"

PrintableMobileObject::PrintableMobileObject(QString name, btRigidBody *body) : _name(name), _pos(new struct position_data),_body(body){}

PrintableMobileObject::PrintableMobileObject(btRigidBody *body): _name("unknown"), _pos(new struct position_data),_body(body){}


struct position_data * PrintableMobileObject::getPosition() {
	btTransform trans;
	_body->getMotionState()->getWorldTransform(trans);
	btVector3 position =trans.getOrigin();
	_pos->positionTest.replace(0,position.getX());
	_pos->positionTest.replace(1,position.getY());
	_pos->positionTest.replace(2,position.getZ());
	_pos->angle=trans.getRotation();
	return _pos;
}
