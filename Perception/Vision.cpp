//
//  Vision.cpp
//  Colony
//
//  Created by Sean on 1/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Vision.hpp"
//
//  Vision.hpp
//  Colony
//
//  Created by Sean on 1/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//



#include <stdio.h>

#include "Vision.hpp"

//For now vision is a square

Vision::Vision()
{
    
}


Vision::Vision(sf::Vector2i _origin)
{
    origin = _origin;
}


//Todo return only the indexes into the map
std::vector<Tile> Vision::getVisibleTiles(Map &map)
{
    std::vector<Tile> tempTiles;
    for(int i=0; i < visionArea.size(); i++)
    {
        
        
        if(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getCreatureOnTile() != NULL)
        {
            tempTiles.push_back(map.Map2D[visionArea.at(i).x][visionArea.at(i).y]);
        }
        
    }
    

    
    
    return tempTiles;
    
}
//Todo maybe return indices into creaturesOnMap rather than copying everything
std::vector<BaseCreature> Vision::getVisibleCreatures(Map &map)
{
    
    std::vector<BaseCreature> tempCreatures;
    for(int i=0; i < visionArea.size(); i++)
    {
       
        
        if(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getCreatureOnTile() != NULL)
        {
            tempCreatures.push_back(*map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getCreatureOnTile());
        }
        
    }
    
    

    
    return tempCreatures;

}




std::vector<Item*> Vision::getVisibleItems(Map &map)
{
    std::vector<Item*> tempItems;
    for(int i=0; i < visionArea.size(); i++)
    {
        
        
        if(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getItemOnTile() != NULL)
        {
            tempItems.push_back(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getItemOnTile());
        }
        
    }
    

    
    
    return tempItems;
    
}


std::vector<GridLocation> Vision::getVisibleItemLocation(Map &map)
{
    std::vector<GridLocation> tempItems;
    GridLocation loc;
    for(int i=0; i < visionArea.size(); i++)
    {
        
        
        if(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getItemOnTile() != NULL)
        {
            loc.x = visionArea.at(i).x;
            loc.y = visionArea.at(i).y;
            tempItems.push_back(loc);
        }
        
    }
    
    
    
    
    return tempItems;
    
}

std::vector<GridLocation> Vision::getVisibleCreatureLocation(Map &map)
{
    std::vector<GridLocation> tempItems;
    GridLocation loc;
    for(int i=0; i < visionArea.size(); i++)
    {
        
        
        if(map.Map2D[visionArea.at(i).x][visionArea.at(i).y].getCreatureOnTile() != NULL)
        {
            loc.x = visionArea.at(i).x;
            loc.y = visionArea.at(i).y;
            tempItems.push_back(loc);
        }
        
    }
    
    
    
    
    return tempItems;
    
}



std::vector<sf::Vector2i> Vision::getVisibleCoordinates(Map &map)
{
    std::vector<sf::Vector2i> tempVec;
    for(int i=0; i < visionArea.size(); i++)
    {
        tempVec.push_back(sf::Vector2i(visionArea.at(i).x,visionArea.at(i).y));
    }
    
    return tempVec;
}

//If origin changes, vision area must also be updated
void Vision::UpdateVision(Map &map,sf::Vector2i newOrigin)
{
    
 
    origin = newOrigin;
    visionArea.clear();
    
    int count = 0;
    for(int i=-1; i<5; i++)
        for(int j=-1; j<5; j++)
        {
            if(map.isInBounds(sf::Vector2i(origin.x+ i,origin.y+j)))
               visionArea.push_back(sf::Vector2i(origin.x+ i,origin.y+j));
        }
    
    
     
}

void Vision::setOrigin(sf::Vector2i newOrigin)
{
    origin = newOrigin;
}

sf::Vector2i Vision::getOrigin()
{
    return origin;
}




