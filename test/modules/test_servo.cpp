#include "../../src/modules/servo.hpp"

#include <QtTest/QtTest>
#include <QObject>

class Servotestable : public Servo {

};

class testServo : public QObject {
	Q_OBJECT
	private slots:
	void sender();

};

void testServo::sender() {
	Servo servoTest = new Servo(5);


}