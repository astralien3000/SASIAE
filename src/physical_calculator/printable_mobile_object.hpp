#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>
// #include Mesh
//used as a list in the gui coordinateur to be printed on Qt

struct position_data {
	QVector<int> positionTest;
	btQuaternion angle;
};

class PrintableMobileObject /*: public Mesh*/ {
private:
	QString _name;
	struct position_data * _pos;
protected:
	btRigidBody *_body;
public:
	PrintableMobileObject(QString name, btRigidBody *body);
	PrintableMobileObject(btRigidBody *body);
  position_data * getPosition(); //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
};

#endif
