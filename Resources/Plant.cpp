//
//  Plant.cpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Plant.hpp"
#include "Constants.hpp"

Plant plantResource[MAX_RESOURCES_PER_GROUP];
int numPlantResources = 0;
Plant::Plant() : Resource(false,enPlant,ERROR_STRING,50,true)
{
    
}

void Plant::setGrowthRate(float rate)
{
    growthRate = rate;
}

void Plant::setGrowthDuration(float rate)
{
    growthDuration = rate;
}

void Plant::setYieldSeeds(bool val)
{
    yieldSeeds = val;
}


void Plant::addBiome(std::string str)
{
    biomeVec.push_back(str);
}

float Plant::getGrowthRate()
{
    return growthRate;
}

float Plant::getGrowthDuration()
{
    return growthDuration;
}

bool Plant::getYieldsSeeds()
{
    return yieldSeeds;
}

std::vector<std::string> Plant::getBiomeVec()
{
    return biomeVec;
}

std::vector<std::string>& Plant::getBiomeVecRef()
{
    return biomeVec;
}
