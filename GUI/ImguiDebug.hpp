//
//  ImguiDebug.hpp
//  Colony
//
//  Created by Sean on 7/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ImguiDebug_hpp
#define ImguiDebug_hpp


#include "imgui.h"
#include "imgui-SFML.h"
#include <memory>
#include "BodyGraph.hpp"
#include <string>
#include "BodyPart.hpp"
#include <vector>




//Storing information entered in the debug menu
extern BodyPart tempBodyPart;
extern std::shared_ptr<CreatureBody> anatomy;
extern std::vector<BodyPart> debugBodyparts;
extern std::vector<std::string> debugBodyartNames;


extern bool canSee,canSmell,canBreathe;
extern bool canHoldWeapon,canHoldArmor,canInteract,canMoveCreature,isInternal;



extern int health;
extern std::string bodyPartToken,section,bodyPartName;





void BPCreatorInput();
void BPExaminer();
void BPConnector();
void BodyGraphViewer(CreatureBody &body);
void CreateBPTree(CreatureBody &body,int n);

int getBPTruthValIndex(bool val);
std::string convertBPTruthVal(bool val);

void DisplayShit();


//Will eventually need something that interfaces with mapdata, to put the creatures on the map.
//shared_ptr<BaseCreature> debugCreatures;

/*
 The idea for a class here is one that takes input from the debug window and handles it to allow the construction of different body parts of creatures..A humanoid body, a winged creature, something with horns..
 
  Container of BodyGraph that is manipulated - therefore body pars.
 
 
 
 
 
 */



//Groups of functions that serve as a debug menu..I.E, spawning creatures, modifying stats


#include <stdio.h>

#endif /* ImguiDebug_hpp */
