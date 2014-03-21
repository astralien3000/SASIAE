#ifndef POSITION_DATA_BULLET_HPP
#define POSITION_DATA_BULLET_HPP

#include <btBulletDynamicsCommon.h>
#include <../common/position_data.hpp>


btVector3 castPosTobtVect(const PositionData& pos);
btQuaternion castPosTobtQua(const PositionData& pos);
PositionData castbtVectToPos(const btVector3& pos);
PositionData castbtQuaToPos(const btQuaternion& quad);
#endif // POSITION_DATA_BULLET_HPP
