
class Wheel {

public 
  Wheel(btDynamicWorld* world, btRigidBody* robot);

protected:
  void init();
  void init(double x, double y, double z, double d, double l);
  
  //double getAngularSpeed();
  double getAngle();
  double getTorque();
  void setTorque(double f);
  btRigidBody* _wheel;
}
