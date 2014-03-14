#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include "coordinator.hpp"
#include <QtCore/QVector>
#include <QQuaternion>

#include "../physical_calculator/printable_mobile_object.hpp"

//class PrintableMobileObject ;

struct QtPositionData{
    QVector<float> _pos;
    QQuaternion _rot;
};

class GuiCoordinator : public Coordinator {
  Q_OBJECT;

signals:

public slots:
  /*QVector<int> */
   struct QtPositionData * getAllPositions()const;


public:
  //! \brief Default Constructor
  GuiCoordinator(void);

  //! \brief Destructor
  ~GuiCoordinator(void);

private:
  //PrintableMobileObject *pmo;
    QtPositionData * _test;

};

#endif
