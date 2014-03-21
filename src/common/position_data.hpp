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
  PositionData();
  PositionData(float value[6]);
  PositionData(float x, float y, float z, float alpha, float beta, float gamma);
  PositionData(const QVector3D& vec);
  operator QVector3D(void)const;
  //operator QQuaternion(const PositionData& pos);
  //operator PositionData(const QVector3D& vec);
  //operator PositionData(const QQuaternion qua);
  PositionData operator+(const PositionData& pos);
  PositionData operator-(const PositionData& pos);
  PositionData& operator+=(const PositionData& pos);
  PositionData& operator-=(const PositionData& pos);
};

PositionData castQVectToPos(const QVector3D& vec);

#endif // POSITION_DATA_HPP
