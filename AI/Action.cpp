//
//  Action.cpp
//  Colony
//
//  Created by Sean on 11/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Action.hpp"


Action::Action()
{
    priority = 0;
    actionComplete = false;
}

Action::Action(int prior)
{
    priority = prior;
}

void Action::setPriority(int val)
{
    priority = val;
}


int Action::getPriority()
{
    return priority;
}

