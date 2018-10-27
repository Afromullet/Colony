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
#include <list>
#include <Unordered_Map>

#include "BodyPart.hpp"
#include "EnumTypes.hpp"
#include "Vision.hpp"
#include <queue>
#include "Pathfinding.hpp"
#include "Bodygraph.hpp"

#include "ItemManager.hpp"

#include "Message.hpp"




struct DefenseStats
{
    int vertexIndex; //So we know what to apply to the body part under the armor
    std::string section;
    Armor &armor;
    
};

class Map;



//todo rename..not abstract anymore
class BaseCreature : public Message
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
    int totalHealth;
    sf::Vector2i position;
    std::list<Item*> creatureItems;
    std::queue<sf::Vector2i> path; //A queue holding the path a creature walks
    Vision vision;
    bool isAlive; //For testing
    std::vector<AttackStats> attacks;
    
    bool canMove;
    
    
    
    
    
    
public:
    
    
    
    ItemManager inventory;
    
    CreatureBody body;
    
    
    BaseCreature();
    BaseCreature(const BaseCreature &other);
    BaseCreature(BaseCreature &other);
    


   // BaseCreature(const BaseCreature &creature);
    
    EntityTile creatureTile;

    
    //TODO add some check to ensure the creature tile is initialized
    void loadCreatureTile(const std::string& tileset, int tileXSize,int tileYSize);

    void CalculateTotalHealth();
    //Movement related
    bool MoveCreature(int x, int y);
    
    //Inventory management
    void AddItemToInventory(Item *item);
    void AddArmorToInventory(Armor val);
    void AddWeaponToInventory(Weapon val);
    
    
    void PrintInventory();
    void PrintEquipment();
    void Equip(Item *item);
    void EquipItemFromInventory(int n); //Equips item number n from inventory, n being the position in the list
    void EquipItem(int i);
    
    void PickupItem(Map &map,std::list<Item*> &itemList);
    void AttackCreature(int attackBonus, int damage);
    void AddToPath(sf::Vector2i point);
    void WalkPath(Map &map);
    void clearPath();
    void calculateAttackParameters();
    float CalculateMeleeAttackForce(Weapon &weapon);
    
    
    //Getters

    short int getMeleeAttackValue()  const;
    short int getRangedAttackValue() const;
    short int getStrength() const;
    short int getAgility() const;
    short int getAttackValue() const;
    sf::Vector2i  getPosition() const;
    std::string GetItemInfo(int n) ;
    int getTotalHealth() const;
    std::list<Item*> getInventory();
    Vision &getVision();
    std::vector<AttackStats> &getAttacks();
    bool getCanMove() const;
    
    
    

    //Setters
    void setPosition(short int x, short int y);
    void setVelocity(int x, int y);
    void setStrength(int _strength);
    void setAgility(int _agility);
    void setTotalHealth(int _health);
    void setCanMove(bool val);

    void ReleaseInventoryMemory();
    
    void SendMessage();
    
};



#endif /* AbstractCreature_hpp */
