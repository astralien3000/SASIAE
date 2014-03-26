#include "GP2.hpp"
#include "../physical_calculator/dist_sensor.hpp"
#include <QStandardItem>
#include <QList>

const QString GP2::maxDistXmlName = "max_dist";

GP2::GP2() : Module() {
  _dataRoot = new QStandardItem("GP2");
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Distance") << new QStandardItem(QString::number(0)));
}

GP2::GP2(DistSensor* sensor, int max_dist, QString name) : Module() {
  _sensor = sensor;
  _max_dist = max_dist;
  _dataRoot = new QStandardItem(name);
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Distance") << new QStandardItem(QString::number(0)));
}

QStandardItem* GP2::getGuiItem() {
  return _dataRoot;
}

void GP2::received(QString message) {
  qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void GP2::update() {
  double d = _sensor->getDist();
  if(d > _max_dist)
    d = 0;
  // Push new values
  _dataRoot->child(0,1)->setText(QString::number(d));
  emit(send(QString("value %1").arg((int)d)));
}
