#include "mainwindow.h"

MainWindow::MainWindow(QObject* parent):QObject(parent)
{
    Ui_MainWindow::setupUi(this);
//        QObject::connect(button_robot1, SIGNAL(clicked()), qApp, SLOT(quit()));
            QObject::connect(button_robot1, SIGNAL(clicked()), this, SLOT(do_sth()));
}

void MainWindow::do_sth()
{
    std::cout<<"signal envoyé"<< std::endl;

    plainTextEdit->setPlainText(QApplication::translate("MainWindow", "lol", 0, QApplication::UnicodeUTF8));
}


/* 
   Function for integration's tests
 */
void MainWindow::CReceived(QString message){
  qDebug() << "Message received from Coordinator to GUI : " << message ;
}
