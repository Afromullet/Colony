//
//  Body.cpp
//  Colony
//
//  Created by Sean on 12/4/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Body.hpp"

void Body::setBloodRemaining(float _bloodRemaining)
{
    
}

void Body::setHead(Head _head)
{
    head = _head;
}

void Body::setChest(Chest _chest)
{
    chest = _chest;
}

float Body::getBloodRemaining()
{
    return bloodRemaining;
}

Head Body::getHead()
{
    return head;
}

Chest Body::getChest()
{
    return chest;
}