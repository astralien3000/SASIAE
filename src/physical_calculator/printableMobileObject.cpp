#include "printableMobileObject.hpp"

 printableMobileObject::printableMobileObject(QString name, btRigidBody body) _name(name), _body(body);


btVector3 printableMobileObject::getPosition() {
	btRigidBody* chassis = _tuning->getRigidBody();
  	btTransform trans;
  	btVector3 *position = new btVector3();
  	btQuaternion *angle = new btQuaternion();
  	chassis->getMotionState()->getWorldTransform(&trans);
  	position = trans->getOrigin();
  	angle = trans.getRotation();
}