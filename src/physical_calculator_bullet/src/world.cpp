#include "world.hpp"

World::World(const World &w){
    _world=w._world;
}

World::World(btDiscreteDynamicsWorld* world) : _world(world) {}
btDiscreteDynamicsWorld* World::getScene() {
  return _world;
}
World::operator btDiscreteDynamicsWorld* () {
  return _world;
}
