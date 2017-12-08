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



extern Map MainMap;
extern BaseCreature player;


extern sf::RenderWindow window;
extern sf::Font defaultFont;

void InitializeGlobals();
void InitializeTileData();

extern std::vector<TileIDData> tileIDTable;

extern float CELL_CHANCETOSTARTALIVE;
extern int DEATH_LIMIT;
extern int BIRTH_LIMIT;
extern int NUMBER_OF_STEPS;

#endif /* Globals_hpp */
