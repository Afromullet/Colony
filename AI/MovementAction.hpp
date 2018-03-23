//
//  MovementAction.hpp
//  Colony
//
//  Created by Sean on 3/22/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef MovementAction_hpp
#define MovementAction_hpp

#include <stdio.h>
#include "AbstractAction.hpp"
#include "Pathfinding.hpp"
#include <vector>



class BasicMovementAction : public AbstractAction
{
    
public:
    
    BasicMovementAction(Map &_map,BaseCreature &_creature);

    bool PrepareAction();
    bool PerformAction();
};


#endif /* MovementAction_hpp */
