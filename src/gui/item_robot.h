#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QBrush>

class ItemRobot : public QGraphicsRectItem
{

public:
    //Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    ItemRobot(QBrush& robotBackground, QGraphicsRectItem *item=0) ;
    void move(int step);

private:
/*Coordonates*/
    int x;
    int y;
    QRectF aroundArea;
};

#endif // ROBOT_H
