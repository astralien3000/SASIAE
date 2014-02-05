#include "RDS.hpp"


RDS::RDS() {
	this->balises = new list<Balise*>;
	_dataRoot = new QStandardItem("RDS");
}

void RDS::balise_add(Balise *balise_to_add) {
	//emplace_front a l'air mieux mais ne fonctionne pas encore, push_front fait une copie..
	this->balises->push_front(balise_to_add);
	btVector3 position =balise_to_add->get_position();
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("RDS")
		<< new QStandardItem(QString()+ position.getX() + position.getY() + position.getZ()));
}

QStandardItem* RDS::getData() {
	return _dataRoot;
}

list<btVector3>* RDS::get_other_position(Balise *robot_balise){
	list<btVector3> *result = new list<btVector3>;
	for (list<Balise*>::const_iterator it = balises->begin(); it != balises->end(); ++it) {
		if(*it!=robot_balise)
			result->push_front(*it->get_position());
	}
	return result;

}



void RDS::send(QString message) {}
void RDS::simulStep() {}
void RDS::received(QString message) {}