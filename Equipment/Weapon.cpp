//
//  Weapon.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Weapon.hpp"


//todo add "Blank" weapon for when no weapon is equipped..and also something to identify a two handed weapon is equipped
Weapon::Weapon(int _material,EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siRange,short int _siDamage,EnumWeaponClass _enWeaponClass):
        Equipment::Equipment(_material,_enFitsBodyPart,_sEquipmentName),
        siRange(_siRange),siDamage(_siDamage),enWeaponClass(_enWeaponClass){}


Weapon::Weapon() : Equipment(-1,enUndefinedBodyPart,1),siRange(-1),siDamage(-1),enWeaponClass(enUndefinedWeaponClass)
{
    
}

int Weapon::getEquipmentName()
{
    
    return Equipment::getEquipmentName();
    
}

short int Weapon::getRange(){return siRange;}
short int Weapon::getDamage(){return siDamage;}
EnumFitsBodyPart Weapon::getBodyPart(){ return Equipment::getBodyPart();}
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
void Weapon::setEquipmentName(int value){Equipment::setEquipmentName(value);}
void Weapon::setMaterial(int value){Equipment::setMaterial(1);}
void Weapon::setFitsBodyPart(EnumFitsBodyPart value){Equipment::setFitsBodyPart(value);}
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

