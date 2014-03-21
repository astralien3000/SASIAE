#include "position_data.hpp"
#include <math.h>


PositionData::PositionData():
    _QPosition(),_QRotation(),_btPosition(),_btRotation()
{
}
PositionData::PositionData(const PositionData& posdata) {
  this->_QPosition = posdata._QPosition;
  this->_QRotation = posdata._QRotation;
  this->_btPosition = posdata._btPosition;
  this->_btRotation = posdata._btRotation;
}

PositionData::PositionData(float x, float y, float z,, float alpha, float beta, float gamma):
    _QPosition(x,y,z),_QRotation(alpha,beta,gamma)
{}

void PositionData::setPosition(const btVector3 & vec){
    _btPosition=vec;
    float x=vec.getX(),y=vec.getY(),z=vec.getZ();
    _QPosition.setX(x);
    _QPosition.setY(y);
    _QPosition.setZ(z);

operator PositionData(const btVector3 & vec){
    PositionData p(0,0,0,0,0,0);
    p.x=vec.getX();
    p.y=vec.getY();
    p.z=vec.getZ();

}

operator PositionData(const btQuaternion & quat){
    PositionData p(0,0,0,0,0,0);
    float xx,yy,zz;
    btMatrix3x3 m(quat);
    m.getEulerYPR(z,y,x);
    p.alpha = ((x *360 ) / M_PI + 360) % 360;
    p.beta =  ((y *360 ) / M_PI + 360) % 360;
    p.gamma = ((z *360 ) / M_PI + 360) % 360;
}

operator btVector3(const PositionData& pos) {
  return btVector3(pos.x,pos.y,pos.z);
}
operator btQuaternion(const PositionData& pos) {
  return btQuaternion(pos.alpha, pos.beta, pos.gamma);  
}
PositionData operator(const btVector3& vec, const btQuaternion& quad) {
  PositionData p;
  p += vec;
  p += quad;
  return p; 
}
