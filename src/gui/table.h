#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItemAnimation>
#include <QtGui>

#include "item_robot.h"
//#include "../coordinator/gui_coordinator.hpp"

class Table : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = 0);
    QTimeLine *timer;

signals:

public slots:
    void moveRobot(qreal x, qreal y);
    void moveRobot();

private:
    //QRectF robot;
    ItemRobot * robot;
    //QPropertyAnimation * anim;
    //int duration;
};

#endif // TABLE_H
