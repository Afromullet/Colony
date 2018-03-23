//
//  BasicScoutAction.hpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef BasicScoutAction_hpp
#define BasicScoutAction_hpp

#include <stdio.h>
#include "AbstractAction.hpp"

class BasicScoutAction : public  AbstractAction
{
    BasicScoutAction(Map &_map,BaseCreature &_creature);
    
    bool PrepareAction();
    bool PerformAction();
};

#endif /* BasicScoutAction_hpp */
