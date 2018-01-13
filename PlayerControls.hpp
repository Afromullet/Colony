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




//Don't want to use command pattern riht now
extern bool usingTargetSquare;

extern MapEffect targettingSquare;

extern std::vector<sf::Vector2i> square;
void HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature);
void ControlTargetSquare(MoveDirection moveDir,MapData &mapdata);

#endif /* PlayerControls_hpp */