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



std::vector<BodyPart> humanoidBodySchema;


void InitializeGlobalBodyParts()
{
    
    //Until I finalize the constructor
    NO_WEAPON.setItemName("No Weapon");
    FIST_WEAPON.setItemName("First Weapon");
    NO_WEAPON.setItemName("No Armor");
    
    
    LeftArmBodyPart.weapon = NO_WEAPON;
    LeftArmBodyPart.armor = NO_ARMOR;
    RightArmBodyPart.weapon = NO_WEAPON;
    RightArmBodyPart.armor = NO_ARMOR;
    LeftLegBodyPart.weapon = NO_WEAPON;
    LeftLegBodyPart.armor = NO_ARMOR;
    RightLegBodyPart.weapon = NO_WEAPON;
    RightLegBodyPart.armor = NO_ARMOR;
    leftHandBodyPart.weapon = NO_WEAPON;
    leftHandBodyPart.armor = NO_ARMOR;
    rightHandBodyPart.weapon = FIST_WEAPON;
    rightHandBodyPart.armor = NO_ARMOR;
    
    leftFootBodypart.weapon = NO_WEAPON;
    leftFootBodypart.armor = NO_ARMOR;
    rightFootBodyPart.weapon = NO_WEAPON;
    rightFootBodyPart.armor = NO_ARMOR;
    headBodyPart.weapon = NO_WEAPON;
    headBodyPart.armor = NO_ARMOR;
    chestBodyPart.weapon = NO_WEAPON;
    chestBodyPart.armor = NO_ARMOR;
    
    

    humanoidBodySchema.push_back(LeftArmBodyPart);
    humanoidBodySchema.push_back(RightArmBodyPart);
    humanoidBodySchema.push_back(LeftLegBodyPart);
    humanoidBodySchema.push_back(RightLegBodyPart);
    humanoidBodySchema.push_back(leftHandBodyPart);
    humanoidBodySchema.push_back(rightHandBodyPart);
    humanoidBodySchema.push_back(leftFootBodypart);
    humanoidBodySchema.push_back(rightFootBodyPart);
    humanoidBodySchema.push_back(headBodyPart);
    humanoidBodySchema.push_back(chestBodyPart);

    
}

/*
 BodyPart LegBodyPart = "
 BodyPart HeadBodyPart;
 BodyPart ChestBodyPart;
 BodyPart FootBodyPart;
 BodyPart HandBodyPart;


 */

BodyPart::BodyPart(EnumBodyPart _bodypartType,bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health) : canHoldArmor(_canHoldArmor),canHoldWeapon(_canHoldWeapon),enBodyPartType(_bodypartType), armor(NO_ARMOR),weapon(NO_WEAPON),health(1), bodyPartName(_bodyPartName)
{
    
}

BodyPart::BodyPart(bool _canHoldWeapon, bool _canHoldArmor, bool _canInteract, bool _canMoveCreature,std::string _bodyPartName, int _health) : canHoldArmor(_canHoldArmor),canHoldWeapon(_canHoldWeapon), armor(NO_ARMOR),weapon(NO_WEAPON),health(1), bodyPartName(_bodyPartName)
{
    
}




BodyPart::BodyPart(const BodyPart& bp)
{
    health = bp.health;
    canHoldWeapon = bp.canHoldWeapon;
    canHoldArmor = bp.canHoldArmor;
    canInteract = bp.canInteract;
    canMoveCreature = bp.canMoveCreature;
    bodyPartName = bp.bodyPartName;
    
    enBodyPartType = bp.enBodyPartType;
    armor = bp.armor;
    weapon = bp.weapon;
   
    
}

void BodyPart::EquipItem(Item *item)
{
    
    if(item->getBodyPart() != enBodyPartType)
    {
        std::cout << "\n Equipment Name " << item->getItemName();
        std::cout << "\n" << item->getBodyPart() <<  " vs " << enBodyPartType;
        std::cout << "Doesn't fit into slot";
    }
    else if(item->getItemType() == enArmor && canHoldArmor)
    {
    
        Armor *arm = dynamic_cast<Armor*>(item);
        arm->isEquipped = true;
        armor = *arm;
        
    }
    else if(item->getItemType() == enWeapon && canHoldWeapon)
    {
        //todo handle two handed equippment correctly.
        Weapon *wep = dynamic_cast<Weapon*>(item);
        wep->isEquipped = true;
        weapon = *wep;
    }
    else
    {
        errorLog.writeToFile("Error equipping item of type\n");
    
    }
}




void BodyPart::setBodyPartType(EnumBodyPart _bodyPartType)
{
    enBodyPartType = _bodyPartType;
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

void BodyPart::ApplyDamage(int damage)
{
    health -= damage;
}
