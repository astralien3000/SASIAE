#include "motor_wheel.hpp"
#include <QObject>
#include <QString>


MotorWheel::MotorWheel(Wheel* wheel, QString params, QObject* parent)
 : Modules(parent), _wheel = wheel {
  //TODO read from param
  _motorMaxTorque = 4;
  _gearRatio = 1;
  _inputRatio = 0;
}
void MotorWheel::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value")
    _inputRatio = list.at(1).toDouble();
}
void MotorWheel::simulStep() {
  _wheel->setTorque(_motorMaxTorque*_gearRatio*_inputRatio);
}
