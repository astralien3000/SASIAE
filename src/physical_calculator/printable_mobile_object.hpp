#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>

<<<<<<< HEAD
#include "position_data.hpp"

/*
Alternative
struct PositionData {
	QVector<int> positionTest;
	btQuaternion angle;
};
*/

class PrintableMobileObject /*: public Mesh*/ {
private:
  QString _name;
  //struct position_data * _pos;
    PositionData * _pos;
protected:
	btRigidBody *_body;
public:
<<<<<<< HEAD
  PrintableMobileObject(QString name, btRigidBody *body);
  PrintableMobileObject(btRigidBody *body);
  PositionData * getPosition(); //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
};

#endif
