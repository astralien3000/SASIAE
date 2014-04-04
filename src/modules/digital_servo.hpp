#ifndef __DIGITAL_SERVO_
#define __DIGITAL_SERVO_

#include "module.hpp"
#include <QObject>
#include <QString>

class DigitalServo : public Module {
Q_OBJECT

public:
  DigitalServo(QString name = "DigitalServo");

public slots:
  virtual QStandardItem* getGuiItem(); 
  virtual void received(QString message);  
  virtual void update();

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
