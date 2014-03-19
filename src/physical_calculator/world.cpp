#include "world.hpp"

World::World(btDiscreteDynamicsWorld* world) : _world(world) {}
btDiscreteDynamicsWorld* World::getScene() {
  return _world;
}
operator btDiscreteDynamicsWorld* () {
  return _world;
}
