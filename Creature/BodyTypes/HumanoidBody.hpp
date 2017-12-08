//
//  HumanoidBody.hpp
//  Colony
//
//  Created by Sean on 12/5/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef HumanoidBody_hpp
#define HumanoidBody_hpp

#include <stdio.h>
#include "Body.hpp"
#include "Arm.hpp"
#include "Leg.hpp"

class HumanoidBody : public Body
{
    
private:
    Arm leftArm;
    Arm rightArm;
    Leg leftLeg;
    Leg rightLeg;
public:
    HumanoidBody();
    void AttackRandomBodyPart(int attackBonus, int damage);
};


#endif /* HumanoidBody_hpp */
