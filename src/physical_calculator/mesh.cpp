#include "mesh.hpp"

World* Mesh::_world;
Mesh::Mesh(btCollisionShape* shape, double mass, PositionData start_pos) : _shape(shape) {
  buildRigidBody(shape, mass, start_pos);
}

Mesh::Mesh() {}

Mesh::Mesh(const Mesh & source) {
  this->_shape = source._shape;
  btTransform trans;
  source._body->getMotionState()->getWorldTransform(trans);
  PositionData pos_data;
  pos_data += castbtVectToPos(trans.getOrigin())+castbtQuaToPos(trans.getRotation());
  buildRigidBody(_shape, 1.f/ source._body->getInvMass(), pos_data);
}

Mesh::~Mesh()
{
 ((btDiscreteDynamicsWorld *)_world)->removeRigidBody(_body);
}

Mesh::operator btRigidBody*()
{
  return _body;
}

Mesh::operator const btRigidBody *() const{
  return _body;
}
void Mesh::buildRigidBody(btCollisionShape* shape, double mass, PositionData start_pos) {
const QVector3D v = start_pos;

  btDefaultMotionState* bodyMotionState = new btDefaultMotionState(btTransform(
        btQuaternion(start_pos.alpha,start_pos.beta, start_pos.gamma),
        btVector3(v.x(),v.y(),v.z())));
      btScalar Mass = mass;
      btVector3 bodyInertia(0,0,0);
      _shape->calculateLocalInertia(Mass,bodyInertia);
        btRigidBody::btRigidBodyConstructionInfo
                bodyRigidBodyCI(0,bodyMotionState,shape,bodyInertia);
        _body = new btRigidBody(bodyRigidBodyCI);
        if(_world != NULL)
          _world->getScene()->addRigidBody(_body);
        else
          qDebug() << "Ajout d'un corps sans avoir défini de scene";
}

Mesh* Mesh::buildCylinder(unsigned int axis, float high, float r, float mass, PositionData start_pos)
{
  btCollisionShape* shape;
  //find cylinderaxis
  if(axis == 0)
    shape = new btCylinderShapeX(btVector3(high/2., r, r));
  else if(axis == 2)
    shape = new btCylinderShapeZ(btVector3(r,r,high/2.));
  else 
    shape = new btCylinderShape(btVector3(r,high/2., r));
  return new Mesh(shape, mass, start_pos);
}

Mesh* Mesh::buildBox(QVector3D size, float mass, PositionData start_pos)
{
  return new Mesh(new btBoxShape(btVector3(size.x()/2.,size.y()/2., size.z()/2)), mass, start_pos);
}

Mesh* Mesh::buildSphere(float radius, float mass, PositionData start_pos)
{
  return new Mesh(new btSphereShape(radius), mass, start_pos);
}

void Mesh::setWorld(World& world)
{
  _world = &world;
}

PositionData Mesh::getPosition() const {
  PositionData pos;
  btTransform trans;
	_body->getMotionState()->getWorldTransform(trans);
  pos += castbtQuaToPos(trans.getRotation())+castbtVectToPos(trans.getOrigin());
  return pos;
}
