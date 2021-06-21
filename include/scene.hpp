#ifndef SCENE_HPP
#define SCENE_HPP

#include "createObjects.hpp"

class SceneNode {
protected:
    point localZero;
    std::list<SceneNode*> children;
public:
    SceneNode();
    SceneNode(point localz);
    SceneNode(SceneNode* prev);
    void addChild(SceneNode* child);
    void setChild(std::list<SceneNode*> children);
    void setLocal(point localz);
    point getLocal();
    void update();
};

class ObjectNode : public SceneNode {
protected:
    std::list<Object*> assets;
public:
    ObjectNode() : SceneNode(){};
    ObjectNode(SceneNode* prev) : SceneNode(prev){};
    void addObject(Object* o);
    void setObjects(std::list<Object*> objects);
    void update();
};


#endif