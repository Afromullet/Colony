//
//  AttackHandler.cpp
//  Colony
//
//  Created by Sean on 3/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "AttackHandler.hpp"
#include "BodyGraphGetters.hpp"
#include <iostream>

void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender)
{
    attacker.calculateAttackParameters();
    
    
    
    for(int i = 0; i < attacker.attacks.size(); i++)
    {
        int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
        
        if(!attacker.attacks.at(i).isRangedAttack)
        {
            
            std::cout << "\n Attack Value, Armor Bonus: " << attacker.attacks.at(i).attackValue << "," << defender.body.anatomyGraph[target].getArmor().siGetArmorBonus() << "\Damage " << attacker.attacks.at(i).damage;
            if(attacker.attacks.at(i).attackValue > defender.body.anatomyGraph[target].getArmor().siGetArmorBonus())
            {
                std::cout << "\n Hit";
                defender.body.anatomyGraph[target].ApplyDamage(attacker.attacks.at(i).damage);
                defender.setTotalHealth(defender.getTotalHealth() - attacker.attacks.at(i).damage);
                
            }
            else
            {
                std::cout << "\n Miss";
                
                
            }
            
            std::cout << "\n Remaining health" <<  defender.body.anatomyGraph[target].getHealth();
            std::cout << "\n Remaining total health " << defender.getTotalHealth();
        }
           
        //if(attackers.attacks.at(i).attackValue > )
        
    }
    
}

void AttackCreature_Ranged(BaseCreature &attacker,BaseCreature &defender)
{
    attacker.calculateAttackParameters();
    
    
    int distance = std::abs(attacker.getPosition().x - defender.getPosition().x) + std::abs(attacker.getPosition().y - defender.getPosition().y);
    
    
    
    for(int i = 0; i < attacker.attacks.size(); i++)
    {
        int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
        
         std::cout << "\n Weapon range " << attacker.attacks.at(i).range;
        std::cout << "\n Is Ranged " << attacker.attacks.at(i).isRangedAttack;
        
        if(attacker.attacks.at(i).isRangedAttack)
        {
            
           
            if(attacker.attacks.at(i).range < distance)
            {
                std::cout << "\n Target too far away";
                continue;
            }
            std::cout << "\n Attack Value, Armor Bonus: " << attacker.attacks.at(i).attackValue << "," << defender.body.anatomyGraph[target].getArmor().siGetArmorBonus();
            if(attacker.attacks.at(i).attackValue > defender.body.anatomyGraph[target].getArmor().siGetArmorBonus())
            {
                std::cout << "\n Hit";
                defender.body.anatomyGraph[target].ApplyDamage(attacker.attacks.at(i).damage);
                defender.setTotalHealth(defender.getTotalHealth() - attacker.attacks.at(i).damage);
                
            }
            else
            {
                std::cout << "\n Miss";
                
                
            }
            
            std::cout << "\n Remaining health" <<  defender.body.anatomyGraph[target].getHealth();
            std::cout << "\n Remaining total health " << defender.getTotalHealth();
        }
        
        //if(attackers.attacks.at(i).attackValue > )
        
    }

}
