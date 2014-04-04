#include "servo.hpp"


Servo::~Servo(){
}

Servo::Servo(int position, QString name) : Module() {
	this->_position = position;
	_dataRoot = new QStandardItem(name);
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Position") << new QStandardItem(QString::number(_position)));
}

void Servo::received(QString message) {
	QStringList list = message.split(" ");
	if(list.at(0) == "value") {
  // le message est du type : "value [position]"
		_position = list.at(1).toInt();
		_dataRoot->child(1,1)->setText(QString::number(_position));
	}
}


QStandardItem* Servo::getGuiItem() {
	return _dataRoot;
}


void Servo::update() {
} // nothing to do

void send(QString message) {}

