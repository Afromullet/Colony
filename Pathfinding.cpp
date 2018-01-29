//
//  Pathfinding.cpp
//  Colony
//
//  Created by Sean on 1/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Pathfinding.hpp"
#include <queue>

//Pathfinding methods based on https://www.redblobgames.com/pathfinding/a-star/introduction.html
void BreadthFirstSearch(sf::Vector2i startPoint,Map &map)
{
    
    if(!map.isInBounds(startPoint))
    {
        std::cout << "\nBFS starting point not in  bounds";
    }
    std::queue<sf::Vector2i> frontier;
    std::vector<sf::Vector2i> visited;
    
    visited.push_back(startPoint);
    frontier.push(startPoint);
    map.Map2D[startPoint.x][startPoint.y].visited = true;
    
    sf::Vector2i current;
    std::vector<sf::Vector2i> neighbors;
    int count = 0;
    while(!frontier.empty())
    {
        current = frontier.front();
        frontier.pop();
        neighbors = GetNeighbors(current);
        
        for(int i = 0; i < neighbors.size(); i++)
        {
            if(!map.isInBounds(neighbors.at(i)))
                continue;
            
            if(!map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited)
            {
                map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited = true;
                frontier.push(neighbors.at(i));
                visited.push_back(neighbors.at(i));
            }
        }
    }
}

//Helps navigate to a specific point from startPoint..The endpoint is the offset from startpoint
//Right now returns all visited nodes..Currently, when moving the creature checks if we arrived at destination
//TODO handle that in the function
std::vector<sf::Vector2i> GetBasicPath(sf::Vector2i startPoint,sf::Vector2i endPoint,Map &map)
{
    
    if(!map.isInBounds(startPoint))
    {
        std::cout << "\nBFS starting point not in  bounds";
    }
    std::queue<sf::Vector2i> frontier;
    std::vector<sf::Vector2i> visited;
    
    visited.push_back(startPoint);
    frontier.push(startPoint);
    map.Map2D[startPoint.x][startPoint.y].visited = true;
    
    sf::Vector2i current;
    std::vector<sf::Vector2i> neighbors;
    int count = 0;
    while(!frontier.empty())
    {
        current = frontier.front();
        frontier.pop();
        neighbors = GetNeighbors(current,map);
        
        for(int i = 0; i < neighbors.size(); i++)
        {
            if(!map.isInBounds(neighbors.at(i)))
                continue;
            
            if(!map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited)
            {
                
                map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited = true;
                frontier.push(neighbors.at(i));
                visited.push_back(neighbors.at(i));
                
                
              
            }
       
        }
    }
    
    current = startPoint;
    std::vector<sf::Vector2i> path;
    

 
    

    /*
    int v = 0;
    for(int i=0; i < visited.size(); i++)
    {
        v++;
        current = visited.at(i);
        if(current.x == endPoint.x && current.y == endPoint.y)
        {
            
            path.push_back(current);
            std::cout << "\n" << current.x << "," << current.y;
      

            break;
        }
        
        
        path.push_back(current);
        
        
        
        
    }
     */
     
     


    
    current = startPoint;
    
    for(int i=visited.size() - 1; i >= 0; i--)
    {
  
        current = visited.at(i);
        if(current.x == endPoint.x && current.y == endPoint.y)
        {
     
            path.push_back(current);
            std::cout << "\n" << current.x << "," << current.y;
    
            break;
        }
       
       
                path.push_back(current);
        
        
        
        
    }
     
    
    
    map.ResetVisited();

    return path;
    
}

//Returns the indices of the neighboring cells
std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint)
{
    
    std::vector<sf::Vector2i> tempPoints;
    
    
    int count = 0;
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            //Don't want to add myself
            if(i == 0 && j == 0)
            {
                
            }
            else
            {
                tempPoints.push_back(sf::Vector2i(startPoint.x+ i,startPoint.y+j));
            }
      
        }
    }
        
    return tempPoints;
    
}


//Returns the indices of the neighboring cells, with cells that are not in bounds removed. Optional argument is to determine whether to select tiles creature can pass

std::vector<sf::Vector2i> GetNeighbors(sf::Vector2i startPoint, Map &map,bool getNonPassable)
{
    std::vector<sf::Vector2i> tempPoints;
    
    
    int count = 0;
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            sf::Vector2i newPos(startPoint.x+i,startPoint.y+j);
            if(map.isInBounds(newPos));
            {
             
                if(getNonPassable)
                    tempPoints.push_back(newPos);
                else if(map.Map2D[newPos.x][newPos.y].getCanHoldCreature())
                {
                    tempPoints.push_back(newPos);
                }
            }
            
            
        }
    }
    
    return tempPoints;
    
}