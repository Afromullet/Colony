//
//  Armor.cpp
//  Colony
//
//  Created by Sean on 9/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Armor.hpp"
#include "BodyPart.hpp"
#include "ItemManager.hpp"

//#include "Globals.hpp"


//todo add "Blank" armor for when no armor is equipped or when we have something like leg armor

bool Armor::operator==(const Armor &other) const
{
    if(siArmorBonus == other.siArmorBonus && fDodgeModifier == other.fDodgeModifier && fDamageReduction == other.fDamageReduction && fMovementModifier == other.fMovementModifier)
    {
       if(size == other.size && mass == other.mass && section == other.section && material == other.material && sEquipmentName == other.sEquipmentName && isEquipped == other.isEquipped && itemTile == other.itemTile && tile == other.tile && sections == other.sections)
           
       {
           
          return true;
       }
       
    }
    
    

    return false;
}



bool Armor::operator!=(const Armor &other) const
{
    return !(*this == other);
}

void Armor::operator=(const Armor &other)
{
    siArmorBonus = other.siArmorBonus;
    fDodgeModifier = other.fDodgeModifier;
    fDamageReduction = other.fDamageReduction;
    fMovementModifier = other.fMovementModifier;
    sEquipmentName = other.sEquipmentName;
    section = other.section;
    size = other.size;
    mass = other.mass;
    material = other.material;
    isEquipped = other.isEquipped;
    position = other.position;
    tile = other.tile;
    itemTile = other.itemTile;
    sections = other.sections;
    position = other.position;
    tag = other.tag;
    enItemType = enArmorType;
    stackSize = other.stackSize;
    maxStackSize = other.maxStackSize;
    descriptiveText = other.descriptiveText;
    itemTile = other.itemTile;
    

}


Armor::Armor(Material _material, std::string _sEquipmentName, short int _siArmorBonus, float _fDodgeModifier, float _fDamageReduction,float _fMovementModifier)
: Item(_material,_sEquipmentName,enArmorType),
siArmorBonus(_siArmorBonus),fDodgeModifier(_fDodgeModifier),
fDamageReduction(_fDamageReduction),fMovementModifier(_fMovementModifier)
{

    

}




//Ah..the bug was here. It wasn't copying the data needed because I thought it was using the Armor &armor() constructor, but it calls this oen instead Armor::Armor(const Armor &armor)
Armor::Armor(const Armor &other)
{
    

    
    siArmorBonus = other.siArmorBonus;
    fDodgeModifier = other.fDodgeModifier;
    fDamageReduction = other.fDamageReduction;
    fMovementModifier = other.fMovementModifier;
    sEquipmentName = other.sEquipmentName;
    section = other.section;
    size = other.size;
    mass = other.mass;
    material = other.material;
    isEquipped = other.isEquipped;
    position = other.position;
    tile = other.tile;
    itemTile = other.itemTile;
    sections = other.sections;
    position = other.position;
    tag = other.tag;
    stackSize = other.stackSize;
    maxStackSize = other.maxStackSize;
    descriptiveText = other.descriptiveText;
    enItemType = enArmorType;
    itemTile = other.itemTile;

    
}

Armor::Armor(const Armor *other)
{
    
    siArmorBonus = other->siArmorBonus;
    fDodgeModifier = other->fDodgeModifier;
    fDamageReduction = other->fDamageReduction;
    fMovementModifier = other->fMovementModifier;
    sEquipmentName = other->sEquipmentName;
    section = other->section;
    size = other->size;
    mass = other->mass;
    material = other->material;
    isEquipped = other->isEquipped;
    position = other->position;
    tile = other->tile;
    itemTile = other->itemTile;
    sections = other->sections;
    position = other->position;
    tag = other->tag;
    stackSize = other->stackSize;
    maxStackSize = other->maxStackSize;
    descriptiveText = other->descriptiveText;
    enItemType = enArmorType;
    itemTile = other->itemTile;
    
    
}



Armor::Armor()
{

    *this = NO_ARMOR;
    tag = boost::uuids::random_generator()();
 
}



/*
Armor::~Armor()
{
}
*/


std::string Armor::getItemExamineString() const
{
    std::string tempString;
    tempString = "Item Name: ";
    tempString = "\nArmor Bonus: "  + std::to_string(siArmorBonus);
    tempString = "\nDodge Modifier: "  + std::to_string(fDodgeModifier);
    tempString = "\nDamage Reduction:  "  + std::to_string(fDamageReduction);
    tempString = "\nMovemement Modifier "  + std::to_string(fMovementModifier);
    
    return tempString;
    
    
    
}

//At this point, a copy has ben created
void Armor::EquipItem(BodyPart &bp)
{
    
    bp.setArmor(*this);
    
  
    
}


void Armor::showItemStats() const
{
    std::cout << "ItemName " << getItemName() << "\n";
    std::cout << "Armor Bonus " << siArmorBonus << "\n";
    std::cout << "Doge Modifier " <<  fDodgeModifier << "\n";
    std::cout << "Damage Reduction " <<  fDamageReduction<< "\n";
    std::cout << "Movement Modifier " <<  fMovementModifier<< "\n";
}


void Armor::AddToItemManager(ItemManager &manager)
{
    manager.addArmor(*this);
}


short int Armor::siGetArmorBonus() const
{
    return siArmorBonus;
}


float Armor::fGetDodgeModifier() const
{
    return fDodgeModifier;
}

float Armor::fGetDamageReduction() const
{
    return fDamageReduction;
}

float Armor::fGetMovementModifier() const
{
    return fMovementModifier;
}

void Armor::setArmorBonus(short int value)
{
    
    siArmorBonus = IS_NUM_GT_0(value);

}

void Armor::setDodgeModifier(float value)
{
    fDodgeModifier = IS_NUM_GT_0(value);
}

void Armor::setDamageReduction(float value)
{
    fDamageReduction = IS_NUM_GT_0(value);
}

void Armor::setMovementModifier(float value)
{
    fMovementModifier = IS_NUM_GT_0(value);
}

void Armor::setMaterial(Material value)
{
    Item::setMaterial(value);
    
}


Armor NO_ARMOR(Material(),"No armor",1,1,1,1);






