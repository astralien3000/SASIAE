#include "modules.hpp"
#include <QObject>
#include <QString>

class Servo : public Modules {
Q_OBJECT

public:
  Servo(int position);

public slots:
  virtual void received(QString message);  
  virtual void simulStep();

signals:
  virtual void send(QString message);
 
private:
  int position;

};
