//
//  ExamineAction.cpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ExamineAction.hpp"

BasicExamineSurroundingAction::BasicExamineSurroundingAction(Map &_map,BaseCreature &_creature) : AbstractAction(_map,_creature)
{
    actionType = enExamineAction;
    actionName = "BasicExamineAction";
    
}

bool BasicExamineSurroundingAction::PrepareAction()
{
    
}

bool BasicExamineSurroundingAction::PerformAction()
{
    PointOfInterest poi;
    std::vector<GridLocation> locations = creature.vision.getVisibleItemLocation(map);
    
    for(int i = 0; i < locations.size(); i++)
    {
        poi.type = enItemPOI;
        poi.location = locations.at(i);
        
        AddPOI(poi);
        
        
    }
    
    for(int i = 0; i < locations.size(); i++)
    {
        std::cout << "\n New Item" << i;
    }
    
    locations = creature.vision.getVisibleCreatureLocation(map);
    
    
    for(int i = 0; i < locations.size(); i++)
    {
        poi.type = enCreaturePOI;;
        poi.location = locations.at(i);
        AddPOI(poi);
        
    }
    
    
    
    

    
}
