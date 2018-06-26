//
//  Tissue.cpp
//  Colony
//
//  Created by Sean on 3/30/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "Tissue.hpp"


bool Tissue::operator==(const Tissue &other) const
{
    if(name == other.name && thickness == other.thickness && bleedingRate == other.bleedingRate && hasArteries == other.hasArteries && material == other.material)
        return true;
    
    return false;
}

bool Tissue::operator!=(const Tissue &other) const
{
    return !(*this == other);
}

void Tissue::operator=(const Tissue &other) 
{
    name = other.name;
    thickness = other.thickness;
    bleedingRate = other.bleedingRate;
    hasArteries = other.hasArteries;
    material = other.material;
    
}

Tissue::Tissue()
{
    name = ERROR_STRING_INPUT;
    thickness = ERROR_INPUT_NUMBER;
    bleedingRate = ERROR_INPUT_NUMBER;
    hasArteries = false;
    
}

Tissue::Tissue(Tissue &other)
{
    name = other.name;
    thickness = other.thickness;
    bleedingRate = other.bleedingRate;
    hasArteries = other.hasArteries;
    material = other.material;
}

Tissue::Tissue(std::string _name, int _thickness, int _bleedingRate, bool _hasArteries, Material _mat) : name(_name),thickness(_thickness),bleedingRate(_bleedingRate),hasArteries(_hasArteries),material(_mat)
{
    
}


void Tissue::setName(std::string val)
{
    name = val;
}

void Tissue::setThickness(int val)
{
    if(val < 0)
        return;
    
    thickness = val;
}

void Tissue::setBleedingRate(int val)
{
    if(bleedingRate < 0)
        return;
    
    bleedingRate = val;
}

void Tissue::setHasArteries(bool val)
{
    hasArteries = val;
}

void Tissue::setMaterial(Material val)
{
    material = val;
}

std::string Tissue::getName()
{
    return name;
}

int Tissue::getThickness()
{
    return thickness;
}

int Tissue::getBleedingRate()
{
    return bleedingRate;
}

bool Tissue::getHasArteries()
{
    return hasArteries;
}

Material Tissue::getMaterial()
{
    return material;
}

std::vector<AppliedForceEffect>& Tissue::getTissueMaterialEffects()
{
    return material.getAppliedForceEffects();
}
