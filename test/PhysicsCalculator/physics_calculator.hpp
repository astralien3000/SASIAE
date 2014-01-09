#ifndef PHYSICS_CALCULATOR_HPP
#define PHYSICS_CALCULATOR_HPP
#include <btBulletDynamicsCommon.h>


class PhysicsCalculator{

public:
  void empty_scene();
  void simple_scene();
  void init();
  
  btDiscreteDynamicsWorld* getScene();
  void cleanWorld();


private:
  btDiscreteDynamicsWorld* _scene;
  btBroadphaseInterface* _broadphase;
  btDefaultCollisionConfiguration* _collisionConfiguration;
  btCollisionDispatcher* _dispatcher;
  btSequentialImpulseConstraintSolver* _solver;
};



#endif
