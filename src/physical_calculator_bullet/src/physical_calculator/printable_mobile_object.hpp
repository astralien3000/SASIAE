#ifndef PRINTABLE_MOBILE_OBJECT
#define PRINTABLE_MOBILE_OBJECT

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector>
#include <QPair>
#include <QPixmap>
#include <QMap>
#include <QRectF>
#include <QGraphicsPixmapItem>
#include "position_data_bullet.hpp"
#include "stlmesh.hpp"

//class PrintableMobileObject : public STLMesh {
class PrintableMobileObject {
public:
signals:
  void updateTable();
private:
	static const QString _img_path;
	static QVector<const PrintableMobileObject*> objects;
	static QMap<QString,QPair<QPixmap*,int>*> images;
private:
	QString _name; //nom de l'image inclue pour le Pixmap
	QGraphicsPixmapItem* _item; //permet d'update l'affichage.
public:
//  PrintableMobileObject(const STLMesh& mesh);
//  PrintableMobileObject(const QString name, const STLMesh & mesh);
//  PrintableMobileObject(const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos, const QString name, const QString imgpath=".png");
//  ~PrintableMobileObject();
  static const QVector<const PrintableMobileObject*>& getObjectsList();
  void update() const;
  QGraphicsPixmapItem* getItem() const;
};

#endif
