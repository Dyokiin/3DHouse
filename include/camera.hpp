#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>


#include <iostream>
#include <list>

#include "voxels.hpp"

extern float profondeur;
extern float latitude;
extern float longitude;
extern float offx;
extern float offz;
extern float offy;
extern float cx;
extern float cy;
extern float cz;

class KeyPoints {
protected:
    std::list<point> kp;
public:
    KeyPoints();
    void step(float cx, float cy, float cz);
};

#endif