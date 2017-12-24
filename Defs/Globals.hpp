//
//  Globals.hpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//



#ifndef Globals_hpp
#define Globals_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include <Vector>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <string>
#include "Map.hpp"
#include "BaseCreature.hpp"
#include <list>

#define MAX_CREATURES_PER_MAP 100

//Matches up a tile ID with a tile type, texture, etc.
//To be loaded at initilization, so when generating maps, you have the necessary data
typedef struct TileIdentificationData
{
    TileTerrainType enTileTerrainType;
    int ID;
    bool canHoldCreature;
    std::string textureFileName;
    
}TileIDData;



extern Map MainMap; //No need to have more than one main map (At least for now)

extern BaseCreature player; //Maybe sometimes in the future there'll be more than one player. For now, having a player as a global var makes things easier for me


extern sf::RenderWindow window;
extern sf::Font defaultFont;

void InitializeGlobals();
void InitializeTileData();

extern std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.

extern std::list<BaseCreature> lCreatures;

extern std::list<Item*> itemsOnMap;

extern float CELL_CHANCETOSTARTALIVE;
extern int DEATH_LIMIT;
extern int BIRTH_LIMIT;
extern int NUMBER_OF_STEPS;

#endif /* Globals_hpp */
