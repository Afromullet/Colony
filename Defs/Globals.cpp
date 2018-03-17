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

bool PlayerActionTaken = false;

sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");

FileLogger errorLog("errors.txt");

sf::Font defaultFont;

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.
Armor NO_ARMOR(1,enAnyBodyPart,"No armor",0,0,0,0,enLight);
Weapon FIST_WEAPON(1,enFitsOneHand,"Fist Weapon",1,1,enUnarmed);
Weapon NO_WEAPON(1,enFitsOneHand,"No weapon",0,0,enUndefinedWeaponClass);
Weapon WEAPON_SLOT_FILLED(1,enFitsOneHand,"Weapon Slot Filled",0,0,enUndefinedWeaponClass);

std::string leftArmString = "Left Arm";
std::string rightArmString = "Right Arm";
std::string leftHandString = "Left Hand";
std::string rightHandString = "Right Hand";
std::string leftLegString = " Left Leg";
std::string rightLegString = "Right Leg";
std::string rightFootString = "Right Foot";
std::string leftFootString = "Left Foot";
std::string headString = "Head";
std::string chestString = "Chest";

BodyPart LeftArmBodyPart(enArmsBodyPart,false,true,false,false,leftArmString,10);
BodyPart RightArmBodyPart(enArmsBodyPart,false,true,false,false,rightArmString,10);
BodyPart LeftLegBodyPart(enLegsBodyPart,false,true,false,false,leftLegString,10);
BodyPart RightLegBodyPart(enLegsBodyPart,false,true,false,false,rightLegString,10);
BodyPart leftHandBodyPart(enLeftHandBodyPart,true,true,true,false,leftHandString,10);
BodyPart rightHandBodyPart(enRightHandBodyPart,true,true,true,false,rightHandString,10);
BodyPart leftFootBodypart(enFootBodyPart,false,true,false,true,leftFootString,10);
BodyPart rightFootBodyPart(enFootBodyPart,false,true,false,true,rightFootString,10);
BodyPart headBodyPart(enHeadBodyPart,false,true,false,false,headString,10);
BodyPart chestBodyPart(enChestBodyPart,false,true,false,false,chestString,10);


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



