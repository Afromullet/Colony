//
//  Chest.hpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Chest_hpp
#define Chest_hpp

#include <stdio.h>

#include "Armor.hpp"



class Chest
{
private:
    Armor armor;
    short int health;
    
    
public:
    Chest(Armor _armor, short int _chestHealth);
    Chest(short int _chestHealth);
    Chest();
    
    Armor getChestArmor();
    short int getChestHealth();
    
    
    void setChestArmor(Armor value);
    void setChestHealth(short int value);
    
    bool doesAttackHitChest(short int attackBonus); //Returns true if hit succeeded, returns false if not
    int damageChest(short int damage);

};

#endif /* Chest_hpp */
