#include "wheel.hpp"
#include "../../src/modules/encoder.hpp"
#include "../../src/modules/motor_wheel.hpp"

#include <QtTest/QtTest>
#include <QObject>

class TestModules : public QObject
{
  Q_OBJECT
  private slots:
    //void modules();
    void encoder_param();
    void encoder_rotation();
    void motor_wheel_param();
    void motor_wheel_step();

};

void TestModules::encoder_param() {
  Wheel w;
  w._rotation = 1;
  Encoder e(&w, "<accuracy>1024</accuracy>", this);
  //testing send emission
  QSignalSpy spy(&e, SIGNAL(send(QString)));
  //testing accuracy
  e.simulStep();
  QCOMPARE(spy.count(), 1); //signal was emitted exactly one time
  QList<QVariant> arguments = spy.takeFirst(); // take the first signal
  QVERIFY2(arguments.at(0).toString() == "value 1024", qPrintable(arguments.at(0).toString()));
 
  Encoder e2(&w, "<accuracy>10000</accuracy>", this);
  //testing send emission
  QSignalSpy spy2(&e2, SIGNAL(send(QString)));
  //testing accuracy
  e2.simulStep();
  QCOMPARE(spy2.count(), 1); //signal was emitted exactly one time
  QList<QVariant> arguments2 = spy2.takeFirst(); // take the first signal
  QVERIFY2(arguments2.at(0).toString() == "value 10000", qPrintable(arguments2.at(0).toString()));
 

}

void TestModules::encoder_rotation() {
  Wheel w;
  Encoder e(&w, "<accuracy>1024</accuracy>", this);
  //it have to be my son
  QVERIFY(e.parent() == this);
  //testing send emission
  QSignalSpy spy(&e, SIGNAL(send(QString)));
  //fixing ghost wheel & test signal emission
  w._rotation = 0;
  e.simulStep();
  QCOMPARE(spy.count(), 1); //signal was emitted exactly one time
  QList<QVariant> arguments = spy.takeFirst(); // take the first signal
  QVERIFY2(arguments.at(0).toString() == "value 0", qPrintable(arguments.at(0).toString()));
  //fixing ghost wheel & test signal emission
  w._rotation = 0.5;
  e.simulStep();
  QCOMPARE(spy.count(), 1); //signal was emitted exactly one time
  arguments = spy.takeFirst(); // take the first signal
  QVERIFY2(arguments.at(0).toString() == "value 512", qPrintable(arguments.at(0).toString()));
  //QVERIFY(arguments.at(0).toString() == "value 512");
  //fixing ghost wheel & test signal emission
  w._rotation = 2.2;
  e.simulStep();
  QCOMPARE(spy.count(), 1); //signal was emitted exactly one time
  arguments = spy.takeFirst(); // take the first signal
  QVERIFY(arguments.at(0).toString() == "value 2252"); //2048+0.2*1024 round down
  //fixing ghost wheel & test signal emission
  w._rotation = -2;
  e.simulStep();
  QCOMPARE(spy.count(), 1); //signal was emitted exactly one time
  arguments = spy.takeFirst(); // take the first signal
  QVERIFY(arguments.at(0).toString() == "value -2048");
}
 
void TestModules::motor_wheel_step() {
  Wheel w;
  MotorWheel m(&w, "<params><gear>1</gear><torque>1000</torque></params>", this);
  QVERIFY(m.parent() == this);
  //testing received
  m.received("value 0.1");
  m.simulStep();
  QVERIFY2(w._torque == 1000*0.1, qPrintable(QString("%1").arg(w._torque)));
  
  m.received("value 0.2");
  m.simulStep();
  QVERIFY2(w._torque == 1000*0.2, qPrintable(QString("%1").arg(w._torque)));
  m.received("value 0.5");
  m.simulStep();
  QVERIFY2(w._torque == 1000*0.5, qPrintable(QString("%1").arg(w._torque)));
  
}

void TestModules::motor_wheel_param() {
  Wheel w;
  MotorWheel m(&w, "<params><gear>1</gear><torque>2000</torque></params>", this);
  m.received("value 1");
  m.simulStep();
  QVERIFY2(w._torque == 2000*1, qPrintable(QString("%1").arg(w._torque)));
  MotorWheel m2(&w, "<params><gear>1</gear><torque>3000</torque></params>", this);
  m2.received("value 1");
  m2.simulStep();
  QVERIFY2(w._torque == 3000*1, qPrintable(QString("%1").arg(w._torque)));
  MotorWheel m3(&w, "<params><gear>0.2</gear><torque>3000</torque></params>", this);
  m3.received("value 1");
  m3.simulStep();
  QVERIFY2(w._torque == 3000*1*0.2, qPrintable(QString("%1").arg(w._torque)));
}
QTEST_MAIN(TestModules)
#include "test_modules.moc"
