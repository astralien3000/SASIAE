#include "modules.hpp"
#include "wheel.hpp"
#include <QObject>
#include <QString>

class Servo : public Modules {
Q_OBJECT

public:
  Servo(Wheel* wheel, int position, QObject* parent);

public slots:
  virtual void received(QString message);  
  virtual void simulStep();

signals:
  virtual void send(QString message);
 
private:
  int position;

};
