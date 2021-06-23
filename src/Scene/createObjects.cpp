#include "../../include/createObjects.hpp"


Object::Object(float voxels[][3]){
    int i = 1;
    while(voxels[i][1]!=-1){
        this->voxels.push_front(Vox(voxels[0][0],voxels[0][1], voxels[0][2],voxels[i][0],voxels[i][1],voxels[i][2]));
        i++;
    }
}

void Object::Display(float x, float y, float z){
    for(Vox i : this->voxels){
        i.Display(x, y, z);
    }
}