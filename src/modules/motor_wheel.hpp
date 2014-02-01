#include "wheel.hpp"
#include "modules.hpp"
#include <QStandardItem>
#include <QObject>
#include <QString>
#include <QRegExp>

class MotorWheel : public Modules {
Q_OBJECT

public:
  MotorWheel(Wheel* wheel, QString params, QObject* parent = 0);
  static const QString xmlGearName;
  static const QString xmlTorqueName;
  virtual QStandardItem& getData(); 

public slots:
  virtual void received(QString message);  
  virtual void simulStep();

signals:
  virtual void send(QString message);
 
private:
  Wheel* _wheel;
  double _motorMaxTorque;
  double _gearRatio;
  double _inputRatio;
  QStandardItem* _dataRoot;
};
