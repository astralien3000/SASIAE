#include "balise.hpp"
#include "modules.hpp"
#include <list>

using namespace std;


class RDS : public Modules {
	Q_OBJECT

public:
  RDS();
       
public slots:
  virtual void balise_add(Balise *balise_to_add);
  virtual list<btVector3>* get_other_position(Balise *robot_balise);
  virtual QStandardItem* getData();
  virtual void received(QString message);
  virtual void simulStep();
  
  
signals:
  virtual void send(QString message);
  
private:
  list<Balise*> *balises;
  QStandardItem* _dataRoot;
};


