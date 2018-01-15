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


//todo replace raw pointers with unique ptr

BaseCreature::BaseCreature()
{
    totalHealth = 0;
    isAlive = true;
    
}

void BaseCreature::addBodyPart(BodyPart bodyPart)
{
    bodyPartSchema.push_back(&bodyPart);
}

//Copies an entire schema to the creatures bodyParts.
void BaseCreature::addBodyPart(std::vector<BodyPart> &bodyPartVector)
{
    //Probably a better way to do this todo
    for(int i = 0; i < bodyPartVector.size(); i++)
        bodyPartSchema.push_back(&bodyPartVector.at(i));
    
    

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
    creatureTile.loadTile(tileset,  sf::Vector2i(tileXSize, tileYSize), sf::Vector2i(position.x, position.y));
}

void BaseCreature::CalculateAttackParameters()
{
    
    creatureWeaponAttacks = getAttacks();
    std::list<AttackParameters>::iterator attacksIt;
    int counter = 0;
    for(attacksIt = creatureWeaponAttacks.begin(); attacksIt != creatureWeaponAttacks.end(); ++attacksIt)
    {
        if(attacksIt->weapon->isRangedWeapon())
        {
            attacksIt->damage += agility;
            attacksIt->attackBonus = getRangedAttackValue();
        }
        else
        {
            attacksIt->damage += strength;
            attacksIt->attackBonus = getMeleeAttackValue();
        }
        counter++;
    }
    
}

void BaseCreature::CalculateTotalHealth()
{
    
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        totalHealth += bodyPartSchema.at(i)->getHealth();
    }
    
    
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

sf::Vector2i  BaseCreature::getPosition()
{
    return position;
}

sf::Vector2i BaseCreature::getPrevePosition()
{
    return prevPosition;
}

sf::Vector2i BaseCreature::getVelocity()
{
    return velocity;
}

//Doesn't have an attack bonus yet since that is calculated based on creature attacks
//TODO,  make the initialization of attackParameters simpler
std::list<AttackParameters> BaseCreature::getAttacks()
{
    std::list<AttackParameters> attackParameters;
    AttackParameters tempAttackParams;
    
    
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        
        // if(bodyPartSchema.at(i))
        
        tempAttackParams.damage = bodyPartSchema.at(i)->weapon.getDamage();
        tempAttackParams.weapon = bodyPartSchema.at(i)->weapon.clone();
        
        if(tempAttackParams.weapon->getWeaponClass() == enUndefinedWeaponClass)
            continue;
        
        ///Need to implement checks, and handle weapon fitting to a body part slot a better way
        attackParameters.push_back(tempAttackParams);
    }
    
    return attackParameters;
    
}

std::vector<BodyPart*> BaseCreature::getBodyPartSchema()
{
    return bodyPartSchema;
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

void BaseCreature::setStrength(int _strength)
{
    strength = _strength;
}

void BaseCreature::setAgility(int _agility)
{
    agility = _agility;
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

void BaseCreature::AddItemToInventory(Item *item)
{
    creatureItems.push_back(item);
}

void BaseCreature::PrintInventory()
{
    std::list<Item*>::iterator itemIt;
    std::cout << "\nPrinting inventory\n";
    int i = 0;
    for(itemIt = creatureItems.begin(); itemIt != creatureItems.end(); ++itemIt)
    {
  
        std::cout << "\n" << i << ": Item Name: " << (*itemIt)->getItemName() << " Item Type " << (*itemIt)->getItemType() << "\n";
        i++;
    }
}


void BaseCreature::PrintEquipment()
{
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        std::cout << "\nBody Part Name: " << bodyPartSchema.at(i)->bodyPartName << " Armor Name: " << bodyPartSchema.at(i)->armor.getItemName() << "  Weapon Name: " << bodyPartSchema.at(i)->weapon.getItemName() << "\n";
    }
}


void BaseCreature::Equip(Item *item)
{
    for(int i = 0; i < bodyPartSchema.size(); i++)
    {
        if(bodyPartSchema.at(i)->enBodyPartType == item->getBodyPart())
        {
            bodyPartSchema.at(i)->EquipItem(item);
            break;
        }
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
            Equip(*itemIt);
            break;
        }
        i++;
 
    }
    

}

//Equips item number n from inventory, n being the position in the list
std::string BaseCreature::GetItemInfo(int n)
{
    std::list<Item*>::iterator itemIt;
    std::cout << "\nPrinting inventory\n";
    int i = 0;
    std::string tempString = "" ;
    for(itemIt = creatureItems.begin(); itemIt != creatureItems.end(); ++itemIt)
    {
        if(i == n)
        {
            
            tempString = (*itemIt)->getItemExamineString();
            
            break;
        }
        i++;
        
    }
    
    return tempString;
    
    
}

 //Picks up item at current position (if there is one) and adds it to the creatures inventory. TODO, determine whether there should be a class for creature and map interaction, or whether it's better to just pass the map as a reference
void BaseCreature::PickupItem(Map &map,std::list<Item*> &itemList)
{
 Tile *tile = &map.Map2D[position.x][position.y];
 
 if(tile->getItemOnTile() == NULL)
 {
     std::cout << "No item on tile";
 }
 else
 {
     //TODO, need to handle removing item from itemList
    // int localID = tile->getItemOnTile()->localItemID; //So we can find it in the list
     //std::cout << "\nID " << localID << "\n";
 
     creatureItems.push_back(tile->getItemOnTile()); //TODO, need a different way to handle pushing the itme back, because when we remove it from the itemlist, we still want it in the creatureItems..both are pointers, so we need to do some copying. Create a copy constructor that handles this
     //tile->SetItemOnTile(NULL);
     std::list<Item*>::iterator iter;
 
     
     int count = 0;
     for(iter = itemList.begin(); iter != itemList.end(); ++iter)
     {
         
         
        //Identify item through its local ID. TODO ensure that local ID is unique
         //Probably pick from a bin of random numbers of all possible local ids
         if((*iter) == tile->getItemOnTile())
         {
             
         
            itemList.erase(iter);
             map.Map2D[position.x][position.y].SetItemOnTile(NULL);
             
             
             break;
         }
 
         ++count;
     }
     
     std::cout << "Picking up item";
 }
 
}


std::list<Item*> BaseCreature::getInventory()
{
    return creatureItems;
}




//Just using rand to determne what body part to attack. TODO, choose random body part to attacj a better way than rand()
void BaseCreature::AttackCreature(int attackBonus, int damage)
{
    
    
    int randNum = rand() % bodyPartSchema.size();
    
    if(attackBonus >= bodyPartSchema.at(randNum)->getArmor().siGetArmorBonus())
    {
        std::cout << "Hit";
        bodyPartSchema.at(randNum)->ApplyDamage(damage);
        totalHealth -= damage;
        std::cout << "\nTotal health left " << totalHealth;
    }
    else
    {
        std::cout << "Miss";
    }
}


