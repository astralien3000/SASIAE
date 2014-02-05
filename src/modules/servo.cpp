#include "servo.hpp"



Servo::Servo(int position){
  this->_position = position;
}

Servo::~Servo(){
}

void Servo::received(QString message) {
  QStringList list = message.split(" ");
  if(list.at(0) == "value") // le message est du type : "value [_position]"
    _position = list.at(1).toInt();
}

void Servo::simulStep() {
} // nothing to do
