#include <btBulletDynamicsCommon.h>


class Wheel {

public:
  Wheel(btDynamicsWorld* world, btRigidBody* robot);
  ~Wheel();
  void init();
  void init(double x, double y, double z, double r, double l);
  
  //double getAngularSpeed();
  double getAngle();
  double getTorque();
  void setTorque(double f);
  btVector3 getPos();
protected:
  btRigidBody* _wheel;
  btDynamicsWorld* _world;
  btRigidBody* _robot;
  btCollisionShape* _wheelShape;

};
