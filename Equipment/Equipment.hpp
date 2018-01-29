//
//  Equipment.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "EnumTypes.hpp"
#include "EntityTile.hpp"


#ifndef Equipment_hpp
#define Equipment_hpp



//TODO rename enbodypart to something that indicates it is the body part the equipment fits to

//TODO...GetEquipmentParameters. Returns a hashtable of equipment parameters. Whenever this funtion is called, it is up to the user to parse those parameters. I.E



class Item
{

private:
    friend class Armor;
    friend class Weapon;
    int itemID; //Need a way to identify an item of a specific kind for bookeeping and accounting
    int material;
    EnumBodyPart enFitsBodyPart;
    EnItemType enItemType;
    std::string sEquipmentName;
    sf::Vector2i position; //Is this a good idea? The position of an object does not matter if it's on a creature. Is the space this uses worth making managing items on the map easier?
    
    
    
  
    
public:
    
    bool isEquipped;
    EntityTile itemTile; //Every item needs a tile for when it is represented on the map. Need to ensure that we distinguish between an item on the map and worn by the player. todo
    
    Item(int _material, EnumBodyPart _enFitsBodyPart, std::string _sEquipmentName);
    
    Item(std::string equipmentName, EnItemType _itemType);
    Item();
    virtual Item *clone() const = 0;
    virtual Item *create() const  = 0;
    
    
    //virtual ~Item(){};
    //virtual void calculateMaterialBonuses() = 0;
    
    //virtual Item* clone() const = 0;

    std::string getItemName();
    EnumBodyPart getBodyPart();
    sf::Vector2i getPosition();
    virtual std::string getItemExamineString() = 0;
    
    void setItemName(std::string value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumBodyPart value);
    void setPosition(int x, int y); //For setting the position of the item when it's on the map
    void setItemID(int id);
    void setItemType(EnItemType itemType);
    void setIsEquipped(bool _isEquipped);
    
    bool getIsEquipped();
    EnItemType getItemType();
    int getItemID();
    EntityTile &getTile();
    
    EntityTile tile;
    
    //int localItemID; //ItemID is the unique key identifying an item of a particular type. localItemID helps us identify the instance of the item. Public data field for testing. todo remove
    
    std::string name; //Public right now..make getters and setters later
    
    virtual void CalculateMaterialBonuses() = 0;
    virtual void showItemStats() = 0;
    
    
    
   

    
    
  
    
    
    
};

#endif /* Equipment_hpp */
