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



sf::Font defaultFont;

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.

//The maps used for testing
SqureDiggingMap squareMap;
CA_Map caMap;
Map MainMap;
BaseCreature player;

//TODO, need a better way to handle items on a particular map. Maybe add an itemsOnMap* to the Map itself, assuming that doesn't take up too much space..Or maybe some sort of class containing pointers to a map and and items that handles all interaction between them


//Tile types are predefined. TODO, populate this from a file.







void InitializeGlobals()
{
    if (!defaultFont.loadFromFile("tnr.ttf"))
    {
        // error...
    }
}





