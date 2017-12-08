//
//  MovementHandler.cpp
//  Colony
//
//  Created by Sean on 11/26/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "MovementHandler.hpp"



int InMapBoundaries(Map &map,int newX, int newY)
{
    
    int retVal;
    if(newX < 0 || newX >= map.GetWidth())
    {
       // //std::cout << "Width out of bounds\n";
        //creatureTile.setPosition(position.x,position.y);
        retVal = 0;
        
    }
    else if(newY < 0|| newY > map.GetHeight())
    {
        
       // //std::cout << "Height out of bounds\n";
        retVal = 0;
        
    }
    else
    {
        retVal = 1;
    }
    
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


void MovePlayer(MoveDirection moveDirection, BaseCreature &_creature,Map &map)
{
    sf::Vector2u direction(0,0);
    int newX = _creature.getPosition().x;
    int newY = _creature.getPosition().y;
    

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
        
        
        
        std::cout << "bo\n";
        
       
        
        if(map.Map2D[newX][newY].getCreatureOnTile() == NULL)
        {
          std::cout << "aa\n";
      

            
            
            
        }
        else
        {
            std::cout << "Attacking \n";
            //PlayerAttackCreature(_creature, *map.Map2D[newX][newY].GetCreaturesOnTile());
            // //std::cout << "\n Creature already in tile\n";
        }
        
    }
    
}
/*
//Todo better random movement generation
//Tie this into MovementComponent for Creature
void MoveCreatureRandomly(Map &map)
{
    
   
    int newX, newY;
    sf::Vector2u direction(0,0);
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

//Todo resolve collisions
void AddCreatureToMap(Map &map)
{
    //map.Map2D[_creature->getPosition().x][_creature->getPosition().y].SetCreatureOnTile(_creature);
}
*/