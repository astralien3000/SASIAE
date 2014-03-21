#ifndef POSITION_DATA_HPP
#define POSITION_DATA_HPP

#include <QString>
#include <QVector3D>
//#include <QQuaternion>
//used as a list in the gui coordinateur to be printed on Qt

union PositionData
{
  struct{
	  float x;
	  float y;
		float z;
		float alpha;
		float beta;
		float gamma;
	};
	float val[6];
  inline float& operator[](int index) {
    return val[index];
  }

  inline const float& operator[](int index) const {
    return val[index];
  }
  PositionData(float[6] value);
  PositionData(float x, float y, float z, float alpha, float beta, float gamma);
};

  operator QVector3D(const PositionData& pos);
  //operator QQuaternion(const PositionData& pos);
  operator PositionData(const QVector3D& vec);
  //operator PositionData(const QQuaternion qua);
  PositionData operator+(const PoistionData& pos1, const PositionData& pos2);
  PositionData operator-(const PoistionData& pos1, const PositionData& pos2);
  PositionData& operator+=(PoistionData& pos1, const PositionData& pos2);
  PositionData& operator-=(PoistionData& pos1, const PositionData& pos2);

#endif // POSITION_DATA_HPP
