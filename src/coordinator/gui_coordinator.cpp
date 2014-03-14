#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"

GuiCoordinator::GuiCoordinator(void){
    _test=new QtPositionData();
    _mainWindow=new MainWindow();
}

MainWindow* GuiCoordinator::getMainWindow(void)const{
    return _mainWindow;
}

GuiCoordinator::~GuiCoordinator(void){
}

/* old version
 * QtPositionData *GuiCoordinator::getAllPositions()const{
  PositionData * objectPosition;
  objectPosition=(_robotObject.value(MAIN_ROBOT1))->getPosition();
  //objectsList=pmo->getPosition();
    _test->_pos=objectPosition->getQtPosition();
    _test->_rot=objectPosition->getQtRotation();
    return _test;
}
*/
