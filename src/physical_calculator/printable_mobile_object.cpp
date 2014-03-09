#include "printable_mobile_object.hpp"

printableMobileObject::printableMobileObject(QString name, btRigidBody *body) : _name(name), _pos(new struct position_data),_body(body){}

printableMobileObject::printableMobileObject(btRigidBody *body): _name("unknown"), _pos(new struct position_data),_body(body){}


struct position_data * printableMobileObject::getPosition() {
  	btTransform trans;
  	_body->getMotionState()->getWorldTransform(trans);
  	_pos->position=trans.getOrigin();
  	_pos->angle=trans.getRotation();
	return _pos;
}
