//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"
#include "ErrorConstants.hpp"
#include "UtilMacros.h"
#include <boost/uuid/uuid_generators.hpp>
#include "Constants.hpp"
//Overloaded operators

bool Item::operator==(const Item &other) const
{
    
    //Nested If make it more readable
    if(sEquipmentName == other.sEquipmentName && isEquipped == other.isEquipped 
       && material == other.material && size == other.size && mass == other.mass &&
       section == other.section)
    {
        if(itemTile == other.itemTile)
        {
            //TODO check if comparing vectors like this works
            if(sections == other.sections)
                return true;
        }
        
    }
    return false;
}


bool Item::operator!=(const Item &other) const
{
    return !(*this == other);
}


void Item::operator=(const Item &other)
{
    sEquipmentName = other.sEquipmentName;
    isEquipped = other.isEquipped;
    itemTile = other.itemTile;
    material = other.material;
    size = other.size;
    mass = other.size;
    sections = other.sections;
    section = other.section;
    tag = boost::uuids::random_generator()();
    stackSize = other.stackSize;
    maxStackSize = other.maxStackSize;
    descriptiveText = other.descriptiveText;

}


 Item::Item()
{
    isEquipped = false;
    tag = boost::uuids::random_generator()();
    itemTile.loadTile(ERROR_TILE_LOCATION, sf::Vector2i(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE), position);

}

Item::Item(Material _material, std::string _sEquipmentName,EnItemType itType): material(_material),sEquipmentName(_sEquipmentName),isEquipped(false)
{
    
    tag = boost::uuids::random_generator()();
    enItemType = itType;
    stackSize = 1;
    maxStackSize = 99;
}








Item::Item(const Item &other)
{
    sEquipmentName = other.sEquipmentName;
    isEquipped = other.isEquipped;
    itemTile = other.itemTile;
    material = other.material;
    size = other.size;
    mass = other.size;
    sections = other.sections;
    section = other.section;
    stackSize = other.stackSize;
    maxStackSize = other.maxStackSize;
    descriptiveText = other.descriptiveText;
    
}




void Item::CalculateMaterialBonuses()
{
    
    mass = material.getDensity() * size; //Density = mass * volume
}


std::string Item::getItemName() const
{
    return sEquipmentName;
}



 
sf::Vector2i Item::getPosition() const
{
    return position;
}

float Item::getMass() const
{
    return mass;
}

float Item::getSize() const
{
    return size;
}


std::string Item::getSection() const
{
    return section;
}

Material Item::getMaterial() const
{
    return material;
}

Material &Item::getMaterialRef()  
{
    return material;
}

bool Item::getIsEquipped() const
{
    return isEquipped;
}

boost::uuids::uuid Item::getTag()
{
    return tag;
}

EnItemType Item::getItemType()
{
    return enItemType;
}

int Item::getStackSize()
{
    return stackSize;
}

int Item::getMaxStackSize()
{
    return maxStackSize;
}

std::string Item::getDescriptiveText() const
{
    return descriptiveText;
}

void Item::UpdateTileTexture(const std::string &textureLocation,sf::Vector2i tileSize)
{
    itemTile.loadTile(textureLocation,tileSize,position);
}

//TODO add check to not allow duplicate sections
void Item::addSection(std::string value)
{
    if(std::find(sections.begin(),sections.end(),value) == sections.end())
    {
        sections.push_back(value);
    }
    
}

void Item::setItemName(std::string value)
{
    sEquipmentName = value;
}
 

void Item::setMaterial(Material value)
{
    material = value;
    
}

//For setting the position of the item when it's on the map
void Item::setPosition(int x, int y)
{
    
    itemTile.setPosition(x, y);
    position.x = x;
    position.y = y;
    
}



void Item::setIsEquipped(bool _isEquipped)
{
    isEquipped = _isEquipped;
}

void Item::setMass(float _mass)
{
    mass = IS_NUM_GT_0(_mass);
}

void Item::setSize(float _size)
{
  
    size = IS_NUM_GT_0(_size);
}

void Item::setSection(std::string _section)
{
    section = _section;
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

void Item::setTag(boost::uuids::uuid val)
{
   
    tag = val;
}

void Item::setItemType(EnItemType val)
{
     enItemType = val;
}

void Item::setStackSize(int val)
{
    stackSize = IS_NUM_GT_0(val);
}

void Item::setMaxStackSize(int val)
{
    maxStackSize = IS_NUM_GT_0(val);
}

void Item::setDescriptiveText(std::string str)
{
    descriptiveText = str;
}

void Item::IncrementStackSize()
{
    ++stackSize;
}

void Item::DecrementStackSize()
{
    --stackSize;
}





