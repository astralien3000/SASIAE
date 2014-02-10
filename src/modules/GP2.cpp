#include "GP2.hpp"

GP2::GP2() {
  _dataRoot = new QStandradItem("GP2");
  _dataRoot->appendRow(QList<QStandradItem*>() << new QStandardItem("Distance") << new QStandardItem(QString() + 0));
}

QStandardItem* GP2::getData() {
  return _dataRoot;
}

void GP2::received(QString message) {
  qDebug() << "Message du robot vers l'encodeur Oo :" << message;
}

void GP2::simulStep() {
  // Call GP2 phy stuff

  // Push new values
  _dataRoot->child(0,1)->setText(QString() + 0);
  emit(send(QString("value %1").arg((int)0)));
}
