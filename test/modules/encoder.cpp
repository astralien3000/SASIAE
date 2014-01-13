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
  emit(send(QString("value ")+_wheelè>getRotation*_accuracy));
}
