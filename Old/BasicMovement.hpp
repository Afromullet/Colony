//
//  BasicMovement.hpp
//  Colony
//
//  Created by Sean on 7/28/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef BasicMovement_hpp
#define BasicMovement_hpp

#include <stdio.h>
#include "GameObject.hpp"

class BasicMovement : public MovComponent
{
    
    
    void update(GameObject& obj);
};


#endif /* BasicMovement_hpp */
