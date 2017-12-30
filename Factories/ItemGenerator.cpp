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


//For testing...need to get inventory and equipping items owrking
void RandomItemGen()
{
    
    for(int i = 0; i < 10; i++)
    {
        Item *item;
        itemsOnMap.push_back(item);
    }
    
    std::list<Item*>::iterator itemIt;
    int counter = 0;
    
    int randX,randY;
    for(itemIt = itemsOnMap.begin(); itemIt != itemsOnMap.end(); ++itemIt)
    {
       
        //A lot of redunancy in the code below..just testing for now
        Armor arm = GenerateRandomArmor();

        
        *itemIt = arm.clone();
        
        //std::cout << "\nInside random item gen after cast " << (* << "\n";
        
       // (*itemIt)->setItemName(arm.getItemName());
        std::cout << "\nRandom item gen item armor name " << (*itemIt)->getItemName() << "\n";
        (*itemIt)->setFitsBodyPart(arm.getBodyPart());
        randX = rand() % MAP_WIDTH;
        randY = rand() % MAP_HEIGHT;
        (*itemIt)->setPosition(randX, randY);
        //(*itemIt)->localItemID = counter;
        counter++;
    }
    

}


void PlaceItemsOnMap(Map &map)
{
    std::list<Item*>::iterator itemit;
    for(itemit = itemsOnMap.begin(); itemit != itemsOnMap.end(); ++itemit)
    {
        //TODO...Do some research on whether setting a pointer with a list iterator like that is a bad idea
        
       (*itemit)->tile.loadTile("blessed_blade.png", sf::Vector2u(32,32), sf::Vector2u((*itemit)->getPosition().x,(*itemit)->getPosition().y));
        map.Map2D[(*itemit)->getPosition().x][(*itemit)->getPosition().y].SetItemOnTile(*itemit);
    }
}
