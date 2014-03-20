#ifndef MESH_HPP
#define MESH_HPP

#include <btBulletDynamicsCommon.h>
#include "world.hpp"
#include "position_data.hpp"

class Mesh {
private:
  static World* _world;
  btCollisionShape* _shape;
protected:
  btRigidBody* _body;
  
  Mesh(btCollisionShape* shape, double mass, PositionData start_pos);
  Mesh();
  Mesh(const Mesh & source);
  ~Mesh();
  void buildRigidBody(btCollisionShape* shape, double mass, PositionData pos);
   operator btRigidBody*();

public:
  operator const btRigidBody*() const;
  static Mesh* buildCylinder(unsigned int axis, float high, float radius, float mass, PositionData start_pos);
  static Mesh* buildBox(QVector3D size, float mass, PositionData start_pos);
  static Mesh* buildSphere(float radius, float mass, PositionData start_pos);
  static void setWorld(World& world);
  PositionData getPosition();
};
#endif //ROBOT_HPP
