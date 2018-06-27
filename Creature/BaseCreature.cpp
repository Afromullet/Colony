//
//  AbstractCreature.cpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "BaseCreature.hpp"
#include "BodyGraphGetters.hpp"
#include "Globals.hpp"
#include "Constants.hpp"


//todo replace raw pointers with unique ptr

BaseCreature::BaseCreature()
{
    totalHealth = 50;
    isAlive = true;
    attackValue = 0;
    strength = 10;
    agility = 10;
    endurance = 10;
    mind = 10;
    will = 10;
    charisma = 10;
    moveSpeed = 1;
   
    
}


//TODO, ensure that the tile is loaded every time a creature is placed on a map. We do not have to load the tile until the creature has to be displayed on the map
void BaseCreature::loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize)
{
    creatureTile.loadTile(tileset,  sf::Vector2i(tileXSize, tileYSize), sf::Vector2i(position.x, position.y));
}


void BaseCreature::calculateAttackParameters()
{
    AttackStats attackStats;
    
    std::vector<int> verts =  getVerticesThatCanHoldWeapons(body.anatomyGraph);
    
    for(int i=0; i < verts.size(); i++)
    {
        
        if(body.anatomyGraph[verts.at(i)].getWeaponRef() == NO_WEAPON ||body.anatomyGraph[verts.at(i)].getWeaponRef() == WEAPON_SLOT_FILLED)
            continue;
        attackStats.range = body.anatomyGraph[verts.at(i)].getWeaponRef().getRange();
        attackStats.damage = body.anatomyGraph[verts.at(i)].getWeaponRef().getDamage();
        
        std::cout << "\nweapon damage " <<  attackStats.damage;
        
        
        
        //A spear may have a range greater than 1, but it's not a ranged weapon, whcih is why that distinction is made
        
        std::cout << "\n Is Ranged " << body.anatomyGraph[verts.at(i)].getWeaponRef().isRangedWeapon();
        if(body.anatomyGraph[verts.at(i)].getWeaponRef().isRangedWeapon())
        {
            attackStats.attackValue = getRangedAttackValue();
            
            attackStats.damage += getAgility();
            attackStats.isRangedAttack = true;
        }
        else
        {
            attackStats.attackValue = getMeleeAttackValue();
            
            attackStats.damage += getStrength();
            attackStats.isRangedAttack = false;
            attackStats.force = CalculateMeleeAttackForce(body.anatomyGraph[verts.at(i)].getWeaponRef());
            attackStats.contactArea = body.anatomyGraph[verts.at(i)].getWeaponRef().getSize(); //TODO get size based on attack type
        }
        
        
        attacks.push_back(attackStats);
        
        
    }
    
    for(int i = 0; i < attacks.size(); i++)
    {
        std::cout << "\n Damage at the end " << attacks.at(i).damage;
    }
    
}

/*
 Acceleration Calculation:
 
 Melee attack velocity, unlike ranged attacks, is not calculated. It would be far too much trouble to worry about an objects changing velocity
 so I'll calculate acceleraton differently (acceleration being derived from velocity)
 
 Heavier weapiers are harder to swing.
 
 
 
 */
float BaseCreature::CalculateMeleeAttackForce(Weapon &weapon)
{
    float force;
    float acceleration;
    
    //A smaller weapon can be swung faster, that's why we divide by size
    acceleration = (strength + weapon.getMaterialRef().getDensity());
    
    force = weapon.getMass() * acceleration;
    
    return force;
    
}

//Does bound checking against the global MAP_WIDTH and MAP_HEIGHT
//TODO, consider passing width and height as a parameter so the class does not depend
//On outside values
bool BaseCreature::MoveCreature(int x, int y)
{
    int newX = position.x + x;
    int newY = position.y + y;
    bool retVal = 1;
    
    //Is the bound checking really needed? Boundary checking should be done outside the class
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
        
        std::cout << "\n" << i << ": Item Name: " << (*itemIt)->getItemName() << " Item Type " << "\n";
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
            //  Equip(*itemIt);
            break;
        }
        i++;
        
    }
    
    
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

//Just using rand to determne what body part to attack. TODO, choose random body part to attacj a better way than rand()
void BaseCreature::AttackCreature(int attackBonus, int damage)
{
    
    /*
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
     */
}

void BaseCreature::AddToPath(sf::Vector2i point)
{
    path.emplace(point);
}


//Every time this is called, pops a point off the queue and moves the creature
//Does not currently handle movement if a creature is on the tile or if it cannot hold a creature
void BaseCreature::WalkPath(Map &map)
{
    
    if(path.size() == 0)
        return;
    
    sf::Vector2i tempPoint = path.front();
    
    if(!map.isInBounds(tempPoint))
        return;
    
    if(!map.canHoldCreature(tempPoint))
        return;
    
    if(map.isCreatureOnTile(tempPoint))
        return;
    
    path.pop();
    
    map.Map2D[position.x][position.y].ClearCreatureOnTile();
    
    
    setPosition(tempPoint.x, tempPoint.y);
    map.Map2D[position.x][position.y].SetCreatureOnTile(this);
    
}



void BaseCreature::clearPath()
{
    while(!path.empty())
    {
        path.pop();
    }
}



short int BaseCreature::getMeleeAttackValue() const
{
    return attackValue + strength;
}

short int BaseCreature::getRangedAttackValue() const
{
    return attackValue + agility;
}

short int BaseCreature::getStrength() const
{
    return strength;
}

short int BaseCreature::getAgility() const
{
    return agility;
}

sf::Vector2i  BaseCreature::getPosition() const
{
    return position;
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



std::list<Item*> BaseCreature::getInventory()
{
    return creatureItems;
}



short int BaseCreature::getAttackValue() const
{
    return attackValue;
}



int BaseCreature::getTotalHealth() const
{
    return totalHealth;
}

Vision& BaseCreature::getVision() 
{
    return vision;
}


std::vector<AttackStats>& BaseCreature::getAttacks()
{
    return attacks;
}

//Need to update both the creatures logical position and the position of its texture
void BaseCreature::setPosition(short int x, short int y)
{
    position.x = x;
    position.y = y;
    
    creatureTile.setPosition(x,y); //Also need to update the vertices of the tile used to represent this creature
    
}


void BaseCreature::setStrength(int _strength)
{
    strength = _strength;
}

void BaseCreature::setAgility(int _agility)
{
    agility = _agility;
}


void BaseCreature::setTotalHealth(int _health)
{
    totalHealth = _health;
}






