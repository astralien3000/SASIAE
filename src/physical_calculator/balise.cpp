#include "balise.hpp"




//cylindre de masse 0.1

Balise::Balise(btDynamicsWorld* world, btRigidBody* chassis)
	: _chassis(chassis), _world(world)  {

	//masse très faible pour ne pas empecher les mouvements du robot.
		btScalar mass(0.00001);
	// Collision avec rien
		 btVector3 normal = btVector3(4,4,4);
		btCollisionShape* boxShape = new btCylinderShape(normal);
		btVector3 boxInertial(0,0,0);

		boxShape->calculateLocalInertia(mass, boxInertial);

    btTransform trans;
    _chassis->getMotionState()->getWorldTransform(trans);
		btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),trans.getOrigin()+btVector3(0,17.5+4,0)));
		boxShape->calculateLocalInertia(mass, boxInertial);
		btRigidBody::btRigidBodyConstructionInfo boxBodyCi(mass, boxMotionState, boxShape, boxInertial);
		_sensor_box = new btRigidBody(boxBodyCi);
    _sensor_box->setDamping(0,100000);
		_world->addRigidBody(_sensor_box);
		//ok

  // ajout des contraintes de points not complete ()
  normal.normalize();
  btVector3 pivotInChassis(0, 17.5, 0); //todo : add this as a constant when verified
  btVector3 pivotInBox(0,-4,0);
  btTypedConstraint* p2pL = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis,pivotInBox);

  // add constraint to world
  _world->addConstraint(p2pL);

}

btVector3 Balise::get_position() {
    btTransform trans2;
 _sensor_box->getMotionState()->getWorldTransform(trans2);
 btVector3 position(trans2.getOrigin().getX(),0,trans2.getOrigin().getZ());
 return position;
}

