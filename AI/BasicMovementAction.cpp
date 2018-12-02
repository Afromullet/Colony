//
//  BasicMovementAction.cpp
//  Colony
//
//  Created by Sean on 11/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BasicMovementAction.hpp"
#include "Pathfinding.hpp"


BasicMovementAction::BasicMovementAction(BaseCreature &c, Map &m,std::vector<GridLocation> newPath) : creature(c), map(m)
{
    
    sf::Vector2i point;
    for(int i = 0; i < newPath.size(); i++)
    {
        point.x = newPath.at(i).x;
        point.y = newPath.at(i).y;
        path.emplace(point);
    }
}

BasicMovementAction::BasicMovementAction(const BasicMovementAction &other) : Action(priority), creature(other.creature),map(other.map),path(other.path)
{

}

void BasicMovementAction::Execute()
{
    if(path.size() == 0)
    {
        
        actionComplete = true;
        return;
        
    }
    
    sf::Vector2i tempPoint = path.front();
    
    if(!map.isInBounds(tempPoint))
    {
        path.pop();
        return;
        
    }
    
    if(!map.canHoldCreature(tempPoint))
    {
        path.pop();
        return;
    }
    
    if(map.isCreatureOnTile(tempPoint))
    {
        return;
    }
    
    path.pop();
    
    map.Map2D[creature.getPosition().x][creature.getPosition().y].ClearCreatureOnTile();
    
    
    creature.setPosition(tempPoint.x, tempPoint.y);
    map.Map2D[creature.getPosition().x][creature.getPosition().y].SetCreatureOnTile(&creature);
}

