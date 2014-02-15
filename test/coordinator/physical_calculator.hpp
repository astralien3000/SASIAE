#ifndef PHYSICAL_CALCULATOR_HPP
#define PHYSICAL_CALCULATOR_HPP
#include <btBulletDynamicsCommon.h>
#include <QObject>
//! \brief Physic Calculator
/*!
  The goal of this object is
  to instanciate a scene with a
  Physic Engine ( here we use Bullet )
  and to permit to the Coordinator
  to create the robots it needs.
  Finally it simulates the robots' behaviour.
 */
class PhysicalCalculator : public QObject {
  Q_OBJECT

public slots:
  //! it calculates the next step
  void nextStep(double, int);
public:
  //! \brief return the current time of simulation in sec
  double getTime() const;
  //! \brief it returns a DiscreteDynamicsWorld
  //! which is the scene
  btDiscreteDynamicsWorld* getScene();
  //! \brief it creates an empty scene
  void empty_scene();
  //! \brief it creates an empty scene
  void simple_scene(btScalar size);

  //! it creates a scene with a ground, and 4 walls.
  void simple_scene_walls(btScalar size);
  //! \brief it adds a box in the world
  void addBox( btVector3 size, btVector3 position, btScalar mass);
  //! \brief Constructor
  /*!
   * It initialises a physic calculator, with
   * the broadphase, the collision configuration, the dispatcher,
   * the solver and the scene ( world ).
   */
   PhysicalCalculator(QObject* parent = 0);
  ~PhysicalCalculator();
  
   int nextstep_valuei;
   float nextstep_valuef;
   int nextstep_called_times;
   enum worldType {NONE, EMPTY_WORLD, SIMPLE_WORLD, WALL_WORLD};
   enum worldType sceneType;
   double time;

};



#endif
