#ifndef SIMPLE_SCENE_HPP
#define SIMPLE_SCENE_HPP

#include "physical_object.hpp"

class SimpleScene : public PhysicalObject {
public:
    SimpleScene(std::string name, double size);
    virtual ~SimpleScene(void);
};

#endif//SIMPLE_SCENE_HPP
