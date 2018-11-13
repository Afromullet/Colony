//
//  Vision.hpp
//  Colony
//
//  Created by Sean on 1/24/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

/*

#include "Map.hpp"

#ifndef Vision_hpp
#define Vision_hpp

#include <stdio.h>
#include "Pathfinding.hpp"
#include "Tile.hpp"
#include "BaseCreature.hpp"

class Vision
{
private:
    sf::Vector2i origin; //Vision needs an origin point from which it is calculated.
    std::vector<sf::Vector2i> visionArea; //Need to define a set of basic shapes..The vision area are coordinates on a 2d grid (tile positions)
public:
    
    
    bool operator==(const Vision &other) const;
    bool operator!=(const Vision &other) const;
    void operator=(const Vision &other);
    
    
    Vision();
    Vision(sf::Vector2i _origin);
    Vision(const Vision &other);
    
       void UpdateVision(Map &map,sf::Vector2i newOrigin); //If origin changes, vision area must also be updated
    
    
    std::vector<Tile> getVisibleTiles(Map &map) const;
    std::vector<BaseCreature> getVisibleCreatures(Map &map) const ;
    std::vector<Item*> getVisibleItems(Map &map);
    std::vector<GridLocation> getVisibleItemLocation(Map &map) const ;
    std::vector<GridLocation> getVisibleCreatureLocation(Map &map) const ;
    std::vector<sf::Vector2i> getVisibleCoordinates(Map &map) const ;
    sf::Vector2i getOrigin() const ;
    
    void setOrigin(sf::Vector2i newOrigin);
 
    
    
   
    
    
};

*/
#endif /* Vision_hpp */
