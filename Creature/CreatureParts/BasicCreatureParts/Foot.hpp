//
//  Foot.hpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Foot_hpp
#define Foot_hpp

#include <stdio.h>
#include "Appendage.hpp"
#include "Armor.hpp"


class Foot : public Appendage
{

protected:
    Armor armor;
    
public:
    Foot();
    Foot(AppendageType _appendageType);
    
    Armor getFootArmor();
    
    void setFootArmor(Armor _armor);
};

#endif /* Foot_hpp */
