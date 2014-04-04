#ifndef __RDS_H__
#define __RDS_H__

#include "../physical_calculator/balise.hpp"
#include "module.hpp"
#include <QObject>
#include <QString>
#include <QList>
#include <QVector3D>

class RDS : public Module {
	Q_OBJECT

public:
  RDS(Balise *balise, QString name = "RDS");

public slots:
  virtual QList<QVector3D> get_position();
  virtual QStandardItem* getGuiItem();
  virtual void received(QString message);
  virtual void update();


signals:
  virtual void send(QString message);

private:
  int _mode;
  Balise* _myBalise;
  QStandardItem* _dataRoot;

  void maj_affichage(QList<QVector3D> pos_list);
};


#endif
