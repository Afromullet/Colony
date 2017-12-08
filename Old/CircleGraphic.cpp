//
//  CircleGraphic.cpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "CircleGraphic.hpp"

void CircleGraphic::update(GameObject& obj)
{
    obj.shape.setPosition(obj.location.getX(),obj.location.getY());
    obj.window->draw(obj.shape);
    
}
