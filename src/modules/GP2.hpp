#include "modules.hpp"
#include <list>

using namespace std;


class GP2 : public Modules {
Q_OBJECT
  
public:
  GP2();
       
public slots:
  virtual QStandardItem* getData();
  virtual void received(QString message);
  virtual void simulStep();
    
signals:
  virtual void send(QString message);

private:
	QStandardItem* _dataRoot;
};


