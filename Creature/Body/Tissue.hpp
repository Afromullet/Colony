//
//  Tissue.hpp
//  Colony
//
//  Created by Sean on 3/30/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Tissue_hpp
#define Tissue_hpp

#include <stdio.h>
#include <string>
#include "Material.hpp"
#include "ErrorConstants.hpp"

class Tissue
{
    
    
private:
    std::string name;
    int thickness;
    int bleedingRate;
    bool hasArteries;
    Material material;
    
    
    
public:
    
    bool operator==(const Tissue &other) const;
    bool operator!=(const Tissue &other) const;
    void operator=(const Tissue &other) ;
    
    Tissue();
    Tissue(Tissue &other);
    Tissue(std::string _name, int _thickness, int _bleedingRate, bool _hasArteries, Material _mat);
    
    
    void setName(std::string val);
    void setThickness(int val);
    void setBleedingRate(int val);
    void setHasArteries(bool val);
    void setMaterial(Material val);
    
    std::string getName();
    int getThickness();
    int getBleedingRate();
    bool getHasArteries();
    Material getMaterial();
    std::vector<AppliedForceEffect> &getTissueMaterialEffects();
    
    
};

#endif /* Tissue_hpp */
