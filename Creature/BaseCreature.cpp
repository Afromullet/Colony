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
    isAlive = true;
}


/*
 TODO copy constructor
BaseCreature::BaseCreature(const BaseCreature &creature)
{
    body = creature.body;
    position = creature.position;
    creatureTile = creature.creatureTile;
}
 */

//TODO, ensure that the tile is loaded every time a creature is placed on a map. We do not have to load the tile until the creature has to be displayed on the map
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

//Does bound checking against the global MAP_WIDTH and MAP_HEIGHT
//TODO, consider passing width and height as a parameter so the class does not depend
//On outside values
bool BaseCreature::MoveCreature(int x, int y)
{
    
    
    //Not used at the moment, so don't pay attention to this.
    prevPosition.x = position.x;
    prevPosition.y = position.y;
    
    int newX = position.x + x;
    int newY = position.y + y;
    bool retVal = 1;
    
    if(newX < 0 || newX >= MAP_WIDTH)
        retVal = 0;
    else if(newY < 0|| newY > MAP_HEIGHT)
        retVal = 0;
    else
    {
        position.x += x;
        position.y += y;
        creatureTile.setPosition(position.x,position.y);
        retVal = 1;
    }
    
    
    return retVal;
    
}

void BaseCreature::setBody(Body *_body)
{
    body = _body;
    
}

void BaseCreature::AddItemToInventory(Item *item)
{
    creatureItems.push_back(item);
}

void BaseCreature::CloneBody(Body *_body)
{
    body = _body->clone();
}

void BaseCreature::PrintInventory()
{
    std::list<Item*>::iterator itemIt;
    std::cout << "\nPrinting inventory\n";
    int i = 0;
    for(itemIt = creatureItems.begin(); itemIt != creatureItems.end(); ++itemIt)
    {
        std::cout << "\n" << i << ": Item Name: " << (*itemIt)->getItemType() << " Item Type" << (*itemIt)->getItemType();
        i++;
    }
}

//Equips item number n from inventory, n being the position in the list
void BaseCreature::EquipItemFromInventory(int n)
{
    std::list<Item*>::iterator itemIt;
    std::cout << "\nPrinting inventory\n";
    int i = 0;
    for(itemIt = creatureItems.begin(); itemIt != creatureItems.end(); ++itemIt)
    {
        if(i == n)
        {
            std::cout << "\nEquipping item number " << i << "compare to " << n;
            body->EquipItem(*itemIt);
            std::cout << "Equipped";
            break;
        }
 
    }
}


