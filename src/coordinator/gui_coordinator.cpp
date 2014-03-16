#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"

#include "coordinator.hpp"

GuiCoordinator::GuiCoordinator(void){
    qDebug() << "GuiCoordinator constructor";

    _mainWindow=new MainWindow();

/*
    QTimer *timer2 = new QTimer(this);
    qDebug() << "connect timer2 to moveRobot";
    connect(timer2, SIGNAL(timeout()), & Coordinator::getInstance(), SLOT(Coordinator::update()));
    qDebug() << "timer2 connected to moveRobot";
    timer2->start(1000/60);
*/

}

MainWindow* GuiCoordinator::getMainWindow(void)const{
    return _mainWindow;
}

GuiCoordinator::~GuiCoordinator(void){
}

void GuiCoordinator::update(){
 const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
 if(!objectsList.isEmpty()){
    qDebug() << "GC update  objectList" << objectsList ;
    const PositionData * posRot=objectsList.first()->getPosition();
    QVector<float> pos=posRot->getQtPosition();
    qDebug() << "GuiCoordinator update pos.x=" << pos.at(0) << "pos.y =" << pos.at(1) ;
    _mainWindow->animateRobot(pos.at(0),pos.at(2));
    }
 else{
     _mainWindow->animateRobot(0,0);
     qDebug() << "GuiCoordinator objectList is empty";
    }

}
QVector<const PositionData*>* GuiCoordinator::getAllPositions() const {
	const QVector<const PrintableMobileObject*>& objectsList = PrintableMobileObject::getObjectsList();
    QVector<const PositionData*> *result = new QVector<const PositionData*>;
    for (auto it = objectsList.cbegin(); it < objectsList.cend(); ++it)
	{
        result->append((*it)->getPosition());
	}
    return result;
    //TO COPY THAT INTO THE GUI TO SHOW POSITIONS ON THE LIST !!
}

