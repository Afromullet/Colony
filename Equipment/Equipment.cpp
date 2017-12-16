//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"

Item::Item(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName): material(_material),enFitsBodyPart(_enFitsBodyPart),sEquipmentName(_sEquipmentName)
{
    
}


Item::Item() : material(1),enFitsBodyPart(enUndefinedBodyPart),sEquipmentName(2)
{
    
}

EnumFitsBodyPart Item::getBodyPart()
{
    return enFitsBodyPart;
}

int Item::getItemName()
{
    return sEquipmentName;
}
 
sf::Vector2u Item::getPosition()
{
    return position;
}


void Item::setItemName(int value)
{
    sEquipmentName = value;
}
 

void Item::setMaterial(int value)
{
    material = value;
    
}

void Item::setFitsBodyPart(EnumFitsBodyPart value)
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

int Item::getItemID()
{
    return itemID;
}

void Item::setItemID(int id)
{
    itemID = id;
}