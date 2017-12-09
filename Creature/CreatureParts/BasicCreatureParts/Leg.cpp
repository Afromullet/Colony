//
//  Leg.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Leg.hpp"

Leg::Leg()
{
    setLimbHealth(10);
    
}

Leg::Leg(LimbType _limbType, AppendageType _appendageType) : Limb(_limbType), foot(_appendageType)
{
    
}

void Leg::setLegArmor(Armor _armor)
{
    armor = _armor;
}

void Leg::setFootArmor(Armor _armor)
{
    foot.setFootArmor(_armor);
}

Armor Leg::getLegArmor()
{
    return armor;
}

Armor Leg::getFootArmor()
{
    return foot.getFootArmor();
}