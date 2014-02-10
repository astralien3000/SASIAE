#include "balise.hpp"




//cylindre de masse 0.1

Balise::Balise(Robot* robot, QObject* parent, PhysicalCalculator* calculator): Modules(parent) {


	btDiscreteDynamicsWorld * myscene= calculator->getScene();


	btTransform trans;
	trans = robot->getChassisWorldTransform();
	btScalar z,y,x;
	trans.getBasis().getEulerZYX(z,y,x);
	this->position =
	btVector3(trans.getOrigin().getX()
		, trans.getOrigin().getY()
		, trans.getOrigin().getZ()); //la position de la balise.



	_dataRoot = new QStandardItem("Balise");

	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("X")
		<< new QStandardItem(QString()+ trans.getOrigin().getX()));
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Y")
		<< new QStandardItem(QString()+ trans.getOrigin().getY()));
	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Z")
		<< new QStandardItem(QString()+ trans.getOrigin().getZ()));



	//masse très faible pour ne pas empecher les mouvements du robot.
	btScalar mass(0.1);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(trans);
	// Collision avec rien
	btCollisionShape* boxShape = new btCylinderShape(btVector3(3,0,0));

	btVector3 localInertia(0,0,0);
	boxShape->calculateLocalInertia(mass, localInertia);



	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,boxShape,localInertia);
	boxBody=new btRigidBody(rbInfo);

	myscene->addRigidBody(boxBody);
}

btVector3 Balise::get_position() {
	return this->position;
}

QStandardItem* Balise::getData() {
	return _dataRoot;
}

void Balise::simulStep() {
    btTransform transformation;
	boxBody->getMotionState()->getWorldTransform(transformation);
	this->position.setX(transformation.getOrigin().getX());
	this->position.setY(transformation.getOrigin().getY());
	this->position.setZ(transformation.getOrigin().getZ());
  _dataRoot->child(1,1)->setText(QString() + transformation.getOrigin().getX()); // pas sûr pour les valeurs mises dan child, les tests permettront d'être sur.
  _dataRoot->child(2,1)->setText(QString() + transformation.getOrigin().getY());
  _dataRoot->child(3,1)->setText(QString() + transformation.getOrigin().getZ());

}//TODO remet à jour le vecteur de position.
void Balise::received(QString message) {}
