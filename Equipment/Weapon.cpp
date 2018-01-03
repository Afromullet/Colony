//
//  Weapon.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Weapon.hpp"

Weapon FIST_WEAPON(1,enFitsOneHand,1,1,1,enUnarmed);

//todo add "Blank" weapon for when no weapon is equipped..and also something to identify a two handed weapon is equipped
Weapon::Weapon(int _material,EnumBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siRange,short int _siDamage,EnumWeaponClass _enWeaponClass):
        Item::Item(_material,_enFitsBodyPart,_sEquipmentName),
        siRange(_siRange),siDamage(_siDamage),enWeaponClass(_enWeaponClass){}


Weapon::Weapon() : Item(-1,enUndefinedPart,1),siRange(-1),siDamage(-1),enWeaponClass(enUndefinedWeaponClass)
{
    
}






Weapon::Weapon(const Weapon &weapon)
{
    enFitsBodyPart = weapon.enFitsBodyPart;
    position = weapon.position;
    itemID = weapon.itemID;
    sEquipmentName = weapon.sEquipmentName;
    enItemType = weapon.enItemType;
    siRange = weapon.siRange;
    siDamage = weapon.siDamage;
    enWeaponClass = weapon.enWeaponClass;
    
    
}
Weapon::Weapon(Weapon &weapon)
{
    enFitsBodyPart = weapon.enFitsBodyPart;
    position = weapon.position;
    itemID = weapon.itemID;
    sEquipmentName = weapon.sEquipmentName;
    enItemType = weapon.enItemType;
    siRange = weapon.siRange;
    siDamage = weapon.siDamage;
    enWeaponClass = weapon.enWeaponClass;
}


/*
int Weapon::getItemName()
{
 
    return Item::getItemName();
    
}
 */

short int Weapon::getRange(){return siRange;}
short int Weapon::getDamage(){return siDamage;}
EnumBodyPart Weapon::getBodyPart(){ return Item::getBodyPart();}
EnumWeaponClass Weapon::getWeaponClass(){ return enWeaponClass;}


//Two handed melee weapons have 1.5 modifier to damage
float Weapon::getDamageModifier()
{
    if(enWeaponClass == enGreatsword)
        return 1.5;
    else
        return 1;
    
}


void Weapon::setRange(short int value){siRange = value;}
void Weapon::setDamage(short int value){siDamage = value;}
//void Weapon::setItemName(int value){Item::setItemName(value);}
void Weapon::setMaterial(int value){Item::setMaterial(1);}
void Weapon::setFitsBodyPart(EnumBodyPart value){Item::setFitsBodyPart(value);}
void Weapon::setWeaponClass(EnumWeaponClass weaponClass){enWeaponClass = weaponClass;}

//Depending on the type of weapon, we want to add a different modifier to attack bonus.
//This funtion determines which stat is added to the attack bonus
EnumBonusType Weapon::getAttackBonusType()
{
    //For now, there are only two ranged weapon clases, so uses shorter conditions to narrow down the possible checks for the conditionals...TODO, expand and check for each type
    if(enWeaponClass == enUndefinedWeaponClass)
        return enUndefinedBonus;
    else if(enWeaponClass == enLongbow || enWeaponClass == enCrossbow)
        return enDexterityBonus;
    else
        return enStrengthBonus;
        
    
}

void Weapon::calculateMaterialBonuses()
{
        
}

void Weapon::CalculateMaterialBonuses()
{
    
}

void Weapon::showItemStats()
{
    
    std::cout << "Item Name" << getItemName()<< "\n";
    std::cout << "Damage" << siDamage << "\n";
    std::cout << "Range" <<  siRange<< "\n";

    
}

bool Weapon::isRangedWeapon()
{
    if(enWeaponClass == enLongbow || enWeaponClass == enCrossbow)
        return true;
    
    return false;
        
    
}
