#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItemAnimation>
#include <QtGui>

#include "item_robot.h"
#include "../coordinator/gui_coordinator.hpp"

class Table : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = 0);
    QTimeLine *timer;
    const QGraphicsScene & getScene()const;

signals:

public slots:
//    void moveRobot(qreal x, qreal y);

private:
    ItemRobot * robot;
};

#endif // TABLE_H
