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

void Single_Attack_Melee(AttackStats attack, BaseCreature &defender);
void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender);
void AttackCreature_Ranged(BaseCreature &attacker,BaseCreature &defender);
void AttackBodyPart(AttackStats stats,int index,AnatomyGraph &graph);

#endif /* AttackHandler_hpp */
