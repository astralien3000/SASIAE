#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>

#include "position_data.hpp"
#include "mesh.hpp"
/*
Alternative
struct PositionData {
	QVector<int> positionTest;
	btQuaternion angle;
};
*/


class PrintableMobileObject : public Mesh {
private:
	static QVector<const PrintableMobileObject*> objects;
//destructeur -> enlever les objets qui n'existent plus.
private:
  QString _name;
  //struct position_data * _pos;
    PositionData _pos;
public:
  PrintableMobileObject(QString name, const Mesh& mesh);
  ~PrintableMobileObject();
  static const QVector<const PrintableMobileObject*>& getObjectsList();
  PrintableMobileObject(const Mesh& mesh);
  const PositionData & getPosition() const; //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
};

#endif
