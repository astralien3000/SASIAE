#include "modules.hpp"
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

};
