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
#include "Wound.hpp"

void Single_Attack_Melee(AttackStats attack, BaseCreature &defender)
{
    int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
    defender.body.anatomyGraph[target].armor.getMaterialRef().PerformMaterialCalculations(attack.force,attack.contactArea,attack.enAttackForceType,attack.attackType);
    
    std::vector<AppliedForceEffect> &effects = defender.body.anatomyGraph[target].armor.getMaterialRef().getAppliedForceEffects();
    
    WoundCalculations woundCalcs(target);
    
    for(int i=0;i<effects.size();i++)
    {
        woundCalcs.ApplyWound(effects.at(i),defender.body.anatomyGraph);
    }
    
    
    
    
}

void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender)
{
    attacker.calculateAttackParameters();
    
    
    
    for(int i = 0; i < attacker.attacks.size(); i++)
    {
        int target = getRandomExternalBodyParts(defender.body.anatomyGraph);
        
        if(!attacker.attacks.at(i).isRangedAttack)
        {
            
       
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

//Performs the attack calculations for attacking a body part
void AttackBodyPart(AttackStats stats,int index,AnatomyGraph &graph)
{
    std::vector<AppliedForceEffect> effects = graph[index].ApplyAttack(stats); //For now only apply the first effect
    WoundCalculations woundCalcs(index);
    woundCalcs.ApplyWound(effects.at(0),graph);
}
