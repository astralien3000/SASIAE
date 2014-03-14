#include "printable_mobile_object.hpp"

PrintableMobileObject::PrintableMobileObject(QString name, btRigidBody *body) :
    _name(name) /*_pos(new struct position_data)*/,_body(body)
{
    _pos=new PositionData();
}

PrintableMobileObject::PrintableMobileObject(btRigidBody *body):
    _name("unknown") /*_pos(new struct position_data)*/,_body(body)
{
    _pos=new PositionData();
}


PositionData *PrintableMobileObject::getPosition() {
  	btTransform trans;
  	_body->getMotionState()->getWorldTransform(trans);
    _pos->setPosition(trans.getOrigin());
    _pos->setRotation(trans.getRotation());

    /* use of structure :
     * _pos->position=trans.getOrigin();
     * _pos->angle=trans.getRotation();
    */
return _pos;
}
