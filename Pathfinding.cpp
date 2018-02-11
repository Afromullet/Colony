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
           
            std::cout << "\n Cost" << it->second;
            return it->second;
        }
        
    }
    return -1;
    
}

std::vector<GridLocation> recontructPath(GridLocation start,GridLocation end,std::map<GridLocation,GridLocation> cameFrom)
{
    std::vector<GridLocation> path;
    GridLocation current = end;
    
    
    
    while(current != start)
    {
        
        path.push_back(current);
        current = cameFrom[current];
        std::cout << "\ncurrent " << current.x << "," << current.y;
        if(current.x == start.x && current.y == start.y)
            break;
    }
    
    std::reverse(path.begin(), path.end());
    
    for(int i = 0; i < path.size(); i++)
    {
        std::cout << "\n (X,Y) " << path.at(i).x << "," << path.at(i).y;
    }
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
    std::cout << "\n Cost so far size " << costSoFar.size();
 
 
   
    std::vector<sf::Vector2i> neighbors;
    GridLocation curLocation;
    GridLocation nextLocation;
    

    while(!frontier.empty())
    {
        AStarNode current = frontier.top();
        frontier.pop();
        current.x = frontier.top().x;
        
        //std::cout << "\n Current x,y " << current.x << "," <<  current.y;
        // std::cout << "\n Goal x,y " << end.x << "," <<  end.y;
        
        
        if(current.x == end.x && current.y == end.y)
        {
            break;
        }
        
        neighbors = GetNeighbors(sf::Vector2i(current.x,current.y));
        for(int i = 0; i < neighbors.size(); i++)
        {
             int newCost = costSoFar[curLocation] + 1;
         
           
            nextLocation.x = neighbors.at(i).x;
          //  std::cout << "\n Next: " << nextLocation.x;
            nextLocation.y = neighbors.at(i).y;
            curLocation.x = current.x;
            curLocation.y = current.y;
           
            
            //TODO, should it be newCost <= or <
            if(!searchCostSoFar(costSoFar, neighbors.at(i)) || newCost <= getCost(costSoFar, neighbors.at(i)))
            {
                

      
                if(!map.isInBounds(neighbors.at(i)))
                    continue;
                
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

/*
 
 
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
 std::cout << "\n Cost so far size " << costSoFar.size();
 
 
 
 std::vector<sf::Vector2i> neighbors;
 GridLocation curLocation;
 GridLocation nextLocation;
 
 
 while(!frontier.empty())
 {
 AStarNode current = frontier.top();
 frontier.pop();
 current.x = frontier.top().x;
 
 //std::cout << "\n Current x,y " << current.x << "," <<  current.y;
 // std::cout << "\n Goal x,y " << end.x << "," <<  end.y;
 
 
 if(current.x == end.x && current.y == end.y)
 {
 break;
 }
 
 neighbors = GetNeighbors(sf::Vector2i(current.x,current.y));
 for(int i = 0; i < neighbors.size(); i++)
 {
 int newCost = costSoFar[curLocation] + 1;
 
 
 nextLocation.x = neighbors.at(i).x;
 //  std::cout << "\n Next: " << nextLocation.x;
 nextLocation.y = neighbors.at(i).y;
 curLocation.x = current.x;
 curLocation.y = current.y;
 
 
 //TODO, should it be newCost <= or <
 if(!searchCostSoFar(costSoFar, neighbors.at(i)) || newCost <= getCost(costSoFar, neighbors.at(i)))
 {
 
 
 
 if(!map.isInBounds(neighbors.at(i)))
 continue;
 
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

 
 */

/*
 
 //Todo pass cameFrom by reference
 std::map<GridLocation,GridLocation> aStarSearch(Map &map, GridLocation start, GridLocation end)
 {
 
 
 std::map<GridLocation,GridLocation> cameFrom;
 std::map<GridLocation,int> costSoFar;
 
 
 AStarNode tempNode;
 
 tempNode.x = start.x;
 tempNode.y = start.y;
 tempNode.cost = map.Map2D[start.x][start.y].movementCost;
 
 std::priority_queue<AStarNode> frontier;
 
 frontier.emplace(tempNode);
 
 
 
 
 
 
 cameFrom[start] = start;
 
 costSoFar[start] = 0;
 
 std::vector<sf::Vector2i> neighbors;
 GridLocation curLocation;
 GridLocation nextLocation;
 
 
 while(!frontier.empty())
 {
 AStarNode current = frontier.top();
 frontier.pop();
 current.x = frontier.top().x;
 std::cout << "\n (x,y) " << current.x << "," << current.y;
 
 std::cout << "\nCur vs end " << current.x << "," << current.y << " " << end.x << "," << end.y;
 if(current.x == end.x && current.y == end.y)
 {
 break;
 }
 
 neighbors = GetNeighbors(sf::Vector2i(current.x,current.y));
 for(int i = 0; i < neighbors.size(); i++)
 {
 
 
 nextLocation.x = neighbors.at(i).x;
 std::cout << "\n Next: " << nextLocation.x;
 nextLocation.y = neighbors.at(i).y;
 curLocation.x = current.x;
 curLocation.y = current.y;
 int newCost = costSoFar[curLocation] + 1;
 
 
 if(!searchCostSoFar(costSoFar, sf::Vector2i(neighbors.at(i).x,neighbors.at(i).y)) || getCost(costSoFar, neighbors.at(i)))
 {
 
 costSoFar[nextLocation] = newCost;
 int priority = newCost + aStarHeuristic(nextLocation, end);
 tempNode.x = nextLocation.x;
 tempNode.y = nextLocation.y;
 //std::cout << "\n Temp (x,y) " << tempNode.x << "," << tempNode.y;
 frontier.emplace(tempNode);
 cameFrom[nextLocation] = curLocation;
 
 }
 
 
 
 }
 
 
 }
 
 std::cout<<  "\n" << cameFrom.size();
 std::cout<<  "\n" << cameFrom.size();
 
 return cameFrom;
 
 
 
 
 
 
 }
 
*/


//sf::Vector2i

std::vector<PosPair> DA(sf::Vector2i startPoint,sf::Vector2i endPoint,Map &map)
{
 
    if(!map.isInBounds(startPoint))
        std::cout << "\nBFS starting point not in  bounds";
 
    Tile curTile = map.Map2D[startPoint.x][startPoint.y];
    std::queue<int> frontier;
    frontier.push(curTile.index);
 
    std::vector<PosPair> cameFrom;
    std::map<int,double> costSoFar;
 
    std::set<int> visited;
 
    int goalIndex = map.Map2D[endPoint.x][endPoint.y].index;
    visited.insert(curTile.index);
    
    PosPair tPair;
    
    tPair.origin = curTile.index;
    tPair.destination = curTile.index;
    
    
    std::vector<int> neighbors;
    
    
    
    bool posFound = false;
    while(!frontier.empty())
    {
        int current = frontier.front();
        frontier.pop();
        
        neighbors =  GetNeighborIndices(current,map);
        //std::cout << "\nVisiting " << current;
        
        
        if(current == goalIndex)
        {
            std::cout << "\n Goal Index " << goalIndex;
            
            
            tPair.destination = goalIndex;
            tPair.origin = current;
            cameFrom.push_back(tPair);
            break;
        }
        for(int i=0; i < neighbors.size(); i++)
        {
            for(int j=0; j < cameFrom.size(); j++)
            {
                if(cameFrom.at(j).destination == neighbors.at(i))
                {
                    posFound = true;
                }
            }
            
            
            if(posFound == false)
            {
                frontier.push(neighbors.at(i));
                tPair.origin = current;
                tPair.destination = neighbors.at(i);
                cameFrom.push_back(tPair);
                
            }
            posFound = false;
        }
        
        
        
        
        
        
        
    }
    
    return cameFrom;
    
    
    
    
}




std::vector<PosPair> BFS(sf::Vector2i startPoint,sf::Vector2i endPoint,Map &map)
{
    
    if(!map.isInBounds(startPoint))
        std::cout << "\nBFS starting point not in  bounds";
    
    Tile curTile = map.Map2D[startPoint.x][startPoint.y];
    std::queue<int> frontier;
    frontier.push(curTile.index);
    
    std::vector<PosPair> cameFrom;
    
    std::set<int> visited;
    
    int goalIndex = map.Map2D[endPoint.x][endPoint.y].index;
    visited.insert(curTile.index);
    
    PosPair tPair;
   
    tPair.origin = curTile.index;
    tPair.destination = curTile.index;
    
    
    std::vector<int> neighbors;
    
    bool posFound = false;
    while(!frontier.empty())
    {
        int current = frontier.front();
        frontier.pop();
        
        neighbors =  GetNeighborIndices(current,map);
        //std::cout << "\nVisiting " << current;
        
        
        if(current == goalIndex)
        {
            std::cout << "\n Goal Index " << goalIndex;
            
            
            tPair.destination = goalIndex;
            tPair.origin = current;
            cameFrom.push_back(tPair);
            break;
        }
        for(int i=0; i < neighbors.size(); i++)
        {
            for(int j=0; j < cameFrom.size(); j++)
            {
                if(cameFrom.at(j).destination == neighbors.at(i))
                {
                    posFound = true;
                }
            }
            
            
            if(posFound == false)
            {
                frontier.push(neighbors.at(i));
                tPair.origin = current;
                tPair.destination = neighbors.at(i);
                cameFrom.push_back(tPair);
                
            }
            posFound = false;
        }
        
        
        
        
        
        
        
    }
    
    return cameFrom;
    
    
    
    
}

/*
std::vector<PosPair> BFS(sf::Vector2i startPoint,sf::Vector2i endPoint,Map &map)
{
    
    if(!map.isInBounds(startPoint))
        std::cout << "\nBFS starting point not in  bounds";
    
    Tile curTile = map.Map2D[startPoint.x][startPoint.y];
    std::queue<int> frontier;
    frontier.push(curTile.index);
    
    std::vector<PosPair> cameFrom;
    
    std::set<int> visited;
    
    int goalIndex = map.Map2D[endPoint.x][endPoint.y].index;
    
    
    visited.insert(curTile.index);
    
    PosPair tPair;
    PosPair nextPos;
    tPair.origin = curTile.index;
    tPair.destination = curTile.index;
    
    
    
    
    
    std::vector<int> neighbors;
    
    bool posFound = false;
    while(!frontier.empty())
    {
        int current = frontier.front();
        frontier.pop();
        
        neighbors =  GetNeighborIndices(current,map);
        //std::cout << "\nVisiting " << current;
        
        
        if(current == goalIndex)
        {
            std::cout << "\n Goal Index " << goalIndex;
            
            
            tPair.destination = goalIndex;
            tPair.origin = current;
            cameFrom.push_back(tPair);
            break;
        }
        for(int i=0; i < neighbors.size(); i++)
        {
            for(int j=0; j < cameFrom.size(); j++)
            {
                if(cameFrom.at(j).destination == neighbors.at(i))
                {
                    posFound = true;
                }
            }
            
            
            if(posFound == false)
            {
                frontier.push(neighbors.at(i));
                tPair.origin = current;
                tPair.destination = neighbors.at(i);
                cameFrom.push_back(tPair);
                
            }
            posFound = false;
        }
        
        
    

        
        
        
    }
    
    return cameFrom;
    

    
    
}
*/

std::vector<int> GetNeighborIndices(int i,Map &map)
{
    std::vector<int> tempPoints;
    int count = 0;
    
    sf::Vector2i startPoint = map.getCoordinates(i);
    
  

   
    
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            sf::Vector2i newPos(startPoint.x+i,startPoint.y+j);

            //Don't want to add myself
            if(i == 0 && j == 0)
            {
                
            }
            else
            {
             
           
                
                if(map.isInBounds(newPos))
                    tempPoints.push_back(map.Map2D[newPos.x][newPos.y].index);
                
              
            }
            
        }
    }
    
    return tempPoints;
    

    
}


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
        
        if(current.x == endPoint.x && current.y == endPoint.y)
            break;
        
        for(int i = 0; i < neighbors.size(); i++)
        {
            if(!map.isInBounds(neighbors.at(i)))
                continue;
  
            if(!map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited)
            {
                
                map.Map2D[neighbors.at(i).x][neighbors.at(i).y].visited = true;
                
                
                //TODO use vector find instead of searching like this
                bool entryFound = false;
                for(int j = 0; j < visited.size(); j++)
                {
                    if(visited.at(j).x == neighbors.at(i).x && visited.at(j).y == neighbors.at(i).y)
                        entryFound = false;
                }
                
                frontier.push(neighbors.at(i));
                if(!entryFound)
                {
                    visited.push_back(neighbors.at(i));
                    
                }
                
                
                
                
              
            }
       
        }
    }
    
    current = startPoint;
    std::vector<sf::Vector2i> path;
    

 

     
     


    
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



int ManhattanDistance(sf::Vector2i start,sf::Vector2i end)
{
    return abs(start.x - end.x) + abs(start.y - end.y);
}