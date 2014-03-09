#include "table.h"



#define SIZE 30
Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{


    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QBrush(QColor(Qt::green)));
    robot=new Rect();
    robot->setRect(0,0,100,100);
    scene()->addItem(robot);
    //scene()->addRect(robot,QPen(),robotBackground);

    QPixmap robotImg("petitrobot.png");
    QBrush robotBackground(robotImg);
    robot->setBrush(robotBackground);
    robot->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    anim= new QPropertyAnimation(robot,"pos");
    duration=5000;


}

void Table::startAnimation(){

    anim->setDuration(duration);
    anim->setStartValue(QPointF(0,0));
    anim->setKeyValueAt(0.25,QPointF(100,300));
    anim->setKeyValueAt(0.5,QPointF(500,100));
    anim->setKeyValueAt(0.75,QPointF(90,80));
    anim->setEndValue(QPointF(0,0));
    anim->setLoopCount(-1);
    anim->start();

}
