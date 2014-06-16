#ifndef SCENE_HPP
#define SCENE_HPP

#include "../physical_object.hpp"

#include <string>

class Scene : public PhysicalObject {
public:
    Scene(std::string name, std::string path);
    virtual ~Scene(void);

private:
    struct PrivateData;
    PrivateData* _data;
};

#endif//SCENE_HPP
