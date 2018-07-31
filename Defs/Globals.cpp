//
//  Globals.cpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "Globals.hpp"
#include "Constants.hpp"
#include "Material.hpp"




#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <TGUI/TGUI.hpp>


bool PlayerActionTaken = false;

sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");
tgui::Gui gui;

//FileLogger errorLog("errors.txt");

sf::Font defaultFont;
tgui::Font tguiFont("tnr.ttf");

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.
Armor NO_ARMOR(Material(),"No armor",1,1,1,1);
Weapon FIST_WEAPON(Material(),"Fist Weapon",1,1);
Weapon NO_WEAPON(Material(),"No weapon",0,0);
Weapon WEAPON_SLOT_FILLED(Material(),"Weapon Slot Filled",0,0);




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
    
    

    InitializeWindows();
    gui.setFont("tnr.ttf"); // Load the font directly
    
    
    
    if (!defaultFont.loadFromFile("tnr.ttf"))
    {
        std::cout << "\n Error initializing global font";
        // error...
    }
    else
    {
        
    }
    
    
    
    
    //yellow.a = 1;
}

void InitializeWindows()
{

    window.setVerticalSyncEnabled(true);
    
   
   gui.setWindow(window);
    ImGui::SFML::Init(window);
    
    
    

 
    
    
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



