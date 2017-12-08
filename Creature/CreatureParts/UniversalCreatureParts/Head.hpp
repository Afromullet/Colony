//
//  Head.hpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Head_hpp
#define Head_hpp

#include <stdio.h>

#include "Armor.hpp"
#include "Weapon.hpp"

class Head
{
private:
    Armor armor;
    Weapon weapon; //A creature can have a bite attack. A bite attack is modelled as a weapon.
    short int headHealth;
    
public:
    Head(Armor _armor,short int _headHealth);
    Head(short int _headHealth);
    Head();
    
    Armor getHeadArmor();
    short int getHeadHealth();

    
    void setHeadArmor(Armor value);
    void setHeadHealth(short int value);
    
    bool doesAttackHitHead(short int attackBonus);
    int damageHead(short int damage);
    
    
};

#endif /* Head_hpp */

