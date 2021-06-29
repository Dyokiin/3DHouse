#include "../include/camera.hpp"

KeyPoints::KeyPoints(){
    this->kp = {makePoint(-97,31,-16),
                makePoint(0,40,-15),
                makePoint(180,45,10),
                makePoint(60,50,35),
                makePoint(100,65,100),
                makePoint(190,100,130)
                };
}

void KeyPoints::step(float x, float y, float z){
    for(point p : this->kp){
        if(z <= p.z){
            offz+=0.5;
            offx+=p.x-x;
            offy+=p.y-y;
            std::cout << offz << std::endl << z << ", " << p.z << std::endl;;
            break;
        }
    }
}

