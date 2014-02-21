#ifndef TABLE_H
#define TABLE_H

#include <QGraphicsView>

class Table : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = 0);

signals:

public slots:

private:
    QRectF robot;
};

#endif // TABLE_H
