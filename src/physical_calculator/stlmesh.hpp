#ifndef MESH_HPP
#define MESH_HPP

#include <btBulletDynamicsCommon.h>
#include "../stl/STLReader.hpp"
#include "world.hpp"
#include <QString>
#include <QMap>
#include <QPair>

class Mesh {
private:
  World* _world;
  double _mass;
  bool _mov;
  btCollisionShape* _shape;
  QString _path;
  static QMap<QString, QPair<btCollisionShape*, unsigned int> > _stlshapes;
public:
  Mesh(World& world, QString stlpath, double mass, bool movable = true);
  Mesh();
  Mesh(const Mesh & source);
  ~Mesh();
  const btRigidBody* operator btRigidBody*() const;
  btRigidBody* operator btRigidBody*();
protected:
  btRigidBody* _body;
  void buildRigidBody(); 
  void init(World& world, QString stlpath, double mass, bool movable = true);
};
#endif //ROBOT_HPP
