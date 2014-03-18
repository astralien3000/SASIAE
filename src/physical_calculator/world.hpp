#ifndef WORLD_HPP
#define WORLD_HPP

#include <btBulletDynamicsCommon.h>

class World {
  private:
    btDiscreteDynamicsWorld* _world;
  public:
    World(btDiscreteDynamicsWorld* world);
    btDiscreteDynamicsWorld* getScene();
};

#endif // WORLD_HPP
