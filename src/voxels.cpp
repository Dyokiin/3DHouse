#include <iostream>
#include "../includes/voxels.hpp"

#define OFF 0.5

point makePoint(float x, float y , float z){
    point* p = (point*)malloc(3*(sizeof(float)));
    p->x = x;
    p->y = y;
    p->z = z;
    return *p;
}

triangle makeTriangle(point p1, point p2, point p3){
    triangle* t = (triangle*)malloc(3*(sizeof(point)));
    t->c1.x = p1.x;
    t->c1.y = p1.y;
    t->c1.z = p1.z;
    t->c2.x = p2.x;
    t->c2.y = p2.y;
    t->c2.z = p2.z;
    t->c3.x = p3.x;
    t->c3.y = p3.y;
    t->c3.z = p3.z;
    return* t;
}

Vox::Vox(float r, float g, float b, float alpha, float x, float y, float z){
    this->color = makePoint(r, g, b);
    this->alpha = alpha;
    
    this->f11 = makeTriangle(makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x+OFF,y-OFF,z+OFF));
    this->f12 = makeTriangle(makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z+OFF));

    this->f21 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x-OFF,y+OFF,z+OFF),
                             makePoint(x-OFF,y-OFF,z+OFF));
    this->f22 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x-OFF,y-OFF,z+OFF));
}

Vox::~Vox(){}

void Vox::Display(){

}