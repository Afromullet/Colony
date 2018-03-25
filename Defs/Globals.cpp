//
//  Globals.cpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "Globals.hpp"
#include "Constants.hpp"

bool PlayerActionTaken = false;

sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");

FileLogger errorLog("errors.txt");

sf::Font defaultFont;

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.
Armor NO_ARMOR(1,"No armor",0,0,0,0);
Weapon FIST_WEAPON(1,"Fist Weapon",1,1);
Weapon NO_WEAPON(1,"No weapon",0,0);
Weapon WEAPON_SLOT_FILLED(1,"Weapon Slot Filled",0,0);




//The maps used for testing

CA_Map caMap;
Map MainMap;
BaseCreature player;

sf::Color BasicHighlightColor = sf::Color(215,215,55);

//TODO, need a better way to handle items on a particular map. Maybe add an itemsOnMap* to the Map itself, assuming that doesn't take up too much space..Or maybe some sort of class containing pointers to a map and and items that handles all interaction between them


//Tile types are predefined. TODO, populate this from a file.



sf::Color yellow = sf::Color::Yellow;
std::vector<int> allEffectIDs;


void InitializeGlobals()
{
    if (!defaultFont.loadFromFile("tnr.ttf"))
    {
        std::cout << "\n Error initializing global font";
        // error...
    }
    else
    {
        std::cout << "\n Font loaded";
    }
    
    //yellow.a = 1;
}

bool doesEffectIDExist(int id)
{
    for(int i = 0; i < allEffectIDs.size(); i++)
    {
        if(id == allEffectIDs.at(i))
            return true;
    }
    
    return false;
}

int AssignEffectID()
{
    //Assign a random ID
    //There shouldn't ever be that many effects, so there is no need for a timeout...or is there? todo
    int id = rand() & 100000000;
    while(doesEffectIDExist(id))
        id = rand() & 100000000;
    
    return id;
    
 
}



