//
//  Biomes.cpp
//  Colony
//
//  Created by Sean on 5/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Biomes.hpp"
#include "DataStorage.hpp"
#include "EnumTypes.hpp"
#include "ErrorConstants.hpp"
#include "UtilMacros.h"



bool Biome::operator==(const Biome &other) const
{
    if(lowTemp == other.lowTemp && highTemp == other.highTemp
       && currentTemp == other.currentTemp && vegetationLevel == other.vegetationLevel
       && treeLevel == other.treeLevel && wildlifeLevel == other.wildlifeLevel &&
       EnBiome == other.EnBiome && name == other.name

       )
        return true;
    
    return false;
}

bool Biome::operator!=(const Biome &other) const
{
    return !(*this == other);
}

void Biome::operator=(const  Biome &other)
{
    lowTemp = other.lowTemp;
    highTemp = other.highTemp;
    currentTemp = other.currentTemp;
    vegetationLevel = other.vegetationLevel;
    treeLevel = other.treeLevel;
    wildlifeLevel = other.wildlifeLevel;
    EnBiome = other.EnBiome;
    name = other.name;
    
}

Biome::Biome() : EnBiome(enUndefinedBiome), lowTemp(ERROR_INPUT_NUMBER), highTemp(ERROR_INPUT_NUMBER),vegetationLevel(ERROR_INPUT_NUMBER),treeLevel(ERROR_INPUT_NUMBER)
{
    
}

Biome::Biome(const Biome &biome)
{
    lowTemp = biome.lowTemp;
    highTemp = biome.highTemp;
    currentTemp = biome.currentTemp;
    name = biome.name;
    vegetationLevel = biome.vegetationLevel;
    treeLevel = biome.treeLevel;
    wildlifeLevel = biome.wildlifeLevel;
    
    
    
}

void Biome::setTemperatureLimits(float _lowTemp,float _highTemp)
{
    lowTemp = _lowTemp;
    highTemp = _highTemp;
}

void Biome::setBiome(enBiomes _EnBiome)
{
    EnBiome = _EnBiome;
}

void Biome::setBiomeName(std::string _name)
{
    name = _name;
}

void Biome::setCurrentTemp(float _currentTemp)
{
    currentTemp = _currentTemp;
}

void Biome::setVegetationLevel(float level)
{
    vegetationLevel = IS_NUM_GT_0(level);
}
void Biome::setTreelevel(float level)
{
    treeLevel = IS_NUM_GT_0(level);
}
void Biome::setWildlifeLevel(float level)
{
    wildlifeLevel = IS_NUM_GT_0(level);
}


float Biome::getLowTemp() const
{
    return lowTemp;
}

float Biome::getHighTemp() const
{
    return highTemp;
}


enBiomes Biome::getBiome() const
{
    return EnBiome;
}

std::string Biome::getBiomeName() const
{
    return name;
}

float Biome::getCurrentTemp() const
{
    return currentTemp;
}

float Biome::getWildlifeLevel() const
{
    return wildlifeLevel;
}

float Biome::getVegetationLevel() const
{
    return vegetationLevel;
}

float Biome::getTreeLevel() const
{
    return treeLevel;
}
