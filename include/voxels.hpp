#ifndef VOXELS_HPP
#define VOXELS_HPP

typedef struct Point {
    float x;
    float y;
    float z;
} point;

point makePoint(float x, float y, float z);
point multPoint(point p1, point p2);

typedef struct Triangle {
    point c1;
    point c2;
    point c3;
} triangle;

triangle makeTriangle(point c1, point c2, point c3);

class Vox {
public:
    point color; 
    //face 1
    triangle f11;
    triangle f12;
    //face 2
    triangle f21;
    triangle f22;
    //face 3
    triangle f31;
    triangle f32;
    //face 4
    triangle f41;
    triangle f42;
    //face 5
    triangle f51;
    triangle f52;
    //face 6
    triangle f61;
    triangle f62;
public:
    Vox(float r, float g, float b, float x, float y, float z);
    ~Vox(); 
    void Display(float x, float y, float z);
    void setColor(float r, float g, float b);
};


#endif