//
//  BodyPart.cpp
//  Colony
//
//  Created by Sean on 1/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BodyPart.hpp"
#include "Globals.hpp"
//Read these from a file later and store in a vector of strings
//That way it can be customized easily by reading from files






void InitializeGlobalBodyParts()
{
    
    //Until I finalize the constructor
    NO_WEAPON.setItemName("No Weapon");
    FIST_WEAPON.setItemName("First Weapon");
    NO_ARMOR.setItemName("No Armor");
    
    
}



std::ostream& operator<<(std::ostream& os, const BodyPart& bp)
{
    /*
    os << "\nBodypart Name " << bp.bodyPartName << "\nHealth " << bp.health << "\nCan Hold Armor " << bp.canHoldArmor << "\nCan Hold Weapon " << bp.canHoldWeapon << "\nCan Interact " << bp.canInteract << "\nArmor Name " << bp.armor.sEquipmentName << "\nCan Breathe " << bp.canBreathe << "\nCan See " << bp.canSee << "\n Can smell " << bp.canSmell << "\n Token " << bp.bodyPartToken << "\n Section " << bp.section << "\nWeapon Name " << bp.weapon.sEquipmentName  << "\n\n";
     */
    return os;
    
}

BodyPart::BodyPart() : armor(NO_ARMOR),weapon(NO_WEAPON)
{
    canHoldArmor = true;
    canHoldWeapon = true;

    health = 1;
    bodyPartName = "No part";
    
}

BodyPart::BodyPart(bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health) : canHoldArmor(_canHoldArmor),canHoldWeapon(_canHoldWeapon),armor(NO_ARMOR),weapon(NO_WEAPON),health(1), bodyPartName(_bodyPartName)
{
    
}



BodyPart::BodyPart(std::string bptoken,std::string bpname) : bodyPartToken(bptoken),bodyPartName(bpname)
{
    health = 10;
}



BodyPart::BodyPart(const BodyPart& bp)
{
    health = bp.health;
    
    canHoldWeapon = bp.canHoldWeapon;
    canHoldArmor = bp.canHoldArmor;
    canBreathe = bp.canBreathe;
    canInteract = bp.canInteract;
    canMoveCreature = bp.canMoveCreature;
    canSmell = bp.canSmell;
    
    
    bodyPartName = bp.bodyPartName;
    bodyPartToken = bp.bodyPartToken;
    section = bp.section;
    
  
    armor = bp.armor;
    weapon = bp.weapon;
    relativeSize = bp.relativeSize;
    wounds = bp.wounds;
   
    
}



void BodyPart::EquipArmor(Item *item)
{
    
    if(item->isValidSection(section))
    {
        if(canHoldArmor)

        //if(item->getItemType() == enArmorType && canHoldArmor)
        {
            Armor *arm = dynamic_cast<Armor*>(item);
            arm->isEquipped = true;
            armor = *arm;
            std::cout << "\n Equipped";
            
            std::cout << "\n Equipment Name " << armor.sEquipmentName;
        }
        
    }
}

void BodyPart::EquipWeapon(Item *item)
{
    Weapon *wep = dynamic_cast<Weapon*>(item);
  //  std::cout << "\n Damage and range " << wep->getDamage() << ", " << wep->isRangedWeapon();
    wep->isEquipped = true;
    weapon = *wep;
    
  //  std::cout << "\n Damage and range " << weapon.getDamage() << ", " << weapon.isRangedWeapon();
    

}





int BodyPart::getHealth()
{
    return health;
}


Armor BodyPart::getArmor()
{
    return armor;
}

Weapon BodyPart::getWeapon()
{
    return weapon;
}

std::vector<AppliedForceEffect>& BodyPart::getArmorMaterialEffects()
{
    return armor.material.getAppliedForceEffects();
}

//Calculates the body parts size in units based on the total size passed as a parameter. RelativeSize is a percent
float BodyPart::getBodyPartSize(float totalBodySize)
{
    return totalBodySize * relativeSize;
}

void BodyPart::ApplyDamage(int damage)
{
    health -= damage;
}
bool BodyPart::hasWeapon()
{
    
    //return true;
}

//Applies an attack to this body part
std::vector<AppliedForceEffect> BodyPart::ApplyAttack(AttackStats params)
{
    
    std::vector<AppliedForceEffect> effects;
    armor.material.PerformMaterialCalculations(params.force,params.contactArea,params.enAttackForceType,params.attackType);
    effects = getArmorMaterialEffects();
    
    return effects;
    
    
}

void BodyPart::ShowWounds()
{
    std::cout << "Body Part Name: " << bodyPartName << std::endl;
    for(int i =0; i < wounds.size(); i++)
    {
        std::cout << wounds.at(i) << std::endl;
    }
}

void BodyPart::AddWound(WoundType woundType)
{
    wounds.push_back(woundType);
}

void BodyPart::ClearWounds()
{
    wounds.clear();
}


