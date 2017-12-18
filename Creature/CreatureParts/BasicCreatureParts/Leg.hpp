//
//  Leg.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Leg_hpp
#define Leg_hpp

#include <stdio.h>
#include "Limb.hpp"
#include "Foot.hpp"




class Leg : public Limb
{
protected:
    Foot foot;
    Armor armor;
    
    
public:
    Leg();
    Leg(LimbType _limbType, AppendageType _appendageType);
    
    void setLegArmor(Armor _armor);
    void setFootArmor(Armor _armor);
    void SetLegType(LimbType _limbType);
    
    Armor getLegArmor();
    Armor getFootArmor();
    
    
    
    
};



#endif /* Leg_hpp */
