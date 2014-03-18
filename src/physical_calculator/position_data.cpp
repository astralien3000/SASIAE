#include "position_data.hpp"

PositionData::PositionData():
    _QPosition(3),_QRotation(3),_btPosition(),_btRotation()
{
}

void PositionData::setPosition(const btVector3 & vec){
    _btPosition=vec;
    float x=vec.getX(),y=vec.getY(),z=vec.getZ();
    _QPosition.replace(0,x);
    _QPosition.replace(1,y);
    _QPosition.replace(2,z);
}

void PositionData::setRotation(btQuaternion quat){
    _btRotation=quat;
    float x,y,z;
    btMatrix3x3 m(quat);
    m.getEulerYPR(z,y,x);
    _QRotation.replace(0,x)
    _QRotation.replace(1,y)
    _QRotation.replace(2,z)
}

const QVector<float> & PositionData::getQtPosition(void)const{
    return _QPosition;
}
const QQuaternion &PositionData::getQtRotation(unsigned int axe)const{
    if(axe <0 || axe > 3)
      return _QRotation[1];
    return _QRotation[axe];
}

