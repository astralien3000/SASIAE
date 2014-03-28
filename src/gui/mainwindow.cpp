#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QTime>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget* parent):
QMainWindow(parent), ui(new Ui::MainWindow)
{
  qDebug() << "MainWindow constructor";
  _model = new QStandardItemModel(0,2,this);
  ui->setupUi(this);
  ui->graphicsView->setScene(new QGraphicsScene());

  ui->treeView->setModel(_model);
  connect(ui->actionChoisir,SIGNAL(triggered()),this,SLOT(openDirForTable()));
  connect(ui->button_table,SIGNAL(clicked()),ui->actionChoisir,SIGNAL(triggered()));
  //todo add intermediate button to redirect the Number of sender / user signal mapping with sender();

  // connect(ui->actionRobot_new_1,SIGNAL(triggered()),this,SLOT(openDirForRobot()));
  connect(ui->actionRobot_new_1,SIGNAL(triggered()),this,SLOT(robotButtonClicked()));
  connect(ui->button_robot1,SIGNAL(clicked()),ui->actionRobot_new_1,SIGNAL(triggered()));

  connect(ui->actionRobot_new_2,SIGNAL(triggered()),this,SLOT(robotButtonClicked()));
  connect(ui->button_robot2,SIGNAL(clicked()),ui->actionRobot_new_2,SIGNAL(triggered()));

  connect(ui->actionRobot_new_3,SIGNAL(triggered()),this,SLOT(robotButtonClicked()));
  connect(ui->button_robot3,SIGNAL(clicked()),ui->actionRobot_new_3,SIGNAL(triggered()));

  connect(ui->actionRobot_new_4,SIGNAL(triggered()),this,SLOT(robotButtonClicked()));
  connect(ui->button_robot4,SIGNAL(clicked()),ui->actionRobot_new_4,SIGNAL(triggered()));


  connect(ui->button_play,SIGNAL(clicked()),this,SLOT(slotPlay()));
  connect(ui->button_pause,SIGNAL(clicked()),this,SLOT(slotPause()));


  //Ui_MainWindow::setupUi(this);
//        QObject::connect(button_robot1, SIGNAL(clicked()), qApp, SLOT(quit()));

  //QObject::connect(button_robot1, SIGNAL(clicked()), this, SLOT(do_sth()));
}

MainWindow::~MainWindow()
{
  emit uiPause();
  delete ui;
}

void MainWindow::robotButtonClicked()
{
  QAction *button = (QAction *)sender();
  emit openDirForRobot(button->text()[6].digitValue());
}

void MainWindow::addRobot(QStandardItem* item) {
  _model->appendRow(item);
}
/*
 * Ancient version
void MainWindow::animateRobot(qreal x,qreal y){
    qDebug() << "MainWindow::animateRobot";
    ui->graphicsView->moveRobot(x,y);
    ui->graphicsView->moveRobot();
}
*/
/*
QTimeLine *MainWindow::getTimer()const{
 return   ui->graphicsView->timer;
}
*/
void MainWindow::do_sth()
{
  std::cout<<"signal envoyé"<< std::endl;

    /*plainTextEdit->setPlainText(QApplication::translate("MainWindow", "lol", 0, QApplication::UnicodeUTF8)); */
}

void MainWindow::slotPlay() {
  emit uiPlay();
}
void MainWindow::slotPause() {
  emit uiPause();
}

void MainWindow::wantClose() {
  emit uiPause();
  emit close();
}

void MainWindow::setTimestamp(int t) {
  QTime time(0,0,0,0);
  time = time.addSecs(t/1000);
  qDebug() << "le temps est de "<< t;
  ui->time->setTime(time);
}
/*
   Function for integration's tests
 */
   void MainWindow::CReceived(QString message){
    qDebug() << "Message received from Coordinator to GUI : " << message ;
  }

  void MainWindow::openDirForTable(){
    const QString fileName = QFileDialog::getOpenFileName(this,
      "Open Xml file", "./", "Config Files (*.xml)");
    if(fileName!=NULL){
      emit tableFileXml(fileName);
      qDebug() << "MainWindow emit tableFileStl(" <<fileName << ") to PhyCoord loadTable";
    }
    else
      qDebug() << "MainWindow file NULL";
  }


  void MainWindow::openDirForRobot(int robotNumber){
    // int robotNumber = 1; //to get from user input
    const QString fileName = QFileDialog::getOpenFileName(this,
      "Open Xml file", "./", "Config Files (*.xml)");

    if(fileName!=NULL){
          qDebug() << robotNumber; //works just fine.

          QString name = ("robot" + QString::number(robotNumber)); // todo : ask user and signal mapping
          qDebug() << "robotNumber : (" << name << ") ";
          emit robotFileXml(name,fileName);
          qDebug() << "MainWindow emit robotFileXml(" <<fileName << ") to config_robot_coordinator loadRobotConfig";
        }
        else
          qDebug() << "MainWindow file NULL";
  }

  void MainWindow::newLog(QString msg){
        ui->plainTextEdit->appendPlainText(msg+"\n");
  }
      const QGraphicsScene* MainWindow::getScene(void)const{
        return ui->graphicsView->scene();
      }
      QGraphicsScene* MainWindow::getScene(void)
      {
        return ui->graphicsView->scene();
      }
