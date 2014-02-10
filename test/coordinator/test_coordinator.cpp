//#include "wheel.hpp"
#include "../../src/coordinator/coordinator.hpp"

#include <QtTest/QtTest>
#include <QObject>

class TestCoordinator : public QObject
{
  Q_OBJECT
  private slots:
    void syncCalculator();

};

void TestCoordinator::syncCalculator() {
  Coordinator& c = Coordinator::getInstance(); 
  QSignalSpy spyNext(&c, SIGNAL(calcNextStep(double,int)));
  QSignalSpy spyTimer(&c, SIGNAL(timer(double)));
  c.play();
  c.pause();
  QCOMPARE(spyNext.count(), 1); //signal was emitted exactly one time
  QCOMPARE(spyTimer.count(), 1); //signal was emitted exactly one time
  QList<QVariant> argTimer = spyTimer.takeFirst(); // take the first signal
  QVERIFY2(argTimer.at(0).toDouble() == 0., qPrintable(QString("Erreur, pas de simulation :")+argTimer.at(0).toDouble()));
  QList<QVariant> argNext = spyNext.takeFirst(); // take the first signal
  QVERIFY2(argNext.at(0).toDouble() == 1./120., qPrintable(QString("Erreur, pas de simulation :")+argNext.at(0).toDouble()));
  QVERIFY2(argNext.at(1).toDouble() == 20, qPrintable(QString("Erreur, sous pas de simulation :")+argNext.at(0).toDouble()));
  c.stepDone();
  c.play();
  c.pause();
  QCOMPARE(spyTimer.count(), 1); 
   argTimer = spyTimer.takeFirst(); // take the first signal
  QVERIFY2(argTimer.at(0).toDouble() == 1./120., qPrintable(QString("Erreur, pas de simulation :")+argTimer.at(0).toDouble()));
  
}



QTEST_MAIN(TestCoordinator)
#include "test_coordinator.moc"
