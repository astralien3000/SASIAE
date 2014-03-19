#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include <QtCore/QVector>
#include <QQuaternion>
#include <QTimer>

#include "../physical_calculator/printable_mobile_object.hpp"
#include "../physical_calculator/position_data.hpp"
#include "../gui/mainwindow.h"
#include "base_coordinator.hpp"

class GuiCoordinator: public BaseCoordinator {
  Q_OBJECT;

signals:

public slots:
  //QVector<const PositionData*>* getAllPositions()const;
  void update(void);

public:
  //! \brief Default Constructor
  GuiCoordinator(void);

  //! \brief Return the Gui mainWindow
  MainWindow* getMainWindow(void)const;
  //! \brief Destructor
  ~GuiCoordinator(void);

private:
  //PrintableMobileObject *pmo;
    MainWindow * _mainWindow;
};

#endif
