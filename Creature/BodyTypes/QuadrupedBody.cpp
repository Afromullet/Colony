//
//  QuadrupedBody.cpp
//  Colony
//
//  Created by Sean on 12/7/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "QuadrupedBody.hpp"

QuadrupedBody::QuadrupedBody()
{
    
}

void QuadrupedBody::AttackRandomBodyPart(int attackBonus, int damage)
{
    
    switch(rand() % 5)
    {
        case 0:
            if(attackBonus >= fronLeftLeg.getLegArmor().siGetArmorBonus())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 1:
            if(attackBonus >= frontRightLeg.getLegArmor().siGetArmorBonus())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 2:
            if(attackBonus >= backLeftLeg.getLegArmor().siGetArmorBonus())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 3:
            if(attackBonus >= backRightLeg.getLegArmor().siGetArmorBonus())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 4:
            if(attackBonus >= getHead().getHeadArmor().siGetArmorBonus())
                getHead().damageHead(damage);
            break;
        case 5:
            if(attackBonus >= getChest().getChestArmor().siGetArmorBonus())
                getChest().damageChest(damage);
            break;
    }
    
    
}

void QuadrupedBody::CalculateHealth()
{
    
}

