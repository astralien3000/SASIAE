#ifndef __BALISE_H__
#define __BALISE_H__

#include "robot.hpp"
#include "physical_calculator.hpp"

#include <QObject>
#include <QString>
#include <QStandardItem>
#include <btBulletDynamicsCommon.h>


class Balise {
public:
	Balise(btDynamicsWorld* world, btRigidBody* chassis);
	//done
	btVector3 get_position();


	// public slots:
	// virtual void simulStep(); //TODO
	// not needed : la position est calculée à chaque appel.



private:
  btRigidBody* _chassis; //ok
	btRigidBody* _sensor_box; //ok
	QStandardItem* _dataRoot; //ok
  btDynamicsWorld* _world; // ok
};


#endif
