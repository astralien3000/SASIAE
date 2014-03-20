#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"

#include "coordinator.hpp"

GuiCoordinator::GuiCoordinator(void){
    qDebug() << "GuiCoordinator constructor";
    _mainWindow=new MainWindow();

    // MainWindow -> GuiCoordinator : load the Table
    connect(
         _mainWindow,
         SIGNAL(tableFileStl(QString)),
         _gui_cdn,
         SLOT(forwardTbleFStl(QString))
          );

}

MainWindow* GuiCoordinator::getMainWindow(void)const{
    return _mainWindow;
}

GuiCoordinator::~GuiCoordinator(void){
}

void GuiCoordinator::update(){

/*
 * Hugo : ancient version...
        const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
        if(!objectsList.isEmpty()){
           qDebug() << "GC update  objectList" << objectsList ;
           const PositionData * posRot=objectsList.first()->getPosition();
           QVector<float> pos=posRot->getQtPosition();
           qDebug() << "GuiCoordinator update pos.x=" << pos.at(0) << "pos.y =" << pos.at(2) ;
           _mainWindow->animateRobot(pos.at(0),pos.at(2));
           }
        else{
            qDebug() << "GuiCoordinator objectList is empty";
           }
*/

 const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
     if(!objectsList.isEmpty()){
    QVector<float> curPosition;
    qDebug() << "GC update  objectList" << objectsList ;
    for (auto it = objectsList.cbegin(); it < objectsList.cend(); ++it) {
        curPosition = ((*it)->getPosition())->getQtPosition();
        qDebug() << "GuiCoordinator update pos.x=" << curPosition.at(0) << "pos.y =" << curPosition.at(2) ;
        _mainWindow->animateRobot(curPosition.at(0),curPosition.at(2));
        }
    }
 else{
     qDebug() << "GuiCoordinator objectList is empty";
     _mainWindow->animateRobot(0,0);
    }

}

void GuiCoordinator::forwardTbleFStl(QString file){
    emit forwardTbleFStl(file);
}

//QVector<const PositionData*>* GuiCoordinator::getAllPositions() const {

//    const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
//    QVector<float> & curPosition;
//    for (auto it = objectsList.cbegin(); it < objectsList.cend(); ++it)
//    {
//        curPosition = ((*it)->getPosition())->getQtPosition();
//        _mainWindow->animateRobot(curPosition->at(0),curPosition->at(2));
//        //not tested yet because of compiling problems !!
//    }
//    return result;
//    //TO COPY THAT INTO THE GUI TO SHOW POSITIONS ON THE LIST !!
//}


