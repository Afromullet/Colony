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
: Item(_material,_enFitsBodyPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor(int _material,int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClass)
: Item(_material,enUndefinedBodyPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor() : Item(),siArmorBonus(-1),fDodgeModifier(-1),fDamageReduction(-1),
fMovementModifier(-1),enArmorClass(enUndefinedArmorClass)
{

    setArmorBonus(0);
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
    Item::getBodyPart();
}

int Armor::getItemName()
{
 
    return Item::getItemName();
    
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

void Armor::setItemName(int value)
{

    Item::setItemName(value);
    
}
void Armor::setMaterial(int value)
{
    Item::setMaterial(1);
    
}

void Armor::setFitsBodyPart(EnumFitsBodyPart value)
{
    Item::setFitsBodyPart(value);
    
}

void Armor::CalculateMaterialBonuses()
{
    
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