#include "RDS.hpp"


RDS::RDS(Balise *balise): _myBalise(balise){
	this->balises = new list<Balise*>;
	_dataRoot = new QStandardItem("RDS");
}

void RDS::balise_add(Balise *balise_to_add) {
	this->balises->push_front(balise_to_add);
	btVector3 position =balise_to_add->get_position();
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("RDS")
		<< new QStandardItem(QString()+ position.getX() + position.getY() + position.getZ()));
}

QStandardItem* RDS::getData() {
	return _dataRoot;
}

list<btVector3>* RDS::get_position(){
	list<btVector3> *result = new list<btVector3>;
	//for (list<Balise*>::const_iterator it = balises->begin(); it != balises->end(); ++it) {
	for (auto it = balises->begin(); it != balises->end(); ++it) {
			result->push_front((*it)->get_position()-_myBalise->get_position());
	}
	return result;

}



void RDS::simulStep() {}
void RDS::received(QString message) {}
