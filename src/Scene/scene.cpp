#include <iostream>
#include <list>

#include "../../include/scene.hpp"


SceneNode::SceneNode(){
    this->localZero = makePoint(0.,0.,0.);
}

SceneNode::SceneNode(point localz){
    this->localZero = localz;
}

SceneNode::SceneNode(SceneNode* prev){
    this->localZero = prev->localZero;
    prev->addChild(this);
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

void SceneNode::update(){
    for(SceneNode* x : this->children){
        x->update();
    }
}

void ObjectNode::addObject(Object* o){
    this->assets.push_back(o);
}

void ObjectNode::setObjects(std::list<Object*> children){
    this->assets = children;
}

void ObjectNode::update(){
    point z = this->getLocal();
    for(Object* x : this->assets){
        x->Display(z.x,z.y,z.z);
    }
    for(SceneNode* y : this->children){
        y->update();
    }
}