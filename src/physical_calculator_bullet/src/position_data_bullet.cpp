#include "position_data_bullet.hpp"
#include <math.h>
#include <QDebug>

PositionData::PositionData(const PositionData& posdata) {
    int i=0;
    for(i=0;i<6;i++){
        val[i]=posdata[i];
    }
}

/*
PositionData::PositionData(float x, float y, float z,, float alpha, float beta, float gamma):
    _QPosition(x,y,z),_QRotation(alpha,beta,gamma)
{}

void PositionData::setPosition(const btVector3 & vec){
    _btPosition=vec;
    float x=vec.getX(),y=vec.getY(),z=vec.getZ();
    _QPosition.setX(x);
    _QPosition.setY(y);
    _QPosition.setZ(z);
}
*/

PositionData castbtVectToPos(const btVector3 & pos){
    PositionData p(0,0,0,0,0,0);
    p.x=pos.getX();
    p.y=pos.getY();
    p.z=pos.getZ();
    return p;
}

PositionData castbtQuaToPos(const btQuaternion & quat){
    PositionData p(0,0,0,0,0,0);
    float x,y,z;
    btMatrix3x3 m(quat);
    m.getEulerZYX(z,y,x);
    p.alpha = ((int)((x *180 ) / M_PI)) ;
    p.beta =  ((int)((-y *180 ) / M_PI)) ;
    p.gamma = ((int)((z *180 ) / M_PI)) ;
    if(p.alpha > 178 || p.alpha < -178 || p.gamma > 178 || p.gamma < -178 )
      p.beta = 180-p.beta;
    return p;
}

btVector3 castPosTobtVect(const PositionData& pos) {
  return btVector3(pos.x,pos.y,pos.z);
}

btQuaternion castPosTobtQua(const PositionData& pos) {
  return btQuaternion(pos.alpha, pos.beta, pos.gamma);  
}
