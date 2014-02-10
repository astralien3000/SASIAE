#include "dist_sensor.hpp"

DistSensor::DistSensor(btDynamicsWorld* world, btRigidBody* chassis) : _world(world), _chassis(chassis) {}

DistSensor::DistSensor(btDynamicsWorld* world, btRigidBody* chassis, const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass) : _world(world), _chassis(chassis) {
  init(pos,direction,boxSize,mass);  
}
void DistSensor::init(const btVector3 &pos, const btVector3 &direction, const btVector3 &boxSize, const btScalar &mass){
  //creation de la boite
 btCollisionShape* boxShape = new btBoxShape(boxSize);
 btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform());
 btVector3 boxInertial(0,0,0);
 boxShape->calculateLocalInertia(mass, boxMotionState);
 btRigidBody::btRigidBodyConstructionInfo boxBodyCi(mass, boxMotionState, boxShape, boxInertial);
 _sensor_box = new btRigidBody(boxBodyCi);
 _world->addRigidBody(_sensor_box);
 //creation de la contraint3 
 /*TODO calculer correctement les 4 vecteurs
 btVector3 pivotInA(CUBE_HALF_EXTENTS,CUBE_HALF_EXTENTS,0);
 btVector3 pivotInB(CUBE_HALF_EXTENTS,CUBE_HALF_EXTENTS,0);
 btVector3 pivotInA2(-CUBE_HALF_EXTENTS,CUBE_HALF_EXTENTS,0);
 btVector3 pivotInB2(-CUBE_HALF_EXTENTS,CUBE_HALF_EXTENTS,0);
 btTypedConstraint* p2p = new btPoint2PointConstraint(*body0,*body1, pivotInB,pivotInA);
 btTypedConstraint* p3p = new btPoint2PointConstraint(*body0,*body1, pivotInB2,pivotInA2);
 */
 
 // add constraint to world
 m_dynamicsWorld->addConstraint(constraintG);
 m_dynamicsWorld->addConstraint(constraintD);

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
 rayCallback.m_flags |= btTriangleRaycastCallback::kF_FilterBackfaces;
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
