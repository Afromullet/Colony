//
//  Armor.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Armor.hpp"

//todo add "Blank" armor for when no armor is equipped or when we have something like leg armor



Armor::Armor(int _material, EnumBodyPart _enFitsBodyPart, int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClass)
: Item(_material,_enFitsBodyPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor(int _material,int _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier,EnumArmorClass _enArmorClass)
: Item(_material,enUndefinedPart,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier),enArmorClass(_enArmorClass)
{}

Armor::Armor(std::string itemName, EnItemType _itemType) :Item(itemName,_itemType)
{
    
}

//Ah..the bug was here. It wasn't copying the data needed because I thought it was using the Armor &armor() constructor, but it calls this oen instead Armor::Armor(const Armor &armor)
Armor::Armor(const Armor &armor)
{
    
    /*
    
    //std::cout << "Item type " << armor.enItemType << "\n";
   sEquipmentName = armor.sEquipmentName;
   
    
    siArmorBonus = armor.siArmorBonus;
   // sEquipmentName = armor
    enFitsBodyPart = armor.enFitsBodyPart;
     */
    
    
    siArmorBonus = armor.siArmorBonus;
    sEquipmentName = armor.sEquipmentName;
    
    enFitsBodyPart = armor.enFitsBodyPart;
    position = armor.position;
    itemID = armor.itemID;
    
    enItemType = armor.enItemType;
    fDodgeModifier = armor.fDodgeModifier;
    fDamageReduction = armor.fDamageReduction;
    fMovementModifier = armor.fMovementModifier;
    enArmorClass = armor.enArmorClass;
    

    
}


Armor::Armor(Armor &armor)
{

   // std::cout << "\nnmam" << armor.getItemName() << "n";
    
    siArmorBonus = armor.siArmorBonus;
    sEquipmentName = armor.sEquipmentName;
    
    enFitsBodyPart = armor.enFitsBodyPart;
    position = armor.position;
    itemID = armor.itemID;
    
    enItemType = armor.enItemType;
    fDodgeModifier = armor.fDodgeModifier;
    fDamageReduction = armor.fDamageReduction;
    fMovementModifier = armor.fMovementModifier;
    enArmorClass = armor.enArmorClass;

   // std::cout << "\n Name " << sEquipmentName << "\n" << "adsdas " << armor.siGetArmorBonus() << "\n";
    //armor.setItemName(armor.getItemName());
    
}

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

EnumBodyPart Armor::getBodyPart()
{
    return Item::getBodyPart();
}


/*
int Armor::getItemName()
{
 
    return Item::getItemName();
    
}
 */

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
    //std::cout <<  "set \nvalue = " << siArmorBonus;
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

/*
void Armor::setItemName(int value)
{

    Item::setItemName(value);
    
}
 */


void Armor::setMaterial(int value)
{
    Item::setMaterial(1);
    
}

void Armor::setFitsBodyPart(EnumBodyPart value)
{
    Item::setFitsBodyPart(value);
    
}

void Armor::CalculateMaterialBonuses()
{
    
}

void Armor::showItemStats()
{
    std::cout << "ItemName " << getItemName() << "\n";
    std::cout << "Armor Bonus " << siArmorBonus << "\n";
    std::cout << "Doge Modifier " <<  fDodgeModifier << "\n";
    std::cout << "Damage Reduction " <<  fDamageReduction<< "\n";
    std::cout << "Movement Modifier " <<  fMovementModifier<< "\n";
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