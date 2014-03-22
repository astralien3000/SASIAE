/*
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtWidgets/QApplication>
*/
#include <iostream>
#include <QDebug>

#include "../coordinator/coordinator.hpp"


int main(int argc, char* argv[])
{
    std::cout << "Creation de l'application..." << std::endl;
    Coordinator * cdn=& Coordinator::getInstance(argc, argv);

   // std::cout << "Chargement des robots et de la table..." << std::endl;

  /* Initialize the UpdateTimer which
   * calls the update methods in Coordinators
   * during each idle time in the gui application
   */
  QTimer *timerUpdate = new QTimer(cdn);
  qDebug() << "main : connect and start Updatetimer";
  cdn->startUpdateTimer(timerUpdate);

  std::cout << "Boucle principale..." << std::endl;
  cdn->exec();

  return 0;

}


