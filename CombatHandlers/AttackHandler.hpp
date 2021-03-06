//
//  AttackHandler.hpp
//  Colony
//
//  Created by Sean on 3/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//



#ifndef AttackHandler_hpp
#define AttackHandler_hpp
#include "BaseCreature.hpp"
#include <stdio.h>
#include <string>
//#include "BodyGraphGetters.hpp"
#include "BodyGraph.hpp"
#include <iostream>
#include "Wound.hpp"





void Single_Attack_Melee(AttackStats &attack, BaseCreature &defender);
void AttackCreature_Melee(BaseCreature &attacker,BaseCreature &defender);
void AttackCreature_Ranged(BaseCreature &attacker,BaseCreature &defender);
void AttackBodyPart(AttackStats stats,int index,AnatomyGraph &graph);

std::string getAttackString(BaseCreature &attacker, BaseCreature &defender,AttackStats &stats);

#endif /* AttackHandler_hpp */
