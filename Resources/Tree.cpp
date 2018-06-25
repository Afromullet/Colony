//
//  Tree.cpp
//  Colony
//
//  Created by Sean on 6/2/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Tree.hpp"
#include <iostream>

Tree treeResource[MAX_RESOURCES_PER_GROUP];
 int numTreeResources;


bool Tree::operator==(const Tree &other) const
{
    
    if(isRenewable == other.isRenewable && isEdible == other.isEdible && resourceCategory == other.resourceCategory && name == other.name && rarity == other.rarity && material == other.material)
    {
        if(growthRate == other.growthRate && growthDuration == other.growthDuration && yieldSeeds == other.yieldSeeds && biomeVec == other.biomeVec)
            
            if(maxHeight == other.maxHeight && maxDiameter == other.maxDiameter);
                return true;
    }
}


bool Tree::operator=(const Tree &other) const
{
    return !(*this == other);
}


bool Tree::operator=(const Tree other)
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
    maxHeight = other.maxHeight;
    maxDiameter = other.maxDiameter;
}


void InitializeTreeMaterials()
{
    std::string matName;
    for(int i =0; i < numTreeResources; i++)
    {
        matName = treeResource[i].getMaterialName();
        
        
        
        for(int j=0;j < materials.size(); j++)
        {
            
            if(matName == materials.at(j).getMaterialName())
            {
                treeResource[i].setMaterial(materials.at(j));
            }
        }
    }
    
    std::cout << "\n End";
}

Tree::Tree() : maxDiameter(1),maxHeight(1)
{
    
}

Tree::Tree(const Tree &other)
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
    maxHeight = other.maxHeight;
    maxDiameter = other.maxDiameter;
}

void Tree::setMaxHeight(float val)
{
    if(val < 0)
        return;
    
    maxHeight = val;
}

void Tree::setMaxDiameter(float val)
{
    if(val < 0)
        return;
    maxDiameter = val;
}

float Tree::getMaxHeight()
{
    return maxHeight;
}

float Tree::getMaxDiameter()
{
    return maxDiameter;
}
