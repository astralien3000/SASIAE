#include "robot.hpp"


Robot* Robot::_r=NULL;

Robot::Robot(World& world, const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos)
//  :  PrintableMobileObject(cfg,mass,start_pos,"name", "path"),
//     btRaycastVehicle(_tuning,
//		      _body,
//		      new btDefaultVehicleRaycaster(world))
{

//  setCoordinateSystem(0,1,2);
//  _body->setDamping(0.5,0.6);
//  _body->setFriction(0.00001);
//  //_body->setRollingFriction(1);
//  btDiscreteDynamicsWorld* w = world;
//  w->addVehicle(this);
//  _r = this;
}

Robot* Robot::getRobot() {return _r;};

Robot::~Robot() {
}

btWheelInfo& Robot::addWheel (const btVector3 &connectionPointCS0,
			      const btVector3 &wheelDirectionCS0,
			      const btVector3 &wheelAxleCS,
			      btScalar wheelRadius,
			      bool isFrontWheel) {
//  qDebug() << "ROUE " << connectionPointCS0.x() << " " << connectionPointCS0.y() << " " << connectionPointCS0.z() << " ";
//  return btRaycastVehicle::addWheel (connectionPointCS0,
//				     wheelDirectionCS0,
//				     wheelAxleCS,
//				     btScalar(0), //valeur complètement arbitraire de la longueur de la suspension au repos
//				     wheelRadius,
//				     _tuning,
//				     isFrontWheel);
}


