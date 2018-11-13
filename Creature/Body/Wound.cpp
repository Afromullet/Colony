//
//  Wound.cpp
//  Colony
//
//  Created by Sean on 4/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Wound.hpp"
//#include "BodyGraphGetters.hpp"

std::vector<WoundRule> shearWoundRuleset;
std::vector<WoundRule> impactWoundRuleset;



WoundTable::WoundTable()
{
    
}

//Need to merge tables when the creatures woundTable gets updated
void WoundTable::operator=(WoundTable &other) const
{
    
    
}

void WoundTable::AddElement(int index, WoundType woundType)
{
    //std::vector<WoundTableElement>::iterator it;
    
    
    bool elementFound = false;
    
    for(int i = 0; i < table.size(); i++)
    {
        
        std::vector<WoundTableElement>::iterator it;
        it = std::find(table.begin(),table.end(),table.at(i));
        
        if( it != table.end())
        {
            table.at(i).addWoundType(woundType);
        }
        else
        {
            table.push_back(WoundTableElement(index,woundType));
        }
        /*
         if(table.at(i).index == index)
         {
         elementFound = true;
         table.at(i).addWoundType(woundType);
         break;
         }*/
    }
}


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
            {
                //May not have internal vertices
                if(tempTargets.size() > 0)
                    targets.push_back(tempTargets[rand() % tempTargets.size()]);
            }
            
                
            
      
            
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
                    targets.push_back(tempTargets[rand() % tempTargets.size()]);
                
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
                std::cout << "\n Origin: " << graph[origin].getBodyPartName();
                for(int i =0; i < tempTargets.size(); i++)
                {
                    std::cout << "\n BP Name: " << graph[tempTargets.at(i)].getBodyPartName();
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


std::string GetWoundType(WoundType type)
{
    if(type == enMinorFracture)
    {
        return "Minor Fracture";
    }
    else if(type == enModerateFracture)
    {
        return  "Moderate Fracture";
    }
    else if(type == enMajorFracture)
    {
        return  "Major Fracture";
    }
    else if(type == enMinorPuncture)
    {
        return  "Minor Pucture";
    }
    else if(type == enModeratePuncture)
    {
        return  "Moderate Pucture";
    }
    else if(type == enMajorPuncture)
    {
        return  "Major Pucture";
    }
    else if(type == enMinorCut)
    {
        return  "Minor Cut";
    }
    else if(type == enModerateCut)
    {
        return  "Moderate Cut";
    }
    else if(type == enMajorCut)
    {
        return  "Major Cut";
    }
    else if(type == enMinorBruise)
    {
        return  "Minor Bruise";
    }
    else if(type == enModerateBruise)
    {
        return  "Moderate Bruise";
    }
    else if(type == enMajorBruise)
    {
        return  "Major Bruise";
    }
    else if(type == enRupture)
    {
        return  "Rupture";
    }
    else if(type == enDismember)
    {
        return  "Dismember";
    }
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


bool WoundCalculations::operator==(WoundCalculations &other) const
{
    if(woundType == other.woundType && origin == other.origin && woundEffectActive == other.woundEffectActive)
        return true;
    
    return false;
}

bool WoundCalculations::operator!=(WoundCalculations &other) const
{
    return !(*this == other);
}

void WoundCalculations::operator=(WoundCalculations &other)
{
    woundType = other.woundType;
    origin = other.origin;
    woundEffectActive = other.woundEffectActive;
}

WoundCalculations::WoundCalculations(int _origin) : origin(_origin)
{
    
}

WoundCalculations::WoundCalculations()
{
    origin = 0;
    
}

WoundCalculations::WoundCalculations(const WoundCalculations &other)
{
    woundType = other.woundType;
    origin = other.origin;
    woundEffectActive = other.woundEffectActive;
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
             woundTable.AddElement(0,enMinorCut);
        }
        else if(effect.woundSeverity == enModerateWound)
        {
            graph[targets.at(0)].AddWound(enModerateCut);
            woundTable.AddElement(0,enModerateCut);
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            graph[targets.at(0)].AddWound(enMajorCut);
            int dismmemberChance = rand() % 101;
            if(dismmemberChance <= DISMEMBER_CHANCE)
            {
                graph[targets.at(0)].AddWound(enDismember);
                woundTable.AddElement(0,enDismember);
            }
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
            woundTable.AddElement(0,enMinorPuncture);

        }
        else if(effect.woundSeverity == enModerateWound)
        {
        
            graph[targets.at(0)].AddWound(enModeratePuncture);
            woundTable.AddElement(0,enModeratePuncture);
            
            if(targets.size() > 1)
            {
                graph[targets.at(1)].AddWound(enMinorPuncture);
                woundTable.AddElement(1,enMinorPuncture);
                
            }
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            graph[targets.at(0)].AddWound(enMajorPuncture);
            woundTable.AddElement(0,enMajorPuncture);
            
            if(targets.size() > 1)
            {
                graph[targets.at(1)].AddWound(enModeratePuncture);
                woundTable.AddElement(1,enModeratePuncture);
            }
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
            woundTable.AddElement(0,enMinorBruise);
            if(fractureChance <= FRACTURE_CHANCE)
            {
                graph[targets.at(0)].AddWound(enMinorFracture);
                woundTable.AddElement(0,enMinorFracture);
            }
        }
        else if(effect.woundSeverity == enModerateWound)
        {
            graph[targets.at(0)].AddWound(enModerateBruise);
            woundTable.AddElement(0,enModeratePuncture);
        
            if(fractureChance <= FRACTURE_CHANCE)
            {
                woundTable.AddElement(0,enModerateFracture);
                graph[targets.at(0)].AddWound(enModerateFracture);
                
            }
        
            if(targets.size() > 1)
            {
                graph[targets.at(1)].AddWound(enMinorBruise);
                woundTable.AddElement(1,enMinorBruise);
            }
        
        }
        else if(effect.woundSeverity == enMajorWound)
        {
            int ruptureChance = rand() % 101;
        
            graph[targets.at(0)].AddWound(enMajorBruise);
            woundTable.AddElement(0,enMajorBruise);
        
            if(fractureChance <= FRACTURE_CHANCE)
            {
                graph[targets.at(0)].AddWound(enMajorFracture);
                woundTable.AddElement(0,enMajorFracture);
            }
        
            std::cout << "\n Target size " << targets.size();
         
            if(targets.size() > 1)
            {
                   std::cout << "\n Targets at 1" << targets.at(1);
                graph[targets.at(1)].AddWound(enMajorBruise);
                woundTable.AddElement(1,enMajorBruise);
                
            }
        
            if(ruptureChance <= RUPTURE_CHANCE && targets.size() > 1)
            {
                graph[targets.at(1)].AddWound(enRupture);
                woundTable.AddElement(1,enRupture);
            }
            
        }
    
  

    }
    
    return targets;
}

