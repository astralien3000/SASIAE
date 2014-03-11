#include "table.h"



#define SIZE 30
Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{

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



    timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(robot);
    animation->setTimeLine(timer);
    for (int i = 0; i < 200; ++i)
        animation->setPosAt(i / 200.0, QPointF(i, i));

  //robot->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    //anim= new QPropertyAnimation(robot,"pos");
    //duration=5000;


}


/*Une possibilité serait de faire un QGraphicsScene::update() à chaque fois qu'on reçoit une nouvelle
position des robots depuis gui_coordinator. Ces update serait donc très fréquents.*/


/*
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
*/
