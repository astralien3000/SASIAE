#ifndef __ENCODER_H_
#define __ENCODER_H_

#include "../physical_calculator/wheel.hpp"
//#include "wheel.hpp"
#include "module.hpp"
#include <QStandardItem>
#include <QString>
#include <QObject>
#include <QRegExp>
#include <QDebug>

class Encoder : public Module {
Q_OBJECT
Q_INTERFACES(Module)
Q_PLUGIN_METADATA(IID Modules_iid FILE "encoder.json")

public:
  Encoder();
  Encoder(Wheel* wheel, int accuracy, QString name = "Encoder");
  Encoder(Wheel* wheel, QString params);
  virtual QStandardItem* getGuiItem(void); 
  virtual Module* buildModule(Robot* robot, const ObjectConfig::moduleConfig* conf);

  static const QString xmlAccuracyName;

public slots:
  virtual void received(QString message);  
  virtual void update(void);

signals:
  virtual void send(QString message);
 
private:
  Wheel* _wheel;  
  int _accuracy;
  QStandardItem* _dataRoot;
};

#endif
