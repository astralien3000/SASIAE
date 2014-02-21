#include <QCoreApplication>
#include "../../../src/coordinator/coordinator.hpp"

int main(int argc, char * argv[]){
  QCoreApplication app(argc,argv);
  Coordinator& BigDaddy=Coordinator::getInstance();

  BigDaddy.openRobot("client",Coordinator::MAIN_ROBOT1);


  return app.exec();
}
