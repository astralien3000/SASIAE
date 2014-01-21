#ifndef __ENCODER_H_
#define __ENCODER_H_

//#include "../PhysicalCalculator/wheel.hpp"
#include "wheel.hpp"
#include "modules.hpp"
#include <QString>
#include <QObject>
#include <QRegExp>
#include <QDebug>

class Encoder : public Modules {
Q_OBJECT

public:
  Encoder(Wheel* wheel, QString params, QObject* parent = 0);
  static const QString xmlAccuracyName;

public slots:
  virtual void received(QString message);  
  virtual void simulStep();

signals:
  virtual void send(QString message);
 
private:
  Wheel* _wheel;  
  int _accuracy;
};

#endif
