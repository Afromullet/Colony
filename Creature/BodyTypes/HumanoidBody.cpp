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
    
    std::cout << "attack\n";
    
    switch(rand() % 5)
    {
        case 0:
            if(attackBonus >= leftArm.getArmArmor().siGetArmorBonus())
            {
                leftArm.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            break;
        case 1:
            if(attackBonus >= rightArm.getArmArmor().siGetArmorBonus())
            {
                rightArm.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 2:
            if(attackBonus >= leftLeg.getLegArmor().siGetArmorBonus())
            {
      
                leftLeg.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 3:
            if(attackBonus >= rightLeg.getLegArmor().siGetArmorBonus())
            {
                rightLeg.ApplyDamage(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
        case 4:
            if(attackBonus >= getHead().getHeadArmor().siGetArmorBonus())
            {
                getHead().damageHead(damage);
                SubtractFromTotalHealth(damage);
            
            }
            break;
        case 5:
            if(attackBonus >= getChest().getChestArmor().siGetArmorBonus())
            {
                getChest().damageChest(damage);
                SubtractFromTotalHealth(damage);
            }
            
            break;
    
    }
    
    std::cout << "Total Health left: " << getTotalHealth() << "\n";

    
}

 void HumanoidBody::CalculateHealth()
{
    int totalHealth = leftArm.getLimbHealth() + rightArm.getLimbHealth() + leftLeg.getLimbHealth() + rightLeg.getLimbHealth() + getHead().getHeadHealth() + getChest().getChestHealth();
    setTotalHealth(totalHealth);
    
    
    
    
}