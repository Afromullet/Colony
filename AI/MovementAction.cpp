//
//  MovementAction.cpp
//  Colony
//
//  Created by Sean on 3/22/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "MovementAction.hpp"





BasicMovementAction::BasicMovementAction(Map &_map,BaseCreature &_creature) : AbstractAction(_map,_creature)
{
    
}




bool BasicMovementAction::PrepareAction()
{
    if(getDestinationsSize() == 0)
        return false;
    
    GridLocation start,end;
    start.x = creature.getPosition().x;
    start.y = creature.getPosition().y;

    end.x = getDestination(0).x;
    end.y = getDestination(0).y;
    
    

    std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(map,  start,  end);
    
    
    
    movementPath = recontructPath(start,end, cameFrom);
    
    for(int i=0; i < movementPath.size(); i++)
    {
        creature.AddToPath(sf::Vector2i(movementPath.at(i).x,movementPath.at(i).y));
        
    }
    
  
   
}




//Always moves to the first location in destinations vector
//Should really be using a queue for this...

bool BasicMovementAction::PerformAction()
{
    
    creature.WalkPath(map);
    /*
 
     std::cout << "\n New Movement Path Size " << movementPath.size();
    if(movementPath.size() == 0)
    {
        std::cout << "\n mov path 0";
        return false;
        
    }
    
    sf::Vector2i tempPoint;
    tempPoint.x = AbstractMovementAction::getDestination(0).x;
    tempPoint.y = AbstractMovementAction::getDestination(0).y;
    
    if(!map.isInBounds(tempPoint) || !map.canHoldCreature(tempPoint) ||map.isCreatureOnTile(tempPoint) )
        return false;
    

    
    map.Map2D[creature.getPosition().x][creature.getPosition().y].ClearCreatureOnTile();
    
    
    
    
    creature.setPosition(tempPoint.x, tempPoint.y);
    map.Map2D[tempPoint.x][tempPoint.y].SetCreatureOnTile(&creature);
    
    */
    
    
    //AbstractMovementAction::getDestinationsSize()
    
    
    
}
