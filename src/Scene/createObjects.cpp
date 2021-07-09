#include "../../include/createObjects.hpp"
#include <iostream>

/* HEAVY memory use :/ */


Object::Object(float voxels[][3]){
    int i = 1;
    while(voxels[i][1]!=-1){
        this->voxels.push_front(Vox(voxels[0][0],voxels[0][1], voxels[0][2],voxels[i][0],voxels[i][1],voxels[i][2]));
        i++;
    }
}

void Object::Display(float x, float y, float z){

    for(Vox i : this->voxels){
        
//Calcul de lumière : ne fonctionne pa 

        // /* Calcul de la couleur : un par Voxel */
        // point lv = makePoint((i.f11.c1.x+x)-this->l->pos.x, (i.f11.c1.y+y)-this->l->pos.y, (i.f11.c1.z+z)-this->l->pos.z);
        // point coul = multPoint(this->l->Pd,multPoint(makePoint(1.,1.,1.),lv));
        // coul = multPoint(makePoint(i.color.x*255, i.color.y*255, i.color.z*255),coul);
        // float div = 1 + 3.14159261 * (lv.x*lv.x + lv.y*lv.y + lv.z*lv.z);
        // coul.x = coul.x / div;
        // coul.y = coul.y / div;
        // coul.z = coul.z / div;
        // //std::cout << coul.x << ", " << coul.y << ", " << coul.z << std::endl;
        
        //glColor3f(coul.x, coul.y, coul.z);
        
        i.Display(x, y, z);
    }
}