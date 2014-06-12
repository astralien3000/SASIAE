#include <QString>
#include <QList>
#include <QVector>

class STLReader {
public:
  static QList<QVector<float> > readSTLTextFile(QString path);
  static QList<QVector<float> > readSTLBinaryFile(QString path);

};
