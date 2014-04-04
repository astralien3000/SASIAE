#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include <QtCore/QVector>
#include <QTimer>

#include "../physical_calculator/printable_mobile_object.hpp"
#include "../common/position_data.hpp"
#include "../gui/mainwindow.h"
#include "base_coordinator.hpp"
class Module;

class GuiCoordinator: public BaseCoordinator {
  Q_OBJECT;

signals:

    void uiPlay();
    void uiPause();
    void uiStop();
    void nextStep();
    void close();
  
public slots:
  void update(void);
  //void updateTable(void);
  void updateTable(QGraphicsPixmapItem*);
  void slotPause();
  void slotPlay();
  void slotStop();
  void slotClose();
  void addRobotToList(QStandardItem* item);

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
