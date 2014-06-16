#include "printable_mobile_object.hpp"
#include <QFile>

QVector< const PrintableMobileObject*> PrintableMobileObject::objects;
const QString PrintableMobileObject::_img_path("../../ressources/img"); // TO BE FIXED IF CHANGED !

QMap<QString,QPair<QPixmap*,int>*> PrintableMobileObject::images;


const QVector<const PrintableMobileObject*>& PrintableMobileObject::getObjectsList() {
    return PrintableMobileObject::objects;
}
void PrintableMobileObject::update() const {
}


PrintableMobileObject::PrintableMobileObject(const QString name, const STLMesh & mesh)
    : STLMesh(mesh), _name(name) {
    objects.append(this);
}

PrintableMobileObject::PrintableMobileObject(const ObjectConfig::meshConfig& cfg,
                                             float mass,
                                             PositionData start_pos,
                                             const QString name,
                                             const QString img_path)
    : STLMesh(cfg,mass,start_pos),_name(name) {
    objects.append(this);
    update();
}

PrintableMobileObject::~PrintableMobileObject() {
    delete(_item);
    int objectPosition = objects.indexOf(this);
    objects.remove(objectPosition);
}

PrintableMobileObject::PrintableMobileObject(const STLMesh & mesh):
    STLMesh(mesh), _name("unknown") {
    objects.append(this);
}

QGraphicsPixmapItem* PrintableMobileObject::getItem() const {
    return NULL;
}
