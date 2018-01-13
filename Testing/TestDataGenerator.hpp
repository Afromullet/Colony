//
//  TestDataGenerator.hpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef TestDataGenerator_hpp
#define TestDataGenerator_hpp

#include <stdio.h>
#include "CaMap.hpp"
#include "MapData.hpp"
#include "Globals.hpp"
#include "Constants.hpp"

extern Armor tHeadArmor;
extern Armor tChestArmor;
extern Armor tLegArmor;
extern Armor tHandArmor;
extern Armor tFootArmor;

extern Weapon tOneHnaded;
extern Weapon tTwoHanded;


void CreateRandomCreatures(MapData &mapdata);
void CreateTargetCreatures(MapData &mapdata);
void GenerateRandomItems(MapData &mapdata, int numberOfItems);
void GenerateTestEquipment();
void GenerateRandomCave();
#endif /* TestDataGenerator_hpp */
