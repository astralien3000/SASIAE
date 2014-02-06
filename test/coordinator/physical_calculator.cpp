#include "physical_calculator.hpp"
double PhysicalCalculator::getTime(){return time;}
void PhysicalCalculator::empty_scene(){ sceneType = EMPTY_WORLD;}
  //! \brief it creates an empty scene
  void PhysicalCalculator::simple_scene(btScalar size){sceneType = SIMPLE_WORLD;}
  //! \brief it returns a DiscreteDynamicsWorld
  //! which is the scene
  btDiscreteDynamicsWorld* PhysicalCalculator::getScene(){return NULL;}

  //! it creates a scene with a ground, and 4 walls.
  void PhysicalCalculator::simple_scene_walls(btScalar size){sceneType = WALL_WORLD;}
  //! \brief it adds a box in the world
  void PhysicalCalculator::addBox( btVector3 size, btVector3 position, btScalar mass){}
  //! it calculates the next step
  void PhysicalCalculator::nextStep(double f, int i){ nextstep_called_times++;
  nextstep_valuei = i;nextstep_valuef = f;time +=f;}
  //! \brief Constructor
  /*!
   * It initialises a physic calculator, with
   * the broadphase, the collision configuration, the dispatcher,
   * the solver and the scene ( world ).
   */
   PhysicalCalculator::PhysicalCalculator(QObject* parent):QObject(parent){
    nextstep_valuei = 0;
   nextstep_valuef = 0.;
   nextstep_called_times =0;
   sceneType= NONE;
    time = 0.;
 
     }
  PhysicalCalculator::~PhysicalCalculator(){
    }
  
