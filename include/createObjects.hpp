#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "voxels.hpp"
#include <list>

class Object {
private:
    std::list<Vox> voxels;
public:
    Object(float voxlist[][3]);
    Object(std::list<Vox> voxels);
    void Display(float x, float y, float z);
};

std::list<Object*> InitScene();

#endif
