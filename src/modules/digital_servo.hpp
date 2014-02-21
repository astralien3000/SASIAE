#ifndef __DIGITAL_SERVO_
#define __DIGITAL_SERVO_

#include "modules.hpp"
#include <QObject>

class DigitalServo : public Modules {
Q_OBJECT

public:
  DigitalServo();

public slots:
  virtual QStandardItem* getData(); 
  virtual void received(QString message);  
  virtual void simulStep();

signals:
  virtual void send(QString message);

private:
  int position;
  int speed;
  int accel;

  int max_pos;
  int max_spe;
  int max_acc;

  int cmd_pos;
  int cmd_spe;
  int cmd_acc;
  
  enum Mode {
    POSITION,
    SPEED,
    TORQUE
  };

  Mode com_mode;
  Mode true_mode;

  QStandardItem* _dataRoot;
};


#endif//__DIGITAL_SERVO_
