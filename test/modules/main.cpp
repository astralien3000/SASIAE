#include "../../src/PhysicalCalculator/physical_calculator.hpp"
#include "wheel.hpp"
#include <btBulletDynamicsCommon.h>
#include <iostream>

int main () {
    std::cout << "Hello World!" << std::endl;
    PhysicalCalculator * ph_cal=new PhysicalCalculator();
    ph_cal->empty_scene();
    btDiscreteDynamicsWorld * myscene=ph_cal->getScene();
    // Wheel * mywheel=new Wheel(myscene,NULL); commentée car cela ne fonctionnait pas


    //ph_cal->simple_scene();
    //btDiscreteDynamicsWorld * myscene=ph_cal->getScene();

    // a_sphere_goes_down(myscene,create_sphere(myscene)); commentée car cela ne fonctionnait pas


    ph_cal->cleanWorld();
  return 0;
}
