#include "position_data.hpp"


operator QVector3D()const
{
  return QVector3D(this->x, this->y,this->z);
}
//operator QQuaternion(const PositionData& pos);
operator PositionData(const QVector3D& vec)
{
  return PositionData(vec.x(),vec.y(),vec.z(),0,0,0);
}
//operator PositionData(const QQuaternion qua);
PositionData operator+(const PoistionData& pos)
{
  return PositionData(pos.x + x,
                      pos.y + y,
                      pos.z + z,
                      (pos.alpha + alpha +360) %360,
                      (pos.beta + beta +360) %360,
                      (pos.gamma + gamma +360) %360);
}

PositionData operator-(const PoistionData& pos)
{
  return PositionData(x - pos.x,
                      y - pos.y,
                      z - pos.z,
                      (alpha - pos.alpha +720) %360,
                      (beta - pos.beta +720) %360,
                      (gamma - pos.gamma +720) %360);
}

PositionData& operator+=(const PositionData& pos)
{
  x += pos.x;
  y += pos.y;
  z += pos.z;
  alpha = (alpha + pos.alpha +720) %360;
  beta = (beta + pos.beta +720) %360;
  gamma = (gamma + pos.gamma +720) %360;
  return *this;
}

PositionData& operator-=(const PositionData& pos)
{
  x -= pos.x;
  y -= pos.y;
  z -= pos.z;
  alpha = (alpha - pos.alpha +720) %360;
  beta = (beta - pos.beta +720) %360;
  gamma = (gamma - pos.gamma +720) %360;
  return *this;
}
