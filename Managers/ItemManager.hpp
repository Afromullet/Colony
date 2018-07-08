//
//  ItemManager.hpp
//  Colony
//
//  Created by Sean on 6/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//


#include "Armor.hpp"
#include "Weapon.hpp"


#ifndef ItemManager_hpp
#define ItemManager_hpp

#include <stdio.h>
#include <memory>


using namespace std;

class CreatureBody;

class ItemManager
{
private:
    
    std::vector<unique_ptr<Item>> items;
    
public:
    
    
    
    void operator=(ItemManager &other);
    
    //void operator=(ItemManager &&other);
    ItemManager& operator=(ItemManager&& other);
    
    

    
    
    
    ItemManager();
    ItemManager(ItemManager &other);
    ItemManager(ItemManager&& other);
    
    
    void addItem(unique_ptr<Item> item);
    void addArmor(Armor armor);
    void addWeapon(Weapon weapon);
    void showItemStats(int i);
    void EquipItem(int i,CreatureBody &body);
    
    void ClearSlot(int i); //Clears slot at index i
    
    void ReleaseAllMemory();
    
    //void MoveInventory(
    
    
    
};

#endif /* ItemManager_hpp */
