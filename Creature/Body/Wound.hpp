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



extern std::vector<WoundRule> shearWoundRuleset;
extern std::vector<WoundRule> impactWoundRuleset;



void SetupWoundRuleset();

std::vector<int> DetermineWoundTargets(int origin,AppliedForceEffect &effect, AnatomyGraph &graph);


class WoundCalculations
{
private:
    WoundType woundType;
    int origin; //Index for the origin of the wound in the graph
    
public:
    WoundCalculations(int _origin);
    
    void ApplySlashingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph);
    void ApplyPiercingShearWound(AppliedForceEffect &effect,AnatomyGraph &graph);
    void ApplyImpactWound(AppliedForceEffect &effect,AnatomyGraph &graph);
};
#endif /* Wound_hpp */
