#include <QObject>

class Modules : QObject {
Q_OBJECT

public:
  Modules(QObject* parent = 0);

public slots:
  virtual void received(QString message) = 0;  
  virtual void simulStep() = 0;

signals:
  virtual void send(QString message) = 0;
  

};
