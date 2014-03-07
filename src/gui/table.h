#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QtGui>


class Rect : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

    Rect(QGraphicsItem* item=0):QObject(), QGraphicsRectItem(){};
};

class Table : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = 0);
    //QGraphicsRectItem * robotItem;
    void startAnimation();
signals:

public slots:

private:
    //QRectF robot;
    Rect * robot;
    QPropertyAnimation * anim;
    int duration;
};

#endif // TABLE_H
