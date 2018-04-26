//
//  Wound.cpp
//  Colony
//
//  Created by Sean on 4/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Wound.hpp"
#include "BodyGraphGetters.hpp"

std::vector<WoundRule> shearWoundRuleset;
std::vector<WoundRule> impactWoundRuleset;



void SetupWoundRuleset()
{
    
}

/*
 The wound rulesets are based on ratios..The ratio being the ratio of the force absorbed to the force remaining
 
 Ratio is effect.endForce / effect.startForce;
 
 Uses a limit check, i.e, if a 
 
 */


//Determines what vertices are targetted by the wound.
std::vector<int> DetermineWoundTargets(int origin,AppliedForceEffect &effect, AnatomyGraph &graph)
{
    
    std::vector<int> targets;
    std::vector<int> tempTargets;
    targets.push_back(origin);
    
    if(effect.effect == enImpactDefEffect)
    {
        //doesn't do anything
    }
    else if(effect.effect == enImpactFracEffect)
    {
        tempTargets = getInternalVertices(origin,graph);
        
        if(effect.woundSeverity == enMinorWound)
        {
            //Doesn't do anything, just affects the origin
        }
        else if(effect.woundSeverity == enModerateWound)
        {
            //Choose 1 random internal vertex connected to the origin
            targets.push_back(tempTargets[rand() % tempTargets.size()]);
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            //Choose 2 random internal vertices connected to the origin
            //Can choose teh same vertex twice..that'll be more sever damage
            targets.push_back(tempTargets[rand() % tempTargets.size()]);
            targets.push_back(tempTargets[rand() % tempTargets.size()]);
            
        }
    }
    else if(effect.effect == enShearDefEffect)
    {
        //Doesn't do anything
    }
    else if(effect.effect == enShearFracEffect)
    {
        if(effect.attackType == enPierce)
        {
            
            if(effect.woundSeverity == enMinorWound)
            {
                //Doesn't do anything, just affects the origin
            }
            else if(effect.woundSeverity == enModerateWound)
            {
                tempTargets = getInternalVertices(origin,graph);
                //Choose 1 random internal vertex connected to the origin
                targets.push_back(tempTargets[rand() % tempTargets.size()]);
            }
            else if(effect.woundSeverity == enMajorWound)
            {
                tempTargets = getInternalVertices(origin,graph);
                //Choose 1 random internal vertex connected to the origin
                targets.push_back(tempTargets[rand() % tempTargets.size()]);
                
            }
        }
        else if(effect.attackType == enSlash)
        {
            //Only affects the origin
            
        }
        
    }
    
    return targets;
    
}


WoundCalculations::WoundCalculations(int _origin) : origin(_origin)
{
    
}

//One thing that needs to be addressed - The way the ApplyxWound functions access the vertices
//Currently, it's coupled closely to DetermineWoundTargets in terms of how it accesses the vertices

void WoundCalculations::ApplySlashingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    if(effect.effect == enShearDefEffect || effect.effect == enShearFracEffect || effect.attackType == enSlash)
        
    {
        std::vector<int> targets= DetermineWoundTargets(origin,effect,graph);
        //0 = origin
        if(effect.woundSeverity == enMinorWound)
        {
            graph[targets.at(0)].AddWound(enMinorCut);
        }
        else if(effect.woundSeverity == enModerateWound)
        {
            graph[targets.at(0)].AddWound(enModerateCut);
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            graph[targets.at(0)].AddWound(enMajorCut);
            int dismmemberChance = rand() % 101;
            if(dismmemberChance <= DISMEMBER_CHANCE)
                graph[targets.at(0)].AddWound(enDismember);
        }
    }
    
}

void WoundCalculations::ApplyPiercingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    if(effect.effect == enShearDefEffect || effect.effect != enShearFracEffect || effect.attackType == enPierce)
    {
        

        std::vector<int> targets= DetermineWoundTargets(origin,effect,graph);
    //0 = origin
        if(effect.woundSeverity == enMinorWound)
        {
            graph[targets.at(0)].AddWound(enMinorPuncture);

        }
        else if(effect.woundSeverity == enModerateWound)
        {
        
            graph[targets.at(0)].AddWound(enModeratePuncture);
            graph[targets.at(1)].AddWound(enMinorPuncture);
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            graph[targets.at(0)].AddWound(enMajorPuncture);
            graph[targets.at(0)].AddWound(enModeratePuncture);
        }
    }
    
}

void WoundCalculations::ApplyImpactWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    
    //For some reason the negation of this condition does not work..returnign when effect != enimpacteffect or impactfraceffect
    if(effect.effect == enImpactDefEffect || effect.effect == enImpactFracEffect)
    {
        std::vector<int> targets= DetermineWoundTargets(origin,effect,graph);
    
        int fractureChance = rand() % 101;
    
    
        //0 = origin
        if(effect.woundSeverity == enMinorWound)
        {
            graph[targets.at(0)].AddWound(enMinorBruise);
        
            if(fractureChance <= FRACTURE_CHANCE)
                graph[targets.at(0)].AddWound(enMinorFracture);
        }
        else if(effect.woundSeverity == enModerateWound)
        {
            graph[targets.at(0)].AddWound(enModerateBruise);
        
            if(fractureChance <= FRACTURE_CHANCE)
                graph[targets.at(0)].AddWound(enModerateFracture);
        
            graph[targets.at(1)].AddWound(enMinorBruise);
        
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            int ruptureChance = rand() % 101;
        
            graph[targets.at(0)].AddWound(enMajorBruise);
        
            if(fractureChance <= FRACTURE_CHANCE)
                graph[targets.at(0)].AddWound(enMajorFracture);
        
            graph[targets.at(1)].AddWound(enMajorBruise);
        
            if(ruptureChance <= RUPTURE_CHANCE)
                graph[targets.at(1)].AddWound(enRupture);
            
        }
    
        std::cout << "\n Printing wounds";
        for(int i=0; i < targets.size(); i++)
        {
            for(int j=0; j < graph[targets.at(i)].wounds.size(); j++)
            {
                std::cout << " " << graph[targets.at(i)].wounds.at(j);
            }
        }

    }
}
