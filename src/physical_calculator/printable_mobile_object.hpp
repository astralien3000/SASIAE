#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>
#include <QPair>
#include <QPixmap>
#include <QMap>

#include "position_data.hpp"
#include "stlmesh.hpp"

//PMO contient un pointeur sur QGraphicsItem, le coordinateur doit appeler addPMO(scene) à chaque création de PMO (à coderdans gui coordinator)
//reset PMO dans gui coordinator doit etre implémentée pour virer tous les PMO déjà mis, dans update de gui coord, il itère et appelle update sur chaque PMO qui lui meme fait un truc du style (graphicsitem->setposition) objet, puis table.update pour rafraichir.


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
	static QMap<QString,QPair<QPixmap*,int>*> images; //changer QPixmap en Qgraphic Item ou mettre une liste PMO/QgraphicItem dans guiCoordinator
//destructeur -> enlever les objets qui n'existent plus.
private:
	QString _name; //nom de l'image inclue pour le Pixmap !!!!!! 
  //struct position_data * _pos;
<<<<<<< HEAD
    PositionData _pos;
public:
  PrintableMobileObject(QString name, const Mesh& mesh);
  ~PrintableMobileObject();
  static const QVector<const PrintableMobileObject*>& getObjectsList();
  PrintableMobileObject(const Mesh& mesh);
  const PositionData & getPosition() const; //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
=======
	PositionData * _pos;

protected:
	btRigidBody *_body;
public:
	PrintableMobileObject(QString name, btRigidBody *body);
	~PrintableMobileObject();
	static const QVector<const PrintableMobileObject*>& getObjectsList();
	PrintableMobileObject(btRigidBody *body);
  const PositionData * getPosition() const; //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
>>>>>>> ffa4c2ea4520fa5e60fd3769bec0ecde733c9d09
};

#endif
