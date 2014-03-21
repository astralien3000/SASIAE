#include "table.h"


Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{
    qDebug() << "Table constructor";

    /*Create the scene, fill it with a background */
    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QBrush(QColor(Qt::green)));

    /*
     * Create a QBrush, passing it in argument of the ItemRobot
     * for filling the robot-item background
    */
    QPixmap robotImg("petitrobot.png");
    QBrush robotBackground(robotImg);
    robot=new ItemRobot(robotBackground);

    /*
     * Add the robot-item to the scene built
     * in the central widget graphicsView ( Table )
     */
    scene()->addItem(robot);

 /*
 * This timer is no longer implemented.
 * Instead, the method moveRobot() is called
 * whenever the method GuiCoordinator::update()
 * is called.
*/
    //QTimer *timer2 = new QTimer(this);
    //connect(timer2, SIGNAL(timeout()), this, SLOT(moveRobot()));
    //timer2->start(1000/60);


    /*
     * Without the time line the application
     * doesn't work. Why ? (Hugo)
      */
    timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);
    timer->setLoopCount(0);

}

QGraphicsScene & Table::getScene()const{
    return scene;
}

void Table::moveRobot(qreal x, qreal y) {
    robot->setPos(x,y);
}
