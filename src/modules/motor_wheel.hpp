//#include "wheel.hpp"
#include "../physical_calculator/wheel.hpp"
#include "module.hpp"
#include <QStandardItem>
#include <QObject>
#include <QString>
#include <QRegExp>

class MotorWheel : public Module {
Q_OBJECT

public:
  MotorWheel(Wheel* wheel, QString params, QObject* parent = 0);
  static const QString xmlGearName;
  static const QString xmlTorqueName;
  virtual QStandardItem* getGuiItem(void); 

public slots:
  virtual void received(QString message);  
  virtual void update(void);

signals:
  virtual void send(QString message);
 
private:
  Wheel* _wheel;
  double _motorMaxTorque;
  double _gearRatio;
  double _inputRatio;
  QStandardItem* _dataRoot;
};
