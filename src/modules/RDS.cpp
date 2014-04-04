#include "RDS.hpp"
#include <qmath.h>

RDS::RDS(Balise *balise, QString name): _myBalise(balise){
  _mode=0;
	_dataRoot = new QStandardItem(name);
  maj_affichage(QList<QVector3D>());
}

QStandardItem* RDS::getGuiItem() {
	return _dataRoot;
}

QList<QVector3D> RDS::get_position(){
	QList<QVector3D> result;
	foreach (Balise* it , Balise::listBalise()) {
      if(it != _myBalise) {
        if(_mode == 0) {//mode cartesian
          PositionData v = it->getPosition()-_myBalise->getPosition();
			    result.append(v);
        }
        if(_mode == 1) {
          PositionData v = it->getPosition()-_myBalise->getPosition();
          double d = qSqrt(v.x*v.x+v.z*v.z);
			    result.append(QVector3D(d, 0 , 2 *qAtan(v.z/(v.x + d))));
        }
      }

  }
  maj_affichage(result);
	return result;
}

void RDS::maj_affichage(QList<QVector3D> pos_list) {
  //suppression de l'ancien arbre
  _dataRoot->removeRows(0,_dataRoot->rowCount());
  //ajout de ma position
  PositionData position = _myBalise->getPosition();
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Ma position")
		<< new QStandardItem(QString::number(position.x) +QString(" ")+ QString::number(position.y)+QString(" ") + QString::number(position.z)));
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Mode") << new QStandardItem(QString((_mode == 0) ? "cartesien" : "polaire")));
  foreach(QVector3D vec, pos_list) {
    _dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Detection")
      << new QStandardItem(QString::number(vec.x()) +QString(" ")+ QString::number(vec.y())+QString(" ") + QString::number(vec.z())));
  }
}

void RDS::update() {
  QList<QVector3D> list_result = this->get_position();
  QString string_result;
  string_result.append( QString::number(list_result.length()) );
  foreach(QVector3D it , list_result) {
    string_result.append(QString(" ") + QString::number(it.x()) + QString(" ") + QString::number(it.z()) );
  }
  emit(send(string_result));

} //calcul distance et emit(send())


void RDS::received(QString message) {
  QStringList list = message.split(" "); 
    if(list.at(0) == "mode") {
    // le message est du type : "value [position]" 
      if(list.at(1) == "cartesian") {
      _mode = 0;
      } else if (list.at(1) == "polar") {
      _mode = 1;
      } else {
        //error
      }
    } else {
      //also error
    }
} 
