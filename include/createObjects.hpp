#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
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

#endif
