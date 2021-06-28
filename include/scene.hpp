#ifndef SCENE_HPP
#define SCENE_HPP

#include "createObjects.hpp"

class ObjectNode;

class SceneNode {
public:
    point localZero;
    std::list<SceneNode*> children;
    std::list<ObjectNode*> elements;
public:
    SceneNode();
    SceneNode(point localz);
    void addChild(SceneNode* child);
    void setChild(std::list<SceneNode*> children);
    void setLocal(point localz);
    point getLocal();
    void update(point loc);
};

class ObjectNode : public SceneNode {
public:
    std::list<Object> assets;
public:
    ObjectNode() : SceneNode(){};
    ObjectNode(point getLocal);
    void addObject(Object o);
    void setObjects(std::list<Object>* objects);
    void update(point loc);
};


#endif