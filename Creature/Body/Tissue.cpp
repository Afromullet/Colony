//
//  Tissue.cpp
//  Colony
//
//  Created by Sean on 3/30/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Tissue.hpp"

std::vector<AppliedForceEffect>& Tissue::getTissueMaterialEffects()
{
    return material.getAppliedForceEffects();
}
