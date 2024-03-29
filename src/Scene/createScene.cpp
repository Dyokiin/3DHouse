#include "../../include/createScene.hpp"
#include "../../include/assets.hpp"


/* Chargement complet de la scène ici */

SceneNode* initScene(){

    /* Scène Principale */
//aussi : salon
    SceneNode* scene = new SceneNode(makePoint(0.,0.,0.));

    /* Scènes Secondaires */
    SceneNode* cuisine  = new SceneNode(makePoint(110.,0.,35.));
    SceneNode* sdb = new SceneNode(makePoint(161.,0.,-30.));
    SceneNode* chambre = new SceneNode(makePoint(161.,69.,-30.));



    /* On construit d'abord tous les objets de la scene principale */

//plantes
    ObjectNode* plante1 = new ObjectNode(makePoint(2.,62.,15.));
    std::list<Object> lplante = {Object(pot), Object(dirt), Object(plant1)};
    plante1->setObjects(&lplante);
    ObjectNode* plante2 = new ObjectNode(makePoint(145.,15.,-15.));
    lplante = {Object(pot), Object(dirt), Object(plant2), Object(flower)};
    plante2->setObjects(&lplante);
    ObjectNode* stool1 = new ObjectNode(makePoint(145,0,-15));
    lplante = {Object(stool)};
    stool1->setObjects(&lplante);

//table 
    ObjectNode* table1 = new ObjectNode(makePoint(40,0,60));
    std::list<Object> ltable = {Object(table)};
    table1->setObjects(&ltable);

//murs
    ObjectNode* wall = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lwall = {Object(wallz), Object(wallz2), Object(wallz3), Object(windowz1), Object(windowz2)};
    wall->setObjects(&lwall);
    ObjectNode* wall1 = new ObjectNode(makePoint(0.,0.,0.));
    lwall = {Object(wallx2), Object(windowx)};
    wall1->setObjects(&lwall);
    ObjectNode* wall2 = new ObjectNode(makePoint(0.,0.,180.));
    wall2->setObjects(&lwall); //reduce RAM usage


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
    roof2->setObjects(&lroof); //reduce RAM usage

//Objet complexe : étagère, Opti RAM usage
    SceneNode* etagere = new SceneNode(makePoint(1.,1.,10.));
    std::list<Object> letag = {Object(etagS)};
    ObjectNode* etag1 = new ObjectNode(makePoint(0.,0.,0.));
    etag1->setObjects(&letag);
    letag = {Object(etagC)};
    ObjectNode* etag2 = new ObjectNode(makePoint(0.,10,0.));
    etag2->setObjects(&letag);
    ObjectNode* etag3 = new ObjectNode(makePoint(0.,20,0.));
    etag3->setObjects(&letag);
    ObjectNode* etag4 = new ObjectNode(makePoint(0.,30,0.));
    etag4->setObjects(&letag);
    ObjectNode* etag5 = new ObjectNode(makePoint(0.,40,0.));
    etag5->setObjects(&letag);
    ObjectNode* etag6 = new ObjectNode(makePoint(0.,50,0.));
    etag6->setObjects(&letag);
    ObjectNode* etag7 = new ObjectNode(makePoint(0.,60,0.));
    etag7->setObjects(&letag);
    letag = {Object(etagS)};
    ObjectNode* etag8 = new ObjectNode(makePoint(0.,0.,40.));
    etag8->setObjects(&letag);

    std::list<ObjectNode*> loetag = {etag1,etag2,etag3,etag4,etag5,etag6,etag7,etag8};
    etagere->elements = loetag;

//même principe pour l'escalier
    SceneNode* escalier = new SceneNode(makePoint(96,-1,125));
    std::list<Object> lstep = {Object(step)};
    ObjectNode* step1 = new ObjectNode(makePoint(0.,0.,0.));
    step1->setObjects(&lstep);
    ObjectNode* step2 = new ObjectNode(makePoint(9.,10.,0.));
    step2->setObjects(&lstep);
    ObjectNode* step3 = new ObjectNode(makePoint(18.,20.,0.));
    step3->setObjects(&lstep);
    ObjectNode* step4 = new ObjectNode(makePoint(27.,30.,0.));
    step4->setObjects(&lstep);
    ObjectNode* step5 = new ObjectNode(makePoint(36.,40.,0.));
    step5->setObjects(&lstep);
    ObjectNode* step6 = new ObjectNode(makePoint(45.,50.,0.));
    step6->setObjects(&lstep);
    ObjectNode* step7 = new ObjectNode(makePoint(54.,60.,0.));
    step7->setObjects(&lstep);

    std::list<ObjectNode*> lostep = {step1, step2, step3, step4, step5, step6, step7};
    escalier->elements = lostep;


    /* Construction des objets des scènes secondaire */

//Sols sdb et chanmbre : mêmes voxels
    ObjectNode* floorsSDBCH = new ObjectNode(makePoint(0.,0.,0.));
    lfloor = {Object(floorsc)};
    floorsSDBCH->setObjects(&lfloor);
    ObjectNode* floorsC = new ObjectNode(makePoint(0.,0.,0.));
    lfloor = { Object(floor12),Object(floor11)};
    floorsC->setObjects(&lfloor);

//Meubles cuisine
    ObjectNode* Fkitch = new ObjectNode(makePoint(25,0.,10));
    std::list<Object> lkitch = {Object(board), Object(furns), Object(hndls), Object(frigo)};
    Fkitch->setObjects(&lkitch);


//Douche
    ObjectNode* shower = new ObjectNode(makePoint(29,1,140));
    std::list<Object> lshow = {Object(bac), Object(bord), Object(barre), Object(pommeau), Object(mitig)};
    shower->setObjects(&lshow);

//chambre 
    ObjectNode* stick = new ObjectNode(makePoint(0,0,0));
    std::list<Object> lstick = {Object(ramb), Object(bed)};
    stick->setObjects(&lstick);

    ObjectNode* Prof = new ObjectNode(makePoint(60,1,140));
    std::list<Object> lprof = {Object(lap1), Object(lap2)};
    Prof->setObjects(&lprof);


    /* Construiction de la scène et affectation des Objets */

    std::list<ObjectNode*> loc = {floorsC, Fkitch};
    cuisine->elements = loc; 
    std::list<ObjectNode*> los = {floorsSDBCH, shower};
    sdb->elements = los;
    std::list<ObjectNode*> loch = {floorsSDBCH, stick, Prof};
    chambre->elements = loch;
    std::list<ObjectNode*> lo = {door, door2, wall, wall1, wall2, plante1, plante2, floorsS, roof1, roof2, stool1, table1};
    scene->elements = lo;

    std::list<SceneNode*> ls = {cuisine, sdb, chambre, etagere, escalier};
    scene->children = ls;

    return scene;
}