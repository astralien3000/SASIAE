#include "wheel.hpp"
#include "modules.hpp"
#include <QObject>
#include <QString>

class MotorWheel : public Modules {

public:
  MotorWheel(Wheel* wheel, QString params, QObject* parent = 0);

public slots:
  virtual void received(QString message) = 0;  
  virtual void simulStep() = 0;

signals:
  virtual void send(QString message) = 0;
 
private:
  double _motorMaxTorque;
  double _gearRatio;
  double _inputRatio;
};
