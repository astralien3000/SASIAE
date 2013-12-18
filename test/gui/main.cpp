#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtGui/QApplication>
#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Creation de l'application..." << std::endl;
  QApplication app(argc, argv);
  std::cout << "Creation de la fenetre principale..." << std::endl;
  MainWindow mainwindow;
  mainwindow.show();
  std::cout << "Boucle principale..." << std::endl;
  app.exec();
  std::cout << "Fin de l'application..." << std::endl;
  return 0;

}
