#include "dist_sensor.hpp"

int DistSensor::MAX_DIST = 100000;

DistSensor::DistSensor(World* world, Robot* chassis) : _chassis(chassis), _world(world) {}

DistSensor::DistSensor(World* world, Robot* chassis, const PositionData pos, const PositionData direction, const QVector3D& boxSize, float mass) : _chassis(chassis), _world(world) 
{
  init(pos,direction,boxSize,mass);  
}

void DistSensor::init(const PositionData pos_data, const PositonData &direction, const QVector3D& boxSize, float mass){
  
  _box_depth = boxSize.z()/2;
 //creation de la boite
 _sensor_box = Mesh::buildBox(boxSize, mass, _chassis->getPosition()+pos_data);
 //creation de la contrainte
 //lx = -z y x
 btVector3 normal(direstion.getPosition().x(),
              direstion.getPosition().y(),
              direstion.getPosition().z());
 btVector3 pos(pos_data.getPosition().x(),
              pos_data.getPosition().y(),
              pos_data.getPosition().z());
 normal.normalize();
 btVector3 relativeVec(-1*normal.getZ(), normal.getY(), normal.getX());
 btVector3 pivotInChassis1 = pos + relativeVec*btScalar(boxSize.x()*4./3.); 
 btVector3 pivotInChassis2 = pos + relativeVec*btScalar(boxSize.x()*-4./3.); 
 btVector3 pivotInBox1(boxSize.x()*btScalar(-4./3.),0,-boxSize.z());
 btVector3 pivotInBox2(boxSize.x()*btScalar(4./3.),0,-boxSize.z());
 btTypedConstraint* p2pL = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis1,pivotInBox1);
 btTypedConstraint* p2pR = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis2,pivotInBox2);
 
 // add constraint to world
 _world->addConstraint(p2pL);
 _world->addConstraint(p2pR);

  }
double DistSensor::getCachedDist(){
  return _cache;   
}
double DistSensor::getDist(){
  calcDist();
  return getCachedDist();
}
void DistSensor::calcDist(){
  btTransform trans;
 _sensor_box->getMotionState()->getWorldTransform(trans);//TODO check if it's the right vect 
btVector3 worldDir = btVector3(0,0,1).rotate(trans.getRotation().getAxis(), trans.getRotation().getAngle()).normalize();
 btVector3 start = trans.getOrigin()+worldDir*_box_depth;
 btVector3 end = start+worldDir*MAX_DIST;//TODO check if it's the right vect 
 btCollisionWorld::ClosestRayResultCallback rayCallback(start,end);
 //rayCallback.m_flags |= btTriangleRaycastCallback::kF_FilterBackfaces;
 _world->rayTest(start,end,rayCallback);
 if(rayCallback.hasHit()) {
  //btVector3 p = start.lerp(end, rayCallback.m_closestHitFraction);
  //_cache = start.distance(p);
  _cache = trans.getOrigin().distance(end)*rayCallback.m_closestHitFraction;
 }
 else {
   _cache = INFINITY;
  }
}
