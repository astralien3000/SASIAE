#include "STLReader.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include <QString>

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

std::vector< std::vector<float> > MyStlReader::readStlTextFile(std::string path) {
    std::vector< std::vector<float> > ret;
    std::ifstream ifs(path.c_str());

    if(!ifs.good()) {
        std::cerr << "Can't open STL file : " << path << std::endl;
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

std::vector< std::vector<float> > MyStlReader::readStlBinaryFile(std::string path) {
    std::vector< std::vector<float> > ret;
    std::ifstream ifs(path.c_str());

    if(!ifs.good()) {
        // ERROR
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
//#include <QFile>
//#include <QDebug>
//#include <QStringList>

//QList<QVector<float> > STLReader::readSTLTextFile(QString path) {
//    QList<QVector<float> > triangles;
//    QFile file(path);
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        qDebug()<<"STLReader failed open file" ;
//        return triangles;
//    }
//    while(!file.atEnd()) {
//        QByteArray ba = file.readLine();
//        QStringList lineWord = QString(ba).simplified().split(" ");
//        if(lineWord.at(0) == "outer") {
//            triangles.append(QVector<float>());
//            std::cout << std::endl;
//        }
//        if(lineWord.at(0) == "vertex")
//        {
//            triangles.last().append(lineWord.at(1).toFloat());
//            triangles.last().append(lineWord.at(2).toFloat());
//            triangles.last().append(lineWord.at(3).toFloat());
//        }

//    }

//    return triangles;
//}

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
