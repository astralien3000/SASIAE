#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector3D>
#include <QPair>
#include <QPixmap>
#include <QMap>
#include <QGraphicsPixmapItem>
#include "position_data.hpp"
#include "stlmesh.hpp"
#include "../coordinator/gui_coordinator.hpp"

/*PMO contient un pointeur sur QGraphicsPixmapItem, le coordinateur doit appeler addPMO(scene) 
à chaque création de PMO (à coderdans gui coordinator)
reset PMO dans gui coordinator doit etre implémentée pour virer tous les PMO déjà mis, 
dans update de gui coord, il itère et appelle update sur chaque PMO qui lui meme fait un 
truc du style (graphicsitem->setposition) objet, puis !!! PEUT ETRE(si nécessaire) !!! table.update pour rafraichir.
*/

class PrintableMobileObject : public STLMesh {
signals:
    void updateTable(); //si on veut faire un truc génial on pourra utiliser ce signal pendant la cration du PMO pour le rajouter directement à la table !! 
private:
	static const QString _img_path;
	static QVector<PrintableMobileObject*> objects;
	static QMap<QString,QPair<QPixmap*,int>*> images; //changer QPixmap en Qgraphic Item ou mettre une liste PMO/QgraphicItem dans guiCoordinator
//destructeur -> enlever les objets qui n'existent plus.
private:
	QString _name; //nom de l'image inclue pour le Pixmap 
	QGraphicsPixmapItem* _item; //permet d'update l'affichage.
  // struct position_data * _pos;contenu dans le Mesh mtn
public:
	PrintableMobileObject(const QString name, const STLMesh & mesh);
//  PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name); peut être remise si besoin
	PrintableMobileObject(const QString path, float mass, PositionData start_pos, const QString name);
	~PrintableMobileObject();
	static const QVector<PrintableMobileObject*>& getObjectsList();
	PrintableMobileObject(const STLMesh& mesh);
	void update();
	QGraphicsPixmapItem* getItem();
  // Déplacé dans STLMesh const PositionData & getPosition() const; 

};

#endif
