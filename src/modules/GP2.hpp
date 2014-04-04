#ifndef GP2_HPP
#define GP2_HPP

#include "module.hpp"
#include <QString>
#include <QList>
#include <QStandardItem>

class DistSensor;

class GP2 : public Module {
Q_OBJECT
Q_INTERFACES(Module)

public:
  static const QString maxDistXmlName;
  GP2();
  GP2(DistSensor* sensor, int max_dist, QString name = "GP2");
  virtual QStandardItem* getGuiItem();
       
public slots:
  virtual void received(QString message);
  virtual void update();
    
signals:
  virtual void send(QString message);

private:
	QStandardItem* _dataRoot;
  DistSensor* _sensor;
  int _max_dist;
};

#endif
