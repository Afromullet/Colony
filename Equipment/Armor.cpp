//
//  Armor.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Armor.hpp"

//todo add "Blank" armor for when no armor is equipped or when we have something like leg armor


Armor::Armor(int _material, EnumFitsBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClass)
: Equipment(_material,_enFitsBodyPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor(int _material,int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClass)
: Equipment(_material,enUndefinedBodyPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor() : Equipment(),siArmorBonus(-1),fDodgeModifier(-1),fDamageReduction(-1),
fMovementModifier(-1),enArmorClass(enUndefinedArmorClass)
{
    
    
}

short int Armor::siGetArmorBonus()
{
    return siArmorBonus;
}


float Armor::fGetDodgeModifier()
{
    return fDodgeModifier;
}

float Armor::fGetDamageReduction()
{
    return fDamageReduction;
}

float Armor::fGetMovementModifier()
{
    return fMovementModifier;
}

EnumFitsBodyPart Armor::getBodyPart()
{
    Equipment::getBodyPart();
}

int Armor::getEquipmentName()
{
 
    return Equipment::getEquipmentName();
    
}

EnumArmorClass Armor::getArmorClass()
{
    return enArmorClass;
}

void Armor::calculateMaterialBonuses()
{
    
}

void Armor::setArmorBonus(short int value)
{
    siArmorBonus = value;
}

void Armor::setDodgeModifier(float value)
{
    fDodgeModifier = value;
}

void Armor::setDamageReduction(float value)
{
    fDamageReduction = value;
}

void Armor::setMovementModifier(float value)
{
    fMovementModifier = value;
}

void Armor::setEquipmentName(int value)
{

    Equipment::setEquipmentName(value);
    
}
void Armor::setMaterial(int value)
{
    Equipment::setMaterial(1);
    
}

void Armor::setFitsBodyPart(EnumFitsBodyPart value)
{
    Equipment::setFitsBodyPart(value);
    
}



/*
short int siGetArmorBonus;
float fGetDodgeModifier;
float fGetDamageReduction;
float fGetMovementModifier;
void setArmorBonus(short int value);
void setDodgeModifier(float value);
void setDamageReduction(float value);
void setMovementModifier(float value);
void calculateMaterialBonuses();

*/