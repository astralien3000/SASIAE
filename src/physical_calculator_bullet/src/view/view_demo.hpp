#ifndef BASIC_DEMO_H
#define BASIC_DEMO_H

#ifdef _WINDOWS
#warning "Go and get a REAL OS !"

#include "bullets3D/Win32DemoApplication.h"
#define PlatformDemoApplication Win32DemoApplication
#else
#include "bullets3D/GlutDemoApplication.h"
#define PlatformDemoApplication GlutDemoApplication
#endif

class BasicDemo : public PlatformDemoApplication
{
public:
  BasicDemo(void);
  virtual ~BasicDemo();

  virtual void initPhysics();

  virtual void renderme();
  virtual void clientMoveAndDisplay();

  virtual void displayCallback();
};

#endif //BASIC_DEMO_H

