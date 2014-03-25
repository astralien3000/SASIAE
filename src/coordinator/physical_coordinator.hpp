#ifndef PHYSICAL_COORDINATOR_HPP
#define PHYSICAL_COORDINATOR_HPP

#include "base_coordinator.hpp"
#include "../xml_parser/xml_parser.hpp"
#include "../stl/STLReader.hpp"
#include <QGraphicsPixmapItem>

//! \brief PhysicalCalculator declaration (avoid include)
class PhysicalCalculator;

//! \brief represents a shape compatible with the physical calculator
class Mesh;

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

  //! \brief Send the table-s item
  void tableItem(QGraphicsPixmapItem*);

  //! \brief Send the table's image
  void tableImg(QPixmap);

public slots:
    //! \brief Load a Table from XML file
  virtual void loadTable(const QString&);

  //! \brief Launch physical calculator's computation
  void update(void);

public:
  //! \brief Default Constructor
  PhysicalCoordinator(void);
  
  //! \brief Constructor with external PhysicalCalculator
  PhysicalCoordinator(PhysicalCalculator*);

  //! \brief Destructor
  ~PhysicalCoordinator();

  //! \brief Return the physical calculator
  PhysicalCalculator* getPhysicalCalculator(void);

private:
  //! \brief Private data, to avoid includes
  struct PrivateData;
  PrivateData* _data;
};

#endif//PHYSICAL_COORDINATOR_HPP
