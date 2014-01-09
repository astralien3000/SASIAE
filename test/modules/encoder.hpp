#include "wheel.h"
#include "Modules.h"
#include <QString>
#include <QObject>

class Encoder : public Modules {

public:
  Encoder(Wheel* wheel, QString params, QObject* parent = 0);

public slots:
  virtual void received(QString message) = 0;  
  virtual void simulStep() = 0;

signals:
  virtual void send(QString message) = 0;
 
private:
  Wheel* _wheel;  
  int _accuracy;
}
