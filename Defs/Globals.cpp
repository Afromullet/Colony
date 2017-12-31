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

std::list<BaseCreature> lCreatures;

Map MainMap;
BaseCreature player;

//TODO, need a better way to handle items on a particular map. Maybe add an itemsOnMap* to the Map itself, assuming that doesn't take up too much space..Or maybe some sort of class containing pointers to a map and and items that handles all interaction between them
std::list<Item*> itemsOnMap;

//Tile types are predefined. TODO, populate this from a file.

void InitializeTileData()
{
    
    //A messy way to do this right now, coyping the data generated from TileReader
    //Nothing to ensure yet that the method has been called..rename the variable later
    
    
    
    //TileIDData idData;
  
    
    //Todo, I have no idea why it needs 3 tiles to work. Can't remember the way the map is implemented enough, todo investigate later
    
     CELL_CHANCETOSTARTALIVE = 0.45;
    DEATH_LIMIT = 3;
    BIRTH_LIMIT = 4 ;
    NUMBER_OF_STEPS = 2;
    
    
}






void InitializeGlobals()
{
    if (!defaultFont.loadFromFile("tnr.ttf"))
    {
        // error...
    }
}





