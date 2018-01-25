//
//  Vision.hpp
//  Colony
//
//  Created by Sean on 1/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Vision_hpp
#define Vision_hpp

#include <stdio.h>
#include "Map.hpp"


class Vision
{
private:
    sf::Vector2i origin; //Vision needs an origin point from which it is calculated.
    std::vector<sf::Vector2i> visionArea; //Need to define a set of basic shapes..The vision area are coordinates on a 2d grid (tile positions)
    
    
    
    
public:
    Vision();
    Vision(sf::Vector2i _origin);
    
    
    
    
    std::vector<Tile*> getVisibleTiles(Map &map);
    std::vector<BaseCreature> getVisibleCreatures(Map &map);
    std::vector<BaseCreature> getVisibleItems(Map &map);
    
    
    void UpdateVision(Map &map,sf::Vector2i newOrigin); //If origin changes, vision area must also be updated
    
    
    void setOrigin(sf::Vector2i newOrigin);
    
    sf::Vector2i getOrigin();
};


#endif /* Vision_hpp */
