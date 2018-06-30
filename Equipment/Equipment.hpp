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
#include "Material.hpp"



//TODO rename enbodypart to something that indicates it is the body part the equipment fits to

//TODO...GetEquipmentParameters. Returns a hashtable of equipment parameters. Whenever this funtion is called, it is up to the user to parse those parameters. I.E



class Item
{

private:
    friend class Armor;
    friend class Weapon;
    
    sf::Vector2i position; //Is this a good idea? The position of an object does not matter if it's on a creature. Is the space this uses worth making managing items on the map easier?
    
    float size; //Volume
    float mass;
    std::string section;
    Material material;
    std::string sEquipmentName;
    bool isEquipped;
    
    
  
    //Why do I have tile and itemtile?
    
   
    
    
public:
    
    
    EntityTile itemTile; //The texture of this item
    EntityTile tile;
    std::vector<std::string> sections; //The sections this armor covers

    //Overloaded operators
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
    void operator=(const Item &other);
    
    Item(Material _material,std::string _sEquipmentName);
    Item(std::string equipmentName);
    Item(std::string equipmentName, std::string _section);
    Item();
    Item(const Item &other);
    
    
    virtual ~Item(){}
    virtual Item *clone() const = 0;
    virtual Item *create() const  = 0;
    
    virtual void showItemStats() const = 0;
    virtual std::string getItemExamineString() const = 0;
    

    

    
    void CalculateMaterialBonuses();
    
    std::string getItemName() const;
    sf::Vector2i getPosition() const;
    float getMass() const;
    float getSize() const;
    bool getIsEquipped() const;
    std::string getSection() const;
    Material getMaterial() const;
    Material &getMaterialRef() ;
    EntityTile &getTile();
    
    void addSection(std::string value);
    void setItemName(std::string value);
    void setMaterial(Material value);
    void setPosition(int x, int y); //For setting the position of the item when it's on the map
    void setIsEquipped(bool _isEquipped);
    void setMass(float _mass);
    void setSize(float _size);
    void setSection(std::string _section);
    bool isValidSection(std::string _section);

    
    
   
    

    
  
    
    
 
   
  
    
    
   

    
    
  
    
    
    
};

#endif /* Equipment_hpp */
