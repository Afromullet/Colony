//
//  Globals.cpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "Globals.hpp"
#include "Constants.hpp"
#include "TestData.hpp"
#include "HumanoidBody.hpp"
sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");


//For cellular automota. TODO move ot cellular automota map class
float CELL_CHANCETOSTARTALIVE;
int DEATH_LIMIT;
int BIRTH_LIMIT;
int NUMBER_OF_STEPS;

sf::Font defaultFont;

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.

std::vector<BaseCreature> creatureList;




Map MainMap;
BaseCreature player;




//Tile types are predefined. TODO, populate this from a file.

void InitializeTileData()
{
    TileIDData idData;
    
    idData.enTileTerrainType = enWall1;
    idData.ID = 0;
    idData.textureFileName = "marble_wall1.png";
    idData.canHoldCreature = true;
    tileIDTable.push_back(idData);
    
    idData.enTileTerrainType = enFloor1;
    idData.ID = 1;
    idData.textureFileName = "pebble_brown0.png";
    idData.canHoldCreature = true;
    tileIDTable.push_back(idData);

    
    idData.enTileTerrainType = enSnow1;
    idData.ID = 2;
    idData.textureFileName = "ice0.png";
    idData.canHoldCreature = true;
    tileIDTable.push_back(idData);
    
     CELL_CHANCETOSTARTALIVE = 0.45;
    DEATH_LIMIT = 3;
    BIRTH_LIMIT = 4 ;
    NUMBER_OF_STEPS = 2;
    
    
   
    
    
    
}






void InitializeGlobals()
{
    
    

    //creatureList.p
    
    if (!defaultFont.loadFromFile("tnr.ttf"))
    {
        // error...
    }
    
  
    
    
    
}





