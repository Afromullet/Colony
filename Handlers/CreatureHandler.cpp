//
//  CreatureHandler.cpp
//  Colony
//
//  Created by Sean on 12/9/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "CreatureHandler.hpp"
#include "Globals.hpp"

//Handles cleanup for when a dead creature dies
//TODO, have to check if it correctly clears the texture memory, and see if anything else in the program still has to be cleared when a creature dies
void RemoveDeadCreature(Map &_map,std::list<BaseCreature> &creatures)
{
    std::list<BaseCreature>::iterator i = lCreatures.begin();
    while (i != lCreatures.end())
    {
        if(i->getBody()->getTotalHealth() < 30)
        {
            _map.Map2D[i->getPosition().x][i->getPosition().y].ClearCreatureOnTile();
            lCreatures.erase(i++);  // alternatively, i = items.erase(i);
        }
        else
        {
            ++i;
        }
    }
}