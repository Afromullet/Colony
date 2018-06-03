//
//  Ore.hpp
//  Colony
//
//  Created by Sean on 6/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//
#include "Resource.hpp"
#ifndef Ore_hpp
#define Ore_hpp

#include <stdio.h>


enum EnOreType{enGemOre,enStoneOre,enMetalOre,enErrorOreType};

void InitializeOreMaterials();


class Ore;

//Stone and gem is also considered an ore for purposes of modeling it
extern Ore metalResources[MAX_RESOURCES_PER_GROUP];
extern Ore stoneResources[MAX_RESOURCES_PER_GROUP];
extern Ore gemResources[MAX_RESOURCES_PER_GROUP];

extern int numMetalResources;
extern int numStoneResources;
extern int numGemResources;






//Currently doesn't have much in this class
//It's here for future growth
class Ore : public Resource
{
private:
    EnOreType enOreType;
public:
    Ore();
    
    void setOreType(EnOreType type);
    
    EnOreType getOreType();
    
    
    
};
 

#endif /* Ore_hpp */
