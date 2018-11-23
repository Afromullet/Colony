//
//  ShearWoundInterface.cpp
//  Colony
//
//  Created by Sean on 11/14/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ShearWoundInterface.hpp"


void ShearWoundInterface::ProcessElement(WoundTableElement &element)
{
    std::vector<WoundType>::iterator it;
    WoundType type;
    for(it = element.woundTypes.begin(); it != element.woundTypes.end();)
    {
        type = *it;
        std::cout << "\n Attacking " << graph[element.index].getBodyPartName();
        if(type == enMinorCut || type == enModerateCut || type == enMajorCut)
        {
            ApplyCut(element.index,type);
            graph[element.index].DetermineEffects(body.bodyProperties);
            body.AddToPainLevel(graph[element.index].getPainLevel());
            body.AddToBleedingRate(graph[element.index].getBleedingRate());
            element.woundTypes.erase(it);
        }
        else if(type == enMinorPuncture || type == enModeratePuncture || type == enMajorPuncture)
        {
            ApplyPuncture(element.index,type);
            graph[element.index].DetermineEffects(body.bodyProperties);
            body.AddToPainLevel(graph[element.index].getPainLevel());
            body.AddToBleedingRate(graph[element.index].getBleedingRate());
            element.woundTypes.erase(it);
        }
        else if(type == enDismember)
        {
            ApplyDismember(element.index,type);
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
void ShearWoundInterface::ProcesWoundTable()
{
    for(int i = 0; i < woundTable.table.size(); i++)
    {
        ProcessElement(woundTable.table.at(i));
    }
}
 */

void ShearWoundInterface::ApplyCut(int bpIndex,WoundType woundType)
{
    if(woundType == enMinorCut)
    {
        graph[bpIndex].increaseCutLevel(LOW_WOUND_LEVEL);
    }
    else if(woundType == enModerateCut)
    {
        graph[bpIndex].increaseCutLevel(MODERATE_WOUND_LEVEL);
    }
    else if(woundType == enMajorCut)
    {
        graph[bpIndex].increaseCutLevel(MAJOR_WOUND_LEVEL);
    }
}

void ShearWoundInterface::ApplyDismember(int bpIndex,WoundType woundType)
{
    if(woundType == enDismember)
    {
        
    }
}

void ShearWoundInterface::ApplyPuncture(int bpIndex,WoundType woundType)
{
    if(woundType == enMinorPuncture)
    {
        graph[bpIndex].increasePiercedLevel(LOW_WOUND_LEVEL);
    }
    else if(woundType == enModeratePuncture)
    {
        graph[bpIndex].increasePiercedLevel(MODERATE_WOUND_LEVEL);
    }
    else if(woundType == enMajorPuncture)
    {
        graph[bpIndex].increasePiercedLevel(MAJOR_WOUND_LEVEL);
    }
}
