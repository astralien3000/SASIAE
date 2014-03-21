#ifndef POSITION_DATA_HPP
#define POSITION_DATA_HPP

#include <btBulletDynamicsCommon.h>
#include <QString>
#include <QVector3D>
//#include <QQuaternion>
//used as a list in the gui coordinateur to be printed on Qt

class PositionData
{
public:
    PositionData();
    PositionData(const PositionData& posdata);
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

#endif // POSITION_DATA_HPP
