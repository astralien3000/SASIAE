#include "table.h"

#include <QPainter>

#define SIZE 20
Table::Table(QWidget*parent) :
    QGraphicsView(parent)
{

    QRectF robot(QPointF(0,5),QSizeF(SIZE,SIZE));
    setScene(new QGraphicsScene(this));
    scene()->setBackgroundBrush(QBrush(QColor(Qt::green)));
    scene()->addRect(robot);

}

