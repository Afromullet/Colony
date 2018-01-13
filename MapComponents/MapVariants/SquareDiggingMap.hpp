//
//  SquareDiggingMap.hpp
//  Colony
//
//  Created by Sean on 11/28/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef SquareDiggingMap_hpp
#define SquareDiggingMap_hpp

#include <stdio.h>
#include "Map.hpp"
#include <vector>

#define MAX_ROOM_SIZE 5;

typedef struct _Room
{
    sf::Vector2i corner0;
    sf::Vector2i corner1;
    sf::Vector2i corner2;
    sf::Vector2i corner3;
    sf::Vector2i origin;
}Room;


class SqureDiggingMap : public Map
{
    
private:
    std::vector<Room> rooms; //Contains pointers to the location of the room
public:
    void CreateMap(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height, int wallTileID);
    void CreateRoom(int roomSize, int roomTileID, sf::Vector2i startingPoint);
    void CreateRandomRooms(int numberOfRooms, int roomTileID);
    void BuildCorridor(int corridorLength, MoveDirection direction, int corridorTileID,sf::Vector2i origin);
    
    void CorridorBetweenPoints(sf::Vector2i origin, sf::Vector2i  endPoint);
    
    void RecursiveMazeMap();
    void CreatePassage(int xDir, int yDir);
    
    
};





#endif /* SquareDiggingMap_hpp */
