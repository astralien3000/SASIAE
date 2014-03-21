#include "balise.hpp"


//cylindre de masse 0.1

Balise::Balise(World world, Robot* chassis)
: _chassis(chassis)  {

	//masse très faible pour ne pas empecher les mouvements du robot.
	float mass(0.00001);
  PositionData pos(0,17.5 + 8/2., 0,0,0,0);
  pos += chassis->getPosition();
  _sensor_box = Mesh::buildCylinder(1, 8,4, mass, pos);

	((btRigidBody*) _sensor_box)->setDamping(0,100000);

  // ajout des contraintes de points
  btVector3 pivotInChassis(0, 17.5, 0); 
  btVector3 pivotInBox(0,-8/2,0);
  btTypedConstraint* p2pL = new btPoint2PointConstraint(*((btRigidBody*)*_chassis),*((btRigidBody*)*_sensor_box),pivotInChassis,pivotInBox);

  // add constraint to world
  ((btDiscreteDynamicsWorld*)world)->addConstraint(p2pL);

}

PositionData Balise::getPosition() {
  return _sensor_box->getPosition();
}

