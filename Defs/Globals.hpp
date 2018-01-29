//
//  Globals.hpp
//  Colony
//
//  Created by Sean on 5/22/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

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
#include "Filelogger.hpp"

#ifndef Globals_hpp
#define Globals_hpp



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
 

extern FileLogger errorLog;
extern std::vector<TileIDData> tileIDTable; 
extern sf::RenderWindow window;
extern Map MainMap; //No need to have more than one main map (At least for now)
extern SqureDiggingMap squareMap;
extern CA_Map caMap;

extern BaseCreature player; //Maybe sometimes in the future there'll be more than one player. For now, having a player as a global var makes things easier for me

extern Weapon FIST_WEAPON;
extern Weapon NO_WEAPON;
extern Armor NO_ARMOR;

//Read these from a file later and store in a vector of strings
//That way it can be customized easily by reading from files
extern std::string leftArmString;
extern std::string rightArmString;
extern std::string leftHandString;
extern std::string rightHandString;
extern std::string leftLegString;
extern std::string rightLegString;
extern std::string rightFootString;
extern std::string leftFootString;
extern std::string headString;
extern std::string chestString;
extern BodyPart LeftArmBodyPart;
extern BodyPart RightArmBodyPart;
extern BodyPart LeftLegBodyPart;
extern BodyPart RightLegBodyPart;
extern BodyPart leftHandBodyPart;
extern BodyPart rightHandBodyPart;
extern BodyPart leftFootBodypart;
extern BodyPart rightFootBodyPart;
extern BodyPart headBodyPart;
extern BodyPart chestBodyPart;

extern std::vector<BodyPart> humanoidBodySchema;


extern sf::Font defaultFont;

void InitializeGlobals();

extern sf::Color yellow;


extern std::vector<int> allEffectIDs;

bool doesEffectIDExist(int id);

int AssignEffectID();

extern sf::Color BasicHighlightColor;

//extern std::list<Item*> itemsOnMap;



#endif /* Globals_hpp */
