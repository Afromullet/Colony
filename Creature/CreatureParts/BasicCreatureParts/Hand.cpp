//
//  Hand.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Hand.hpp"

Hand::Hand()
{
    
}

Hand::Hand(AppendageType _appendageType) : Appendage(_appendageType)
{
 
}

void Hand::setHandArmor(Armor _armor)
{
    _armor.isEquipped = true;
    armor = _armor;
}

void Hand::setWeapon(Weapon _weapon)
{
    _weapon.setIsEquipped(true);
    weapon = _weapon;
}

Armor Hand::getHandArmor()
{
    return armor;
}

Weapon Hand::getWeapon()
{
    return weapon;
}