#include "position_data.hpp"

PositionData::PositionData():
    _QPosition(3),_QRotation(),_btPosition(),_btRotation()
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
    btVector3 vec=quat.getAxis();
    float ang=quat.getAngle();
    float x=vec.getX(),y=vec.getY(),z=vec.getZ();
    _QRotation=QQuaternion(ang,x,y,z);
}

const QVector<float> & PositionData::getQtPosition(void)const{
    return _QPosition;
}
const QQuaternion &PositionData::getQtRotation(void)const{
    return _QRotation;
}

