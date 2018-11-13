//
//  Plant.cpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Plant.hpp"

#include <iostream>

Plant plantResource[MAX_RESOURCES_PER_GROUP];
int numPlantResources = 0;

bool Plant::operator==(Plant &other) const
{
    if(isRenewable == other.isRenewable && isEdible == other.isEdible && resourceCategory == other.resourceCategory && name == other.name && rarity == other.rarity && material == other.material)
    {
        if(growthRate == other.growthRate && growthDuration == other.growthDuration && yieldSeeds == other.yieldSeeds && biomeVec == other.biomeVec)
            return true;
    }
    
}


bool Plant::operator!=(Plant &other) const
{
    return !(*this == other);
}

void Plant::operator=(Plant &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
    growthRate = other.growthRate;
    growthDuration = other.growthDuration;
    yieldSeeds = other.yieldSeeds;
    biomeVec = other.biomeVec;
}

void InitializePlantMaterials()
{
    
    std::string matName;
    for(int i =0; i < numPlantResources; i++)
    {
        matName = plantResource[i].getMaterialName();
        
        
  
        for(int j=0;j < materials.size(); j++)
        {
            
            if(matName == materials.at(j).getMaterialName())
            {
                plantResource[i].setMaterial(materials.at(j));
            }
        }
    }
}

Plant::Plant() : Resource(false,enPlant,ERROR_STRING,50,true)
{
    
}

Plant::Plant(const Plant &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
    growthRate = other.growthRate;
    growthDuration = other.growthDuration;
    yieldSeeds = other.yieldSeeds;
    biomeVec = other.biomeVec;
}

//Negative growth rate means the plant is dying
void Plant::setGrowthRate(float rate)
{
    growthRate = rate;
}

void Plant::setGrowthDuration(float rate)
{
    if(rate < 0)
        return;
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
