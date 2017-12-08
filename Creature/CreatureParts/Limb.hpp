//
//  Limb.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Limb_hpp
#define Limb_hpp

#include <stdio.h>
#include "Appendage.hpp"

enum LimbType
{
    enArm,
    enLeg,
    enArmRight,
    enArmLeft,
    enLegRight,
    enLegLeft

};

class Limb
{
    
private:
    LimbType limbType;
    int limbHealth;
    
public:
    Limb();
    Limb(LimbType _limbType);
    LimbType getLimbType();
    int getLimbHealth();
    
    void setLimbType(LimbType _limbType);
    void setLimbHealth(int _limbHealth);
    void ApplyDamage(int damage);
    
};

#endif /* Limb_hpp */
