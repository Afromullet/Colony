//
//  MapEffect.cpp
//  Colony
//
//  Created by Sean on 1/12/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "MapEffect.hpp"
#include <iostream>
sf::VertexArray EMPTY_VERTEXARAY;
std::vector<sf::Vector2i> EMPTY_TILEPOSITION;



bool MapEffect::operator==(const MapEffect &other) const
{
    if(id == other.id)
        return true;
    return false;
}



MapEffect::MapEffect(int _id,sf::VertexArray vertArray) : id(_id),vertices(vertArray),color(sf::Color::Transparent),squareSize(0)
{
    
}

MapEffect::MapEffect(const MapEffect &effect) : vertices(effect.vertices),id(effect.id),color(effect.color),squareSize(0)
{

}

MapEffect::MapEffect() : vertices(EMPTY_VERTEXARAY),squareSize(0)
{
    
}

//Doesn't get the vertices right now, those have to be set separetely
void MapEffect::MoveShape(int xOffset,int yOffset)
{
    
    //TODO, don't hardcode the 32..Supposed to be default_tile_size
    
    int vertexCounter = 0;
    for(int i=0; i < tilePositions.size(); i++)
    {
        tilePositions.at(i).x += xOffset;
        tilePositions.at(i).y += yOffset;
        
    }
    
    
}






void MapEffect::addTilePositions(std::vector<sf::Vector2i> newPositions)
{
    for(int i=0; i < newPositions.size(); i++)
    {
        tilePositions.push_back(newPositions.at(i));
    }
}

void MapEffect::addTilePositions(sf::Vector2i newPosition)
{
    tilePositions.push_back(newPosition);
}

std::vector<sf::Vector2i> MapEffect::getShape(sf::Vector2i position,int n)
{
    
    
    sf::Vector2i tempPos;
    std::vector<sf::Vector2i> tempVec;
    
    //For now, calculates with origin at the bottom left corner..
    //TODO, change it to be at origin of square...for that, just translate the origin..when the player gives an origin, subtract 1 from x and y
    
    int its = 0;
    for(int i = position.x; i < position.x + n; i++)
    {
        for(int j = position.y; j < position.y + n; j++)
        {
                tempPos.x = i;
                tempPos.y = j;
                tempVec.push_back(tempPos);
        }
    }
    
    return tempVec;
}

std::vector<sf::Vector2i> MapEffect::getLine(int x0, int y0, int x1, int y1)
{
    int dx =  abs(x1-x0);
    int sx = x0<x1 ? 1 : -1;
    int dy = -abs(y1-y0);
    int sy = y0<y1 ? 1 : -1;
    int err = dx+dy;
    int e2; /* error value e_xy */
    
    std::vector<sf::Vector2i> tempPoints;
    
    sf::Vector2i tempPos;
    
    int i = 0;
    for(;;){  /* loop */
        std::cout << x0 <<  "," << y0 << "\n";
        
        
        tempPos.x = x0;
        tempPos.y = y0;
        tempPoints.push_back(tempPos);
        
        
        if (x0==x1 && y0==y1) break;
        e2 = 2*err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        
        if (e2 <= dx)
        {   err += dx;
            y0 += sy;
        } /* e_xy+e_y < 0 */
        i++;
    }
    
    return tempPoints;
}


std::vector<sf::Vector2i> MapEffect::getTilePositions()
{
    return tilePositions;
}

int MapEffect::getID()
{
    return id;
}

int MapEffect::getSquareSize()
{
    return squareSize;
}

sf::Color MapEffect::getColor()
{
    return color;
}

int MapEffect::getRadius()
{
    return radius;
}

void MapEffect::setColor(sf::Color newColor) 
{
    color = newColor;
    for(int i = 0; i < vertices.getVertexCount(); i++)
    {
        vertices[i].color = newColor;
    }
}

void MapEffect::setID(int _id)
{
    id = _id;
}

void MapEffect::setTilePositions(std::vector<sf::Vector2i> newPositions)
{
    tilePositions = newPositions;
}

//Sets the x and y position of the square itself, not the vertices. The function creates a square of size n
//The vertices have to be set separately..Need to ensure a way the vertices are set before the class is used
void MapEffect::setSquare(sf::Vector2i position,int n)
{
    
    
    sf::Vector2i tempPos;
    std::vector<sf::Vector2i> tempVec;
    
    origin.x = position.x;
    origin.y = position.y;
    
    //For now, calculates with origin at the bottom left corner..
    //TODO, change it to be at origin of square...for that, just translate the origin..when the player gives an origin, subtract 1 from x and y
    tilePositions.clear();
    int its = 0;
    for(int i = position.x; i < position.x + n; i++)
    {
        for(int j = position.y; j < position.y + n; j++)
        {
            tempPos.x = i;
            tempPos.y = j;
            tilePositions.push_back(tempPos);
            
        }
        
    }
    
    enShape = enCircle;
    squareSize = n;
    
}



//Sets the x and y position of the square itself, not the vertices. The function creates a square of size n
//The vertices have to be set separately..Need to ensure a way the vertices are set before the class is used
void MapEffect::setLine(sf::Vector2i position,int n,MoveDirection movDirection)
{
    
    
    sf::Vector2i offset;
    sf::Vector2i tempPos = position;
    
    std::vector<sf::Vector2i> tempVec;
    origin.x = position.x;
    origin.y = position.y;
    
    //For now, calculates with origin at the bottom left corner..
    //TODO, change it to be at origin of square...for that, just translate the origin..when the player gives an origin, subtract 1 from x and y
    tilePositions.clear();
    
    if(movDirection == Up)
    {
        offset.x = 0;
        offset.y = -1;
    }
    else if(movDirection == Down)
    {
        offset.x = 0;
        offset.y = 1;
    }
    else if(movDirection == Left)
    {
        offset.x = -1;
        offset.y = 0;
    }
    else if(movDirection == Right)
    {
        offset.x = 1;
        offset.y = 0;
    }
    
    
    for(int i = 0; i <  n; i++)
    {
        
        tempPos.x += offset.x;
        tempPos.y += offset.y;
        tilePositions.push_back(tempPos);
            
        
        
    }
    
    squareSize = n;
    enShape = enLine;
    
}


void MapEffect::setLine(int x0, int y0, int x1, int y1)
{
    int dx =  abs(x1-x0);
    int sx = x0<x1 ? 1 : -1;
    int dy = -abs(y1-y0);
    int sy = y0<y1 ? 1 : -1;
    int err = dx+dy;
    int e2; /* error value e_xy */
    
    tilePositions.clear();
    std::vector<sf::Vector2i> tempVec;
    sf::Vector2i tempPos;
    origin.x = x0;
    origin.y = x1;
    
    
    int i = 0;
    for(;;){  /* loop */
        std::cout << x0 <<  "," << y0 << "\n";
        
        
        tempPos.x = x0;
        tempPos.y = y0;
        tilePositions.push_back(tempPos);

   
        if (x0==x1 && y0==y1) break;
        e2 = 2*err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        
        if (e2 <= dx)
        {   err += dx;
            y0 += sy;
        } /* e_xy+e_y < 0 */
        i++;
    }
    
    enShape = enLine;
    
}

void MapEffect::setCircle(int xm, int ym, int r)
{
    int x = -r;
    int y = 0;
    tilePositions.clear();
    std::vector<sf::Vector2i> tempVec;
    sf::Vector2i tempPos;
    
    if(r <= 1)
        radius = 1;
    else
        radius = r;
    
    origin.x = xm;
    origin.y = ym;
    
    
    
    int err = 2-2*r; /* II. Quadrant */
    do {
        
        tempPos.x = xm-x;
        tempPos.y = ym+y;
        tilePositions.push_back(tempPos);
        
        tempPos.x = xm-y;
        tempPos.y = ym-x;
        tilePositions.push_back(tempPos);
        
        tempPos.x = xm+x;
        tempPos.y = ym-y;
        tilePositions.push_back(tempPos);
        
        tempPos.x = xm+y;
        tempPos.y = ym+x;
        tilePositions.push_back(tempPos);
       
    
        r = err;
        if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
        if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
    } while (x < 0);
    

    enShape = enCircle;;
}

void MapEffect::setSquareSize(int val)
{
    squareSize = val;
}


sf::Vector2i MapEffect::getRandomPointInCircle()
{
   // int x = rand() % radius + (-radius) + origin.x;
  //  int y = rand() % radius + (-radius) + origin.y;
    

    int x = rand() % radius ;
    int y = rand() % radius ;
    
    int xSelection = rand() % 1;
    int ySelection = rand() % 2;
    
    //So that we don't only draw in positive direction..Point can be x,-x,y,-y
    if(xSelection == 0)
        x *= -1;
    if(ySelection == 0)
        y *= -1;

    

    std::cout << "\n Radius " << radius;
    std::cout << "\n Origin: " << + origin.x << "," <<  origin.y;
    std::cout << "\n New x and y" << x + origin.x << "," << y + origin.y<< "\n";
    
    
    return sf::Vector2i(x + origin.x,y + origin.y);
}



