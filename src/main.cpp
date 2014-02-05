#include <QCoreApplication>
#include "coordinator/coordinator.hpp"

int main(int argc, char * argv[]){
  QCoreApplication app(argc,argv);
  Coordinator& BigDaddy=Coordinator::getInstance();
  QProcess* proc=new QProcess();

  BigDaddy.openRobot(proc,"client",Coordinator::MAIN_ROBOT1);

  delete proc;
  return app.exec();
}
