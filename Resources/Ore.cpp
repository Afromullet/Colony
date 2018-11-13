//
//  Ore.cpp
//  Colony
//
//  Created by Sean on 6/3/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Ore.hpp"


//Stone and gem is also considered an ore for purposes of modeling it
 Ore metalResources[MAX_RESOURCES_PER_GROUP];
 Ore stoneResources[MAX_RESOURCES_PER_GROUP];
 Ore gemResources[MAX_RESOURCES_PER_GROUP];

int numMetalResources = 0;
int numStoneResources = 0;
int numGemResources = 0;






void InitializeOreMaterials()
{
    std::string matName;
    for(int i =0; i < numMetalResources; i++)
    {
        matName = metalResources[i].getMaterialName();
        for(int j=0;j < materials.size(); j++)
        {
            if(matName == materials.at(j).getMaterialName())
                metalResources[i].setMaterial(materials.at(j));
        }
        
        
    }
    
    for(int i =0; i < numStoneResources; i++)
    {
        matName = stoneResources[i].getMaterialName();
        for(int j=0;j < materials.size(); j++)
        {
            if(matName == materials.at(j).getMaterialName())
                stoneResources[i].setMaterial(materials.at(j));
        }
        
        
    }
    
    for(int i =0; i < numGemResources; i++)
    {
        matName = gemResources[i].getMaterialName();
        for(int j=0;j < materials.size(); j++)
        {
            if(matName == materials.at(j).getMaterialName())
                gemResources[i].setMaterial(materials.at(j));
        }
        
        
    }
    
 
}


bool Ore::operator==(const Ore &other) const
{
    if(isRenewable == other.isRenewable && isEdible == other.isEdible && resourceCategory == other.resourceCategory && name == other.name && rarity == other.rarity && material == other.material)
        return true;
    
    return false;
}

bool Ore::operator!=(const Ore &other) const
{
    return !(*this == other);
    
}

void Ore::operator=(const Ore &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
    enOreType = other.enOreType;
}



Ore::Ore() : Resource(false,enPlant,ERROR_STRING,50,true), enOreType(enErrorOreType)
{
    
}

Ore::Ore(const Ore &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
    enOreType = other.enOreType;
}

void Ore::setOreType(EnOreType type)
{
    enOreType = type;
}

EnOreType Ore::getOreType()
{
    return enOreType;
}
