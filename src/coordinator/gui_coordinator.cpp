#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"
#include "../modules/module.hpp"
#include "coordinator.hpp"


GuiCoordinator::GuiCoordinator(void){
  qDebug() << "GuiCoordinator constructor";
  _mainWindow=new MainWindow();

    // MainWindow -> GuiCoordinator : load the Table

    /*connect(
           _mainWindow,
           SIGNAL(robotFileXml(const QString&,const QString&)),
            this,
            SLOT(forwardRobotNameXml(const QString&,const QString&))
           );
*/
    connect(_mainWindow,
           SIGNAL(uiPlay()),
           this,
           SLOT(slotPlay()));

    connect(_mainWindow,
           SIGNAL(uiPause()),
           this,
           SLOT(slotPause()));
    connect(_mainWindow,
           SIGNAL(uiStop()),
           this,
           SLOT(slotStop()));
    connect(_mainWindow,
           SIGNAL(close()),
           this,
           SLOT(slotClose()));

  }

void GuiCoordinator::slotPlay() {
  emit uiPlay();
}
void GuiCoordinator::slotPause() {
  emit uiPause();
}
void GuiCoordinator::slotStop() {
  emit uiStop();
}
void GuiCoordinator::slotClose() {
  emit close();
}
void GuiCoordinator::addRobotToList(QStandardItem* item ) {
  _mainWindow->addRobot(item);
}
MainWindow* GuiCoordinator::getMainWindow(void)const{
  return _mainWindow;
}

GuiCoordinator::~GuiCoordinator(void){
}

void GuiCoordinator::updateTable(QGraphicsPixmapItem * it){
    _mainWindow->getScene()->addItem(it);
}


void GuiCoordinator::update(){

           const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
           if(!objectsList.isEmpty()){
            //qDebug() << "GC update  objectList" << objectsList ;
            foreach (const PrintableMobileObject* it, objectsList) {
              it->update();
        //qDebug() << "GuiCoordinator update pos.x=" << curPosition.at(0) << "pos.y =" << curPosition.at(2) ;
            }
          }
          else{
           qDebug() << "GuiCoordinator objectList is empty";
           }
          emit nextStep();
       }

