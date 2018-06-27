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

bool Vision::operator==(Vision &other) const
{
    if(origin == other.origin && visionArea == other.visionArea)
        return true;
    
    return false;
}

bool Vision::operator!=(Vision &other) const
{
    return !(*this == other);
}

bool Vision::operator=(Vision &other)
{
    origin = other.origin;
    visionArea = other.visionArea;
}


Vision::Vision()
{
    
}


Vision::Vision(sf::Vector2i _origin)
{
    origin = _origin;
}

Vision::Vision(const Vision &other)
{
    origin = other.origin;
    visionArea = other.visionArea;
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





//Todo return only the indexes into the map
std::vector<Tile> Vision::getVisibleTiles(Map &map) const
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
std::vector<BaseCreature> Vision::getVisibleCreatures(Map &map) const
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


std::vector<GridLocation> Vision::getVisibleItemLocation(Map &map) const
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

std::vector<GridLocation> Vision::getVisibleCreatureLocation(Map &map) const
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



std::vector<sf::Vector2i> Vision::getVisibleCoordinates(Map &map) const
{
    std::vector<sf::Vector2i> tempVec;
    for(int i=0; i < visionArea.size(); i++)
    {
        tempVec.push_back(sf::Vector2i(visionArea.at(i).x,visionArea.at(i).y));
    }
    
    return tempVec;
}

sf::Vector2i Vision::getOrigin() const
{
    return origin;
}


void Vision::setOrigin(sf::Vector2i newOrigin)
{
    origin = newOrigin;
}






