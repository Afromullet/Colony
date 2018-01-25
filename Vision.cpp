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




//std::vector<Tile*> getVisibleTiles(Map &map);
//Todo use pointer
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
    
    if(tempCreatures.size() > 0)
        std::cout << "\nCreatures nearby";
    else
        std::cout << "\n No creatures nearby";
    
    return tempCreatures;

}



std::vector<BaseCreature> Vision::getVisibleItems(Map &map)
{
    
}

//If origin changes, vision area must also be updated
void Vision::UpdateVision(Map &map,sf::Vector2i newOrigin)
{
    
 
    origin = newOrigin;
    visionArea.clear();
    
    int count = 0;
    for(int i=-1; i<2; i++)
        for(int j=-1; j<2; j++)
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




