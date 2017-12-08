//
//  Arm.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Arm_hpp
#define Arm_hpp

#include <stdio.h>

#include "Limb.hpp"
#include "Hand.hpp"


class Arm : public Limb
{
protected:
    Hand hand;
    Armor armor;
public:
    Arm();
    Arm(LimbType _limbType,AppendageType _appendageType);
    
    void setArmArmor(Armor _armor);
    void setHandArmor(Armor _armor);
    
    Armor getArmArmor();
    Armor getHandArmor();
    

    
};




#endif /* Arm_hpp */
