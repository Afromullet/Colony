//
//  HumanoidBody.cpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "HumanoidBody.hpp"

HumanoidBody::HumanoidBody()
{
    
}

void HumanoidBody::AttackRandomBodyPart(int attackBonus, int damage)
{
    
    switch(rand() % 5)
    {
        case 0:
            if(attackBonus >= leftArm.getArmArmor().getArmorClass())
                leftArm.ApplyDamage(damage);
            break;
        case 1:
            if(attackBonus >= rightArm.getArmArmor().getArmorClass())
                rightArm.ApplyDamage(damage);
            break;
        case 2:
            if(attackBonus >= leftLeg.getLegArmor().getArmorClass())
                leftLeg.ApplyDamage(damage);
            break;
        case 3:
            if(attackBonus >= rightLeg.getLegArmor().getArmorClass())
                rightLeg.ApplyDamage(damage);
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