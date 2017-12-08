//
//  BasicMovement.cpp
//  Colony
//
//  Created by Sean on 7/28/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "BasicMovement.hpp"


void BasicMovement::update(GameObject& obj)
{
    obj.velocity.add(obj.acceleration);
    obj.location.add(obj.velocity);
    obj.acceleration.mult(0);
    
}