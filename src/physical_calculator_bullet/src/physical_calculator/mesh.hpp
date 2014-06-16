#ifndef MESH_HPP
#define MESH_HPP

#include <string>

class btCollisionShape;

class MyMesh {
protected:
    MyMesh(void);

public:
    virtual ~MyMesh(void);

    btCollisionShape* getShape(void);

protected:
    void setShape(btCollisionShape*);

private:
    struct PrivateData;
    PrivateData* _data;
};

///////////////////////////////////////////////////////////////////////////////////


#include <btBulletDynamicsCommon.h>
#include "world.hpp"
#include "position_data_bullet.hpp"

#include <QDebug>

class Mesh {
private:
    static World _world;
    btCollisionShape* _shape;
protected:
    btRigidBody* _body;

    Mesh(btCollisionShape* shape, double mass, PositionData start_pos);
    Mesh();
    Mesh(const Mesh & source);
    ~Mesh();
    void buildRigidBody(btCollisionShape* shape, double mass, PositionData pos);

public:
    operator btRigidBody*();
    operator const btRigidBody*() const;
    static Mesh* buildCylinder(unsigned int axis, float high, float r, float mass, PositionData start_pos);
    static Mesh* buildBox(QVector3D size, float mass, PositionData start_pos);
    static Mesh* buildSphere(float radius, float mass, PositionData start_pos);
    static void setWorld(World& world);
    static World getWorld();
    PositionData getPosition()const;
};
#endif //ROBOT_HPP
