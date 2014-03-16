#include "table.h"



#define SIZE 30
Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{
    /* initialize Coordination*/
    qDebug() << "Table constructor";

    /*Create the scene, fill it with a background */
    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QBrush(QColor(Qt::green)));

    /*Create a QBrush, passing it in argument of the ItemRobot
     *for filling the robot-item background
    */
    QPixmap robotImg("petitrobot.png");
    QBrush robotBackground(robotImg);
    robot=new ItemRobot(robotBackground);

    /*add the robot-item to the scene built
     * on the central widget graphicsView ( Table )
     */
    scene()->addItem(robot);
/*
    QTimer *timer2 = new QTimer(this);
    qDebug() << "connect timer2 to moveRobot";
    connect(timer2, SIGNAL(timeout()), this, SLOT(moveRobot()));
    qDebug() << "timer2 connected to moveRobot";
    timer2->start(1000/60);
*/
    /*
     * Without the time line the application
     * doesn't work. Why ? (Hugo)
      */
    timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);
    timer->setLoopCount(0);

    /*QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(robot);
    animation->setTimeLine(timer);
    robot->itemMove(animation,50,0);
    robot->itemMove(animation,0,50);
    robot->itemMove(animation,50,50);
    robot->itemMove(animation,-100,-100);
    /*for (int i = 0; i < 200; ++i)
        animation->setPosAt(i / 200.0, QPointF(i, i));
*/
}


void Table::moveRobot() {
    robot->moveBy(-1,-1);
}

void Table::moveRobot(qreal x, qreal y) {
    robot->setPos(x,y);
}
