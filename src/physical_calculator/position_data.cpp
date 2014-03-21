#include "position_data.hpp"
#include <math.h>

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
