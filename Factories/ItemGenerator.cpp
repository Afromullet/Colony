//
//  ItemGenerator.cpp
//  Colony
//
//  Created by Sean on 12/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "ItemGenerator.hpp"
#include "Constants.hpp"
#include "Globals.hpp"
#include "Map.hpp"
#include "EnumTypes.hpp"
#include "TestData.hpp"

//todo add destructors

//Not much done yet. Remove this file later, this is just for testing. Radom item generation will have to be handled differently.
Armor GenerateRandomArmor()
{
    
    //int randNum = rand() % 3;
    Armor armor;
    int randNum = rand() % 3;
    std::cout << "Random number " << randNum << "\n";
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    
    switch(randNum)
    {
        case 0:
            armor.setItemType(enArmorType);
            armor.setFitsBodyPart(enChestBodyPart);
            armor.setItemName("ChestArmor" + std::to_string(rand() % 100));
            break;
        case 1:
            armor.setFitsBodyPart(enHeadBodyPart);
            armor.setItemType(enArmorType);
            armor.setItemName("HeadArmor" + std::to_string(rand() % 100));
            break;
        case 2:
            armor.setFitsBodyPart(enLegsBodyPart);
            armor.setItemType(enArmorType);
            armor.setItemName("LegArmor" + std::to_string(rand() % 100));
            break;
            
    }
    
    return armor;
    

}

Weapon GenerateRandomWeapon()
{
    int randNum = rand() % 5;
    Weapon weapon;
    
    
    weapon.setRange(1); //Default fot melee weapons
    weapon.setDamage(rand() % 5);
    
    //Not dealing with two handed weapons now
    switch(randNum)
    {
        case 0:
            weapon.setWeaponClass(enDagger);
            weapon.setItemName("Dagger" + std::to_string(rand() % 100));
            break;
        case 1:
             weapon.setWeaponClass(enShortSword);
            weapon.setItemName("Shortsword" + std::to_string(rand() % 100));
            break;
        case 2:
            weapon.setWeaponClass(enLongSword);
            weapon.setItemName("Longsword" + std::to_string(rand() % 100));
            break;
        case 3:
            weapon.setWeaponClass(enMace);
            weapon.setItemName("Mace" + std::to_string(rand() % 100));
            break;
        case 4:
            weapon.setWeaponClass(enDagger);
            weapon.setItemName("enHammer" + std::to_string(rand() % 100));
            break;
    }
    
    return weapon;
    
}


