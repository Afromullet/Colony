//
//  ScoutingBehavior.hpp
//  Colony
//
//  Created by Sean on 3/18/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ScoutingBehavior_hpp
#define ScoutingBehavior_hpp

#include <stdio.h>
#include "Behavior.hpp"
#include "Pathfinding.hpp"
#include "BaseCreature.hpp"
#include <vector>

//TODO, add some sort of class that communicates points that have already been explored

class ScoutingBehavior : Behavior
{
    
private:
    
    std::vector<GridLocation> itemLocations;
    int explorationDistance; //Max distance of exploration from starting point
    std::vector<GridLocation> searchLocations;
    
    
    
public:
    
    ScoutingBehavior();
    
    void SelectAction();
    void PerformAction();
    void ExamineSurroundingTask(BaseCreature &creature,Map &map);
    
    void AddSearchLocation(GridLocation location);
    void SelectRandomSearchLocation(int searchWidth,int searchHeight, Map &map);
    
    int getExplorationDistance();
    void setExplorationDistance(int _distance);
    
    bool AddLocationToPath(BaseCreature &creature,Map &map,int index);
    void RemoveLocationFromPath(int index);
    
    
    

    
};

#endif /* ScoutingBehavior_hpp */
