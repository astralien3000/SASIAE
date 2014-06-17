#include "STLReader.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include <QString>

#define MACRO_OSS_STR(stream) ((std::ostringstream&)(std::ostringstream() << stream)).str()

static const int _BUFFER_SIZE = 1024;

static double _stof(std::string str) {
    std::istringstream iss(str);
    double ret = 0;
    iss >> ret;
    return ret;
}

static char _extended_at(const std::string& str, int i) {
    if(i < 0 || str.size() <= i) {
        return ' ';
    }
    return str.at(i);
}

static std::string _simplify(std::string str) {
    QString ret(str.c_str());
    return ret.simplified().toStdString();
}

MyStlReader::TriangleList MyStlReader::readStlTextFile(std::string path) throw(std::runtime_error) {
    std::vector< std::vector<float> > ret;
    std::ifstream ifs(path.c_str());

    if(!ifs.good()) {
        throw std::runtime_error(MACRO_OSS_STR("Can't open STL file : " << path));
        return ret;
    }

    char buffer_line[_BUFFER_SIZE];

    while(!ifs.eof()) {
        ifs.getline(buffer_line, _BUFFER_SIZE);
        std::vector<std::string> line_args;

        std::string simplified_line = _simplify(buffer_line);
        boost::split(line_args, simplified_line, boost::is_any_of(" "));

        if(line_args[0] == "outer") {
            ret.push_back(std::vector<float>());
        }
        if(line_args[0] == "vertex") {
            ret.back().push_back(_stof(line_args[1]));
            ret.back().push_back(_stof(line_args[2]));
            ret.back().push_back(_stof(line_args[3]));
        }
    }

    return ret;
}

MyStlReader::TriangleList MyStlReader::readStlBinaryFile(std::string path) throw(std::runtime_error) {
    std::vector< std::vector<float> > ret;
    std::ifstream ifs(path.c_str());

    if(!ifs.good()) {
        throw std::runtime_error(MACRO_OSS_STR("Can't open STL file : " << path));
        return ret;
    }

    unsigned long face_number = 0;
    ifs.seekg(80, ifs.beg);
    ifs >> face_number;

    for(unsigned long i = 0 ; i < face_number ; i++) {
        ifs.seekg(84 + i * 50, ifs.beg);

        std::vector<float> face;
        float buffer[12];
        ifs.read((char*)buffer, sizeof(buffer));

        for(int j = 0 ; j < 9 ; j++) {
            face.push_back(buffer[3 + j]);
        }

        ret.push_back(face);
    }

    return ret;
}


/////////////////////////////////////////////////////////////////////////////////
// Need to keep this until binary stl is tested

//#include <QFile>
//#include <QDebug>
//#include <QStringList>

//QList<QVector<float> > STLReader::readSTLBinaryFile(QString path) {
//    QList<QVector<float> > triangles;

//    QFile file(path);

//    if(!file.open(QIODevice::ReadOnly))
//        return triangles;

//    file.seek(0);
//    quint32 triangles_nb=0;

//    file.seek(80);
//    QByteArray size = file.read(4);
//    memcpy(&triangles_nb, size.constData(), 4);

//    qDebug() << "nombre de mesh" << triangles_nb;
//    for(quint32 i =0; triangles_nb > i; i++)
//    {
//        file.seek(84+i*50);

//        float nxyz[12];
//        QByteArray ba = file.read(50);
//        memcpy(&nxyz, ba.constData(), 48);

//        QVector<float> xyz;
//        for(int j = 0; j< 9;j++) {
//            xyz.append(nxyz[3+j]);
//            qDebug() << j << ba;
//        }

//        triangles.append(xyz);
//    }

//    return triangles;
//}
