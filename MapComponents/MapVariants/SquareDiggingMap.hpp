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
    sf::Vector2u corner0;
    sf::Vector2u corner1;
    sf::Vector2u corner2;
    sf::Vector2u corner3;
    sf::Vector2u origin;
}Room;


class SqureDiggingMap : public Map
{
    
private:
    std::vector<Room> rooms; //Contains pointers to the location of the room
public:
    void CreateMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height, int wallTileID);
    void CreateRoom(int roomSize, int roomTileID, sf::Vector2u startingPoint);
    void CreateRandomRooms(int numberOfRooms, int roomTileID);
    void BuildCorridor(int corridorLength, MoveDirection direction, int corridorTileID,sf::Vector2u origin);
    
    void CorridorBetweenPoints(sf::Vector2u origin, sf::Vector2u  endPoint);
    
    void RecursiveMazeMap();
    void CreatePassage(int xDir, int yDir);
    
    
};





#endif /* SquareDiggingMap_hpp */
