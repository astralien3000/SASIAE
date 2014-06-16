#ifndef STL_READER_HPP
#define STL_READER_HPP

#include <vector>
#include <string>

class MyStlReader {
public:
  static std::vector< std::vector<float> > readStlTextFile(std::string path);
  static std::vector< std::vector<float> > readStlBinaryFile(std::string path);
};

///////////////////////////////////////////////////////////////
#include <QString>
#include <QList>
#include <QVector>

class STLReader {
public:
  static QList<QVector<float> > readSTLTextFile(QString path);
  static QList<QVector<float> > readSTLBinaryFile(QString path);

};

#endif//STL_READER_HPP
