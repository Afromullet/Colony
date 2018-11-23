//
//  ImpactWoundInterface.cpp
//  Colony
//
//  Created by Sean on 11/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ImpactWoundInterface.hpp"
#include "EnumTypes.hpp"
#include "BodyPart.hpp"


void ImpactWoundInterface::ProcessElement(WoundTableElement &element)
{
    //BodyPart &bp = *graph[element.index];
    
    std::vector<WoundType>::iterator it;
    WoundType type;
    for(it = element.woundTypes.begin(); it != element.woundTypes.end();)
    {
        type = *it;
        std::cout << "\n Attacking " << graph[element.index].getBodyPartName();
        if(type == enMinorFracture || type == enModerateFracture || type == enMajorFracture)
        {
            ApplyFracture(element.index,type);
            graph[element.index].DetermineEffects(body.bodyProperties);
            body.AddToPainLevel(graph[element.index].getPainLevel());
            body.AddToBleedingRate(graph[element.index].getBleedingRate());
            element.woundTypes.erase(it);
        }
        else if(type == enMinorBruise || type == enModerateBruise || type == enMajorBruise)
        {
            ApplyBruise(element.index,type);
            graph[element.index].DetermineEffects(body.bodyProperties);
            body.AddToPainLevel(graph[element.index].getPainLevel());
            body.AddToBleedingRate(graph[element.index].getBleedingRate());
            element.woundTypes.erase(it);
            
        }
        else if(type == enRupture)
        {
            ApplyRupture(element.index,type);
            graph[element.index].DetermineEffects(body.bodyProperties);
            body.AddToPainLevel(graph[element.index].getPainLevel());
            body.AddToBleedingRate(graph[element.index].getBleedingRate());
            element.woundTypes.erase(it);
            
         
        }
        else
        {
            ++it;
        }
    }
}
/*
void ImpactWoundInterface::ProcesWoundTable()
{
    
 
    //graph[vert1]->increaseFractureLevel(10);
   //vert1.increaseFractureLevel(10);
    
    for(int i = 0; i < woundTable.table.size(); i++)
    {
        ProcessElement(woundTable.table.at(i));
    }

     std::cout << "Processing Impact Wound Table";
}
*/
void ImpactWoundInterface::ApplyFracture(int bpIndex,WoundType woundType)
{
    
    //BodyPart &bp = getBodyPartRef(graph,bpIndex);
    if(woundType == enMinorFracture)
    {
        graph[bpIndex].increaseFractureLevel(LOW_WOUND_LEVEL);
    }
    else if(woundType == enModerateFracture)
    {
        graph[bpIndex].increaseFractureLevel(MODERATE_WOUND_LEVEL);
    }
    else if(woundType == enMajorFracture)
    {
        graph[bpIndex].increaseFractureLevel(MAJOR_WOUND_LEVEL);
    }
}

void ImpactWoundInterface::ApplyBruise(int bpIndex,WoundType woundType)
{
    if(woundType == enMinorBruise)
    {
        graph[bpIndex].increaseBruiseLevel(LOW_WOUND_LEVEL);
    }
    else if(woundType == enModerateBruise)
    {
        graph[bpIndex].increaseBruiseLevel(MODERATE_WOUND_LEVEL);
    }
    else if(woundType == enMajorBruise)
    {
        graph[bpIndex].increaseBruiseLevel(MAJOR_WOUND_LEVEL);
    }
}

void ImpactWoundInterface::ApplyRupture(int bpIndex,WoundType woundType)
{
    graph[bpIndex].setIsRuptured(true);
}
