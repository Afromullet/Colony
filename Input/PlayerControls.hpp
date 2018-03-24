//
//  PlayerControls.hpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef PlayerControls_hpp
#define PlayerControls_hpp

#include <stdio.h>
#include "Map.hpp"
#include "MovementHandler.hpp"
#include "MapData.hpp"
#include "EnumTypes.hpp"
#include "DataWindow.hpp"
#include "WindowCommands.hpp"




//Don't want to use command pattern riht now
extern bool usingTargetSquare;
extern bool isInventoryWindowOpen;
extern bool isEquipmentWindowOpen;


extern WindowCommands playerWindowCommands;

extern DataWindow inventoryWindow;
extern DataWindow equipmentWindow;

extern MapEffect targettingSquare;

extern std::vector<sf::Vector2i> square;
bool HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature);
void ControlTargetSquare(MoveDirection moveDir,MapData &mapdata);
void InitializeInventoryWindow();
void AddItemsToInventoryWindow(BaseCreature &creature);
void AddToEquipmentWindow(BaseCreature &creature);


#endif /* PlayerControls_hpp */
