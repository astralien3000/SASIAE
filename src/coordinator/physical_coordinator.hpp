#ifndef PHYSICAL_COORDINATOR_HPP
#define PHYSICAL_COORDINATOR_HPP

#include "base_coordinator.hpp"

//! \brief PhysicalCalculator declaration (avoid include)
class PhysicalCalculator;

//! \brief Manage the physical coordinator
/*!

  Store, load and setup world.
  Can pause and play simulation.
  Read and load a table.

 */
class PhysicalCoordinator : public BaseCoordinator {
  Q_OBJECT;
  
signals:
  //! \brief Ask to compute one step to the PhysicalCalculator
  void calcNextStep(double, int);
  
  //! \brief Send timestamp
  void timestamp(int);

public slots:
  //! \brief start the simulation
  void play();

  //! \brief pause the simulation
  void pause();

  //! \brief Load a Table from XML file
  void loadTable(QString);

  //! \brief Launch physical calculator's computation
  void update(void);

public:
  //! \brief Default Constructor
  PhysicalCoordinator(void);
  
  //! \brief Constructor with external PhysicalCalculator
  PhysicalCoordinator(PhysicalCalculator*);

  //! \brief Destructor
  ~PhysicalCoordinator();

private:
  //! \brief Private data, to avoid includes
  struct PrivateData;
  PrivateData* _data;
};

#endif//PHYSICAL_COORDINATOR_HPP
