//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"

Item::Item(int _material, EnumBodyPart _enFitsBodyPart, std::string _sEquipmentName): material(_material),enFitsBodyPart(_enFitsBodyPart),sEquipmentName("no name"),isEquipped(false)
{
    
}

Item::Item(std::string equipmentName, EnItemType _itemType) : sEquipmentName(equipmentName), enItemType(_itemType)
{
    
}



Item::Item() : material(1),enFitsBodyPart(enUndefinedPart),sEquipmentName("no name"),isEquipped(false)
{
    
}

EnumBodyPart Item::getBodyPart()
{
    return enFitsBodyPart;
}

std::string Item::getItemName()
{
    //std::cout << "Inside item name " << sEquipmentName;
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

void Item::setFitsBodyPart(EnumBodyPart value)
{
    enFitsBodyPart = value;
    
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

int Item::getItemID()
{
    return itemID;
}

void Item::setItemID(int id)
{
    itemID = id;
}