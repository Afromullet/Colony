//
//  BasicMovementAction.hpp
//  Colony
//
//  Created by Sean on 11/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BasicMovementAction_hpp
#define BasicMovementAction_hpp

#include <stdio.h>
#include "Action.hpp"
#include "BaseCreature.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include "Pathfinding.hpp"

class BasicMovementAction : public Action
{
    
private:
    BaseCreature &creature;
    Map &map;
    std::queue<sf::Vector2i> path;
    
public:
    BasicMovementAction(BaseCreature &c, Map &m,std::vector<GridLocation> newPath);
    BasicMovementAction(const BasicMovementAction &other);
    ~BasicMovementAction()
    {
        
    }
    
    
    
    
    virtual void Execute();
    
    
};

#endif /* BasicMovementAction_hpp */
