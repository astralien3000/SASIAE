#ifndef PHYSICAL_OBJECT_HPP
#define PHYSICAL_OBJECT_HPP

#include <string>

class PhysicalObject {
public:
    PhysicalObject(std::string name);
    virtual ~PhysicalObject(void);

    std::string getName(void);

private:
    struct PrivateData;
    PrivateData* _data;
};

#endif//PHYSICAL_OBJECT_HPP
