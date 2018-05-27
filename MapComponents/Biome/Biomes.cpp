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



Biome::Biome() : EnBiome(enUndefinedBiome), lowTemp(ERROR_VALUE), highTemp(ERROR_VALUE)
{
    
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
