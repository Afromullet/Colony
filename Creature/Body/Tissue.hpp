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

class Tissue
{
    std::string name;
    int thickness;
    int bleedingRate;
    bool hasArteries;
    Material material;
    
    
    
};

#endif /* Tissue_hpp */
