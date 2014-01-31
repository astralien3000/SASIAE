
#include <QtTest/QtTest>
#include <QObject>
#include "../../../src/modules/servo.cpp"


class testServo : public Servo{
	public:
	testServo(int position) : Servo(position) {}
	void sender();
	// int get_position();
};

// int testServo::get_position() {
// 	return Servo->position;
// }


void testServo::sender() {
}



int main(int argc, char **argv) {
	testServo *test = new testServo(5);
	test->sender();
	return 0;
}