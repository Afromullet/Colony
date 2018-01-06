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



sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");

FileLogger errorLog("errors.txt");

sf::Font defaultFont;

std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.
Armor NO_ARMOR(1,enAnyBodyPart,1,0,0,0,0,enLight);
Weapon FIST_WEAPON(1,enFitsOneHand,1,1,1,enUnarmed);
Weapon NO_WEAPON(1,enFitsOneHand,0,0,0,enUndefinedWeaponClass);

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
BodyPart leftHandBodyPart(enHandsBodyPart,true,true,true,false,leftHandString,10);
BodyPart rightHandBodyPart(enHandsBodyPart,true,true,true,false,rightHandString,10);
BodyPart leftFootBodypart(enFeetBodyPart,false,true,false,true,leftFootString,10);
BodyPart rightFootBodyPart(enFeetBodyPart,false,true,false,true,rightFootString,10);
BodyPart headBodyPart(enHeadBodyPart,false,true,false,false,headString,10);
BodyPart chestBodyPart(enChestBodyPart,false,true,false,false,chestString,10);


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





