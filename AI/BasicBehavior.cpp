//
//  BasicBehavior.cpp
//  Colony
//
//  Created by Sean on 2/17/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BasicBehavior.hpp"
#include "Pathfinding.hpp"

bool ApproachCreature(Map &map,BaseCreature &approacher,BaseCreature &target)
{
    bool retVal = false;
    
    GridLocation start,end;
    start = approacher.getGridLocation();
    end = target.getGridLocation();
    approacher.clearPath();
    std::vector<sf::Vector2i> neighbors = GetPNeighbors(sf::Vector2i(end.x,end.y),map,false);
    
    //Select a random open neighboring tile.

    sf::Vector2i targetPos;
    while(!neighbors.empty())
    {
        int randNum = rand() % neighbors.size();
        targetPos = neighbors.at(randNum);
    
        if(map.Map2D[targetPos.x][targetPos.y].getCanHoldCreature() && !map.Map2D[targetPos.x][targetPos.y].isCreatureOnTile())
        {
 
            end.x = targetPos.x;
            end.y = targetPos.y;
            retVal = true;
            break;
        }
        
        neighbors.erase(neighbors.begin()+randNum);
    }
    
    std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(map,  start,  end);
    std::vector<GridLocation> path = recontructPath(start,end, cameFrom);

    
    return retVal;
    
    
    
}

bool ApproachTile(Map &map,BaseCreature &approacher,sf::Vector2i position)
{
    bool retVal = false;
    
    GridLocation start,end;
    start = approacher.getGridLocation();
    end.x = position.x;
    end.y = position.y;
    approacher.clearPath();
    
    if(!map.Map2D[end.x][end.y].getCanHoldCreature() || !map.Map2D[end.x][end.y].getCreatureOnTile())
    {
        retVal = false;
    }
    else
    {
        retVal = true;
        
        std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(map,  start,  end);
        std::vector<GridLocation> path = recontructPath(start,end, cameFrom);
        
        for(int i =0; i < path.size(); i++)
        {
            approacher.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
        }
        
        
        
    }
    
    return retVal;
}

bool GetItemBehavior(Map &map,BaseCreature &creature)
{
    
    std::vector<Tile> tiles = creature.vision.getVisibleTiles(map);
    std::vector<sf::Vector2i>  coords = creature.vision.getVisibleCoordinates(map);
    
    
    
    GridLocation start,end;
    start = creature.getGridLocation();
    creature.clearPath();
    std::map<GridLocation,GridLocation> cameFrom;
    std::vector<GridLocation> path;// = recontructPath(start,end, cameFrom);

    
    GridLocation targetPos;
    //For now just pick the first available item to get the behavior owrking
    for(int i =0; i < coords.size(); i++)
    {
      
        if(map.Map2D[coords.at(i).x][coords.at(i).y].getItemOnTile() != NULL && map.Map2D[coords.at(i).x][coords.at(i).y].getCanHoldCreature() && !map.Map2D[coords.at(i).x][coords.at(i).y].isCreatureOnTile())
        {
            std::cout << "Found item\n";
            end.x = coords.at(i).x;
            end.y = coords.at(i).y;
            cameFrom =  aStarSearch(map,  start,  end);
            path = recontructPath(start,end, cameFrom);
            
            for(int i =0; i < path.size(); i++)
            {
                creature.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
            }
            
            break;
        }
        
    }
    
    
    

}
