#include "STLReader.hpp"
#include <QFile>
#include <QDebug>
#include <QStringList>

QList<QVector<float>> STLReader::readSTLTextFile(QString path) {
  QList<QVector<float>> triangles;
  QFile file(path);
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
    qDebug()<<"STLReader failed open file" ;
    return triangles;
    }
  while(!file.atEnd()) {
    QByteArray ba = file.readLine();
    QStringList lineWord = QString(ba).simplified().split(" ");
    if(lineWord.at(0) == "outer")
      triangles.append(QVector<float>());
    if(lineWord.at(0) == "vertex")
    {
      triangles.last().append(lineWord.at(1).toFloat());
      triangles.last().append(lineWord.at(2).toFloat());
      triangles.last().append(lineWord.at(3).toFloat());
    }

  }
    qDebug() << "STLReader return QListtriangles of size ="<< triangles.size();
  return triangles;/*
  quint32 triangles_nb;
  QByteArray size = file.read(4);
  //memcpy(&triangles_nb, size.constData(), 4);
    QVector<float> xyz;
    for(int j = 0; j< 9;j++) {
      qDebug() << j;
    }
    triangles.append(xyz);

  }
  return triangles;*/
}

QList<QVector<float>> STLReader::readSTLBinaryFile(QString path) {
  QList<QVector<float>> triangles;
  
  QFile file(path);
  if(!file.open(QIODevice::ReadOnly))
    return triangles;
  file.seek(0);
  quint32 triangles_nb=0;
  file.seek(80);
  QByteArray size = file.read(4);
  memcpy(&triangles_nb, size.constData(), 4);
  qDebug() << "nombre de mesh" << triangles_nb;
  for(quint32 i =0; triangles_nb > i; i++)
  {
    file.seek(84+i*50);
    float nxyz[12];
    QByteArray ba = file.read(50);
    memcpy(&nxyz, ba.constData(), 48);
    QVector<float> xyz;
    for(int j = 0; j< 9;j++) {
      xyz.append(nxyz[3+j]);
      qDebug() << j << ba;
    }
    triangles.append(xyz);

  }
  return triangles;
}
