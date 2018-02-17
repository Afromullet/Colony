//
//  Pathfinding.cpp
//  Colony
//
//  Created by Sean on 1/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Pathfinding.hpp"
#include <queue>
#include <map>
#include <set>
#include <fstream>

bool operator <(const AStarNode& lhs, const AStarNode& rhs)
{
    return lhs.cost > rhs.cost;
}

bool operator ==(const AStarNode& lhs, const AStarNode& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator ==(const GridLocation& lhs, const GridLocation& rhs)
{
     return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator != (const GridLocation& lhs, const GridLocation& rhs) {
    return !(lhs == rhs);
}

bool operator < (const GridLocation& a, const GridLocation& b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

bool searchCostSoFar(std::map<GridLocation,int> &costSoFarMap, sf::Vector2i position)
{
    std::map<GridLocation,int>::iterator it;
    for(it = costSoFarMap.begin(); it != costSoFarMap.end(); ++it)
    {
        //std::cout << "\nFirst xy " << it->first.x << "," << it->first.y << " " << position.x << "," << position.y;
        if((it->first.x == position.x) && (it->first.y == position.y))
        {
            return true;
        }

    }
    return false;
}


int getCost(std::map<GridLocation,int> &costSoFarMap, sf::Vector2i position)
{
    std::map<GridLocation,int>::iterator it;
    for(it = costSoFarMap.begin(); it != costSoFarMap.end(); ++it)
    {
        if((it->first.x == position.x) && (it->first.y == position.y))
        {
           
           // std::cout << "\n Cost" << it->second;
            return it->second;
        }
        
    }
    return -1;
    
}

std::vector<GridLocation> recontructPath(GridLocation start,GridLocation end,std::map<GridLocation,GridLocation> cameFrom)
{
    std::vector<GridLocation> path;
    GridLocation current = end;
    
    std::map<GridLocation,GridLocation>::reverse_iterator it;

    while(current != start)
    {
        
         //std::cout << "\ncurrent " << current.x << "," << current.y;
        path.push_back(current);
        current = cameFrom[current];
    
        if(current.x == start.x && current.y == start.y)
            break;
    }
    
    
    
    std::reverse(path.begin(), path.end());
    

   // std::cout << "\n Path size" << path.size();
    return path;
    
}

//Todo pass cameFrom by reference
std::map<GridLocation,GridLocation> aStarSearch(Map &map, GridLocation start, GridLocation end)
{
    
    
    std::map<GridLocation,GridLocation> cameFrom;
    std::map<GridLocation,int> costSoFar;
    std::priority_queue<AStarNode> frontier;
  
    
    AStarNode tempNode;
    
    tempNode.x = start.x;
    tempNode.y = start.y;
    tempNode.cost = 0;
    
    
    
    frontier.emplace(tempNode);
    cameFrom[start] = start;
    costSoFar[start] = 0;
    
 
 
   
    std::vector<sf::Vector2i> neighbors;
    GridLocation curLocation;
    GridLocation nextLocation;
    AStarNode endLocation;
    endLocation.x = end.x;
    endLocation.y = end.y;
    
 std::cout << "\nCost so far size " << costSoFar.size();
    while(!frontier.empty())
    {
        AStarNode current = frontier.top();
        frontier.pop();
      
        
        //std::cout << "\n Current x,y " << current.x << "," <<  current.y;
        // std::cout << "\n Goal x,y " << end.x << "," <<  end.y;
        
        
        if(current.x == endLocation.x && current.y == endLocation.y)
        {
            
            break;
        }
        
        neighbors = GetNeighbors(sf::Vector2i(current.x,current.y),map,false);
        
        
        for(int i = 0; i < neighbors.size(); i++)
        {
            if(!map.isInBounds(neighbors.at(i)))
                continue;
        
            //int newCost =1;
            // std::cout << "\nCost so far size " << costSoFar.size();
           
            nextLocation.x = neighbors.at(i).x;
       
            nextLocation.y = neighbors.at(i).y;
            curLocation.x = current.x;
            curLocation.y = current.y;
            int newCost = costSoFar[curLocation] + 1;//map.Map2D[current.x][current.y].movementCost;
             //int newCost = costSoFar[curLocation] + map.Map2D[current.x][current.y].movementCost;
            
            //TODO, should it be newCost <= or <
            if(!searchCostSoFar(costSoFar, neighbors.at(i)) || newCost < costSoFar[nextLocation])
            {
                

      
                
                costSoFar[nextLocation] = newCost;
           
                int priority = newCost + aStarHeuristic(nextLocation, end);
                tempNode.x = nextLocation.x;
                tempNode.y = nextLocation.y;
                //tempNode.cost = map.Map2D[nextLocation.x][nextLocation.y].movementCost;
                 //std::cout << "\n Temp (x,y) " << tempNode.x << "," << tempNode.y;
                tempNode.cost = priority;
                frontier.emplace(tempNode);
                cameFrom[nextLocation] = curLocation;
                   
            }
     
            
            
        }
        
        
    }
    
    std::cout<<  "\n" << cameFrom.size();
    std::cout<<  "\n" << cameFrom.size();
    
    return cameFrom;

    
    
    
    
    
}



//Returns the indices of the neighboring cells, with cells that are not in bounds removed. Optional argument is to determine whether to select tiles creature can pass

std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint, Map &map,bool getNonPassable)
{
    std::vector<sf::Vector2i> tempPoints;
    
    
    int count = 0;
    bool retVal;
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            sf::Vector2i newPos(startPoint.x+i,startPoint.y+j);
        
   
            if(map.isInBounds(newPos));
            {
             
                std::cout << "\n" << newPos.x << "," << newPos.y;
                //Don't want to add myself
                if(i == 0 && j == 0)
                {
                    
                }
                else
                {
                    
                
                    
                    //IsInBounds checks for the same thing, but for some reason, even when it returns false, it still goes into the loop, so here I'm checking again...
                    if( newPos.x < 0 || newPos.y < 0)
                        continue;
                    else if(newPos.x >= map.GetWidth() || newPos.y >= map.GetHeight())
                        continue;
                    if(getNonPassable)
                        tempPoints.push_back(newPos);
                    else if(map.Map2D[newPos.x][newPos.y].getCanHoldCreature())
                    {
                        tempPoints.push_back(newPos);
                    }
                }
            }
            
            
        }
    }
    
   
   
    return tempPoints;
    
}



int ManhattanDistance(sf::Vector2i start,sf::Vector2i end)
{
    return abs(start.x - end.x) + abs(start.y - end.y);
}