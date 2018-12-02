//
//  BasicAttackAction.hpp
//  Colony
//
//  Created by Sean on 11/25/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BasicAttackAction_hpp
#define BasicAttackAction_hpp

#include <stdio.h>
#include "Action.hpp"
#include "BaseCreature.hpp"


class BasicAttackAction : public Action
{
    
private:
    BaseCreature &attacker;
    BaseCreature &defender;
    
public:
    BasicAttackAction(BaseCreature &a, BaseCreature &d);
    BasicAttackAction(const BasicAttackAction &other);
    ~BasicAttackAction()
    {
        
    }
    
    
    
    
    virtual void Execute();
    
    
};


#endif /* BasicAttackAction_hpp */
