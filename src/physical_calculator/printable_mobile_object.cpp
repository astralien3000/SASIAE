#include "printable_mobile_object.hpp"

QVector<const PrintableMobileObject*> PrintableMobileObject::objects;
QMap<QString,QPair<QPixmap*,int>*> PrintableMobileObject::images;


const QVector<const PrintableMobileObject*>& PrintableMobileObject::getObjectsList() {
  return PrintableMobileObject::objects;
}


PrintableMobileObject::PrintableMobileObject(QString name, const Mesh & mesh) :
    Mesh(mesh), _name(name) /*_pos(new struct position_data)*/
{
    _pos=new PositionData();
    objects.append(this);
	//si image est dans tableau, ++, sinon ajouter image dans tableau.
    auto it = images.find(name);
    if(it!=images.end()) {//found
    	(*it)->second++;
    } else { //add the pixmap in the map !
        images.insert(name,new QPair<QPixmap*,int>(new QPixmap(""+name),0));
    }

}

PrintableMobileObject::~PrintableMobileObject() {
    auto it = images.find(this->_name);
    if(it!=images.end()) {//found
    	(*it)->second--;
        if((*it)->second==0) {
    		QPair<QPixmap*,int>* tobedeleted = (images.take(this->_name));
    		delete(tobedeleted);
    	}
    }
	int objectPosition = objects.indexOf(this);
	objects.remove(objectPosition);
}

PrintableMobileObject::PrintableMobileObject(const Mesh & mesh):
    Mesh(mesh), _name("unknown") /*_pos(new struct position_data)*/
{
    //_pos=new PositionData();
    objects.append(this);
}



const PositionData & PrintableMobileObject::getPosition() const {
  	btTransform trans;
  	_body->getMotionState()->getWorldTransform(trans);
    _pos->setPosition(trans.getOrigin());
    _pos->setRotation(trans.getRotation());
return _pos;
}
/*
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
*/
