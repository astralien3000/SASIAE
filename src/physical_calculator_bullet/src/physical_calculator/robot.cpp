#include "robot.hpp"


//Robot::Robot(const QString path, float mass, PositionData start_pos, const QString name, World &world)
Robot* Robot::_r=NULL;
Robot::Robot(const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos, const QString name, const QString& path, World world)
  :  PrintableMobileObject(cfg,mass,start_pos,name, path),
   btRaycastVehicle(	_tuning,
            _body,
            new btDefaultVehicleRaycaster(world))
    {
      //emit was put in config robot coordinator.
// cant be done because PMO has no default constructor, can be emplemented with nothing but not good solution.
    // PrintableMObileObject* pmo = PrintableMobileObject(cfg,mass,start_pos,name,"../ressources/img/" + name + ".png");
    //   btRaycastVehicle(  _tuning, _body, new btDefaultVehicleRaycaster(world));
      //we have to call for   emit(tableItem(pmo->getItem())); PB !!!
  setCoordinateSystem(0,1,2);
  _body->setDamping(0.5,0.6);
  _body->setFriction(0.00001);
  _body->setRollingFriction(1);
  btDiscreteDynamicsWorld* w = world;
  w->addVehicle(this);
  _r = this;
}

Robot* Robot::getRobot() {return _r;};

Robot::Robot(const STLMesh & chassis, World world, QString name)
  : PrintableMobileObject(name,chassis),
  btRaycastVehicle(	_tuning,
			_body,
			new btDefaultVehicleRaycaster(world))
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
  qDebug() << "ROUE " << connectionPointCS0.x() << " " << connectionPointCS0.y() << " " << connectionPointCS0.z() << " "; 
  return btRaycastVehicle::addWheel (connectionPointCS0,
				     wheelDirectionCS0,
				     wheelAxleCS,
				     btScalar(0), //valeur complètement arbitraire de la longueur de la suspension au repos
				     wheelRadius,
				     _tuning,
				     isFrontWheel);
  }


