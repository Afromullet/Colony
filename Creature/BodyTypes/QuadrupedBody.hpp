//
//  QuadrupedBody.hpp
//  Colony
//
//  Created by Sean on 12/7/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef QuadrupedBody_hpp
#define QuadrupedBody_hpp

#include <stdio.h>
#include "Body.hpp"
#include "Leg.hpp"

//Four legged creature. Wolves, tigers etc

class QuadrupedBody : public Body
{
    
private:
    Leg fronLeftLeg;
    Leg frontRightLeg;
    Leg backLeftLeg;
    Leg backRightLeg;
public:
    QuadrupedBody();
    void AttackRandomBodyPart(int attackBonus, int damage);
     void CalculateHealth();
    
    QuadrupedBody* clone() const
    {
        return new QuadrupedBody(*this);
    }
    
    QuadrupedBody *create() const
    {
        return new QuadrupedBody();
    }
    
    std::list<AttackParameters> getAttacks();
    void EquipItem(Item *item);
    void PrintEquippedItems();

};


#endif /* QuadrupedBody_hpp */
