#include "motor_wheel.hpp"
#include <QObject>
#include <QString>
#include <QStringList>
#include <QXmlStreamReader>
#include <QDebug>
#include <QHash>

const QString MotorWheel::xmlGearName = "gear_ratio";
const QString MotorWheel::xmlTorqueName = "max_torque";

MotorWheel::MotorWheel() : Module() {
}
MotorWheel::MotorWheel(Wheel* wheel, double torque, double gear, QString name)
 : Module(), _wheel(wheel), _motorMaxTorque(torque), _gearRatio(gear) {
_inputRatio = 0;
 //build data tree for UI
  _dataRoot = new QStandardItem(name);
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Max torque") << new QStandardItem(QString::number( _motorMaxTorque)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Gear ratio") << new QStandardItem(QString::number( _gearRatio)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Command ratio") << new QStandardItem(QString("0")));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Real torque") << new QStandardItem(QString("0")));
}

MotorWheel::MotorWheel(Wheel* wheel, QString params)
 : Module(), _wheel(wheel) {
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
  //build data tree for UI
  _dataRoot = new QStandardItem("Motor Wheel");
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Max torque") << new QStandardItem(QString()+ _motorMaxTorque));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Gear ratio") << new QStandardItem(QString()+ _wheel->getRotation()));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Command ratio") << new QStandardItem(QString("0")));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Real torque") << new QStandardItem(QString("0")));
}

QStandardItem* MotorWheel::getGuiItem() {
  return _dataRoot;
}


void MotorWheel::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") {
    _inputRatio = list.at(1).toDouble();
    if(_inputRatio > 1 || _inputRatio < -1)
      qDebug() << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nCommande des moteur en dehors de la plage de fonctionenement [-1-1]\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << _inputRatio;
  }
  _dataRoot->child(2,1)->setText(QString::number(_inputRatio));
  _dataRoot->child(3,1)->setText(QString::number(_motorMaxTorque*_gearRatio*_inputRatio));
}
void MotorWheel::update(void) {
  _wheel->setTorque(_motorMaxTorque*_gearRatio*_inputRatio);
}
