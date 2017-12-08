//
//  Appendage.cpp
//  Colony
//
//  Created by Sean on 12/2/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Appendage.hpp"

Appendage::Appendage()
{
    
}

Appendage::Appendage(AppendageType _appendageType) : appendageType(_appendageType)
{
    
}

AppendageType Appendage::getAppendageType()
{
    return appendageType;
}

int Appendage::getHealth()
{
    return appendageHealth;
}

void Appendage::setAppendageType(AppendageType _appendageType)
{
    appendageType = _appendageType;
}

void Appendage::setHealth(int _health)
{
    appendageHealth = _health;
}