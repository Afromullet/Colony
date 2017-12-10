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
void RemoveDeadCreature(Map &_map,std::list<BaseCreature> &creatures);

#endif /* CreatureHandler_hpp */
