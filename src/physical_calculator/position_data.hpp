#ifndef POSITION_DATA_BULLET_HPP
#define POSITION_DATA_BULLET_HPP

#include <btBulletDynamicsCommon.h>
#include <../common/position_data.hpp>

<<<<<<< HEAD
class PositionData
{
public:
    PositionData();
    PositionData(const PositionData& posdata);
    PositionData(float x, float y, float z, float alpha, float beta, float gamma);
    void setPosition(const btVector3 &);
    void setRotation(btQuaternion);
    const QVector3D & getPosition(void)const;
    const QVector3D & getRotation(void)const;
    float getRotation(unsigned int axe)const;
    PositionData operator+(const PositionData& pos);
private:
    QVector3D _QPosition;
    QVector3D _QRotation;
    btVector3 _btPosition;
    btQuaternion _btRotation;
};
=======
PositionData operator(const btVector3& vec, const btQuaternion& quad);
operator btVector3(const PositionData& pos);
operator btQuaternion(const PositionData& pos);
operator PositionData(const btVector3& pos);
operator PositionData(const btQuaternion& quad);
>>>>>>> a959e93f21f454fdaa3708eeb44197270f1f36bc

#endif // POSITION_DATA_BULLET_HPP
