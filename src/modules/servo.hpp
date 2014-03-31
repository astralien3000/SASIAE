#ifndef __SERVO_H_
#define __SERVO_H_


#include "module.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <QtGui/QStandardItem>


class Servo : public Module {

public:
  Servo(int _position, QString name = "Servo");
  ~Servo();

public slots:
  void received(QString message);
  void update();
  virtual QStandardItem* getGuiItem();

signals:
  //virtual void send(QString message);

private:
	int _position;
	QStandardItem* _dataRoot;
};



#endif
