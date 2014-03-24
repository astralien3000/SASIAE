//#include "wheel.hpp"
#include "../physical_calculator/wheel.hpp"
#include "../common/object_config.hpp"
#include "../common/position_data.hpp"
#include <QVector3D>
#include "module.hpp"
#include <QStandardItem>
#include <QObject>
#include <QString>
#include <QRegExp>

class MotorWheel : public Module {
Q_OBJECT
Q_INTERFACES(Module)
Q_PLUGIN_METADATA(IID Modules_iid FILE "motor_wheel.json")

public:
  MotorWheel();
  MotorWheel(Wheel* wheel, QString params);
  MotorWheel(Wheel* wheel, double maxTorque, double gearRatio, QString name = "Motor Wheel");
  virtual Module* buildModule(Robot* robot, const ObjectConfig::moduleConfig* conf);
  virtual QStandardItem* getGuiItem(void); 
  
  static const QString xmlGearName;
  static const QString xmlTorqueName;

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
