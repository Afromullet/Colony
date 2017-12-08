//
//  Creature.cpp
//  Colony
//
//  Created by Sean on 10/13/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Creature.hpp"



Creature::Creature(BodySchema schema) : bodySchema(schema),attackValue(0),strength(0),agility(0),endurance(0),mind(0),will(0),charisma(0)
{
    
    
    sizeCategory = enMediumCreature;
  
    position.x = 0;
    position.y = 0;
}

Creature::Creature(BodySchema schema,short int _movSpeed,short int bab,short int str, short int dex, short int end, short int _mind,short int _will,short int cha) : bodySchema(schema),moveSpeed(_movSpeed),attackValue(0),strength(str),agility(dex),endurance(end),mind(_mind),will(_will),charisma(cha)
{
    sizeCategory = enMediumCreature;
    position.x = 0;
    position.y = 0;
    
}

void Creature::loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize)
{
    creatureTile.loadCreature(tileset,  sf::Vector2u(tileXSize, tileYSize), sf::Vector2u(position.x, position.y));
}

BodySchema Creature::getBodySchema()
{
    return bodySchema;
}
BodySchema& Creature::getBodySchemaRef()
{
    return bodySchema;
}


short int Creature::getAttackValue()
{
    return attackValue;
}

short int Creature::getMeleeAttackValue()
{
    return attackValue + strength;
}

short int Creature::getRangedAttackValue()
{
    return attackValue + agility;
}


short int Creature::getStrength()
{
    return strength;
}

short int Creature::getAgility()
{
    return agility;
}


sf::Vector2u  Creature::getPosition()
{
    return position;
}

sf::Vector2u Creature::getPrevePosition()
{
    return prevPosition;
}

sf::Vector2u Creature::getVelocity()
{
    return velocity;
}
void Creature::setPosition(short int x, short int y)
{
    position.x = x;
    position.y = y;
 
    
    creatureTile.setPosition(x,y); //Also need to update the vertices of the tile used to represent this creature
    
}

void Creature::setVelocity(int x, int y)
{
    velocity.x = x;
    velocity.y = y;
}


void Creature::setMovementComponent(MovementComponent *_movComponent)
{
    movComponent = _movComponent;
    
}

void Creature::UpdatePosition()
{
    movComponent->update(*this);
    
}


//Return values descripes success of move.
//If move is out of bounds, move does not succeed

//TODO currently uses mainmap. At a later time, generalize this some more
bool Creature::MoveCreature(int x, int y)
{
    
    
    
    prevPosition.x = position.x;
    prevPosition.y = position.y;

    int newX = position.x + x;
    int newY = position.y + y;
    bool retVal = 1;
    
    std::cout << "\n (W,H): " << MAP_WIDTH << "," << MAP_HEIGHT << "\n";
    std::cout << "Cur (X,Y) " << position.x << "," << position.y << "\n";
    std::cout << "New (X,Y) " << newX << "," << newY << "\n";

    
    if(newX < 0 || newX >= MAP_WIDTH)
    {
        std::cout << "Width out of bounds\n";
        //creatureTile.setPosition(position.x,position.y);
        retVal = 0;
        
    }
    else if(newY < 0|| newY > MAP_HEIGHT)
    {
        
        std::cout << "Height out of bounds\n";
        retVal = 0;
        
    }
    else
    {
    
    
        std::cout << "No out of bounds\n";
        position.x += x;
        position.y += y;
        creatureTile.setPosition(position.x,position.y);
        retVal = 1;
    }
    
    std::cout << "\n\n";
    return retVal;
    
}








/*
 This series of functions will be used if I ever implement multiple attacks per limb 
 
 Creature::Creature(BodySchema schema) : bodySchema(schema),baseAttackBonus(0),strength(0),dexterity(0),constitution(0),intelligence(0),wisdom(0),charisma(0)
 {
 baseAttackBonus.push_back(0);
 
 }
 
 Creature::Creature(BodySchema schema,short int bab,short int str, short int dex, short int con, short int intel,short int wis,short int cha) : bodySchema(schema),strength(str),dexterity(dex),constitution(con),intelligence(intel),wisdom(wis),charisma(cha)
 {
 
 int numOfAttacks = 0;
 //If the BAB is at least 6, we need to calculate the number of attacks.
 //For every 6 bab we get one attack
 if(bab >= 6)
 {
 while(bab > 0)
 {
 baseAttackBonus.push_back(bab);
 bab -= 5;
 }
 }
 else
 {
 baseAttackBonus.push_back(bab);
 }
 
 }
 
 BodySchema Creature::getBodySchema()
 {
 return bodySchema;
 }
 
 std::vector<short int> Creature::getBaseAttackBonus()
 {
 return baseAttackBonus;
 }
 
 //Adds strength to the base attack bonus
 std::vector<short int> Creature::getMeleeAttackBonus()
 {
 std::vector<short int>::iterator it;
 std::vector<short int> attackBonus;
 
 for(it = baseAttackBonus.begin(); it != baseAttackBonus.end(); ++it)
 attackBonus.push_back(*it + strength);
 
 return attackBonus;
 
 
 }
 
 //Adds dexterity to the base attack bonus
 std::vector<short int> Creature::getRangedAttackBonus()
 {
 std::vector<short int>::iterator it;
 std::vector<short int> attackBonus;
 
 for(it = baseAttackBonus.begin(); it != baseAttackBonus.end(); ++it)
 attackBonus.push_back(*it + dexterity);
 
 return attackBonus;
 
 }
 
 
 void Creature::printShit()
 {
 std::vector<short int>::iterator it;
 //std::cout << "Bab ";
 for(it = baseAttackBonus.begin(); it != baseAttackBonus.end(); ++it)
 {
 std::cout << *it << "\\";
 }
 
 std::vector<short int> ab = getMeleeAttackBonus();
 std::vector<short int>::iterator abIt;
 
 // std::cout << " Strength : " << strength << " ";
 for(abIt = ab.begin(); abIt != ab.end(); ++abIt)
 {
 // std::cout << *abIt << "\\";
 }
 
 ab = getRangedAttackBonus();
 
 
 //std::cout << " Dexterity : " << dexterity << " ";
 for(abIt = ab.begin(); abIt != ab.end(); ++abIt)
 {
 //std::cout << *abIt << "\\";
 }
 
 
 std::cout << "\n";
 
 }
 
 //Gets the attack bonus of a specific attack. I.E, attackNumber 2 will get the second attack
 //if the attacknumber is greater than the total number of attacks, returns iNVALID_VALUE to indicate invalid condition
 //First attack is attack Number 0
 short int Creature::getMeleeAttack(short int attackNumber)
 {
 
 std::vector<short int> attackBonus = getMeleeAttackBonus();
 if(attackNumber > attackBonus.size() - 1 )
 return INVALID_VALUE;
 else
 return attackBonus.at(attackNumber);
 
 }
 
 //Gets the attack bonus of a specific attack. I.E, attackNumber 2 will get the second attack
 //if the attacknumber is greater than the total number of attacks, returns iNVALID_VALUE to indicate invalid condition
 //First attack is attack Number 0
 short int Creature::getRangedAttack(short int attackNumber)
 {
 
 std::vector<short int> attackBonus = getRangedAttackBonus();
 if(attackNumber > attackBonus.size() - 1 )
 return INVALID_VALUE;
 else
 return attackBonus.at(attackNumber);
 
 }

 */



