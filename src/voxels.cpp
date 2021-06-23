#include <iostream>
#include "../include/voxels.hpp"
#include "../include/camera.hpp"

#define OFF 0.5

point makePoint(float x, float y , float z){
    point* p = (point*)malloc(3*(sizeof(float)));
    p->x = x;
    p->y = y;
    p->z = z;
    return *p;
}

triangle makeTriangle(point p1, point p2, point p3){
    triangle* t = (triangle*)malloc(12*(sizeof(float)));
    t->c1.x = p1.x;
    t->c1.y = p1.y;
    t->c1.z = p1.z;
    t->c2.x = p2.x;
    t->c2.y = p2.y;
    t->c2.z = p2.z;
    t->c3.x = p3.x;
    t->c3.y = p3.y;
    t->c3.z = p3.z;
    //t->norm = makePoint(0,0,0);
    return* t;
}

Vox::Vox(float r, float g, float b, float x, float y, float z){
    this->color = makePoint(r, g, b);
//face 1
    this->f11 = makeTriangle(makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x+OFF,y-OFF,z+OFF));
    this->f12 = makeTriangle(makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z+OFF));
    this->f11.norm = makePoint(1.,0.,0.);
    this->f12.norm = makePoint(1.,0.,0.);
//face 2 opposée à face 1
    this->f21 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x-OFF,y+OFF,z+OFF),
                             makePoint(x-OFF,y-OFF,z+OFF));
    this->f22 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x-OFF,y-OFF,z+OFF));
    this->f21.norm = makePoint(-1.,0.,0.);
    this->f22.norm = makePoint(-1.,0.,0.);
//face 3
    this->f31 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x+OFF,y+OFF,z-OFF));
    this->f32 = makeTriangle(makePoint(x-OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x-OFF,y+OFF,z+OFF));
    this->f31.norm = makePoint(0.,1.,0.);
    this->f32.norm = makePoint(0.,1.,0.);
//face 4 opposée à f3
    this->f41 = makeTriangle(makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z+OFF),
                             makePoint(x+OFF,y-OFF,z-OFF));
    this->f42 = makeTriangle(makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z+OFF),
                             makePoint(x-OFF,y-OFF,z+OFF));
    this->f31.norm = makePoint(0.,-1.,0.);
    this->f32.norm = makePoint(0.,-1.,0.);
//face 5
    this->f51 = makeTriangle(makePoint(x-OFF,y-OFF,z+OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x+OFF,y-OFF,z+OFF));
    this->f52 = makeTriangle(makePoint(x-OFF,y-OFF,z+OFF),
                             makePoint(x+OFF,y+OFF,z+OFF),
                             makePoint(x-OFF,y+OFF,z+OFF));
    this->f31.norm = makePoint(0.,0.,1.);
    this->f32.norm = makePoint(0.,0.,1.);
//face 6 opposée à f5
    this->f61 = makeTriangle(makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x+OFF,y-OFF,z-OFF));
    this->f62 = makeTriangle(makePoint(x-OFF,y-OFF,z-OFF),
                             makePoint(x+OFF,y+OFF,z-OFF),
                             makePoint(x-OFF,y+OFF,z-OFF));
    this->f31.norm = makePoint(0.,0.,-1.);
    this->f32.norm = makePoint(0.,0.,-1.);
}

Vox::~Vox(){}

void Vox::Display(float x, float y, float z){
    glColor3f(this->color.x, this->color.y, this->color.z);

    if(this->f11.c1.x+x-(cx+offx)<=0){ //f1* norms are all x positive
        glVertex3f(this->f11.c1.x+x,this->f11.c1.y+y,this->f11.c1.z+z);
        glVertex3f(this->f11.c2.x+x,this->f11.c2.y+y,this->f11.c2.z+z);
        glVertex3f(this->f11.c3.x+x,this->f11.c3.y+y,this->f11.c3.z+z);
        glVertex3f(this->f12.c1.x+x,this->f12.c1.y+y,this->f12.c1.z+z);
        glVertex3f(this->f12.c2.x+x,this->f12.c2.y+y,this->f12.c2.z+z);
        glVertex3f(this->f12.c3.x+x,this->f12.c3.y+y,this->f12.c3.z+z);
    }

    if(-(this->f21.c1.x+x-(cx+offx))<0){ //f2* norms are all x negative 
        //glColor4f(this->color.x+x-0.1, this->color.y+y-0.1, this->color.z+z-0.1, this->alpha);
        glVertex3f(this->f21.c1.x+x,this->f21.c1.y+y,this->f21.c1.z+z);
        glVertex3f(this->f21.c2.x+x,this->f21.c2.y+y,this->f21.c2.z+z);
        glVertex3f(this->f21.c3.x+x,this->f21.c3.y+y,this->f21.c3.z+z);
        glVertex3f(this->f22.c1.x+x,this->f22.c1.y+y,this->f22.c1.z+z);
        glVertex3f(this->f22.c2.x+x,this->f22.c2.y+y,this->f22.c2.z+z);
        glVertex3f(this->f22.c3.x+x,this->f22.c3.y+y,this->f22.c3.z+z);
    }

    if(this->f31.c1.y+y-(cy+offy)<=0){
        //glColor4f(this->color.x+x-0.3, this->color.y+y-0.3, this->color.z+z-0.3, this->alpha);
        glVertex3f(this->f31.c1.x+x,this->f31.c1.y+y,this->f31.c1.z+z);
        glVertex3f(this->f31.c2.x+x,this->f31.c2.y+y,this->f31.c2.z+z);
        glVertex3f(this->f31.c3.x+x,this->f31.c3.y+y,this->f31.c3.z+z);
        glVertex3f(this->f32.c1.x+x,this->f32.c1.y+y,this->f32.c1.z+z);
        glVertex3f(this->f32.c2.x+x,this->f32.c2.y+y,this->f32.c2.z+z);
        glVertex3f(this->f32.c3.x+x,this->f32.c3.y+y,this->f32.c3.z+z);
    }

    if(this->f41.c1.y+y-(cy+offy)>0){
        //glColor4f(this->color.x+x-0.5, this->color.y+y-0.5, this->color.z+z-0.5, this->alpha);
        glVertex3f(this->f41.c1.x+x,this->f41.c1.y+y,this->f41.c1.z+z);
        glVertex3f(this->f41.c2.x+x,this->f41.c2.y+y,this->f41.c2.z+z);
        glVertex3f(this->f41.c3.x+x,this->f41.c3.y+y,this->f41.c3.z+z);
        glVertex3f(this->f42.c1.x+x,this->f42.c1.y+y,this->f42.c1.z+z);
        glVertex3f(this->f42.c2.x+x,this->f42.c2.y+y,this->f42.c2.z+z);
        glVertex3f(this->f42.c3.x+x,this->f42.c3.y+y,this->f42.c3.z+z);
    }

    if(this->f51.c1.z+z-(cz+offz)<=0){
        //glColor4f(this->color.x+x-0.6, this->color.y+y-0.6, this->color.z+z-0.6, this->alpha);
        glVertex3f(this->f51.c1.x+x,this->f51.c1.y+y,this->f51.c1.z+z);
        glVertex3f(this->f51.c2.x+x,this->f51.c2.y+y,this->f51.c2.z+z);
        glVertex3f(this->f51.c3.x+x,this->f51.c3.y+y,this->f51.c3.z+z);
        glVertex3f(this->f52.c1.x+x,this->f52.c1.y+y,this->f52.c1.z+z);
        glVertex3f(this->f52.c2.x+x,this->f52.c2.y+y,this->f52.c2.z+z);
        glVertex3f(this->f52.c3.x+x,this->f52.c3.y+y,this->f52.c3.z+z);
    }

    if(-(this->f61.c1.z+z-(cz+offz))<0){
        //glColor4f(this->color.x+x-0.8, this->color.y+y-0.8, this->color.z+z-0.8, this->alpha);
        glVertex3f(this->f61.c1.x+x,this->f61.c1.y+y,this->f61.c1.z+z);
        glVertex3f(this->f61.c2.x+x,this->f61.c2.y+y,this->f61.c2.z+z);
        glVertex3f(this->f61.c3.x+x,this->f61.c3.y+y,this->f61.c3.z+z);
        glVertex3f(this->f62.c1.x+x,this->f62.c1.y+y,this->f62.c1.z+z);
        glVertex3f(this->f62.c2.x+x,this->f62.c2.y+y,this->f62.c2.z+z);
        glVertex3f(this->f62.c3.x+x,this->f62.c3.y+y,this->f62.c3.z+z);
    }
}