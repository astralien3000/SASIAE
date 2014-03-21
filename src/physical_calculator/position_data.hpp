#ifndef POSITION_DATA_BULLET_HPP
#define POSITION_DATA_BULLET_HPP

#include <btBulletDynamicsCommon.h>
#include <../common/position_data.hpp>

PositionData operator(const btVector3& vec, const btQuaternion& quad);
operator btVector3(const PositionData& pos);
operator btQuaternion(const PositionData& pos);
operator PositionData(const btVector3& pos);
operator PositionData(const btQuaternion& quad);

#endif // POSITION_DATA_BULLET_HPP
