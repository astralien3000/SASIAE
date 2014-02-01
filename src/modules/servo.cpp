#include <QObject>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "servo.hpp"




Servo::Servo(int position, QObject* parent) : Modules(parent) {
	this->position = position;
	_dataRoot = new QStandardItem("Servo");
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Position") << new QStandardItem(QString()+ position));
}

void Servo::received(QString message) {
	QStringList list = message.split(" ");
	if(list.at(0) == "value") {
  // le message est du type : "value [position]"
		position = list.at(1).toInt();
		_dataRoot->removeRow(1);
		_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Position") << new QStandardItem(QString()+ position));
	}
}


QStandardItem* Servo::getData() {
	return _dataRoot;
}


void Servo::simulStep() {
} // nothing to do
