//
//  Throwable.cpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Throwable.hpp"


Throwable::Throwable() : range(0),damage(0)
{
    
}

Throwable::Throwable(int _range, int _damage) : range(_range),damage(_damage)
{
    
}
void Throwable::setAreaOfEffect(std::vector<sf::Vector2i> _areaOfEffect)
{
    areaOfEffect = _areaOfEffect;
    
}