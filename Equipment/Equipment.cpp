//
//  Equipment.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Equipment.hpp"
#include "ErrorConstants.hpp"


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
}


Item::Item(Material _material, std::string _sEquipmentName): material(_material),sEquipmentName(_sEquipmentName),isEquipped(false)
{
    
}

Item::Item(std::string equipmentName) : sEquipmentName(equipmentName)
{
    
}


Item::Item(std::string equipmentName, std::string _section) : sEquipmentName(equipmentName), section(_section)
{
    
}



Item::Item() : material(),sEquipmentName(ERROR_STRING_INPUT),isEquipped(false)
{
    size = ERROR_INPUT_NUMBER;
    mass = ERROR_INPUT_NUMBER;
    section = ERROR_STRING_INPUT;
    
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


void Item::addSection(std::string value)
{
    sections.push_back(value);
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
    
    tile.setPosition(x, y);
    position.x = x;
    position.y = y;
    
}



void Item::setIsEquipped(bool _isEquipped)
{
    isEquipped = _isEquipped;
}

void Item::setMass(float _mass)
{
    if(mass < 0)
        return;
    
    mass = _mass;
}

void Item::setSize(float _size)
{
    if(size < 0)
        return;
    
    size = _size;
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






