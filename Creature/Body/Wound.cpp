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


//Determines what vertices are targetted by the wound. The appliedforceeffect determines how the damage propagates
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
            
            //-1 on the limit because the origin is added at the beginning
            for(int i=0; i < MOD_IMPACT_VERTNUM - 1; i++)
                targets.push_back(tempTargets[rand() % tempTargets.size()]);
            
                
            
           
            
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            //Choose MAJ_IMPACT_VERTNUM random internal vertices connected to the origin
            //Can choose teh same vertex twice..that'll be more sever damage
            int val;
            //-1 on the limit because the origin is added at the beginning
            for(int i=0; i < MAJ_IMPACT_VERTNUM - 1; i++)
            {
                
                //May not have internal vertices
                if(tempTargets.size() > 0)
                    targets.push_back(tempTargets[rand() % tempTargets.size() - 1]);
                
            }
         
            
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
                std::cout << "\n Origin: " << graph[origin].bodyPartName;
                for(int i =0; i < tempTargets.size(); i++)
                {
                    std::cout << "\n BP Name: " << graph[tempTargets.at(i)].bodyPartName;
                }
              
                //Choose 1 random internal vertex connected to the origin
                if(tempTargets.size() > 0)
                    targets.push_back(tempTargets[rand() % tempTargets.size()]);
            }
            else if(effect.woundSeverity == enMajorWound)
            {
             
                tempTargets = getInternalVertices(origin,graph);
                //Choose 1 random internal vertex connected to the origin
                
                
                //If the size is 0, then the body part doesn't have any interal ones, so just use the origin
                if(tempTargets.size() > 0)
                    targets.push_back(tempTargets[rand() % tempTargets.size()]);
                else
                    targets.push_back(origin);

                
            }
        }
        else if(effect.attackType == enSlash)
        {
            //Only affects the origin
            
        }
        
    }
    
    return targets;
    
}

void PrintWoundType(WoundType type)
{
    if(type == enMinorFracture)
    {
        std::cout << "Minor Fracture";
    }
    else if(type == enModerateFracture)
    {
        std::cout << "Moderate Fracture";
    }
    else if(type == enMajorFracture)
    {
        std::cout << "Major Fracture";
    }
    else if(type == enMinorPuncture)
    {
        std::cout << "Minor Pucture";
    }
    else if(type == enModeratePuncture)
    {
        std::cout << "Moderate Pucture";
    }
    else if(type == enMajorPuncture)
    {
        std::cout << "Major Pucture";
    }
    else if(type == enMinorCut)
    {
        std::cout << "Minor Cut";
    }
    else if(type == enModerateCut)
    {
        std::cout << "Moderate Cut";
    }
    else if(type == enMajorCut)
    {
        std::cout << "Major Cut";
    }
    else if(type == enMinorBruise)
    {
        std::cout << "Minor Bruise";
    }
    else if(type == enModerateBruise)
    {
        std::cout << "Moderate Bruise";
    }
    else if(type == enMajorBruise)
    {
        std::cout << "Major Bruise";
    }
    else if(type == enRupture)
    {
        std::cout << "Rupture";
    }
    else if(type == enDismember)
    {
        std::cout << "Dismember";
    }

}

WoundCalculations::WoundCalculations(int _origin) : origin(_origin)
{
    
}

WoundCalculations::WoundCalculations()
{
    
}


void WoundCalculations::ApplyWound(AppliedForceEffect &effect, AnatomyGraph &graph)
{
    
    if((effect.effect == enShearDefEffect || effect.effect == enShearFracEffect) && effect.attackType == enSlash)
    {
        ApplySlashingShearWound(effect,graph);
    }
    else if((effect.effect == enShearDefEffect || effect.effect == enShearFracEffect) && effect.attackType == enPierce )
    {
        ApplyPiercingShearWound(effect,graph);
    }
    else if(effect.effect == enImpactDefEffect || effect.effect == enImpactFracEffect)
    {
        ApplyImpactWound(effect,graph);
    }
    
}

//One thing that needs to be addressed - The way the ApplyxWound functions access the vertices
//Currently, it's coupled closely to DetermineWoundTargets in terms of how it accesses the vertices

std::vector<int> WoundCalculations::ApplySlashingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    
    std::vector<int> targets;
    if(effect.effect == enShearDefEffect || effect.effect == enShearFracEffect || effect.attackType == enSlash)
        
    {
        targets= DetermineWoundTargets(origin,effect,graph);
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
    
    return targets;
    
}

std::vector<int> WoundCalculations::ApplyPiercingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    
    std::vector<int> targets;
    if(effect.effect == enShearDefEffect || effect.effect != enShearFracEffect || effect.attackType == enPierce)
    {
        

    targets= DetermineWoundTargets(origin,effect,graph);
    //0 = origin
        if(effect.woundSeverity == enMinorWound)
        {
            graph[targets.at(0)].AddWound(enMinorPuncture);

        }
        else if(effect.woundSeverity == enModerateWound)
        {
        
            graph[targets.at(0)].AddWound(enModeratePuncture);
            
            if(targets.size() > 1)
                graph[targets.at(1)].AddWound(enMinorPuncture);
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            graph[targets.at(0)].AddWound(enMajorPuncture);
            
            if(targets.size() > 1)
                graph[targets.at(1)].AddWound(enModeratePuncture);
        }
    }
    
    return targets;
    
}

std::vector<int> WoundCalculations::ApplyImpactWound(AppliedForceEffect &effect,AnatomyGraph &graph)
{
    
    //For some reason the negation of this condition does not work..returnign when effect != enimpacteffect or impactfraceffect
    
    std::vector<int> targets;
    if(effect.effect == enImpactDefEffect || effect.effect == enImpactFracEffect)
    {
        targets= DetermineWoundTargets(origin,effect,graph);
    
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
        
            if(targets.size() > 1)
                graph[targets.at(1)].AddWound(enMinorBruise);
        
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            int ruptureChance = rand() % 101;
        
            graph[targets.at(0)].AddWound(enMajorBruise);
        
            if(fractureChance <= FRACTURE_CHANCE)
                graph[targets.at(0)].AddWound(enMajorFracture);
        
            if(targets.size() > 1)
                graph[targets.at(1)].AddWound(enMajorBruise);
        
            if(ruptureChance <= RUPTURE_CHANCE && targets.size() > 1)
                graph[targets.at(1)].AddWound(enRupture);
            
        }
    
  

    }
    
    return targets;
}

