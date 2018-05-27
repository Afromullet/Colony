//
//  Biomes.hpp
//  Colony
//
//  Created by Sean on 5/26/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Biomes_hpp
#define Biomes_hpp

#include <stdio.h>
#include <string>
#include "EnumTypes.hpp"
#include "Constants.hpp"






//Will eventually transition from using enBiome to this class
//For now, the class still requires the enumerated type. I'll have to change the way tile data is being read before removing the enumerated type.
class Biome
{

private:
    float lowTemp;
    float highTemp;
    enBiomes EnBiome;
    std::string name;
    
    
    
    
public:
    Biome();
   // Biome();
    
    void setTemperatureLimits(float _lowTemp,float _highTemp);
    void setBiome(enBiomes _EnBiome);
    void setBiomeName(std::string _name);
    
    
    
    
    float getLowTemp();
    float getHighTemp();
    std::string getBiomeName();
    enBiomes getBiome();
};

#endif /* Biomes_hpp */
