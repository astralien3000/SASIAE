#include "printable_mobile_object.hpp"

PrintableMobileObject::PrintableMobileObject(QString name, btRigidBody *body) : _name(name), _pos(new struct position_data),_body(body){}

PrintableMobileObject::PrintableMobileObject(btRigidBody *body): _name("unknown"), _pos(new struct position_data),_body(body){}


struct position_data * PrintableMobileObject::getPosition() {
  	btTransform trans;
  	_body->getMotionState()->getWorldTransform(trans);
  	_pos->position=trans.getOrigin();
  	_pos->angle=trans.getRotation();
	return _pos;
}
