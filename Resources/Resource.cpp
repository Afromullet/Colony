//
//  Resource.cpp
//  Colony
//
//  Created by Sean on 5/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Resource.hpp"
Resource metalResources[MAX_RESOURCES_PER_GROUP];
Resource stoneResource[MAX_RESOURCES_PER_GROUP];



int numMetalResources = 0;
int numStoneResources = 0;



//For testing
void GenerateTestResources()
{
    
    
    Resource res(false,enMetal,"Copper",0.5,false);
    metalResources[numMetalResources] = res;
    numMetalResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Iron");
    res.setResourceCategory(enMetal);
    res.setRarity(0.5);
    metalResources[numMetalResources] = res;
    numMetalResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Aluminum");
    res.setResourceCategory(enMetal);
    res.setRarity(0.5);
    metalResources[numMetalResources] = res;
    numMetalResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Lead");
    res.setResourceCategory(enMetal);
    res.setRarity(0.5);
    metalResources[numMetalResources] = res;
    numMetalResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Gold");
    res.setResourceCategory(enMetal);
    res.setRarity(0.5);
    metalResources[numMetalResources] = res;
    numMetalResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Marble");
    res.setResourceCategory(enStone);
    res.setRarity(0.5);
    stoneResource[numStoneResources] = res;
    numStoneResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Slade");
    res.setResourceCategory(enStone);
    res.setRarity(0.5);
    stoneResource[numStoneResources] = res;
    numStoneResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Sandstone");
    res.setResourceCategory(enStone);
    res.setRarity(0.5);
    stoneResource[numStoneResources] = res;
    numStoneResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Claystone");
    res.setResourceCategory(enStone);
    res.setRarity(0.5);
    stoneResource[numStoneResources] = res;
    numStoneResources++;
    
    res.setIsRenewable(false);
    res.setResourceName("Alabaster");
    res.setResourceCategory(enStone);
    res.setRarity(0.5);
    stoneResource[numStoneResources] = res;
    numStoneResources++;
    
    
    
    
    
    
    
    
    
}

Resource::Resource(bool _isRenewable,EnResourceCategory _resourceCategory,std::string _name,float _rarity,bool _isEdible) : isRenewable(_isRenewable),resourceCategory(_resourceCategory),name(_name),rarity(_rarity),isEdible(_isEdible)
{
    
}

Resource::Resource() : isRenewable(false),resourceCategory(enUndefinedResourceCategory),name("Undefined Resource"),rarity(0.5)
{
    
}

void Resource::setResourceCategory(EnResourceCategory category)
{
    resourceCategory = category;
}

void Resource::setIsRenewable(bool val)
{
    isRenewable = val;
}

void Resource::setResourceName(std::string _name)
{
    name = _name;
}

void Resource::setRarity(float _rarity)
{
    rarity = _rarity;
}

void Resource::setIsEdible(bool val)
{
    isEdible = val;
}

void Resource::setName(std::string _name)
{
    name = _name;
}

bool Resource::getIsRenewable()
{
    return isRenewable;
}

EnResourceCategory Resource::getResourceCategory()
{
    return resourceCategory;
}

std::string Resource::getResourceName()
{
    return name;
}

float Resource::getRarity()
{
    return rarity;
}

bool Resource::getIsEdible()
{
    return isEdible;
}

std::string Resource::getName()
{
    return name;
}
