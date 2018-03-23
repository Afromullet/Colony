//
//  ExamineAction.hpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ExamineAction_hpp
#define ExamineAction_hpp

#include <stdio.h>
#include "AbstractAction.hpp"

class BasicExamineSurroundingAction : public AbstractAction
{
protected:
    
public:
    BasicExamineSurroundingAction(Map &_map,BaseCreature &_creature);
    
    bool PrepareAction();
    bool PerformAction();
};


#endif /* ExamineAction_hpp */
