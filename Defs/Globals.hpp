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
#include "SquareDiggingMap.hpp"
#include "CaMap.hpp"
#include "Constants.hpp"


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
 

extern std::vector<TileIDData> tileIDTable; 
extern sf::RenderWindow window;
extern Map MainMap; //No need to have more than one main map (At least for now)
extern SqureDiggingMap squareMap;
extern CA_Map caMap;

extern BaseCreature player; //Maybe sometimes in the future there'll be more than one player. For now, having a player as a global var makes things easier for me



extern sf::Font defaultFont;

void InitializeGlobals();






//extern std::list<Item*> itemsOnMap;



#endif /* Globals_hpp */
