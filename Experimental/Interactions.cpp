 //
//  Interactions.cpp
//  Colony
//
//  Created by Sean on 11/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Interactions.hpp"



void CreatureMovesToTile(BaseCreature &creature, Map &map, MoveDirection direction)
{
    int newX = creature.getPosition().x, origX = creature.getPosition().x;
    int newY = creature.getPosition().y, origY = creature.getPosition().y;
    
    
    //if(!InMapBoundaries(map, newX, newY))
      //  return;
    
    switch(direction)
    {
        case Up:
            newY -= 1;
            break;
        case Left:
            newX -= 1;
            break;
        case Right:
            newX += 1;
            break;
        case Down:
            newY += 1;
            break;
    }

    
    Tile &tile = map.Map2D[newX][newY];
    
    if (!tile.isCreatureOnTile())
    {
        
        map.Map2D[origX][origY].ClearCreatureOnTile();
        creature.setPosition(newX,newY);
        tile.SetCreatureOnTile(&creature);
        //creature.setPosition
        
        //if(tile.hadMapEffect) apply mapEffect
    }
    else
    {
        //
        
        CreatureToCreature(creature, *tile.getCreatureOnTile());
    }
}

//What this requires is a way to determine the type of response. For now,
//Just use a simple switching mechanism to get things working
void CreatureToCreature(BaseCreature &initiator, BaseCreature &receiver)
{
    CreatureAttacksCreature(initiator,receiver);
}

void CreatureAttacksCreature(BaseCreature &attacker, BaseCreature &defender)
{
    std::cout << "\n Attacking";
    
    attacker.calculateAttackParameters();
    std::vector<AttackStats> attacks = attacker.getAttacks();

    
    if(attacks.size() > 0)
    {
        AttackStats attack;
        int randNum = rand() % 3;
        
        if(randNum == 0)
        {
            attack = attacker.GetAttack(enBlunt);
        }
        else if(randNum == 1)
        {
            attack = attacker.GetAttack(enSlash);
    
        }
        else if(randNum == 2)
        {
       
            attack = attacker.GetAttack(enPierce);
        }
        
        
     
        
       //For testing purposes, randomly select the attack type
        std::cout << "\n" << getAttackString(attacker,defender,attack);
       Single_Attack_Melee(attack,defender);
        
    }
}
