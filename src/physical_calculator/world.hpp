#ifndef WORLD_HPP
#define WORLD_HPP

#include <btBulletDynamicsCommon.h>

class World {
  private:
    btDiscreteDynamicsWorld* _world;
  public:
    World(const World& w);
    World(btDiscreteDynamicsWorld* world);
    btDiscreteDynamicsWorld* getScene();
    operator btDiscreteDynamicsWorld* ();
};

#endif // WORLD_HPP
