#ifndef BASIC_DEMO_H
#define BASIC_DEMO_H

#ifdef _WINDOWS
#include <Win32DemoApplication.h>
#define PlatformDemoApplication Win32DemoApplication
#else
#include "GlutDemoApplication.h"
#define PlatformDemoApplication GlutDemoApplication
#endif

#include "../../src/coordinator/coordinator.hpp"

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
  Coordinator* cdn;
  btCollisionShape* m_wheelShape;
  /*
    FROM PC to Coordinator

    btCollisionShape* m_wheelShape;
    Robot* _robot;
    Wheel* _MD;
    Wheel* _ED;
    Wheel* _MG;
    Wheel* _EG;
  */
public:

  BasicDemo();
  virtual ~BasicDemo()
  {
    //delete cdn;
    exitPhysics();
  }
  void	initPhysics();
  
  void	exitPhysics();
  virtual void renderme();
  virtual void clientMoveAndDisplay();

  virtual void displayCallback();
  virtual void	clientResetScene();
	
  static DemoApplication* Create();

	
};

#endif //BASIC_DEMO_H

