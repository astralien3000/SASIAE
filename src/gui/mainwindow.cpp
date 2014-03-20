#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
MainWindow::MainWindow(QWidget* parent):
  QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow constructor";
    ui->setupUi(this);
    connect(this,ui->actionChoisir,this,openDirForTable());
  //Ui_MainWindow::setupUi(this);
//        QObject::connect(button_robot1, SIGNAL(clicked()), qApp, SLOT(quit()));
  
  //QObject::connect(button_robot1, SIGNAL(clicked()), this, SLOT(do_sth()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animateRobot(qreal x,qreal y){
    qDebug() << "MainWindow::animateRobot";
    ui->graphicsView->moveRobot(x,y);
    //ui->graphicsView->moveRobot();
}


QTimeLine *MainWindow::getTimer()const{
 return   ui->graphicsView->timer;
}

void MainWindow::do_sth()
{
    std::cout<<"signal envoyé"<< std::endl;

    /*plainTextEdit->setPlainText(QApplication::translate("MainWindow", "lol", 0, QApplication::UnicodeUTF8)); */
}


/* 
   Function for integration's tests
 */
void MainWindow::CReceived(QString message){
  qDebug() << "Message received from Coordinator to GUI : " << message ;
}

  void openDirForTable(){
      QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Stl file"), "/home", tr("Image Files (*.stl)"));
      emit tableFileStl(fileName);
     }
