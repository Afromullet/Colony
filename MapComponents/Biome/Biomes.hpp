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
    float currentTemp;
    float vegetationLevel;
    float treeLevel;
    float wildlifeLevel;
    enBiomes EnBiome;
    std::string name;
    
    
public:
    
    
    bool operator==(const Biome &other) const;
    bool operator!=(const Biome &other) const;
    void operator=(const  Biome &other);
    
    
    Biome();
    Biome(const Biome &biome);

   
    
    
   
    
    void setTemperatureLimits(float _lowTemp,float _highTemp);
    void setBiome(enBiomes _EnBiome);
    void setBiomeName(std::string _name);
    void setCurrentTemp(float _currentTemp);
    void setVegetationLevel(float level);
    void setTreelevel(float level);
    void setWildlifeLevel(float level);
    
    
    
    
    
    float getLowTemp() const;
    float getHighTemp() const;
    float getCurrentTemp() const;
    float getWildlifeLevel() const;
    float getVegetationLevel() const;
    float getTreeLevel() const;
    
    std::string getBiomeName() const;
    enBiomes getBiome() const;
};

#endif /* Biomes_hpp */
