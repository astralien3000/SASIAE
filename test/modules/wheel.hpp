#ifndef WHEEL_HPP
#define WHEEL_HPP

class Wheel {

public: 
  Wheel();
  double getRotation();
  double getTorque();
  void setTorque(double f);
  double _torque;
  double _rotation;
};

#endif
