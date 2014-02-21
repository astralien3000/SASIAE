#ifndef __RDS_H__
#define __RDS_H__

#include "../physical_calculator/balise.hpp"
#include "modules.hpp"
#include <list>

using namespace std;


class RDS : public Modules {
	Q_OBJECT

public:
  RDS(Balise *balise);

public slots:
  virtual void balise_add(Balise *balise_to_add);
  virtual list<btVector3>* get_position();
  virtual QStandardItem* getData();
  virtual void received(QString message);
  virtual void simulStep();


signals:
  virtual void send(QString message);

private:
  int _mode;
  list<Balise*> *balises;
  Balise* _myBalise;
  QStandardItem* _dataRoot;
};


#endif
