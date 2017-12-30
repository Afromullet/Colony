//
//  Foot.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Foot.hpp"

Foot::Foot()
{
    
}

Foot::Foot(AppendageType _appendageType) : Appendage(_appendageType)
{
    
}

Armor Foot::getFootArmor()
{
    return armor;
}

void Foot::setFootArmor(Armor _armor)
{
    _armor.isEquipped = true;
    armor = _armor;
}