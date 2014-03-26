#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <btBulletDynamicsCommon.h>
#include "printable_mobile_object.hpp"
#include "world.hpp"
#include "mesh.hpp"

class Robot :  public PrintableMobileObject, public btRaycastVehicle{
private:
  btRaycastVehicle::btVehicleTuning _tuning;
  //rajouter la balise
public:
  //merge
  //Robot(const QString path, float mass, PositionData start_pos, const QString name, World& world);

  Robot(const ObjectConfig::meshConfig& cfg, float mass, PositionData start_pos, const QString name, World world);
  Robot(const STLMesh& mesh, World world, QString name); 

  ~Robot();

  /* This function is called in Wheel::init().
   * In order to put a wheel on a robot, you must 
   * call Wheel::init() or call 
   * Wheel::Wheel(Robot*, btVector3, btVector3, btScalar, bool);
   */
  btWheelInfo& addWheel (const btVector3 &connectionPointCS0,
			 const btVector3 &wheelDirectionCS0,
			 const btVector3 &wheelAxleCS,
			 btScalar wheelRadius,
			 bool isFrontWheel);
};
#endif //ROBOT_HPP
