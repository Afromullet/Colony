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
                
                std::cout << "Start health\n" << leftArm.getLimbHealth();
                std::cout << "LArm Attack\n";
                leftArm.ApplyDamage(damage);
                std::cout << "Health left\n" << leftArm.getLimbHealth();
            break;
        case 1:
            if(attackBonus >= rightArm.getArmArmor().siGetArmorBonus())
                std::cout << "RArm Attack\n";
            std::cout << "Start health\n" << rightArm.getLimbHealth();
                rightArm.ApplyDamage(damage);
                std::cout << "Health left\n" << rightArm.getLimbHealth();
            break;
        case 2:
            if(attackBonus >= leftLeg.getLegArmor().siGetArmorBonus())
                std::cout << "LLeg Attack\n";
            std::cout << "start left\n" << leftLeg.getLimbHealth();
                leftLeg.ApplyDamage(damage);
                std::cout << "Health left\n" << leftLeg.getLimbHealth();
            break;
        case 3:
            if(attackBonus >= rightLeg.getLegArmor().siGetArmorBonus())
                std::cout << "RLeg Attack\n";
            std::cout << "start left\n" << rightLeg.getLimbHealth();
                rightLeg.ApplyDamage(damage);
             std::cout << "Health left\n" << rightLeg.getLimbHealth();
            break;
        case 4:
            if(attackBonus >= getHead().getHeadArmor().siGetArmorBonus())
                std::cout << "Head Attack\n";
            std::cout << "start left\n" << getHead().getHeadHealth();
                getHead().damageHead(damage);
            std::cout << "Health left\n" << getHead().getHeadHealth();
            break;
        case 5:
            if(attackBonus >= getChest().getChestArmor().siGetArmorBonus())
                std::cout << "Chest Attack\n";
            std::cout << "start left\n" << getChest().getChestHealth();
                getChest().damageChest(damage);
            std::cout << "Health left\n" << getChest().getChestHealth();
            break;
    
    }

    
}

 void HumanoidBody::CalculateHealth()
{
    
}