#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"


class MainWindow: public Ui_MainWindow, public QMainWindow {
 public:
  MainWindow(){
    Ui_MainWindow::setupUi(this);
  }
};


QT_END_NAMESPACE

#endif // MAINWINDOW_H
