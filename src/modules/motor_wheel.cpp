#include "motor_wheel.hpp"
#include <QObject>
#include <QString>
#include <QStringList>
#include <QXmlStreamReader>
#include <QDebug>

const QString MotorWheel::xmlGearName = "gear";
const QString MotorWheel::xmlTorqueName = "torque";

MotorWheel::MotorWheel(Wheel* wheel, QString params, QObject* parent)
 : Modules(parent), _wheel(wheel) {
  //default params :
  _motorMaxTorque = 1000;
  _gearRatio = 1;
  _inputRatio = 0;
  //read from params :
  QXmlStreamReader xml(params);
  while(!xml.atEnd())
  {
    xml.readNext();
    if(xml.name() == xmlGearName) {
      xml.readNext();
       _gearRatio = xml.text().toString().toDouble();
      xml.readNext();
    }
    else if(xml.name() == xmlTorqueName) {
      xml.readNext();
      _motorMaxTorque = xml.text().toString().toDouble();
      xml.readNext();
    }
  } 
}
void MotorWheel::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value")
    _inputRatio = list.at(1).toDouble();
}
void MotorWheel::simulStep() {
  _wheel->setTorque(_motorMaxTorque*_gearRatio*_inputRatio);
}
