//
//  DataStorage.cpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "DataStorage.hpp"
#include <iostream>

std::vector<Material> materials;

void printMaterials()
{
    for(int i=0; i < materials.size(); i++)
    {
        std::cout << materials.at(i);
    }
}

bool allMaterialsValid()
{
    for(int i =0; i < materials.size(); i++)
    {
        if(!materials.at(i).isValidMaterial())
        {
            
            return false;
        }
    }
            
           return true;
}
