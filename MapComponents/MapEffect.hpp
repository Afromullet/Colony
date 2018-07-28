//
//  MapEffect.hpp
//  Colony
//
//  Created by Sean on 1/12/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef MapEffect_hpp
#define MapEffect_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "EnumTypes.hpp"


//TODO initialize soem values and use that for error checking in the classs
extern sf::VertexArray EMPTY_VERTEXARAY;
extern std::vector<sf::Vector2i> EMPTY_TILEPOSITION;

//An effect has a tile position and a vertices position. it's essentially another layer on top of the map
enum Shape{enSquare,enCircle,enLine};

class MapEffect
{
    
private:
   
    
    Shape enShape;
    int squareSize;
    int id;
    sf::Color color;
   
    
public:

    
    std::vector<sf::Vector2i> tilePositions;
    sf::VertexArray vertices;

    
    
    
    
    
    
    bool operator==(const MapEffect &other) const;
    

    MapEffect(const MapEffect &effect);
    MapEffect(int _id,sf::VertexArray vertArray);
    MapEffect();

    void setColor(sf::Color newColor);
    void setID(int _id);
    void setTilePositions(std::vector<sf::Vector2i> newPositions);
    void addTilePositions(std::vector<sf::Vector2i> newPositions);
    void addTilePositions(sf::Vector2i newPosition);
    
    
    std::vector<sf::Vector2i> getShape(sf::Vector2i position,int n) ;
    std::vector<sf::Vector2i> getLine(int x0, int y0, int x1, int y1) ;
    int getSquareSize() ;
    int getID() ;
    sf::Color getColor() ;
    
    
    void setSquare(sf::Vector2i position,int n) ;
    void setLine(sf::Vector2i position,int n,MoveDirection movDirection);
    void setLine(int x0, int y0, int x1, int y1);
    void setCircle(int xm, int ym, int r);
    void setSquareSize(int val);
    
   
    
    
    
    
    
    //Removes out of bounds tiles
    void RemoveOOBTiles();
    void MoveShape(int xOffset,int yOffset);
    void MoveLine(int xOffset,int yOffset);
    
    
    
    
    
    
};

#endif /* MapEffect_hpp */
