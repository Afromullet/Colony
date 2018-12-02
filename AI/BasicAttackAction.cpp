//
//  BasicAttackAction.cpp
//  Colony
//
//  Created by Sean on 11/25/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "BasicAttackAction.hpp"


BasicAttackAction::BasicAttackAction(BaseCreature &a, BaseCreature &d) : attacker(a),defender(d)
{

}

BasicAttackAction::BasicAttackAction(const BasicAttackAction &other) : Action(priority), attacker(other.attacker),defender(other.defender)
{
    
}

void BasicAttackAction::Execute()
{
    std::cout << "\n Attacking";
}
