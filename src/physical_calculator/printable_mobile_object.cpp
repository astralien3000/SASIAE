#include "printable_mobile_object.hpp"

QVector<PrintableMobileObject*> PrintableMobileObject::objects;
const QString PrintableMobileObject::_img_path("./");

QMap<QString,QPair<QPixmap*,int>*> PrintableMobileObject::images;


const QVector<PrintableMobileObject*>& PrintableMobileObject::getObjectsList() {
  return PrintableMobileObject::objects;
}
void PrintableMobileObject::update() {
  PositionData pos;
  btTransform trans;
  _body->getMotionState()->getWorldTransform(trans);
  _item->setPos(trans.getOrigin().getX(),trans.getOrigin().getY());
}


PrintableMobileObject::PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name, QGraphicsItem* item):
STLMesh(path,mass,start_pos),_name(name), _item(item)
{
    objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
    auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
    } else { //add the pixmap in the map !
        images.insert(name,new QPair<QPixmap*,int>(new QPixmap(_img_path+name),0));
    }

}
/*
PrintableMobileObject::PrintableMobileObject(const QString name, const STLMesh & mesh) :
    STLMesh(mesh), _name(name) //to test
    {
        _item = QGraphicsItem();
        objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
        auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
    } else { //add the pixmap in the map !
        images.insert(name,new QPair<QPixmap*,int>(new QPixmap(_img_path+name),0));
    }

}
*/
/*PrintableMobileObject::PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name):
STLMesh(path,mass,start_pos),_name(name)
{
    _item = new QGraphicsItem();
    objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
    auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
    } else { //add the pixmap in the map !
        images.insert(name,new QPair<QPixmap*,int>(new QPixmap(_img_path+name),0));
    }

}
*/

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

PrintableMobileObject::PrintableMobileObject(const STLMesh & mesh):
    STLMesh(mesh), _name("unknown") /*_pos(new struct position_data)*/
{
    //_pos=new PositionData();
    objects.append(this);
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
