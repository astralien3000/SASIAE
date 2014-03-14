#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include <QtCore/QVector>
#include <QQuaternion>

#include "../physical_calculator/printable_mobile_object.hpp"
#include "../gui/mainwindow.h"

//class PrintableMobileObject ;

struct QtPositionData{
    QVector<float> _pos;
    QQuaternion _rot;
};

class GuiCoordinator: public QObject {
  Q_OBJECT;

signals:

public slots:
  /*QVector<int> */
   struct QtPositionData * getAllPositions()const;


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
    QtPositionData * _test;

};

#endif
