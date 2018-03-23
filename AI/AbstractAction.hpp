//
//  AbstractAction.hpp
//  Colony
//
//  Created by Sean on 3/22/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef AbstractAction_hpp
#define AbstractAction_hpp

#include <stdio.h>
#include "WorldStates.hpp"
#include "Map.hpp"
#include "BaseCreature.hpp"
#include <vector>
#endif /* AbstractAction_hpp */

class AbstractAction
{
    
private:
   
    
protected:
    std::vector<GridLocation> destinations;
    std::vector<GridLocation> movementPath;
    Map &map;
    BaseCreature &creature;
    std::vector<POIKnowledge> pointsOfInterest;
    
public:
    
    
    
    

    
    AbstractAction(Map &_map,BaseCreature &_creature);


    
    //Initializes whatever is needed for performing the action
    virtual bool PrepareAction() = 0;
    virtual bool PerformAction() = 0;
    
    
    void AddDestination(GridLocation loc);
    void setMap(Map &_map);
    void setCreature(BaseCreature &_creature);
    int getDestinationsSize();
    std::vector<GridLocation>& getDestinations();
    GridLocation getDestination(int index);

};

