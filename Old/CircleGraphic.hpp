//
//  CircleGraphic.hpp
//  Colony
//
//  Created by Sean on 7/29/16.
//  Copyright © 2016 Afromullet. All rights reserved.
//

#ifndef CircleGraphic_hpp
#define CircleGraphic_hpp

#include <stdio.h>
#include "GameObject.hpp"

class CircleGraphic : public GraphicComponent
{
    
public:
    //sf::CircleShape shape;
    //sf::Color color;
    //float radius;
    void update(GameObject& obj);
    
    
};

#endif /* CircleGraphic_hpp */
