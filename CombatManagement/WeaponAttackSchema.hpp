//
//  WeaponAttackSchema.hpp
//  Colony
//
//  Created by Sean on 2/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Weapon.hpp"
#include "BaseCreature.hpp"

#ifndef WeaponAttackSchema_hpp
#define WeaponAttackSchema_hpp

#include <stdio.h>


//Contains all of the information needed for an attack
typedef struct _AttackParams
{
    int attackValue;
    int damage;
    bool isRanged;
        
}AttackParams;

class WeaponAttackSchema
{
private:
   
    
    
public:
     std::vector<AttackParams> attacks;
    WeaponAttackSchema(BaseCreature &creature);
    WeaponAttackSchema();
    WeaponAttackSchema(const WeaponAttackSchema &schema);
    void setSchema(BaseCreature &creature);
};




#endif /* WeaponAttackSchema_hpp */
