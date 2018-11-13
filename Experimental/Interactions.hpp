//
//  Interactions.hpp
//  Colony
//
//  Created by Sean on 11/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Interactions_hpp
#define Interactions_hpp

#include <stdio.h>
#include "Map.hpp"
#include "Tile.hpp"
#include "BaseCreature.hpp"
#include "EnumTypes.hpp"
#include "AttackHandler.hpp"

enum EnResponseType
{
    enSuccessful,
    enNoActionRequired,
    enUnsuccessful,
    enSelectCreatureToCreatureInteraction
};

void CreatureMovesToTile(BaseCreature &creature, Map &map, MoveDirection direction);

void CreatureAttacksCreature(BaseCreature &attacker, BaseCreature &defender);
void CreatureToCreature(BaseCreature &initiator, BaseCreature &receiver);

#endif /* Interactions_hpp */
