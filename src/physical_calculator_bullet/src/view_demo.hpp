#ifndef BASIC_DEMO_H
#define BASIC_DEMO_H

#ifdef _WINDOWS
#include <Win32DemoApplication.h>
#define PlatformDemoApplication Win32DemoApplication
#else
#include "bullets3D/GlutDemoApplication.h"
#define PlatformDemoApplication GlutDemoApplication
#endif

#include <btBulletDynamicsCommon.h>
#include "physical_calculator.hpp"
#include "robot.hpp"
#include "wheel.hpp"
#include "world.hpp"

#include "dist_sensor.hpp"

#include <cstdio>
/*class btBroadphaseInterface;
  class btCollisionShape;
  class btOverlappingPairCache;
  class btCollisionDispatcher;
  class btConstraintSolver;
  struct btCollisionAlgorithmCreateFunc;
  class btDefaultCollisionConfiguration;
*/
///BasicDemo is good starting point for learning the code base and porting.

class BasicDemo : public PlatformDemoApplication
{
protected:
  PhysicalCalculator* pc;
  btCollisionShape* m_wheelShape;
  Robot* _robot;
  Wheel* _MD;
  Wheel* _ED;
  Wheel* _MG;
  Wheel* _EG;
  DistSensor* _dist_sensor;

public:

  BasicDemo();

  virtual ~BasicDemo();
 
  void	initPhysics();

  void	exitPhysics();
  virtual void renderme();
  virtual void clientMoveAndDisplay();

  virtual void displayCallback();
  virtual void	clientResetScene();
	
  static DemoApplication* Create();


	
};

#endif //BASIC_DEMO_H

