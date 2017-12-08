//
//  EdgeDetection.cpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#include "EdgeDetection.hpp"
#include <SFML/Graphics.hpp>


void EdgeDetection::update(GameObject& obj)
{
    
    sf::Vector2u size = obj.window->getSize();
    
    
    
    if(obj.location.getX() > size.x)
    {
        obj.location.setX(size.x);
        obj.velocity.setX(obj.velocity.getX() * -1);
        
    }
    else if(obj.location.getX() < 0)
    {
        obj.velocity.setX(obj.velocity.getX() * -1);
        obj.location.setX(0);
    }
    
    if(obj.location.getY() > size.y)
    {
        obj.velocity.setY(obj.velocity.getY() * -1);
        obj.location.setY(size.y);
    }
    else if(obj.location.getY() < 0)
    {
        obj.velocity.setY(obj.velocity.getY() * -1);
        obj.location.setY(0);
    }
     
    
}
