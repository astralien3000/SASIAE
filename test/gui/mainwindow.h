#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"



class MainWindow:  public QMainWindow,public Ui_MainWindow {

Q_OBJECT

public:
    MainWindow();

public slots:
    void do_sth();

};


QT_END_NAMESPACE

#endif // MAINWINDOW_H
