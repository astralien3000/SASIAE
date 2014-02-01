#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "servo.hpp"




Servo::Servo(int position, QObject* parent) : Modules(parent) {
  this->position = position;
}

void Servo::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") // le message est du type : "value [position]"
    position = list.at(1).toInt();
}


QStandardItem* Servo::getData() {
	QStandardItem *info = new QStandardItem("position");
	info->appendRow(new QStandardItem(this->position));
	return info;
}


void Servo::simulStep() {
} // nothing to do
