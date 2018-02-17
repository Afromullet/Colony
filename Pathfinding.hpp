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

struct GridLocation
{
    int x;
    int y;
    
};

struct AStarNode
{
    int x,y;
    int cost;
};

bool operator <(const AStarNode& lhs, const AStarNode& rhs);
bool operator ==(const AStarNode& lhs, const AStarNode& rhs);

bool operator ==(const GridLocation& lhs, const GridLocation& rhs);
bool operator != (const GridLocation& lhs, const GridLocation& rhs);
bool operator < (const GridLocation& a, const GridLocation& b);


inline int aStarHeuristic(GridLocation a, GridLocation b)
{
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::map<GridLocation,GridLocation> aStarSearch(Map &map, GridLocation start, GridLocation end);
std::vector<GridLocation> recontructPath(GridLocation start,GridLocation end,std::map<GridLocation,GridLocation> cameFrom);


typedef struct _PosPair
{
    int origin;
    int destination;
    int movCost;
}PosPair;


bool searchCostSoFar(std::map<GridLocation,int> &costSoFarMap, sf::Vector2i position);
int getCost(std::map<GridLocation,int> &costSoFarMap, sf::Vector2i position);
int getCostBetween(GridLocation a, GridLocation b, Map &map);





std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint, Map &map,bool getNonPassable = true); //Returns the indices of the neighboring cells, with cells that are not in bounds removed. Optional argument is to determine whether to select tiles creature can pass

int ManhattanDistance(sf::Vector2i start,sf::Vector2i end);

#endif /* Pathfinding_hpp */
