#include "dist_sensor.hpp"

DistSensor::DistSensor(btDynamicsWorld* world, btRigidBody* chassis) : _world(world), _chassis(chassis) {}

DistSensor::DistSensor(btDynamicsWorld* world, btRigidBody* chassis, const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass) : _world(world), _chassis(chassis) {
  init(pos,direction,boxSize,mass);  
}
void DistSensor::init(const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass){
 //NOTE: boxsize vu de face, X profondeur, Y hauteur, Z largeur
 //NOTE: boxsize en halfextents i.e. dimension d'un quart de boite
 //creation de la boite
 btCollisionShape* boxShape = new btBoxShape(boxSize);
 btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform());
 btVector3 boxInertial(0,0,0);
 boxShape->calculateLocalInertia(mass, boxInertial);
 btRigidBody::btRigidBodyConstructionInfo boxBodyCi(mass, boxMotionState, boxShape, boxInertial);
 _sensor_box = new btRigidBody(boxBodyCi);
 _world->addRigidBody(_sensor_box);
 //creation de la contraint
 //lx = -z y x
 btVector3 normal = direction;
 normal.normalize();
 btVector3 relativeVec(-1*normal.getZ(), normal.getY(), normal.getX());
 btVector3 pivotInChassis1 = pos + relativeVec*btScalar(boxSize.getX()*4/3); 
 btVector3 pivotInChassis2 = pos + relativeVec*btScalar(-1*boxSize.getX()*4/3); 
 btVector3 pivotInBox1(boxSize.getX()*btScalar(4/3),0,boxSize.getZ());
 btVector3 pivotInBox2(boxSize.getX()*btScalar(-4/3),0,boxSize.getZ());
 btTypedConstraint* p2pL = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis1,pivotInBox1);
 btTypedConstraint* p2pR = new btPoint2PointConstraint(*_chassis,*_sensor_box, pivotInChassis1,pivotInBox2);
 
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
 btVector3 start(0,0,0);//TODO find the right vect 
 btVector3 end(0,0,0);//TODO find the right vect 
 btCollisionWorld::ClosestRayResultCallback rayCallback(start,end);
 //rayCallback.m_flags |= btTriangleRaycastCallback::kF_FilterBackfaces;
 _world->rayTest(start,end,rayCallback);
 if(rayCallback.hasHit()) {
  //btVector3 p = start.lerp(end, rayCallback.m_closestHitFraction);
  //_cache = start.distance(p);
  _cache = start.distance(end)*rayCallback.m_closestHitFraction;
 }
 else {
   _cache = INFINITY;
  }
}
