#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include "base_coordinator.hpp"
#include <QtCore/QVector>

#include "../physical_calculator/printable_mobile_object.hpp"

//class PrintableMobileObject ;

class GuiCoordinator : public BaseCoordinator {
  Q_OBJECT;

signals:

public slots:
  /*QVector<int> */
   void getAllPositions()const;

public:


public:
  //! \brief Default Constructor
  GuiCoordinator(void);

  //! \brief Destructor
  ~GuiCoordinator(void);

private:
  PrintableMobileObject *pmo;

};

#endif
