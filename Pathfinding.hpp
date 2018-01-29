//
//  Pathfinding.hpp
//  Colony
//
//  Created by Sean on 1/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//


#include <SFML/Graphics.hpp>

#include <stdio.h>
#include "Map.hpp"

#ifndef Pathfinding_hpp
#define Pathfinding_hpp




void BreadthFirstSearch(sf::Vector2i startPoint,Map &map);
std::vector<sf::Vector2i> GetBasicPath(sf::Vector2i startPoint,sf::Vector2i endPoint,Map &map);

std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint); //Returns the indices of the neighboring cells
std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint, Map &map,bool getNonPassable = true); //Returns the indices of the neighboring cells, with cells that are not in bounds removed. Optional argument is to determine whether to select tiles creature can pass

#endif /* Pathfinding_hpp */
