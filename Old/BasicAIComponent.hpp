//
//  BasicAIComponent.hpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef BasicAIComponent_hpp
#define BasicAIComponent_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "MVector.hpp"
#include "EnumTypes.hpp"

class BasicAIComponent : public AIComponent
{
public:
    
    void update(GameObject &obj,Behaviors behavior);
    void seek(GameObject &obj);
    void randomMovement(GameObject &obj);
    
    
private:
    sf::Clock timer; //Clock of AI component used for timing
    sf::Time elapsed; //Stores the time elapsed since last call to clock function
    MVector desired; //Vector for desired location for seek ai
};

#endif /* BasicAIComponent_hpp */
