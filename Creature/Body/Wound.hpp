//
//  Wound.hpp
//  Colony
//
//  Created by Sean on 4/10/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Wound_hpp
#define Wound_hpp

#include <stdio.h>
#include "BodyGraph.hpp"
#include "Material.hpp"
#include "EnumTypes.hpp"
#include <vector>


struct WoundRule
{
    WoundType woundType;
    float requiredForceRatio;
};



#define FRACTURE_CHANCE 30
#define RUPTURE_CHANCE 30
#define DISMEMBER_CHANCE 30

#define MIN_IMPACT_VERTNUM 1
#define MOD_IMPACT_VERTNUM 2
#define MAJ_IMPACT_VERTNUM 3



extern std::vector<WoundRule> shearWoundRuleset;
extern std::vector<WoundRule> impactWoundRuleset;



void SetupWoundRuleset();

std::vector<int> DetermineWoundTargets(int origin,AppliedForceEffect &effect, AnatomyGraph &graph);

void PrintWoundType(WoundType type);


class WoundCalculations
{
private:
    WoundType woundType;
    int origin; //Index for the origin of the wound in the graph
    bool woundEffectActive;
    
public:
    
    bool operator==(WoundCalculations &other) const ;
    bool operator!=(WoundCalculations &other) const;
    void operator=(WoundCalculations &other);
    
    WoundCalculations(int _origin);
    WoundCalculations();
    WoundCalculations(const WoundCalculations &other);
    
    std::vector<int> ApplySlashingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph);
    std::vector<int> ApplyPiercingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph);
    std::vector<int> ApplyImpactWound(AppliedForceEffect &effect,AnatomyGraph &graph);
    void ApplyWound(AppliedForceEffect &effect, AnatomyGraph &graph);
   
};
#endif /* Wound_hpp */
