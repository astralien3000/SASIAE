#include "position_data.hpp"

/* TODO debug
operator QVector3D(const PositionData& pos)
{
  retrun QVector3D(pos.x, pos.y,pos.z);
}
//operator QQuaternion(const PositionData& pos);
operator PositionData(const QVector3D& vec)
{
  return PositionData(vec.x(),vec.y(),vec.z(),0,0,0);
}
//operator PositionData(const QQuaternion qua);
PositionData operator+(const PoistionData& pos1, const PositionData& pos2)
{
  return PositionData(pos1.x + pos2.x,
                      pos1.y + pos2.y,
                      pos1.z + pos2.z,
                      (pos1.alpha + pos2.alpha +360) %360,
                      (pos1.beta + pos2.beta +360) %360,
                      (pos1.gamma + pos2.gamma +360) %360);
}

PositionData operator-(const PoistionData& pos1, const PositionData& pos2)
{
  return PositionData(pos1.x - pos2.x,
                      pos1.y - pos2.y,
                      pos1.z - pos2.z,
                      (pos1.alpha - pos2.alpha +720) %360,
                      (pos1.beta - pos2.beta +720) %360,
                      (pos1.gamma - pos2.gamma +720) %360);
}

PositionData& operator+=(PoistionData& pos1, const PositionData& pos2)
{
  pos1.x += pos2.x;
  pos1.y += pos2.y;
  pos1.z += pos2.z;
  pos1.alpha = (pos1.alpha + pos2.alpha +720) %360;
  pos1.beta = (pos1.beta + pos2.beta +720) %360;
  pos1.gamma = (pos1.gamma + pos2.gamma +720) %360;
  return pos1;
}

PositionData& operator-=(PoistionData& pos1, const PositionData& pos2)
{
  pos1.x -= pos2.x;
  pos1.y -= pos2.y;
  pos1.z -= pos2.z;
  pos1.alpha = (pos1.alpha - pos2.alpha +720) %360;
  pos1.beta = (pos1.beta - pos2.beta +720) %360;
  pos1.gamma = (pos1.gamma - pos2.gamma +720) %360;
  return pos1;
}

*/
