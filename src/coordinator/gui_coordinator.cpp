#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"

GuiCoordinator::GuiCoordinator(void){
}

GuiCoordinator::~GuiCoordinator(void){
}

/*QVector<int>*/ void  GuiCoordinator::getAllPositions()const{
  struct position_data * objectsList;
  objectsList=pmo->getPosition();

}
