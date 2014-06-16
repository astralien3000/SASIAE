#ifndef STLMESH_HPP
#define STLMESH_HPP

#include "mesh.hpp"

#include <string>

class MyStlMesh : public MyMesh {
public:
    MyStlMesh(std::string path);
    virtual ~MyStlMesh(void);
};

//////////////////////////////////////////////////////////////////////////////////
//#include <btBulletDynamicsCommon.h>
//#include "world.hpp"
//#include "mesh.hpp"
//#include "position_data_bullet.hpp"
//#include <QString>
//#include "common/object_config.hpp"
//#include <QMap>
//#include <QPair>

//class STLMesh : public Mesh {
//public:
//    STLMesh(const ObjectConfig::meshConfig& cfg, double mass, PositionData start_pos);
//    STLMesh(const STLMesh & mesh);
//    virtual ~STLMesh();

//protected:
//    void init(const ObjectConfig::meshConfig& cfg, double mass, PositionData pos);

//private:
//    QString _path;
//    static QMap<QString, QPair<btCollisionShape*, unsigned int> > s_stlshapes;
//};

#endif//STL_MESH_HPP
