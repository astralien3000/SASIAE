#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>
// #include Mesh
//used as a list in the gui coordinateur to be printed on Qt

struct position_data {
 QVector<int> position;
 //vector de position x y z 
 int angle;
};

class printableMobileObject /*: public Mesh*/ {
private:
	QString _name;
protected:
	btRigidBody _body;
public:
  printableMobileObject(QString name, btRigidBody body);
  btVector3 getPosition(); //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation

};

#endif 