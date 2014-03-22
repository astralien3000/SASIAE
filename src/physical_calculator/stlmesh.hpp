#ifndef STLMESH_HPP
#define STLMESH_HPP

#include <btBulletDynamicsCommon.h>
#include "world.hpp"
#include "mesh.hpp"
#include "position_data_bullet.hpp"
#include <QString>
#include <QMap>
#include <QPair>

class STLMesh : public Mesh {
private:
  QString _path;
  static QMap<QString, QPair<btCollisionShape*, unsigned int>> s_stlshapes;

protected:
  void init(const QString path, double mass, PositionData pos);
public:
  STLMesh(const QString path, double mass, PositionData start_pos);
  STLMesh(const STLMesh & mesh);
  ~STLMesh();
};
#endif //ROBOT_HPP
