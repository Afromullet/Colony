//
//  WeaponAttackSchema.cpp
//  Colony
//
//  Created by Sean on 2/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "WeaponAttackSchema.hpp"

WeaponAttackSchema::WeaponAttackSchema(BaseCreature &creature)
{
    
    AttackParams tempParams;
    std::vector<BodyPart*>::iterator it;
    
    for(it = creature.bodyPartSchema.begin(); it != creature.bodyPartSchema.end(); ++it)
    {
        if((*it)->weapon.getWeaponClass() != enUndefinedWeaponClass)
        {
                       tempParams.damage = (*it)->weapon.getDamage();
            tempParams.attackValue = creature.getAttackValue();
            
            
            
            if(((*it)->weapon.getRange() > 1))
            {
                tempParams.isRanged = true;
                tempParams.damage += creature.getAgility();
                tempParams.attackValue += creature.getAgility();
                
                
                
            }
            else
            {
                tempParams.isRanged = false;;
                tempParams.damage  += creature.getStrength();
                tempParams.attackValue += creature.getStrength();
            }
            attacks.push_back(tempParams);
            
            
        }
        
    }
    
    
    //std::vector<Weapon
    
}

WeaponAttackSchema::WeaponAttackSchema()
{
    
}

WeaponAttackSchema::WeaponAttackSchema(const WeaponAttackSchema &schema)
{
    
}

void WeaponAttackSchema::setSchema(BaseCreature &creature)
{
    AttackParams tempParams;
    std::vector<BodyPart*>::iterator it;
    
    for(it = creature.bodyPartSchema.begin(); it != creature.bodyPartSchema.end(); ++it)
    {
        if((*it)->weapon.getWeaponClass() != enUndefinedWeaponClass)
        {
           
            tempParams.damage = (*it)->weapon.getDamage();
            tempParams.attackValue = creature.getAttackValue();
            
            
            
            if(((*it)->weapon.getRange() > 1))
            {
                tempParams.isRanged = true;
                tempParams.damage += creature.getAgility();
                tempParams.attackValue += creature.getAgility();
                
                
                
            }
            else
            {
                tempParams.isRanged = false;;
                tempParams.damage  += creature.getStrength();
                tempParams.attackValue += creature.getStrength();
            }
            attacks.push_back(tempParams);
            
            
        }
    
    }
    
    std::vector<AttackParams>::iterator iter;
    
    for(iter = attacks.begin(); iter != attacks.end(); ++iter)
    {
        std::cout << "\n" << iter->damage;
        
    }
    std::cout << "End";
}