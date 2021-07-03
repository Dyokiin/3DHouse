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

    /* Lumières */
    light* Lsal = makeLight(makePoint(10.,10.,10.), makePoint(70,100,100));
    light* Lsdb = makeLight(makePoint(10.,10.,10.), makePoint(180,80,100));


    /* On construit d'abord tous les objets de la scene principale */

//plantes
    ObjectNode* plante1 = new ObjectNode(makePoint(2.,62.,15.));
    std::list<Object> lplante = {Object(pot, Lsal), Object(dirt, Lsal), Object(plant1, Lsal)};
    plante1->setObjects(&lplante);
    ObjectNode* plante2 = new ObjectNode(makePoint(145.,15.,-15.));
    lplante = {Object(pot, Lsal), Object(dirt, Lsal), Object(plant2, Lsal), Object(flower, Lsal)};
    plante2->setObjects(&lplante);
    ObjectNode* stool1 = new ObjectNode(makePoint(145,0,-15));
    lplante = {Object(stool, Lsal)};
    stool1->setObjects(&lplante);

//murs
    ObjectNode* wall = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lwall = {Object(wallz, Lsal), Object(wallz2, Lsal), Object(wallz3, Lsal)};
    wall->setObjects(&lwall);
    ObjectNode* wall1 = new ObjectNode(makePoint(0.,0.,0.));
    lwall = {Object(wallx2, Lsal)};
    wall1->setObjects(&lwall);
    ObjectNode* wall2 = new ObjectNode(makePoint(0.,0.,180.));
    wall2->setObjects(&lwall); //reduce RAM usage


//sols
    ObjectNode* floorsS = new ObjectNode(makePoint(0.,0.,0.));
    std::list<Object> lfloor = {Object(floor1, Lsal)};
    floorsS->setObjects(&lfloor);

//portes
    ObjectNode* door = new ObjectNode(makePoint(0.,0.,-29.));
    std::list<Object> ldoor = {Object(doorx, Lsal), Object(hdx, Lsal)};
    door->setObjects(&ldoor);
    ObjectNode* door2 = new ObjectNode(makePoint(130.,0.,5));
    ldoor = {Object(doorx2, Lsal), Object(hdx2, Lsal)};
    door2->setObjects(&ldoor);

//toit
    ObjectNode* roof1 = new ObjectNode(makePoint(-20.,124,-30));
    std::list<Object> lroof = {Object(roof, Lsal)};
    roof1->setObjects(&lroof);
    ObjectNode* roof2 = new ObjectNode(makePoint(120.,125,-30));
    roof2->setObjects(&lroof); //reduce RAM usage

//Objet complexe : étagère, Opti RAM usage
    SceneNode* etagere = new SceneNode(makePoint(1.,1.,10.));
    std::list<Object> letag = {Object(etagS, Lsal)};
    ObjectNode* etag1 = new ObjectNode(makePoint(0.,0.,0.));
    etag1->setObjects(&letag);
    letag = {Object(etagC, Lsal)};
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
    letag = {Object(etagS, Lsal)};
    ObjectNode* etag8 = new ObjectNode(makePoint(0.,0.,40.));
    etag8->setObjects(&letag);

    std::list<ObjectNode*> loetag = {etag1,etag2,etag3,etag4,etag5,etag6,etag7,etag8};
    etagere->elements = loetag;

//même principe pour l'escalier
    SceneNode* escalier = new SceneNode(makePoint(96,-1,125));
    std::list<Object> lstep = {Object(step, Lsal)};
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
    lfloor = {Object(floorsc, Lsdb)};
    floorsSDBCH->setObjects(&lfloor);
    ObjectNode* floorsC = new ObjectNode(makePoint(0.,0.,0.));
    lfloor = { Object(floor12, Lsal),Object(floor11, Lsal)};
    floorsC->setObjects(&lfloor);

//Meubles cuisine
    ObjectNode* Fkitch = new ObjectNode(makePoint(25,0.,10));
    std::list<Object> lkitch = {Object(board, Lsal), Object(furns, Lsal), Object(hndls, Lsal), Object(frigo, Lsal)};
    Fkitch->setObjects(&lkitch);


//Douche
    ObjectNode* shower = new ObjectNode(makePoint(29,1,140));
    std::list<Object> lshow = {Object(bac, Lsdb), Object(bord, Lsdb), Object(barre, Lsdb), Object(pommeau, Lsdb), Object(mitig, Lsdb)};
    shower->setObjects(&lshow);

//chambre 
    ObjectNode* stick = new ObjectNode(makePoint(0,0,0));
    std::list<Object> lstick = {Object(ramb, Lsal), Object(bed, Lsal)};
    stick->setObjects(&lstick);


    /* Construiction de la scène et affectation des Objets */

    std::list<ObjectNode*> loc = {floorsC, Fkitch};
    cuisine->elements = loc; 
    std::list<ObjectNode*> los = {floorsSDBCH, shower};
    sdb->elements = los;
    std::list<ObjectNode*> loch = {floorsSDBCH, stick};
    chambre->elements = loch;
    std::list<ObjectNode*> lo = {door, door2, wall, wall1, wall2, plante1, plante2, floorsS, roof1, roof2, stool1};
    scene->elements = lo;

    std::list<SceneNode*> ls = {cuisine, sdb, chambre, etagere, escalier};
    scene->children = ls;

    return scene;
}