//
//  AbstractCreature.cpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "BaseCreature.hpp"
#include "Globals.hpp"
#include "Constants.hpp"

BaseCreature::BaseCreature()
{
    
}

void BaseCreature::loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize)
{
    creatureTile.loadTile(tileset,  sf::Vector2u(tileXSize, tileYSize), sf::Vector2u(position.x, position.y));
}

short int BaseCreature::getAttackValue()
{
    return attackValue;
}

short int BaseCreature::getMeleeAttackValue()
{
    return attackValue + strength;
}

short int BaseCreature::getRangedAttackValue()
{
    return attackValue + agility;
}


short int BaseCreature::getStrength()
{
    return strength;
}

short int BaseCreature::getAgility()
{
    return agility;
}


sf::Vector2u  BaseCreature::getPosition()
{
    return position;
}

sf::Vector2u BaseCreature::getPrevePosition()
{
    return prevPosition;
}

sf::Vector2u BaseCreature::getVelocity()
{
    return velocity;
}

Body* BaseCreature::getBody()
{
    return body;
}

//Need to update both the creatures logical position and the position of its texture
void BaseCreature::setPosition(short int x, short int y)
{
    position.x = x;
    position.y = y;
    
    creatureTile.setPosition(x,y); //Also need to update the vertices of the tile used to represent this creature
    
}

void BaseCreature::setVelocity(int x, int y)
{
    velocity.x = x;
    velocity.y = y;
}

bool BaseCreature::MoveCreature(int x, int y)
{
    
    
    
    prevPosition.x = position.x;
    prevPosition.y = position.y;
    
    int newX = position.x + x;
    int newY = position.y + y;
    bool retVal = 1;
    
    //std::cout << "\n (W,H): " << MAP_WIDTH << "," << MAP_HEIGHT << "\n";
    //std::cout << "Cur (X,Y) " << position.x << "," << position.y << "\n";
    //std::cout << "New (X,Y) " << newX << "," << newY << "\n";
    
    
    if(newX < 0 || newX >= MAP_WIDTH)
    {
        //std::cout << "Width out of bounds\n";
        //creatureTile.setPosition(position.x,position.y);
        retVal = 0;
        
    }
    else if(newY < 0|| newY > MAP_HEIGHT)
    {
        
        //std::cout << "Height out of bounds\n";
        retVal = 0;
        
    }
    else
    {
        
        
        //std::cout << "No out of bounds\n";
        position.x += x;
        position.y += y;
        creatureTile.setPosition(position.x,position.y);
        retVal = 1;
    }
    
    //std::cout << "\n\n";
    return retVal;
    
}

void BaseCreature::setBody(Body *_body)
{
    body = _body;
}