#ifndef GUI_COORDINATOR_HPP
#define GUI_COORDINATOR_HPP

#include "base_coordinator.hpp"
#include <QtCore/QVector>

class GuiCoordinator : public BaseCoordinator {
  Q_OBJECT;

signals:

public slots:
  QVector getAllPostions()const;

public:


public:
  //! \brief Default Constructor
  GuiCoordinator(void);

  //! \brief Destructor
  ~GuiCoordinator();

private:
  PhysicalCalculator *pc;

};

#endif
