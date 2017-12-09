//
//  Arm.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Arm.hpp"

Arm::Arm()
{
    setLimbHealth(10);
}

Arm::Arm(LimbType _limbType,AppendageType _appendageType) : Limb(_limbType), hand(_appendageType)
{
    
}


void Arm::setArmArmor(Armor _armor)
{
    armor = _armor;
}

void Arm::setHandArmor(Armor _armor)
{
    hand.setHandArmor(_armor);
}


Armor Arm::getArmArmor()
{
    return armor;
}

Armor Arm::getHandArmor()
{
    return hand.getHandArmor();
}
