#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "servo.hpp"



Servo::Servo(int position) {
  this->position = position;
}

void Servo::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") // le message est du type : "value [position]"
    position = list.at(1).toInt();
}

void Servo::simulStep() {
} // nothing to do
