#include "modules.hpp"
<<<<<<< HEAD
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDebug>

class Servo : public Modules {

public:
  Servo(int position);
  ~Servo();		     
		   
public slots:
  void received(QString message);  
  void simulStep();

signals:
  //virtual void send(QString message); 
 
private:
  int _position;
=======
#include <QObject>
#include <QString>
#include <QStandardItem>


class Servo : public Modules {
	Q_OBJECT

public:
	Servo(int position, QObject* parent);

	public slots:
	virtual void received(QString message);
	virtual void simulStep();
	virtual QStandardItem* getData();

	signals:
	virtual void send(QString message);
>>>>>>> 72f857d705b5633bec4ddf333239e0bee8692b16

private:
	int position;
	QStandardItem* _dataRoot;
};
