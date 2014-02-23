#ifndef MODULE_HPP
#define MODULE_HPP

#include <QObject>
#include <QStandardItemModel>

class Module : public QObject {
  Q_OBJECT;

signals:
  //! \brief Send a message to the device
  void send(QString);

public slots:
  //! \brief Parse a received message
  virtual void received(QString) = 0;

  //! \brief Computes one simulation step
  virtual void update(void) = 0;

public:
  //! \brief Constructor
  inline Module(QObject* parent = 0) : QObject(parent) {}

  //! \brief Return an item to show on the QTreeView
  virtual QStandardItem* getGuiItem(void) = 0;
};

#endif//MODULE_HPP
