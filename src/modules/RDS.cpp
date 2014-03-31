#include "RDS.hpp"


RDS::RDS(Balise *balise): _myBalise(balise){
  mode=0;
	this->balises = new list<Balise*>;
	_dataRoot = new QStandardItem("RDS");
}

void RDS::balise_add(Balise *balise_to_add) {
	this->balises->push_front(balise_to_add);
	btVector3 position =balise_to_add->get_position();
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("RDS")
		<< new QStandardItem(QString::number(position.getX() + position.getY() + position.getZ()));
}

QStandardItem* RDS::getData() {
	return _dataRoot;
}

list<btVector3>* RDS::get_position(){
	list<btVector3> *result = new list<btVector3>;
	//for (list<Balise*>::const_iterator it = balises->begin(); it != balises->end(); ++it) {
	for (auto it = balises->begin(); it != balises->end(); ++it) {
      if(_mode == 0) //mode cartesian
			  result->push_front((*it)->get_position()-_myBalise->get_position());
      if(_mode == 1) {
        //TODO
      }

}
	return result;
}

void RDS::update() {
  list<btVector3>* list_result = this->get_position();
  Qstring string_result;
  string_result->append( list_result.length().toString() );
  for(auto it=list_result->begin();it!=list_result->end(); ++it) {
    string_result->append( (*it)->getX() + (*it)->getZ() );
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
      } else
        //error
    } else {
      //also error
    }
} 
