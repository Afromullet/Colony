//
//  Armor.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Armor.hpp"

//todo add "Blank" armor for when no armor is equipped or when we have something like leg armor

bool Armor::operator==(const Armor &other) const
{
    if(siArmorBonus == other.siArmorBonus && fDodgeModifier == other.fDodgeModifier && fDamageReduction == other.fDamageReduction && fMovementModifier == other.fMovementModifier )
    {
        
        return true;
     
    }
    return false;
}

bool Armor::operator=(const Armor &other) 
{
    siArmorBonus = other.siArmorBonus;
    fDodgeModifier = other.fDodgeModifier;
    fDamageReduction = other.fDamageReduction;
    fMovementModifier = other.fMovementModifier;
    sEquipmentName = other.sEquipmentName;
}

Armor::Armor(Material _material, std::string _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier)
: Item(_material,_sEquipmentName),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier)
{}



Armor::Armor(std::string itemName) :Item(itemName)
{
    
}

Armor::Armor(std::string itemName, std::string _section) :Item(itemName,_section)
{
    
}

//Ah..the bug was here. It wasn't copying the data needed because I thought it was using the Armor &armor() constructor, but it calls this oen instead Armor::Armor(const Armor &armor)
Armor::Armor(const Armor &armor)
{
    

    
    siArmorBonus = armor.siArmorBonus;
    sEquipmentName = armor.sEquipmentName;
    
 
    position = armor.position;
   
    

    fDodgeModifier = armor.fDodgeModifier;
    fDamageReduction = armor.fDamageReduction;
    fMovementModifier = armor.fMovementModifier;

    section = armor.section;
    

    
}




Armor::Armor() : Item(),siArmorBonus(-1),fDodgeModifier(-1),fDamageReduction(-1),
fMovementModifier(-1)
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


std::string Armor::getItemExamineString()
{
    std::string tempString;
    tempString = "Item Name: ";
    tempString = "\nArmor Bonus: "  + std::to_string(siArmorBonus);
    tempString = "\nDodge Modifier: "  + std::to_string(fDodgeModifier);
    tempString = "\nDamage Reduction:  "  + std::to_string(fDamageReduction);
    tempString = "\nMovemement Modifier "  + std::to_string(fMovementModifier);
    
    return tempString;
    

    
}

/*
int Armor::getItemName()
{
 
    return Item::getItemName();
    
}
 */



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


void Armor::setMaterial(Material value)
{
    Item::setMaterial(value);
    
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
