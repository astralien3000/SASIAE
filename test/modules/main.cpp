#include "../PhysicsCalculator/physics_calculator.hpp"
#include "wheel.hpp"
#include <btBulletDynamicsCommon.h>

int main () {
    std::cout << "Hello World!" << std::endl;
    PhysicsCalculator * ph_cal=new PhysicsCalculator();
    ph_cal->simple_scene();
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();
    Wheel * mywheel=new Wheel();
    ph_cal->simple_scene();
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();

    a_sphere_goes_down(myscene,create_sphere(myscene));
    ph_cal->cleanWorld();
  return 0;
}
