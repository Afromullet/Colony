//
//  MovementHandler.cpp
//  Colony
//
//  Created by Sean on 11/26/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "MovementHandler.hpp"


/*
 Checks the maps width and height and determines if the (x,y) pair is in the bounds of the map
 Does not work correctly atm, fix that todo, low priority, for current testing I am doing it doesn't make a difference
 */
bool InMapBoundaries(Map &map,int newX, int newY)
{
    
    bool retVal;
    if(newX < 0 || newX >= map.GetWidth())
        retVal = false;
    else if(newY < 0|| newY > map.GetHeight())
        retVal = false;
    else
        retVal = true;
    
    return retVal;

}
 


/*
void MoveCreature(MoveDirection moveDirection, Map &map)
{
    sf::Vector2u direction(0,0);
    int newX,newY;
    
    switch(moveDirection)
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
    
    

    
    if(InMapBoundaries(map,newX,newY))
    {
       
       
        if(map.Map2D[newX][newY].GetCreaturesOnTile() == NULL)
        {
            
          
            map.Map2D[_creature.getPosition().x][_creature.getPosition().y].ClearCreatureOnTile(); //Clear previous tile
            _creature.setPosition(newX, newY);
            map.Map2D[_creature.getPosition().x][_creature.getPosition().y].SetCreatureOnTile(&_creature);
            
            
            
        }
        else
        {
           // //std::cout << "\n Creature already in tile\n";
        }
    }

}
*/

//TODO fix bounary checking
void MovePlayer(MoveDirection moveDirection, BaseCreature &_creature,Map &map)
{
    sf::Vector2u direction(0,0);
    int newX = _creature.getPosition().x;
    int newY = _creature.getPosition().y;
    
    
    if(!InMapBoundaries(map, newX, newY))
        return;
    
    switch(moveDirection)
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
    
   ;
    
    //If the new position cannot hold a creature, there's no point in detemining further action
    //TODO, consider removing this in the future in case you want to add some tile-manipulating actions, i.e, removing a wall.
    
    if(!map.Map2D[newX][newY].getCanHoldCreature())
        return;
    if(InMapBoundaries(map,newX,newY))
    {
        if(map.Map2D[newX][newY].getCreatureOnTile() == NULL)
        {
            _creature.setPosition(newX, newY);
        }
        else
        {
            std::cout << "Attacking \n";
            
            //Currently does not handle choosing a weapon or calculating the damage and attack bonus from creature parameters TODO change that
            //map.Map2D[newX][newY].getCreatureOnTile()->getBody()->AttackRandomBodyPart(5, 1);
            map.Map2D[newX][newY].getCreatureOnTile()->AttackCreature(10, 5);
            //AttackCreature(_creature, *map.Map2D[newX][newY].getCreatureOnTile());
            
        }
        
    }
    
}

//Todo better random movement generation
//Tie this into MovementComponent for Creature
//A very random way of movement generation. Mainly for testing
void MoveCreatureRandomly(BaseCreature *_creature,Map &map)
{
    
   
    int newX = _creature->getPosition().x;
    int newY = _creature->getPosition().y;

    //For random direction generation
    int plusOrMinus = rand() % 2;
    int randDirection = rand() % 2;
    int X_Y_OrBoth = rand() % 3; //Horrible variable name..To determine randomly whether we adjust x, y, or both
    
    
    
    if(plusOrMinus == 0)
    {
        
        if(X_Y_OrBoth == 0)
        {
            newX += randDirection;
            newY += randDirection;
        }
        else if(X_Y_OrBoth == 1)
        {
            newX += randDirection;
        }
        else if(X_Y_OrBoth == 2)
        {
            newY += randDirection;
        }
    }
    else if(plusOrMinus == 1)
    {
        if(X_Y_OrBoth == 0)
        {
            newX -= randDirection;
            newY -= randDirection;
        }
        else if(X_Y_OrBoth == 1)
        {
            newX -= randDirection;
            
        }
        else if(X_Y_OrBoth == 2)
        {
            newY -= randDirection;
        }
    }
    
    if(InMapBoundaries(map,newX,newY))
    {
        
        if(map.Map2D[newX][newY].getCreatureOnTile() == NULL)
        {
            map.Map2D[_creature->getPosition().x][_creature->getPosition().y].ClearCreatureOnTile(); //Clear previous tile
            _creature->setPosition(newX, newY);
            map.Map2D[_creature->getPosition().x][_creature->getPosition().y].SetCreatureOnTile(_creature);
        }
        else
        {
           // //std::cout << "\n Creature already in tile\n";
        }
    }
    
}



//Todo resolve collisions
void AddCreatureToMap(Map &map, BaseCreature *_creature)
{
    map.Map2D[_creature->getPosition().x][_creature->getPosition().y].SetCreatureOnTile(_creature);
}
