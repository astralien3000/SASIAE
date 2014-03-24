#include "encoder.hpp"
#include <math.h>
#include <QXmlStreamReader>

const QString Encoder::xmlAccuracyName = "accuracy";

Module* Encoder::buildModule(Robot* robot, const ObjectConfig::moduleConfig* conf) {
    qDebug() << "creation d'une nouvelle Encoder en " << conf->position;
  if(!conf->parameters.contains(Wheel::xmlRadiusName) && 
     !conf->parameters.contains(xmlAccuracyName)) {
    qDebug() <<"Impossible de cree une roue codeuse, des parametres sont manquant";
    return NULL;
  }
  Wheel* w = new Wheel(robot, conf->position, PositionData(0,-1,0,0,0,0), conf->parameters.value(Wheel::xmlRadiusName).toFloat(), true);
  return new Encoder(w,conf->parameters.value(xmlAccuracyName).toInt(),
                          conf->name);

}

Encoder::Encoder() {};
Encoder::Encoder(Wheel* wheel, int accuracy, QString name) 
  : Module(), _wheel(wheel), _accuracy(accuracy) {
  //building data tree for UI
  _dataRoot = new QStandardItem(name);
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Accuracy") << new QStandardItem(QString::number( _accuracy)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Rotation") << new QStandardItem(QString::number( _wheel->getRotation())));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Value") << new QStandardItem(QString("0")));
}

Encoder::Encoder(Wheel* wheel, QString params) 
  : Module(), _wheel(wheel) {
  //defaults
    _accuracy = 1024;
  //read from params :
  QXmlStreamReader xml(params);
  while(!xml.atEnd())
  {
    xml.readNext();
    if(xml.name() == xmlAccuracyName) {
	xml.readNext(); //leaving oppener
	_accuracy = xml.text().toString().toInt();
	xml.readNext(); //leaving closer
    }
  } 
  //building data tree for UI
  _dataRoot = new QStandardItem("Encoder");
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Accuracy") << new QStandardItem(QString::number( _accuracy)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Rotation") << new QStandardItem(QString::number( _wheel->getRotation())));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Value") << new QStandardItem(QString("0")));
}

void Encoder::received(QString message) {
  qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void Encoder::update(void) {
  _dataRoot->child(1,1)->setText(QString::number(_wheel->getRotation()));
  _dataRoot->child(2,1)->setText(QString::number((int)_wheel->getRotation()*(double)_accuracy));
  emit(send(QString("value %1").arg((int)(_wheel->getRotation()*(double)_accuracy))));
}

QStandardItem* Encoder::getGuiItem() {
  return _dataRoot;
}
