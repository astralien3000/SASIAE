#ifndef PHYSICAL_CALCULATOR_HPP
#define PHYSICAL_CALCULATOR_HPP
#include <btBulletDynamicsCommon.h>


class PhysicalCalculator{

public:
  void empty_scene();
  void simple_scene();
  btDiscreteDynamicsWorld* getScene();
  void simple_scene_walls();
  PhysicalCalculator();
  ~PhysicalCalculator();  
  //void cleanWorld(); 

private:
  void init(); 
  btDiscreteDynamicsWorld* _scene;
  btBroadphaseInterface* _broadphase;
  btDefaultCollisionConfiguration* _collisionConfiguration;
  btCollisionDispatcher* _dispatcher;
  btSequentialImpulseConstraintSolver* _solver;
};



#endif
