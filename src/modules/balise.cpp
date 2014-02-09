#include "balise.hpp"




//cylindre de masse 0.1

Balise::Balise(Robot* robot, QObject* parent, PhysicalCalculator* calculator): Modules(parent) {
	_dataRoot = new QStandardItem("Balise");


	btDiscreteDynamicsWorld * myscene= calculator->getScene();


	btTransform trans;
	trans = robot->getChassisWorldTransform();
	btScalar z,y,x;
	trans.getBasis().getEulerZYX(z,y,x);
	this->position =
	btVector3(trans.getOrigin().getX()
		, trans.getOrigin().getY()
		, trans.getOrigin().getZ()); //la position de la balise.

	_dataRoot->appendRow(QList<QStandardItem*>() << new QStandardItem("Balise")
		<< new QStandardItem(QString()+ trans.getOrigin().getX() + trans.getOrigin().getY() + trans.getOrigin().getZ()));

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
	btVector3 new_position = boxBody->getCenterOfMassPosition();
	this->position.setX(new_position.getX());
	this->position.setY(new_position.getY());
	this->position.setZ(new_position.getZ());
}//TODO remet à jour le vecteur de position.
void Balise::received(QString message) {}
