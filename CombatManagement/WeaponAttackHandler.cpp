//
//  WeaponAttackHandler.cpp
//  Colony
//
//  Created by Sean on 2/19/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "WeaponAttackHandler.hpp"

//Performs an attack with all the attackers weapons
void FullAttack(BaseCreature &attacker,BaseCreature &defender)
{
    std::vector<AttackParams> &attacks = attacker.weaponAttackSchema.attacks;
    std::vector<BodyPart*> bodyPartSchema = defender.bodyPartSchema;
    int randNum,attackValue,damage;
    
    for(int i=0; i<attacks.size(); i++)
    {
        randNum = rand() % bodyPartSchema.size();
        attackValue = attacks.at(i).attackValue;
        damage = attacks.at(i).damage;
        
        
        
        
        if(attackValue >= bodyPartSchema.at(randNum)->getArmor().siGetArmorBonus())
        {
            std::cout << "Hit";
            bodyPartSchema.at(randNum)->ApplyDamage(damage);
            defender.totalHealth -= damage;
          
            std::cout << "\nTotal health left " << defender.totalHealth;
        }
        else
        {
            std::cout << "Miss";
        }
        
    }
    
}