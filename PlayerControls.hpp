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


#endif /* PlayerControls_hpp */

//Don't want to use command pattern riht now

void HandlePlayerInput(sf::Event &event, MapData &mapdata, BaseCreature &creature);