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

//A basic humanoid. Maybe a regular human, an orc, etc

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
     void CalculateHealth();
   
    HumanoidBody* clone() const
    {
        return new HumanoidBody(*this);
    }
    
    HumanoidBody *create() const
    {
        return new HumanoidBody();
    }
    
    std::list<AttackParameters> getAttacks();
    void EquipItem(Item *item);
    void PrintEquippedItems();

    
};


#endif /* HumanoidBody_hpp */
