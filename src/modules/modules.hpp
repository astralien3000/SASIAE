#ifndef __MODULES_HPP_
#define __MODULES_HPP_

#include <QStandardItemModel>
#include <QObject>

class Modules : public QObject {
Q_OBJECT

public:
  Modules(QObject* parent = 0);
  //! \brief needed for UI
  virtual QStandardItem* getData()=0;

public slots:
  virtual void received(QString message) = 0;  
  virtual void simulStep() = 0;

signals:
  virtual void send(QString message) = 0;
  

};

#endif
