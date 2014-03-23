#include "table.h"


Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{
    qDebug() << "Table constructor";

    /*Create the scene, fill it with a background */
    setScene(new QGraphicsScene(this));

    /* TODO : faire en sorte que le background soit remplie
     * lors du load de la table.
     * scene()->setBackgroundBrush(QBrush(QColor(Qt::green)));
    */


    /*
     * Create a QBrush, passing it in argument of the ItemRobot
     * for filling the robot-item background
    */

    /*
     * Without the time line the application
     * doesn't work. Why ? (Hugo)
      */
    timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);
    timer->setLoopCount(0);

}

const QGraphicsScene & Table::getScene()const{
    return *scene();
}
