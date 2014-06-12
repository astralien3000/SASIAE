#include "position_data.hpp"
#include <cmath>

PositionData::operator QVector3D()const
{
  return QVector3D(this->x, this->y,this->z);
}
//operator QQuaternion(const PositionData& pos);
PositionData::PositionData()
{
  for(int i = 0; i < 6; i++)
    val[i] = 0;
}
PositionData::PositionData(const QVector3D& vec)
{
  x= vec.x();
  y=vec.y();
  z=vec.z();
  alpha =0;
  beta =0;
  gamma = 0;
}
PositionData::PositionData(float xx, float yy, float zz, float aalpha, float bbeta, float ggamma)
{
  x=xx;
  y=yy;
  z=zz;
  alpha =aalpha;
  beta =bbeta;
  gamma = ggamma;
}
//operator PositionData(const QQuaternion qua);
PositionData PositionData::operator+(const PositionData& pos)
{
  return PositionData(pos.x + x,
                      pos.y + y,
                      pos.z + z,
                      fmod((pos.alpha + alpha +360),360.f),
                      fmod((pos.beta + beta +360),360.f),
                      fmod((pos.gamma + gamma +360),360.f));
}

PositionData PositionData::operator-(const PositionData& pos)
{
  return PositionData(x - pos.x,
                      y - pos.y,
                      z - pos.z,
                      fmod((alpha - pos.alpha +720),360.f),
                      fmod((beta - pos.beta +720),360.f),
                      fmod((gamma - pos.gamma +720),360.f));
}

PositionData& PositionData::operator+=(const PositionData& pos)
{
  x += pos.x;
  y += pos.y;
  z += pos.z;
  alpha = fmod((alpha + pos.alpha +720),360.f);
  beta = fmod((beta + pos.beta +720),360.f);
  gamma = fmod((gamma + pos.gamma +720),360.f);
  return *this;
}

PositionData& PositionData::operator-=(const PositionData& pos)
{
  x -= pos.x;
  y -= pos.y;
  z -= pos.z;
  alpha = fmod((alpha - pos.alpha +720),360.f);
  beta = fmod((beta - pos.beta +720),360.f);
  gamma = fmod((gamma - pos.gamma +720),360.f);
  return *this;
}
