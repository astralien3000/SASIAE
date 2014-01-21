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
}

void Encoder::received(QString message) {
    qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void Encoder::simulStep() {
  emit(send(QString("value %1").arg((int)(_wheel->getRotation()*(double)_accuracy))));
}
