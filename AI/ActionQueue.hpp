//
//  ActionQueue.hpp
//  Colony
//
//  Created by Sean on 11/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ActionQueue_hpp
#define ActionQueue_hpp

#include <stdio.h>
#include <queue>
#include "Action.hpp"
#include "BasicMovementAction.hpp"
#include "BasicAttackAction.hpp"

class ActionQueue
{
private:
    std::priority_queue<Action*> actions;
    

    
public:
    void addAction(BasicMovementAction action);
    void addAction(BasicAttackAction action);
    
    void Execute();

    
};

#endif /* ActionQueue_hpp */
