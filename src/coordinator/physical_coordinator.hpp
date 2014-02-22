#ifndef PHYSICAL_COORDINATOR_HPP
#define PHYSICAL_COORDINATOR_HPP

#include <QHash>
#include <QPair>
#include <QString>

//! \brief Manage the physical coordinator
/*!

  Only this class should contain library-dependent code. (Bullet)

 */
class PhysicalCoordinator {
  Q_OBJECT;
  
public slots:
  //! \brief start the simulation
  void play();

  //! \brief pause the simulation
  void pause();

  //! \brief Load a Table from XML file
  void loadTable(QString);

public:
  PhysicalCoordinator();
  ~PhysicalCoordinator();

private:
  class PrivateData;
  PrivateData* _data;
};

#endif//PHYSICAL_COORDINATOR_HPP
