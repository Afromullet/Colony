//
//  AttackHandler.hpp
//  Colony
//
//  Created by Sean on 3/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//


#include "BaseCreature.hpp"
#ifndef AttackHandler_hpp
#define AttackHandler_hpp

#include <stdio.h>


void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender);
void AttackCreature_Ranged(BaseCreature &attacker,BaseCreature &defender);

#endif /* AttackHandler_hpp */
