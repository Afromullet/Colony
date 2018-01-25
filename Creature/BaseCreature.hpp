//
//  AbstractCreature.hpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//



#ifndef AbstractCreature_hpp
#define AbstractCreature_hpp

#include <stdio.h>
#include "EntityTile.hpp"

#include "Map.hpp"
#include <Unordered_Map>
#include "Equipment.hpp"
#include <list>
#include "BodyPart.hpp"


//Contains all of the information needed for an attack
typedef struct _AttackParameters
{
    int attackBonus;
    int damage;
    Weapon *weapon;
    
}AttackParameters;


class Map;


//todo rename..not abstract anymore
class BaseCreature
{
private:
    short int attackValue;
    short int strength;
    short int agility;
    short int endurance;
    short int mind;
    short int will;
    short int charisma;
    short int moveSpeed; //Currently both x and y speed
    
   
    sf::Vector2i velocity; //Represents basic direction..Not used at the moment.
    sf::Vector2i position;
    sf::Vector2i prevPosition; //Not used at the moment
    std::list<AttackParameters> creatureWeaponAttacks; //Holds data on all of the creature attacks so we don't have to recalculate it every time. Filled by body virtual function getAttacks
    
    
    std::list<Item*> creatureItems;
    
    
    
    
public:
    
   // Vision w;
    
    
    BaseCreature();
    int totalHealth;
    std::vector<BodyPart*> bodyPartSchema; //I.E, a humanoid body, a quadruped body. Need to organize the bodyPartSchema in a hierachy so we know what is connected to what. TODO
    
    void addBodyPart(BodyPart bodyPart);
    void addBodyPart(std::vector<BodyPart> &bodyPartVector);
   
    
   // BaseCreature(const BaseCreature &creature);
    
    EntityTile creatureTile;

    
    //TODO add some check to ensure the creature tile is initialized
    void loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize);
    
    //For calculating creature attributes and attacks
    void CalculateAttackParameters();
    void CalculateTotalHealth();
    
    //Getters
    short int getAttackValue();
    short int getMeleeAttackValue();
    short int getRangedAttackValue();
    short int getStrength();
    short int getAgility();
    sf::Vector2i  getPosition();
    sf::Vector2i  getPrevePosition();
    sf::Vector2i getVelocity();
    std::list<AttackParameters> getAttacks();
    std::vector<BodyPart*> getBodyPartSchema();
    
    //Setters
    void setPosition(short int x, short int y);
    void setVelocity(int x, int y);
    void setStrength(int _strength);
    void setAgility(int _agility);
    
    
    //Movement related
    bool MoveCreature(int x, int y);
    
    //Inventory management
    void AddItemToInventory(Item *item);
    void PrintInventory();
    void PrintEquipment();
    void Equip(Item *item);
    void EquipItemFromInventory(int n); //Equips item number n from inventory, n being the position in the list
    std::string GetItemInfo(int n);
    void PickupItem(Map &map,std::list<Item*> &itemList);
    std::list<Item*> getInventory();

   
    bool isAlive; //For testing
    
    //Combat related
    void AttackCreature(int attackBonus, int damage);
    

    
};



#endif /* AbstractCreature_hpp */
