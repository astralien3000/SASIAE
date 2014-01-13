#ifndef PHYSICAL_CALCULATOR_HPP
#define PHYSICAL_CALCULATOR_HPP
#include <btBulletDynamicsCommon.h>


class PhysicalCalculator{

public:
  void empty_scene();
  void simple_scene();
  btDiscreteDynamicsWorld* getScene();
  PhysicalCalculator();
  ~PhysicalCalculator();  
  void cleanWorld(); //TODO

private:
  void init(); //TODO
  btDiscreteDynamicsWorld* _scene;
  btBroadphaseInterface* _broadphase;
  btDefaultCollisionConfiguration* _collisionConfiguration;
  btCollisionDispatcher* _dispatcher;
  btSequentialImpulseConstraintSolver* _solver;
};



#endif
