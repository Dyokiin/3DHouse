#include "../../include/createScene.hpp"
#include "../../include/assets.hpp"

SceneNode* initScene(){
    /* Scène Principale */
    SceneNode* scene = new SceneNode(makePoint(0.,0.,0.));

    /* On construit d'abord tous les objets */

//plantes
    ObjectNode* plante1 = new ObjectNode(makePoint(20.,20.,20.));
    std::list<Object> lplante = {Object(pot), Object(dirt), Object(plant1)};
    plante1->setObjects(&lplante);
    ObjectNode* plante2 = new ObjectNode(makePoint(145.,1.,-15.));
    lplante = {Object(pot), Object(dirt), Object(plant2), Object(flower)};
    plante2->setObjects(&lplante);

//murs
    ObjectNode* wall = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lwall = {Object(wallz), Object(wallz2), Object(wallz3), Object(wallx2), Object(wallx3)};
    wall->setObjects(&lwall);

//portes
        ObjectNode* door = new ObjectNode(makePoint(0.,0.,-29.));
        std::list<Object> ldoor = {Object(doorx), Object(hdx)};
        door->setObjects(&ldoor);
        ObjectNode* door2 = new ObjectNode(makePoint(130.,0.,5));
        ldoor = {Object(doorx2), Object(hdx2)};
        door2->setObjects(&ldoor);

    /* On définit les scènes secondaire et on fait les affectations */


    std::list<ObjectNode*> l = {door, door2, wall, plante1, plante2};
    scene->elements = l;
    return scene;
}