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

public:
  //! \brief it creates an empty scene
  void empty_scene();
  //! \brief it creates an empty scene
  void simple_scene(btScalar size);
  //! \brief it returns a DiscreteDynamicsWorld
  //! which is the scene
  btDiscreteDynamicsWorld* getScene();

  //! it creates a scene with a ground, and 4 walls.
  void simple_scene_walls(btScalar size);
  //! \brief it adds a box in the world
  btRigidBody* addBox( btVector3 size, btVector3 position, btScalar mass);
  //! it calculates the next step
  void nextStep(float time=1/80.f, int addedoperations=20);

  unsigned long int getTime() const;

  //! \brief Constructor
  /*!
   * It initialises a physic calculator, with
   * the broadphase, the collision configuration, the dispatcher,
   * the solver and the scene ( world ).
   */
   PhysicalCalculator(QObject* parent = 0);
  ~PhysicalCalculator();

private:
  //! \brief The init method set the gravity
  void init();
  btDiscreteDynamicsWorld* _scene;
  btBroadphaseInterface* _broadphase;
  btDefaultCollisionConfiguration* _collisionConfiguration;
  btCollisionDispatcher* _dispatcher;
  btSequentialImpulseConstraintSolver* _solver;
  btClock * _clock;
};



#endif
