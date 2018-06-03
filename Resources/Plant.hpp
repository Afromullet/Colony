//
//  Plant.hpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Plant_hpp
#define Plant_hpp

#include <stdio.h>
#include "Resource.hpp"


extern Plant plantResource[MAX_RESOURCES_PER_GROUP];
extern int numPlantResources;
class Plant : public Resource
{
    
private:
    float growthRate;
    float growthDuration;
    bool yieldSeeds;
    std::vector<std::string> biomeVec;
    
public:
    Plant();
    
    
    void setGrowthRate(float rate);
    void setGrowthDuration(float rate);
    void setYieldSeeds(bool val);
    void addBiome(std::string str);
    
    float getGrowthRate();
    float getGrowthDuration();
    bool getYieldsSeeds();
    std::vector<std::string> getBiomeVec();
    std::vector<std::string>& getBiomeVecRef();
    
    
    
};

#endif /* Plant_hpp */
