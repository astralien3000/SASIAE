#ifndef BASE_COORDINATOR_HPP
#define BASE_COORDINATOR_HPP

#include <QObject>

//! \brief Defines ending signal and update slot.
/*!
  
  The aim is to create a circular chained list of coordinators.

 */
class BaseCoordinator : public QObject {
  Q_OBJECT;

signals:
  //! \brief Computation Finished
  void nextStep(void);

public slots:
  //! \brief Begin comupation
  virtual void update(void) = 0;
};

#endif//BASE_COORDINATOR_HPP
