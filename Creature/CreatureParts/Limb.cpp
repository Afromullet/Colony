//
//  Limb.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Limb.hpp"

Limb::Limb()
{
    
}

Limb::Limb(LimbType _limbType) : limbType(_limbType)
{
    
}

LimbType Limb::getLimbType()
{
    return limbType;
}

int Limb::getLimbHealth()
{
    return limbHealth;
}

void Limb::setLimbType(LimbType _limbType)
{
    limbType = _limbType;
}

void Limb::setLimbHealth(int _limbHealth)
{
    limbHealth = _limbHealth;
}

void Limb::ApplyDamage(int damage)
{
    limbHealth -= damage;
}