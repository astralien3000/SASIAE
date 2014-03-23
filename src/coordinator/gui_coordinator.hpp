#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include <QtCore/QVector>
#include <QTimer>

#include "../physical_calculator/printable_mobile_object.hpp"
#include "../common/position_data.hpp"
#include "../gui/mainwindow.h"
#include "base_coordinator.hpp"

class GuiCoordinator: public BaseCoordinator {
  Q_OBJECT;

signals:

    void forwardRobotFileStl(const QString&, const QString&);
    void uiPlay();
    void uiPause();
    void nextStep();
    void close();

public slots:
  void update(void);
  //void updateTable(void);
  void updateTable(QGraphicsPixmapItem*);
  void forwardRobotNameStl(const QString&, const QString& = QString());
  void slotPause();
  void slotPlay();
  void slotClose();
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
