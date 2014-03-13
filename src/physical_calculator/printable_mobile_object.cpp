#include "printable_mobile_object.hpp"

PrintableMobileObject::PrintableMobileObject(QString name, btRigidBody *body) : _name(name), _pos(new struct position_data),_body(body){}

PrintableMobileObject::PrintableMobileObject(btRigidBody *body): _name("unknown"), _pos(new struct position_data),_body(body){}


struct position_data * PrintableMobileObject::getPosition() {
	btTransform trans;
	_body->getMotionState()->getWorldTransform(trans);
	btVector3 position =trans.getOrigin();
	_pos->positionTest.insert(0,position.getX());
	_pos->positionTest.insert(1,position.getY());
	_pos->positionTest.insert(2,position.getZ());
	_pos->angle=trans.getRotation();
	return _pos;
}
