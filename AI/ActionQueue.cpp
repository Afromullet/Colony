//
//  ActionQueue.cpp
//  Colony
//
//  Created by Sean on 11/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ActionQueue.hpp"
#include <queue>

void ActionQueue::addAction(BasicMovementAction action)
{
    actions.push(new BasicMovementAction(action));
}

void ActionQueue::addAction(BasicAttackAction action)
{
    actions.push(new BasicAttackAction(action));
}

void ActionQueue::Execute()
{
    
    if(actions.size() == 0)
        return;
    
    Action *act = actions.top();
    act->Execute();
    
    if(act->actionComplete)
    {
        actions.pop();
        delete act;
    }

    
   
    
    
    
}
