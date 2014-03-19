#include "position_data.hpp"

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
void PositionData::setPosition(const btVector3 & vec){
    _btPosition=vec;
    float x=vec.getX(),y=vec.getY(),z=vec.getZ();
    _QPosition.setX(x);
    _QPosition.setY(y);
    _QPosition.setZ(z);
}

void PositionData::setRotation(btQuaternion quat){
    _btRotation=quat;
    float x,y,z;
    btMatrix3x3 m(quat);
    m.getEulerYPR(z,y,x);
    _QRotation.setX(x);
    _QRotation.setY(y);
    _QRotation.setZ(z);
}

const QVector3D & PositionData::getPosition(void)const{
    return _QPosition;
}
const QVector3D & PositionData::getRotation(void)const{
    return _QRotation;
}
float PositionData::getRotation(unsigned int axe)const{
    if(axe == 0)
      return _QRotation.x();
    if(axe == 1)
      return _QRotation.y();
    if(axe == 2)
      return _QRotation.z();
    return _QRotation.y();
}

PositionData PositionData::operator+(const PositionData& pos)
{
  PositionData p(*this); 
  p._QPosition += pos._QPosition;
  p._QRotation += pos._QRotation;
  p._btPosition += pos._btPosition;
  p._btRotation += pos._btRotation;
  return p;
}
