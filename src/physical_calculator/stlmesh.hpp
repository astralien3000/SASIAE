#ifndef STLMESH_HPP
#define STLMESH_HPP

#include <btBulletDynamicsCommon.h>
#include "../stl/STLReader.hpp"
#include "world.hpp"
#include "mesh.hpp"
#include "position_data.hpp"
#include <QString>
#include <QMap>
#include <QPair>

class STLMesh : Mesh {
private:
  QString _path;
  static QMap<QString, QPair<btCollisionShape*, unsigned int>> s_stlshapes;

protected:
  void init(QString path, float mass, PositionData pos);
public:
  STLMesh(QString path, float mass, PositionData start_pos);
  STLMesh(const STLMesh & mesh);
  ~STLMesh();
};
#endif //ROBOT_HPP
