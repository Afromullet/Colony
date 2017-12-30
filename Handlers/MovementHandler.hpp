//
//  MovementHandler.hpp
//  Colony
//
//  Created by Sean on 11/26/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef MovementHandler_hpp
#define MovementHandler_hpp


//Handles creature movement..maybe in the future, I should define interaction between a creture and a map in another class or file where the functions describe the interactions between the classes

#include <stdio.h>

#include "Map.hpp"
#include "BaseCreature.hpp"
bool InMapBoundaries(Map &map,int newX, int newY);


//Whenever a creature moves, it has to go through this handler to determine
//whether the move is successful. Currently, not yet an object..This is a prototype. Once the basics have been worked out, I'll organize it differently

void MovePlayer(MoveDirection moveDirection, BaseCreature &_creature,Map &map);
void MoveCreatureRandomly(BaseCreature *_creature,Map &map);

/*
void MoveCreature(MoveDirection moveDirection, Creature &_creature,Map &map);
 */


void AddCreatureToMap(Map &map, BaseCreature *_creature);


#endif /* MovementHandler_hpp */
