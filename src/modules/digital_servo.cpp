#include "digital_servo.hpp"

#include <QStringList>

#define DEFAULT_MAX_POS 160
#define DEFAULT_MAX_SPE 10
#define DEFAULT_MAX_ACC 2

DigitalServo::DigitalServo(QString name) :
  position(0), speed(0), accel(0), 
  max_pos(DEFAULT_MAX_POS), 
  max_spe(DEFAULT_MAX_SPE), 
  max_acc(DEFAULT_MAX_ACC), 
  cmd_pos(0), cmd_spe(0), cmd_acc(0), 
  com_mode(POSITION), true_mode(POSITION)
{
  _dataRoot = new QStandardItem(name);
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Position") << new QStandardItem(QString::number( position)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Speed") << new QStandardItem(QString::number(speed)));
  _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Torque") << new QStandardItem(QString::number(accel)));
}

void DigitalServo::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") {
    bool is_int = false;
    list.at(1).toInt(&is_int);
    if(is_int) { // Try to set position
      cmd_pos = list.at(1).toInt();
    }
    else {
      if(list.at(1) == "speed") { // Try to set speed
	cmd_spe = list.at(2).toInt();
      }
      else if(list.at(1) == "torque") { // Try to set torque
	cmd_acc = list.at(2).toInt();
      }
      else { // ERROR
	
      }
    }
  }
  else if(list.at(0) == "set") {
    if(list.at(1) == "mode") {
      if(list.at(2) == "position") { // Switch comm to pos mode
	com_mode = POSITION;
      }
      else if(list.at(2) == "speed") { // Switch comm to speed mode
	com_mode = SPEED;
      }
      else if(list.at(2) == "troque") { // Switch comm to torque mode
	com_mode = TORQUE;
      }
      else { // ERROR
	
      }
    }
    else if(list.at(1) == "max") {
      if(list.at(2) == "position") { // Set maximum position
	max_pos = list.at(3).toInt();
      }
      else if(list.at(2) == "speed") { // Set maximum speed
	max_spe = list.at(3).toInt();
      }
      else if(list.at(2) == "troque") { // Set maximum torque
	max_acc = list.at(3).toInt();
      }
      else { // ERROR
	
      }
    }
    else if(list.at(1) == "join") { // The Servo act in pos mode
      true_mode = POSITION;
    }
    else if(list.at(1) == "wheel") { // The Servo act in speed mode
      true_mode = SPEED;
    }
  }
}

void DigitalServo::update() {
  // Physics
  if(true_mode == POSITION) {
    position = cmd_pos;
    speed = 0;
    accel = 0;
  }
  else if(true_mode == SPEED) {
    speed = cmd_spe;
    position += speed;
    accel = 0;
  }

  // Comm
  if(com_mode == POSITION) {
    emit(send(QString("value ") + position));
  }
  else if(com_mode == SPEED) {
    emit(send(QString("value speed ") + speed));
  }
  else if(com_mode == TORQUE) {
    emit(send(QString("value torque ") + accel));
  }

  // GUI
  _dataRoot->child(1,1)->setText(QString::number(position));
  _dataRoot->child(2,1)->setText(QString::number(speed));
  _dataRoot->child(3,1)->setText(QString::number(accel));
}

QStandardItem* DigitalServo::getGuiItem() {
  return _dataRoot;
}
