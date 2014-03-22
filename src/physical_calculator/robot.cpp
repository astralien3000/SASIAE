#include "robot.hpp"

Robot::Robot(const Mesh & chassis, World *world) 
  :  PrintableMobileObject(chassis),
   btRaycastVehicle(	_tuning,
			_body, 
			new btDefaultVehicleRaycaster(*world))
    {
  setCoordinateSystem(0,1,2);
  _body->setDamping(0.5,0.6);  
  _body->setFriction(0.00001);
  _body->setRollingFriction(1);
}


Robot::Robot(const QString path, float mass, PositionData start_pos, const QString name, World &world)
  :  PrintableMobileObject(path,mass,start_pos,name),
   btRaycastVehicle(	_tuning,
            _body,
            new btDefaultVehicleRaycaster(world))
    {
  setCoordinateSystem(0,1,2);
  _body->setDamping(0.5,0.6);
  _body->setFriction(0.00001);
  _body->setRollingFriction(1);
}



Robot::Robot(const Mesh & chassis, World *world, QString name) 
  : PrintableMobileObject(name,chassis),
  btRaycastVehicle(	_tuning,
			_body, 
			new btDefaultVehicleRaycaster(*world))
    {
  setCoordinateSystem(0,1,2);
  _body->setDamping(0.5,0.6);  
  _body->setFriction(0.00001);
  _body->setRollingFriction(1);
}

Robot::~Robot() {
}

btWheelInfo& Robot::addWheel (const btVector3 &connectionPointCS0,
			      const btVector3 &wheelDirectionCS0,
			      const btVector3 &wheelAxleCS,
			      btScalar wheelRadius,
			      bool isFrontWheel) {
  return btRaycastVehicle::addWheel (connectionPointCS0,
				     wheelDirectionCS0,
				     wheelAxleCS,
				     btScalar(0), //valeur complètement arbitraire de la longueur de la suspension au repos
				     wheelRadius,
				     _tuning,
				     isFrontWheel);
  }


