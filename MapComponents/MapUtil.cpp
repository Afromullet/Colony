//
//  MapUtil.cpp
//  Colony
//
//  Created by Sean on 11/28/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "MapUtil.hpp"

#include "Map.hpp"


void CreateRoom(Map &map,int roomSize, int roomTileID, sf::Vector2u startingPoint)
{
    int newX,newY;
    
    //roomSize = 0;
    int iterations = 0;
    for(int i = -roomSize; i < roomSize; i++)
    {
        for(int j = -roomSize; j < roomSize; j++)
        {
            newX = startingPoint.x + i;
            newY = startingPoint.y + j;
            
            
            
           // map.Map2D[newX][newY].setTileID(roomTileID);

            if(map.isInBounds(sf::Vector2u(newX,newY)))
            {
                map.Map2D[newX][newY].setTileID(roomTileID);

            }
        }
    }
}