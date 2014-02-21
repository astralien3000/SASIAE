#include "balise.hpp"




//cylindre de masse 0.1

Balise::Balise(btDynamicsWorld* world, btRigidBody* chassis)
	: _chassis(chassis), _world(world)  {

	//masse très faible pour ne pas empecher les mouvements du robot.
		btScalar mass(0.1);
	// Collision avec rien
		 btVector3 normal = btVector3(3,0,0);
		btCollisionShape* boxShape = new btCylinderShape(normal);
		btVector3 boxInertial(0,0,0);

		boxShape->calculateLocalInertia(mass, boxInertial);


		btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform());
		boxShape->calculateLocalInertia(mass, boxInertial);
		btRigidBody::btRigidBodyConstructionInfo boxBodyCi(mass, boxMotionState, boxShape, boxInertial);
		_sensor_box = new btRigidBody(boxBodyCi);
		_world->addRigidBody(_sensor_box);
		//ok

  // ajout des contraintes de points not complete ()
  normal.normalize();
  btVector3 pivotInChassis(0, 0, 43/2); //todo : add this as a constant when verified
  btVector3 pivotInBox(normal.getX()*btScalar(-1),0,normal.getZ());
  btTypedConstraint* p2pL = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis,pivotInBox);

  // add constraint to world
  _world->addConstraint(p2pL);

}

btVector3 Balise::get_position() {
 btVector3 position = _sensor_box->getCenterOfMassPosition();
 return position;
}

