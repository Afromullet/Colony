//
//  TestDataGenerator.hpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//




#ifndef TestDataGenerator_hpp
#define TestDataGenerator_hpp
#include "SettlementEV.hpp"
#include "BaseCreature.hpp"

#include "ItemGenerator.hpp"
#include "CAMap.hpp"
#include <stdio.h>
#include "CaMap.hpp"
#include "MapData.hpp"
//#include "Globals.hpp"
#include "Constants.hpp"


extern Armor tHeadArmor;
extern Armor tChestArmor;
extern Armor tLegArmor;
extern Armor tHandArmor;
extern Armor tFootArmor;

extern Weapon tOneHnaded;
extern Weapon tTwoHanded;


//Some creature types for testing
extern BaseCreature basicGoblin;
extern BaseCreature basicOrc;
extern BaseCreature basicPulser;

void InitializeCreatureTypes();
void CreateRandomCreatures(MapData &mapdata);
void InitCreaturesOnMap(MapData &mapdata);
void GenerateRandomCave();
void GenerateItemsOnMap();

extern std::vector<BaseCreature> testCreatures;


/* 
 TEST DATA FOR FETTLEMENT RELATED THINGS
 
 */


//ResourceFunction rs;
//ResourceFunction testResourceFunctions[10];


#endif /* TestDataGenerator_hpp */
