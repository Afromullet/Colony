//
//  Behavior.hpp
//  Colony
//
//  Created by Sean on 3/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Behavior_hpp
#define Behavior_hpp

#include <stdio.h>
#include "BaseCreature.hpp"


class Behavior
{
private:
  

    
    
public:
    Behavior();
    
    virtual void SelectAction() = 0;
    virtual void PerformAction() = 0;
    virtual void ExamineSurroundingTask(BaseCreature &creature,Map &map) = 0;
};

#endif /* Behavior_hpp */
