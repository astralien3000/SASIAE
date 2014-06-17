#ifndef STL_READER_HPP
#define STL_READER_HPP

#include <vector>
#include <string>
#include <stdexcept>

class MyStlReader {
public:
    typedef std::vector< std::vector<float> > TriangleList;

    static TriangleList readStlTextFile(std::string path) throw(std::runtime_error);
    static TriangleList readStlBinaryFile(std::string path) throw(std::runtime_error);
};

///////////////////////////////////////////////////////////////
// Need to keep this until binary stl is tested

//#include <QString>
//#include <QList>
//#include <QVector>

//class STLReader {
//public:
//    static QList<QVector<float> > readSTLTextFile(QString path);
//    static QList<QVector<float> > readSTLBinaryFile(QString path);

//};

#endif//STL_READER_HPP
