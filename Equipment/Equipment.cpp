//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"

Item::Item(int _material, std::string _sEquipmentName): material(_material),sEquipmentName("no name"),isEquipped(false)
{
    
}

Item::Item(std::string equipmentName, EnItemType _itemType) : sEquipmentName(equipmentName), enItemType(_itemType)
{
    
}


Item::Item(std::string equipmentName, std::string _section) : sEquipmentName(equipmentName), section(_section)
{
    
}



Item::Item() : material(1),sEquipmentName("no name"),isEquipped(false)
{
    
}



std::string Item::getItemName()
{
    return sEquipmentName;
}
 
sf::Vector2i Item::getPosition()
{
    return position;
}


void Item::setItemName(std::string value)
{
    sEquipmentName = value;
}
 

void Item::setMaterial(int value)
{
    material = value;
    
}



//For setting the position of the item when it's on the map
void Item::setPosition(int x, int y)
{
    tile.setPosition(x, y);
    position.x = x;
    position.y = y;
    
}
void Item::setItemType(EnItemType itemType)
{
    enItemType = itemType;
}

EnItemType Item::getItemType()
{
    return enItemType;
}

void Item::setIsEquipped(bool _isEquipped)
{
    isEquipped = _isEquipped;
}

bool Item::getIsEquipped()
{
    return isEquipped;
}

bool Item::isValidSection(std::string _section)
{
    for(int i =0 ; i < sections.size(); i++)
    {
        if(sections.at(i) == _section)
            return true;
    }
    
    return false;
}


