//
//  BasicBehavior.hpp
//  Colony
//
//  Created by Sean on 2/17/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BasicBehavior_hpp
#define BasicBehavior_hpp

#include <stdio.h>
#include "BaseCreature.hpp"

bool ApproachCreature(Map &map,BaseCreature &approacher,BaseCreature &target);
bool ApproachTile(Map &map,BaseCreature &approacher,sf::Vector2i position);
bool GetItemBehavior(Map &map,BaseCreature &creature);


#endif /* BasicBehavior_hpp */
