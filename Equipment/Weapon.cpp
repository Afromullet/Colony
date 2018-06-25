//
//  Weapon.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Weapon.hpp"
#include "ErrorConstants.hpp"

bool Weapon::operator==(const Weapon &other) const
{
    if(siRange == other.siRange && siDamage == other.siDamage && sEquipmentName == other.sEquipmentName && position == other.position && isRanged == other.isRanged)
    {
       
        if(size == other.size && mass == other.mass && section == other.section &&
           material == other.material && sEquipmentName == other.sEquipmentName && isEquipped == other.isEquipped)
        {
            return true;
        }
        
    }
    return false;
}


bool Weapon::operator!=(const Weapon &other) const
{
    return !(*this == other);
}

void Weapon::operator=(const Weapon &other)
{
    position = other.position;
    
    sEquipmentName = other.sEquipmentName;
    siRange = other.siRange;
    siDamage = other.siDamage;
    contactArea = other.contactArea;
    isTwohanded = other.isTwohanded;
    isRanged = other.isRanged;
    
    size = other.size;
    mass = other.mass;
    section = other.section;
    material = other.material;
    isEquipped = other.isEquipped;
    
}

//todo add "Blank" weapon for when no weapon is equipped..and also something to identify a two handed weapon is equipped
Weapon::Weapon(Material _material, std::string _sEquipmentName, short int _siRange,short int _siDamage):
        Item::Item(_material,_sEquipmentName),
        siRange(_siRange),siDamage(_siDamage)
{




}


Weapon::Weapon() : Item(Material(),"Fist Weapon"),siRange(1),siDamage(1),contactArea(1)
{
    
    size = 0;
    mass = 0;
   
}


Weapon::Weapon(std::string _itemname,std::string _section) : Item(_itemname,_section) {
    
}



Weapon::Weapon(const Weapon &weapon)
{
  
    position = weapon.position;
   
    sEquipmentName = weapon.sEquipmentName;
    siRange = weapon.siRange;
    siDamage = weapon.siDamage;
    contactArea = weapon.contactArea;
    isTwohanded = weapon.isTwohanded;
    isRanged = weapon.isRanged;
    
    size = weapon.size;
    mass = weapon.mass;
    section = weapon.section;
    material = weapon.material;
    isEquipped = weapon.isEquipped;
}


void Weapon::showItemStats() const
{
    
    std::cout << "Item Name" << getItemName()<< "\n";
    std::cout << "Damage" << siDamage << "\n";
    std::cout << "Range" <<  siRange<< "\n";
    
    
}

std::string Weapon::getItemExamineString() const
{
    std::string tempString;
    tempString = "\nItem Name: "  + sEquipmentName;
    tempString = "\Damage: "  + siDamage;
    tempString = "\nRange "  + siRange;
    
    return tempString;
    
}



void Weapon::calculateMaterialBonuses()
{
    
}


void Weapon::setIsRanged(bool value)
{
    isRanged = value;
}

void Weapon::setRange(short int value)
{
    
    if(value < 0)
        return;
    
    siRange = value;
    
}

//May have a weapon that heals by attacking, so there's no need to check if the damage is less than 0
void Weapon::setDamage(short int value)
{
    siDamage = value;
}
//void Weapon::setItemName(int value){Item::setItemName(value);}
void Weapon::setMaterial(Material value){Item::setMaterial(value);}
void Weapon::setWeaponSize(EnWeaponSize _size)
{
    enWeaponSize = _size;
}
bool Weapon::isRangedWeapon() const
{
    return isRanged;
}



short int Weapon::getRange() const
{
    return siRange;

}

short int Weapon::getDamage() const
{
    return siDamage;

}


EnWeaponSize Weapon::getWeaponSize() const

{
    
    return enWeaponSize;

}











