#ifndef __ENCODER_H_
#define __ENCODER_H_

//#include "../PhysicalCalculator/wheel.hpp"
#include "wheel.hpp"
#include "module.hpp"
#include <QStandardItem>
#include <QString>
#include <QObject>
#include <QRegExp>
#include <QDebug>

class Encoder : public Module {
Q_OBJECT

public:
  Encoder(Wheel* wheel, QString params, QObject* parent = 0);
  static const QString xmlAccuracyName;
  virtual QStandardItem* getGuiItem(void); 

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
