//
//  ItemManager.hpp
//  Colony
//
//  Created by Sean on 6/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ItemManager_hpp
#define ItemManager_hpp

#include <stdio.h>
#include <memory>
#include "Armor.hpp"
#include "Weapon.hpp"

using namespace std;

class ItemManager
{
private:
    
    
    
public:
    
    std::vector<unique_ptr<Item>> items;
    
    
    ItemManager();
    
    void addItem(unique_ptr<Item> item);
   // void addArmor(Armor armor);
    //void AddWeapon(Weapon weapon);
    
    
    
};

#endif /* ItemManager_hpp */
