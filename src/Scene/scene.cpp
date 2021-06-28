#include <iostream>
#include <list>

#include "../../include/scene.hpp"


SceneNode::SceneNode(){
    this->localZero = makePoint(0.,0.,0.);
}

SceneNode::SceneNode(point localz){
    this->localZero = localz;
}

void SceneNode::addChild(SceneNode* child){
    this->children.push_front(child);
}

void SceneNode::setChild(std::list<SceneNode*> children){
    this->children = children;
}

void SceneNode::setLocal(point localz){
    this->localZero = localz;
}

point SceneNode::getLocal(){
    return this->localZero;
}

void SceneNode::update(point local){
    for(SceneNode* x : this->children){
        x->update(this->localZero);
    }
    for(ObjectNode* y: this->elements){
        y->update(this->localZero);
    }

}

void ObjectNode::addObject(Object o){

    this->assets.push_front(o);
}

ObjectNode::ObjectNode(point localz){
    this->localZero = localz;
}

void ObjectNode::setObjects(std::list<Object>* children){
    this->assets = *children;
}

void ObjectNode::update(point local){
    point z = this->getLocal();
    z.x += local.x;
    z.y += local.y;
    z.z += local.z;
    for(Object x : this->assets){
        x.Display(z.x,z.y,z.z);
    }
    for(SceneNode* y : this->children){
        y->update(this->localZero);
    }
}