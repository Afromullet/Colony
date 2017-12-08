//
//  EdgeDetection.hpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef EdgeDetection_hpp
#define EdgeDetection_hpp

#include <stdio.h>
#include "GameObject.hpp"

class EdgeDetection : public CollisionComponent
{
public:
    void update(GameObject& obj);
};

#endif /* EdgeDetection_hpp */
