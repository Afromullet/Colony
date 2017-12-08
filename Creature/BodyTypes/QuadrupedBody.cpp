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
            if(attackBonus >= fronLeftLeg.getLegArmor().getArmorClass())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 1:
            if(attackBonus >= frontRightLeg.getLegArmor().getArmorClass())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 2:
            if(attackBonus >= backLeftLeg.getLegArmor().getArmorClass())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 3:
            if(attackBonus >= backRightLeg.getLegArmor().getArmorClass())
                fronLeftLeg.ApplyDamage(damage);
            break;
        case 4:
            if(attackBonus >= getHead().getHeadArmor().getArmorClass())
                getHead().damageHead(damage);
            break;
        case 5:
            if(attackBonus >= getChest().getChestArmor().getArmorClass())
                getChest().damageChest(damage);
            break;
    }
    
    
}