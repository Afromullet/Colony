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



Biome::Biome() : EnBiome(enUndefinedBiome), lowTemp(ERROR_VALUE), highTemp(ERROR_VALUE),vegetationLevel(ERROR_VALUE),treeLevel(ERROR_VALUE)
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
Biome::Biome(Biome &biome)
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
    vegetationLevel = level;
}
void Biome::setTreelevel(float level)
{
    treeLevel = level;
}
void Biome::setWildlifeLevel(float level)
{
    wildlifeLevel = level;
}


float Biome::getLowTemp()
{
    return lowTemp;
}

float Biome::getHighTemp()
{
    return highTemp;
}


enBiomes Biome::getBiome()
{
    return EnBiome;
}

std::string Biome::getBiomeName()
{
    return name;
}

float Biome::getCurrentTemp()
{
    return currentTemp;
}

float Biome::getWildlifeLevel()
{
    return wildlifeLevel;
}

float Biome::getVegetationLevel()
{
    return vegetationLevel;
}

float Biome::getTreeLevel()
{
    return treeLevel;
}
