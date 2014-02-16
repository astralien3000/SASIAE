#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"



class MainWindow:  public QMainWindow,public Ui_MainWindow {

Q_OBJECT

public:
  /* 
     Est-ce que cela ne pose pas un problème au lancement du programme,
     puisque c'est gui qui contiendra le main, or il faut que le coordinator
     soir lancé pour construire _gui ..?
   */
    MainWindow(QObject* parent = 0);

public slots:
    void do_sth();
    void CReceived(QString message);

};


QT_END_NAMESPACE

#endif // MAINWINDOW_H
