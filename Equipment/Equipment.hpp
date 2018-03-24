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
    
    
   
    int material;
  
 
    sf::Vector2i position; //Is this a good idea? The position of an object does not matter if it's on a creature. Is the space this uses worth making managing items on the map easier?
    
    
    
    
  
    
public:
    std::string sEquipmentName;
    bool isEquipped;
    EntityTile itemTile; //The texture of this item
    
    std::vector<std::string> sections; //The sections this armor covers
    
 
    std::string section;
    
    Item(int _material,std::string _sEquipmentName);
    
    Item(std::string equipmentName);
    Item(std::string equipmentName, std::string _section);
    Item();
    virtual Item *clone() const = 0;
    virtual Item *create() const  = 0;
    
    std::string getItemName();
    sf::Vector2i getPosition();
    virtual std::string getItemExamineString() = 0;
    
    void setItemName(std::string value);
    void setMaterial(int value);

    void setPosition(int x, int y); //For setting the position of the item when it's on the map
    

    void setIsEquipped(bool _isEquipped);
    
    bool getIsEquipped();

    
    
    bool isValidSection(std::string _section);

    EntityTile &getTile();
    
    EntityTile tile;
    
      
    std::string name; //Public right now..make getters and setters later
    
    virtual void CalculateMaterialBonuses() = 0;
    virtual void showItemStats() = 0;
    
    
    
   

    
    
  
    
    
    
};

#endif /* Equipment_hpp */
