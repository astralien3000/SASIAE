#include "printable_mobile_object.hpp"

QVector< const PrintableMobileObject*> PrintableMobileObject::objects;
const QString PrintableMobileObject::_img_path("./"); // TO BE FIXED IF CHANGED !

QMap<QString,QPair<QPixmap*,int>*> PrintableMobileObject::images;

/*
   //to be tested when the connect above is solved.
connect(
       _mainWindow, //how do i link this ?
       SIGNAL(updateTable()),
       this,
       SLOT(updateTable())
       );
*/

const QVector<const PrintableMobileObject*>& PrintableMobileObject::getObjectsList() {
  return PrintableMobileObject::objects;
}
void PrintableMobileObject::update() const {
  PositionData pos = getPosition();
  _item->setRotation(pos.beta);
  _item->setPos(pos.x, pos.y);
}


PrintableMobileObject::PrintableMobileObject(const QString name, const STLMesh & mesh) :
    STLMesh(mesh), _name(name) //to test
    {
        objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
        auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
        _item = new QGraphicsPixmapItem(*((*it)->first));
    } else { //add the pixmap in the map !
        QPixmap *pixmap = new QPixmap(_img_path+name);
        images.insert(name,new QPair<QPixmap*,int>(pixmap,0));
        _item = new QGraphicsPixmapItem(*pixmap);
    }
    //Connect the signal and then emit it.

    emit updateTable();
}

PrintableMobileObject::PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name):
STLMesh(path,mass,start_pos),_name(name)
{
    _item = new QGraphicsPixmapItem();
    objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
    auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
        _item = new QGraphicsPixmapItem(*((*it)->first));
    } else { //add the pixmap in the map !
        QPixmap *pixmap = new QPixmap(_img_path+name);
        images.insert(name,new QPair<QPixmap*,int>(pixmap,0));
        _item = new QGraphicsPixmapItem(*pixmap);
    }
    emit updateTable();
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
  delete(_item);
  int objectPosition = objects.indexOf(this);
  objects.remove(objectPosition);
}

PrintableMobileObject::PrintableMobileObject(const STLMesh & mesh):
    STLMesh(mesh), _name("unknown") /*_pos(new struct position_data)*/
{
    //_pos=new PositionData();
    objects.append(this);
}

QGraphicsPixmapItem* PrintableMobileObject::getItem() const {
    return _item;
}


/*
PrintableMobileObject::PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name, QGraphicsPixmapItem* item):
STLMesh(path,mass,start_pos),_name(name)
{
    objects.append(this);
    //si image est dans tableau, ++, sinon ajouter image dans tableau.
    auto it = images.find(name);
    if(it!=images.end()) {//found
        (*it)->second++;
    } else { //add the pixmap in the map !
        images.insert(name,new QPair<QPixmap*,int>(new QPixmap(_img_path+name),0));
    }

}*/
