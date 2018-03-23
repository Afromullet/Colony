//
//  ScoutingBehavior.cpp
//  Colony
//
//  Created by Sean on 3/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ScoutingBehavior.hpp"
#include <boost/random/uniform_int_distribution.hpp>

ScoutingBehavior::ScoutingBehavior()
{
    
}

void ScoutingBehavior::SelectAction()
{
    
}

void ScoutingBehavior::PerformAction()
{
    
}

void ScoutingBehavior::ExamineSurroundingTask(BaseCreature &creature,Map &map)
{
    std::vector<GridLocation> itemLocations = creature.vision.getVisibleItemLocation(map);
    
    for(int i=0; i < itemLocations.size(); i++)
    {
        std::cout << "\n(X,Y) " << itemLocations.at(i).x << "," << itemLocations.at(i).y;
    }
    
}

void ScoutingBehavior::AddSearchLocation(GridLocation location)
{
    
}

void ScoutingBehavior::SelectRandomSearchLocation(int searchWidth,int searchHeight,Map &map)
{
    
    GridLocation location;
    
    while(1)
    {
        
 
        location.x = rand() % searchWidth;
        location.y = rand() % searchHeight;
    
        if(map.Map2D[location.x][location.y].getCanHoldCreature())
        {
            searchLocations.push_back(location);
            break;
        }
        
    }
    
    
    
}

int ScoutingBehavior::getExplorationDistance()
{
    return explorationDistance;
}

void ScoutingBehavior::setExplorationDistance(int _distance)
{
    explorationDistance = _distance;
}

bool ScoutingBehavior::AddLocationToPath(BaseCreature &creature,Map &map,int index)
{
    if(index > searchLocations.size())
        return false;
    
    GridLocation start,end;
    start.x = creature.getPosition().x;
    start.y = creature.getPosition().y;
    
    end.x = searchLocations.at(index).x;
    end.y = searchLocations.at(index).y;
    
    std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(map,  start,  end);
    
    
    std::vector<GridLocation> path = recontructPath(start,end, cameFrom);
    // aStarSearch(caMap,  start,  end);
    std::vector<sf::Vector2i> walkPath;
    
    for(int i =0; i < path.size(); i++)
    {
        
        creature.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
        
    }
}

void ScoutingBehavior::RemoveLocationFromPath(int index)
{
    searchLocations.erase (searchLocations.begin()+index);
}


