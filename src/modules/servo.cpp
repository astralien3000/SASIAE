#include "servo.hpp"


Servo::~Servo(){
}
/*
TODO : chose the right one
 */

// Servo::Servo(int position){
//   this->_position = position;
// }


// void Servo::received(QString message) {
//   QStringList list = message.split(" ");
//   if(list.at(0) == "value") // le message est du type : "value [_position]"
//     _position = list.at(1).toInt();
//}


Servo::Servo(int position, QObject* parent) : Modules(parent) {
	this->_position = position;
	_dataRoot = new QStandardItem("Servo");
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Position") << new QStandardItem(QString()+ _position));
}

void Servo::received(QString message) {
	QStringList list = message.split(" ");
	if(list.at(0) == "value") {
  // le message est du type : "value [position]"
		_position = list.at(1).toInt();
		_dataRoot->child(1,1)->setText(QString() + _position);
	}
}


QStandardItem* Servo::getData() {
	return _dataRoot;
}


void Servo::simulStep() {
} // nothing to do

void send(QString message) {}

