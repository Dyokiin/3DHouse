#include "../../include/createScene.hpp"
#include "../../include/assets.hpp"

SceneNode* initScene(){

    /* Scène Principale */
    SceneNode* scene = new SceneNode(makePoint(0.,0.,0.));

    /* Scènes Secondaires */
    SceneNode* cuisine  = new SceneNode(makePoint(110.,0.,35.));
    SceneNode* sdb = new SceneNode(makePoint(161.,0.,-30.));
    SceneNode* chambre = new SceneNode(makePoint(161.,69.,-30.));


    /* On construit d'abord tous les objets de la scene principale */

//plantes
    ObjectNode* plante1 = new ObjectNode(makePoint(20.,20.,20.));
    std::list<Object> lplante = {Object(pot), Object(dirt), Object(plant1)};
    plante1->setObjects(&lplante);
    ObjectNode* plante2 = new ObjectNode(makePoint(145.,15.,-15.));
    lplante = {Object(pot), Object(dirt), Object(plant2), Object(flower)};
    plante2->setObjects(&lplante);
    ObjectNode* stool1 = new ObjectNode(makePoint(145,0,-15));
    lplante = {Object(stool)};
    stool1->setObjects(&lplante);

//murs
    ObjectNode* wall = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lwall = {Object(wallz), Object(wallz2), Object(wallz3), Object(wallx2), Object(wallx3)};
    wall->setObjects(&lwall);

//sols
    ObjectNode* floorsS = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lfloor = {Object(floor1)};
    floorsS->setObjects(&lfloor);

//portes
    ObjectNode* door = new ObjectNode(makePoint(0.,0.,-29.));
    std::list<Object> ldoor = {Object(doorx), Object(hdx)};
    door->setObjects(&ldoor);
    ObjectNode* door2 = new ObjectNode(makePoint(130.,0.,5));
    ldoor = {Object(doorx2), Object(hdx2)};
    door2->setObjects(&ldoor);

//toit
    ObjectNode* roof1 = new ObjectNode(makePoint(-20.,124,-30));
    std::list<Object> lroof = {Object(roof)};
    roof1->setObjects(&lroof);
    ObjectNode* roof2 = new ObjectNode(makePoint(120.,125,-30));
    roof2->setObjects(&lroof);


    /* Construction des objets des scènes secondaire */

    ObjectNode* floorsSDBCH = new ObjectNode(makePoint(0.,0.,0.));
    lfloor = {Object(floorsc)};
    floorsSDBCH->setObjects(&lfloor);
    ObjectNode* floorsC = new ObjectNode(makePoint(0.,0.,0.));
    lfloor = { Object(floor12),Object(floor11)};
    floorsC->setObjects(&lfloor);

    ObjectNode* Fkitch = new ObjectNode(makePoint(25,0.,10));
    std::list<Object> lkitch = {Object(board), Object(furns)};
    Fkitch->setObjects(&lkitch);


    /* Construiction de la scène et affectation des Objets */

    std::list<ObjectNode*> loc = {floorsC, Fkitch};
    cuisine->elements = loc; 
    std::list<ObjectNode*> los = {floorsSDBCH};
    sdb->elements = los;
    std::list<ObjectNode*> loch = {floorsSDBCH};
    chambre->elements = loch;
    std::list<ObjectNode*> lo = {door, door2, wall, plante1, plante2, floorsS, roof1, roof2, stool1};
    scene->elements = lo;

    std::list<SceneNode*> ls = {cuisine, sdb, chambre};
    scene->children = ls;

    return scene;
}