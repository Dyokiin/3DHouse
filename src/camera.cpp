#include "../include/camera.hpp"

KeyPoints::KeyPoints(){
    this->kp = {
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
            offz+=(p.z-z)/100 +0.01;
            offx+=(p.x-x)/100 +0.03;
            offy+=(p.y-y)/100;
            if(x<0){latitude+=3.1415/1000;}
            if(z<45){latitude -= 3.1415/2000;}
            if(x>0 && p.z - z <= 10){
                longitude+=3.1415/145;
            }
            break;
        }
    }
}

