#include "../../include/createScene.hpp"
#include "../../include/assets.hpp"

SceneNode* initScene(){
    /* Scène Principale */
    SceneNode* scene = new SceneNode(makePoint(0.,0.,0.));

    /* On construit d'abord tous les objets */

//plante
    ObjectNode* plante1 = new ObjectNode(makePoint(2.,1.,2.));
    std::list<Object> lplante = {Object(pot),
                                  Object(dirt),
                                  Object(plant)};
    plante1->setObjects(&lplante);

//murs
    ObjectNode* wall = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lwall = {Object(wallz), Object(wallz2), Object(wallz3), Object(wallx), Object(wallx2), Object(wallx3)};
    wall->setObjects(&lwall);

    /* On définit les scènes secondaire et on fait les affectations */

    std::list<ObjectNode*> l = {plante1, wall};
    scene->elements = l;
    return scene;
}