//
//  SquareDiggingMap.cpp
//  Colony
//
//  Created by Sean on 11/28/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "SquareDiggingMap.hpp"

//Todo for every room, set up the corners and push it into room vector
void SqureDiggingMap::CreateMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height, int wallTileID)
{
    Generate2DMap(_tileSize, _width,_height );
    
    //Fill map with tiles
    for(int i = 0; i < GetWidth(); i++)
        for(int j = 0; j < GetHeight(); j++)
        {
            Map2D[i][j].setTileID(wallTileID);
        }
    LoadTileParameters();
    Group2DGridTiles();
    LoadTileTexture();
    //Generate2DGrid();
}

void SqureDiggingMap::CreateRoom(int roomSize, int roomTileID, sf::Vector2u startingPoint)
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
            
            
            if(isInBounds(sf::Vector2u(newX,newY)))
            {
                Map2D[newX][newY].setTileID(roomTileID);
                
            }
        }
    }
}

//Creates rooms of tile with tile ID
void SqureDiggingMap::CreateRandomRooms(int numberOfRooms, int roomTileID)
{
    
    int roomSize,randX,randY;
    for(int i = 0; i < numberOfRooms; i++)
    {
        
        randX = rand() % GetWidth();
        randY = rand() % GetHeight();
        roomSize =  rand() % MAX_ROOM_SIZE + 1;
        CreateRoom(roomSize,roomTileID, sf::Vector2u(randX,randY));
    }
    
    LoadTileParameters();
    Group2DGridTiles();
    LoadTileTexture();
    
    
}

void SqureDiggingMap::BuildCorridor(int corridorLength, MoveDirection direction, int corridorTileID,sf::Vector2u origin)
{
    
    sf::Vector2u corDir;
    if(direction == Up)
        corDir = sf::Vector2u(0,-1);
    else if(direction == Down)
        corDir= sf::Vector2u(0,1);
    else if(direction == Left)
        corDir = sf::Vector2u(-1,0);
    else if(direction == Right)
       corDir =  sf::Vector2u(1,0);
    
    int curX = origin.x;
    int curY = origin.y;
    for(int i = 0; i < corridorLength; i++)
    {
        curX += corDir.x;
        curY += corDir.y;
        //std::cout << "\nX,y" << curX << "," << curY;
        
        if (isInBounds(sf::Vector2u(curX,curY)))
        {
            Map2D[curX][curY].setTileID(corridorTileID);
        }
        
    }
}

void SqureDiggingMap::CorridorBetweenPoints(sf::Vector2u origin, sf::Vector2u  endPoint)
{
    sf::Vector2u difVec(origin.x - endPoint.x,origin.y - endPoint.y);
 
    
  
    
    
}