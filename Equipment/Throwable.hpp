//
//  Throwable.hpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>


#ifndef Throwable_hpp
#define Throwable_hpp


class Throwable
{
    
    
public:
    Throwable();
    Throwable(int _range, int _damage);
    
    void setAreaOfEffect(std::vector<sf::Vector2i> _areaOfEffect);
    
private:
    int range;
    int damage;
    std::vector<sf::Vector2i> areaOfEffect;
};



#endif /* Throwable_hpp */
