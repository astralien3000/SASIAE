#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>

class robot : public QObject
{
    Q_OBJECT
public:
    explicit robot(QObject *parent = 0);

signals:

public slots:

};

#endif // ROBOT_H
