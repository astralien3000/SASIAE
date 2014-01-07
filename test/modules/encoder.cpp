#include <math.h>

Encoder::Encoder(Wheel* wheel, QString params, QObject* parent) 
  : Modules(parent), _wheel = wheel {
  //TODO read param for accuracy
  _accuracy = 1024;
}

void Encoder::received(QString message) {
    qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void Encoder::simulStep() {
  double newAngle = _wheel->getAngle();
  double radDiff = (newAngle - _lastAngle)%M_PI;
  long intDiff = (radDiff * _accuracy) / M_PI; 
  if(intDiff > _accuracy)
    qDebug() << "Moving too fast for encoder accuracy";
  _value = _value + intDiff%_accuracy;
  emit(send(QString("value ")+_value));
  _lastAngle = newAngle;
}
