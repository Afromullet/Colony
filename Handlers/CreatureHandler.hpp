//
//  CreatureHandler.hpp
//  Colony
//
//  Created by Sean on 12/9/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef CreatureHandler_hpp
#define CreatureHandler_hpp

#include <stdio.h>
#include "BaseCreature.hpp"
#include <vector>
#include "Map.hpp"
#include <list>

//If a creature is killed, remove it from the map of the creature list
//TODO, maybe change interaction of drawing betweenmap and creature later to make associating a creautre with a map easier..Maybe add a safety check for when a creature is first created, to see if it is still on any other map
void RemoveDeadCreature(Map &_map,std::list<BaseCreature> &creatures);

#endif /* CreatureHandler_hpp */
