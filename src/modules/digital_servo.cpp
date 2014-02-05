#include "digital_servo.hpp"

#include <QStringList>

#define DEFAULT_MAX_POS 160
#define DEFAULT_MAX_SPE 10
#define DEFAULT_MAX_ACC 2

DigitalServo::DigitalServo() :
  position(0), speed(0), accel(0), 
  cmd_pos(0), cmd_spe(0), cmd_acc(0), 
  com_mode(POSITION), true_mode(POSITION),
  max_pos(DEFAULT_MAX_POS), 
  max_spe(DEFAULT_MAX_SPE), 
  max_acc(DEFAULT_MAX_ACC)
{}

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

void DigitalServo::simulStep() {

}

void DigitalServo::send(QString message) {

}
