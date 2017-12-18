//
//  Equipment.hpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Equipment_hpp
#define Equipment_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "EnumTypes.hpp"
#include "EntityTile.hpp"

//TODO rename enbodypart to something that indicates it is the body part the equipment fits to

//TODO...GetEquipmentParameters. Returns a hashtable of equipment parameters. Whenever this funtion is called, it is up to the user to parse those parameters. I.E

class Item
{

private:
    int itemID; //Need a way to identify an item of a specific kind for bookeeping and accounting
    int material;
    EnumFitsBodyPart enFitsBodyPart;
    EnItemType enItemType;
    int sEquipmentName;
    sf::Vector2u position; //Is this a good idea? The position of an object does not matter if it's on a creature. Is the space this uses worth making managing items on the map easier?
    
    bool isEquipped;
    
  
    
public:
    
    EntityTile itemTile; //Every item needs a tile for when it is represented on the map. Need to ensure that we distinguish between an item on the map and worn by the player. todo
    
    Item(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName);
    Item();
    //virtual ~Item(){};
    //virtual void calculateMaterialBonuses() = 0;
    
    //virtual Item* clone() const = 0;

    int getItemName();
    EnumFitsBodyPart getBodyPart();
    sf::Vector2u getPosition();
    
    void setItemName(int value);
    void setMaterial(int value);
    void setFitsBodyPart(EnumFitsBodyPart value);
    void setPosition(int x, int y); //For setting the position of the item when it's on the map
    void setItemID(int id);
    void setItemType(EnItemType itemType);
    void setIsEquipped(bool _isEquipped);
    
    bool getIsEquipped();
    EnItemType getItemType();
    int getItemID();
    EntityTile &getTile();
    
    EntityTile tile;
    
    int localItemID; //ItemID is the unique key identifying an item of a particular type. localItemID helps us identify the instance of the item. Public data field for testing
    
    std::string name; //Public right now..make getters and setters later
    
    virtual void CalculateMaterialBonuses() = 0;
    
   

    
    
  
    
    
    
};

#endif /* Equipment_hpp */
