#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QDebug>
#include <QtGui>
#include <QFileDialog>
//#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void tableFileStl(QString);

private:
    Ui::MainWindow *ui;

public slots:
    void openDirForTable();
    void do_sth();
    void CReceived(QString message);
    //void animate();
    void animateRobot(qreal x,qreal y);
    QTimeLine *getTimer()const;
};

#endif // MAINWINDOW_H
