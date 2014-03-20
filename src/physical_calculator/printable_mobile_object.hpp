#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector3D>
#include <QPair>
#include <QPixmap>
#include <QMap>

#include "position_data.hpp"
#include "stlmesh.hpp"

//PMO contient un pointeur sur QGraphicsItem, le coordinateur doit appeler addPMO(scene) à chaque création de PMO (à coderdans gui coordinator)
//reset PMO dans gui coordinator doit etre implémentée pour virer tous les PMO déjà mis, dans update de gui coord, il itère et appelle update sur chaque PMO qui lui meme fait un truc du style (graphicsitem->setposition) objet, puis table.update pour rafraichir.


class PrintableMobileObject : public STLMesh {
private:
  static const QString _img_path;
	static QVector<const PrintableMobileObject*> objects;
	static QMap<QString,QPair<QPixmap*,int>*> images; //changer QPixmap en Qgraphic Item ou mettre une liste PMO/QgraphicItem dans guiCoordinator
//destructeur -> enlever les objets qui n'existent plus.
private:
	QString _name; //nom de l'image inclue pour le Pixmap !!!!!! 
  //struct position_data * _pos;
public:
  PrintableMobileObject(const QString name, const STLMesh & mesh);
  PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name);
  ~PrintableMobileObject();
  static const QVector<const PrintableMobileObject*>& getObjectsList();
  PrintableMobileObject(const STLMesh& mesh);
  // Déplacé dans STLMesh const PositionData & getPosition() const; //renvoie 4 entiers dans une structure (un vecteur 3 dimension et un angle) au lieu du btVector3 : x y z orientation
  

};

#endif
