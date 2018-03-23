//
//  Task.cpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Task.hpp"

Task::Task()
{
    
}

void Task::AddEdge(AbstractAction *action)
{
    
    boost::add_vertex(action,graph);
    

    
    
    
}
