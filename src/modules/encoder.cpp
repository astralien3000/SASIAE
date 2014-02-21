#include "encoder.hpp"
#include <math.h>
#include <QXmlStreamReader>

const QString Encoder::xmlAccuracyName = "accuracy";

Encoder::Encoder(Wheel* wheel, QString params, QObject* parent) 
  : Modules(parent), _wheel(wheel) {
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
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Accuracy") << new QStandardItem(QString()+ _accuracy));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Rotation") << new QStandardItem(QString()+ _wheel->getRotation()));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Value") << new QStandardItem(QString("0")));
}

void Encoder::received(QString message) {
  qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void Encoder::simulStep() {
  _dataRoot->child(1,1)->setText(QString() + _wheel->getRotation());
  _dataRoot->child(2,1)->setText(QString() + ((int)_wheel->getRotation()*(double)_accuracy));
  emit(send(this, QString("value %1").arg((int)(_wheel->getRotation()*(double)_accuracy))));
}

QStandardItem* Encoder::getData() {
  return _dataRoot;
}
