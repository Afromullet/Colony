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

Armor GenerateRandomArmor()
{
    
    int randNum = rand() % 3;
    Armor armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    
    switch(randNum)
    {
        case 0:
            armor.setFitsBodyPart(enChest);
            armor.setItemName("ChestArmor" + std::to_string(rand() % 100));
            break;
        case 1:
            armor.setFitsBodyPart(enHead);
            armor.setItemName("HeadArmor" + std::to_string(rand() % 100));
            break;
        case 2:
            armor.setFitsBodyPart(enLegs);
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

//std::list<Item> itemsOnMap;

//For testing...need to get inventory and equipping items owrking
void RandomItemGen()
{
    
    for(int i = 0; i < 10; i++)
    {
        Item *item;
        

        

        
        //item.tile.loadTile("blessed_blade.png", sf::Vector2u(32,32), sf::Vector2u(randX,randY));
        
        //item.setPosition(randX, randY);
        //
        //item.tile.setPosition(randX, randY);
        
        //item.setItemID(rand() % 1000);
        //item.localItemID = rand() % 500;
        
        
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
        std::string name = "Armor";
        name + std::to_string(counter);
        (*itemIt)->setItemName(arm.getItemName());
        (*itemIt)->setFitsBodyPart(arm.getBodyPart());
        randX = rand() % MAP_WIDTH;
        randY = rand() % MAP_HEIGHT;
        (*itemIt)->setPosition(randX, randY);
        //(*itemIt)->localItemID = counter;
        counter++;
    }
    
    std::cout << "\n";
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
