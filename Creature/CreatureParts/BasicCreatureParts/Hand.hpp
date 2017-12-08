//
//  Hand.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include "Appendage.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

class Hand : public Appendage
{
    
protected:
    Weapon weapon;
    Armor armor;
    
public:
    Hand();
    Hand(AppendageType _appendageType);
    
    void setHandArmor(Armor _armor);
    void setWeapon(Weapon _weapon);
    
    Armor getHandArmor();
    Weapon getWeapon();
    
};

#endif /* Hand_hpp */
