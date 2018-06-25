//
//  Resource.cpp
//  Colony
//
//  Created by Sean on 5/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Resource.hpp"


bool Resource::operator==(Resource &other) const
{
    if(isRenewable == other.isRenewable && isEdible == other.isEdible && resourceCategory == other.resourceCategory && name == other.name && rarity == other.rarity && material == other.material)
        return true;
    
    return false;
}

bool Resource::operator!=(Resource &other) const
{
    return !(*this == other);
    
}

void Resource::operator=(Resource &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
}



Resource::Resource(bool _isRenewable,EnResourceCategory _resourceCategory,std::string _name,float _rarity,bool _isEdible) : isRenewable(_isRenewable),resourceCategory(_resourceCategory),name(_name),rarity(_rarity),isEdible(_isEdible)
{
    
}

Resource::Resource() : isRenewable(false),resourceCategory(enUndefinedResourceCategory),name("Undefined Resource"),rarity(0.5)
{
    
}

Resource::Resource(const Resource &other)
{
    isRenewable = other.isRenewable;
    isEdible = other.isEdible;
    resourceCategory = other.resourceCategory;
    name = other.name;
    rarity = other.rarity;
    material = other.material;
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
    if(rarity < 0)
        return;
    
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

void Resource::setMaterial(Material _material)
{
    material = _material;
}

void Resource::setMaterialName(std::string str)
{
    material.setMaterialName(str);
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

Material Resource::getMaterial()
{
    return material;
}

std::string Resource::getMaterialName()
{
    return material.getMaterialName();
}
