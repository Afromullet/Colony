//
//  Ore.hpp
//  Colony
//
//  Created by Sean on 6/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//
#ifndef Ore_hpp
#define Ore_hpp

#include <stdio.h>
#include "Resource.hpp"


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
    bool operator==(const Ore &other) const;
    bool operator!=(const Ore &other) const;
    void operator=(const Ore &other);
    
    Ore();
    Ore(const Ore &other);
    
    void setOreType(EnOreType type);
    
    EnOreType getOreType();
    
    
    
};
 

#endif /* Ore_hpp */
