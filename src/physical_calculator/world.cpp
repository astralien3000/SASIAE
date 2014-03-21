#include "world.hpp"

World::World(btDiscreteDynamicsWorld* world) : _world(world) {}
btDiscreteDynamicsWorld* World::getScene() {
  return _world;
}
World::operator btDiscreteDynamicsWorld* () {
  return _world;
}
