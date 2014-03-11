#include "item_robot.h"

ItemRobot::ItemRobot(QBrush &robotBackground, QGraphicsRectItem *item):QGraphicsRectItem(),x(0),y(0){
        this->setRect(0,0,75,75);
        this->setBrush(robotBackground);

}



/*void ItemRobot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
        QPixmap img(":/Images/monimage.png");
    painter->drawPixmap(0,0,cote,cote,img);
}
*/
