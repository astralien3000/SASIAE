#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "servo.hpp"
#include "motor_wheel.hpp"




Servo::Servo(Wheel* wheel, int position, QObject* parent) : Modules(parent), _wheel(wheel) {
  this->position = position;
}

void Servo::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") // le message est du type : "value [position]"
    position = list.at(1).toInt();
}

void Servo::simulStep() {
} // nothing to do
