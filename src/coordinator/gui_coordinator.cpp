#include "gui_coordinator.hpp"
#include <QtCore/QDebug>

#include "../physical_calculator/physical_calculator.hpp"
#include "../physical_calculator/printable_mobile_object.hpp"

GuiCoordinator::GuiCoordinator(void){
    _mainWindow=new MainWindow();
}

MainWindow* GuiCoordinator::getMainWindow(void)const{
    return _mainWindow;
}

GuiCoordinator::~GuiCoordinator(void){
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
