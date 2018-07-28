//
//  Weapon.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Weapon.hpp"
#include "BodyPart.hpp"
#include "ItemManager.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "Globals.hpp"
#include "UtilMacros.h"

bool Weapon::operator==(const Weapon &other) const
{
    if(siRange == other.siRange && siDamage == other.siDamage && sEquipmentName == other.sEquipmentName && position == other.position && isRanged == other.isRanged)
    {
       
        if(size == other.size && mass == other.mass && section == other.section &&
           material == other.material && sEquipmentName == other.sEquipmentName && isEquipped == other.isEquipped)
        {
            if(sections == other.sections)
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
    enWeaponSize = other.enWeaponSize;
    size = other.size;
    mass = other.mass;
    section = other.section;
    material = other.material;
    isEquipped = other.isEquipped;
    tag = boost::uuids::random_generator()();
    enItemType = enWeaponType;
    sections = other.sections;
    stackSize = other.stackSize;
    maxStackSize = other.maxStackSize;
    descriptiveText = other.descriptiveText;
    itemTile = other.itemTile;

    
}

//todo add "Blank" weapon for when no weapon is equipped..and also something to identify a two handed weapon is equipped
Weapon::Weapon(Material _material, std::string _sEquipmentName, short int _siRange,short int _siDamage):
        Item::Item(_material,_sEquipmentName,enWeaponType),
        siRange(_siRange),siDamage(_siDamage)
{




}


Weapon::Weapon()
{
    
    *this = FIST_WEAPON;
    tag = boost::uuids::random_generator()();
    enItemType = enWeaponType;
    
    size = 0;
    mass = 0;
   
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
    enWeaponSize = weapon.enWeaponSize;
    size = weapon.size;
    mass = weapon.mass;
    section = weapon.section;
    material = weapon.material;
    isEquipped = weapon.isEquipped;
    tag = weapon.tag;
    section = weapon.section;
    sections = weapon.sections;
    stackSize = weapon.stackSize;
    maxStackSize = weapon.maxStackSize;
    descriptiveText = weapon.descriptiveText;
    enItemType = enWeaponType;
    itemTile = weapon.itemTile;
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
    tempString = "\n Item Name: "  + sEquipmentName;
    tempString = "\n Damage: "  + siDamage;
    tempString = "\n nRange "  + siRange;
    
    return tempString;
    
}


void Weapon::AddToItemManager(ItemManager &manager)
{
    manager.addWeapon(*this);
}

void Weapon::EquipItem(BodyPart &bp)
{
    bp.setWeapon(*this);
}




void Weapon::setIsRanged(bool value)
{
    isRanged = value;
}

void Weapon::setRange(short int value)
{
    
    
    siRange = IS_NUM_GT_0(value);
    
}

//May have a weapon that heals by attacking, so there's no need to check if the damage is less than 0
void Weapon::setDamage(short int value)
{
    siDamage = IS_NUM_GT_0(value);
}
//void Weapon::setItemName(int value){Item::setItemName(value);}
void Weapon::setMaterial(Material value){Item::setMaterial(value);}
void Weapon::setWeaponSize(EnWeaponSize _size)
{
    enWeaponSize = _size;
}

 void Weapon::setContactArea(int area)
{
    contactArea = IS_NUM_GT_0(area);
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











