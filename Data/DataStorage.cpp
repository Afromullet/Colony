//
//  DataStorage.cpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "DataStorage.hpp"
#include <iostream>
#include "Constants.hpp"

std::vector<Material> materials;
std::vector<Biome> vecBiome;
std::vector<std::string> initialHistoryTokens; //The initial tokens before any rewrite rules

void printMaterials()
{
    for(int i=0; i < materials.size(); i++)
    {
        //std::cout << materials.at(i);
    }
}

void printBiomes()
{
    for(int i=0; i < vecBiome.size(); i++)
    {
        //std::cout << "\n Name " << vecBiome.at(i).getBiomeName() << "\n (Low Temp,High Temp): " << vecBiome.at(i).getLowTemp() << "," << vecBiome.at(i).getHighTemp();
    }
    
    //std::cout << "\n";
    
}

Biome findBiome(std::string biomeString)
{
    for(int i =0; i < vecBiome.size(); i++)
    {
        
        
        if(vecBiome.at(i).getBiomeName() == biomeString)
            return vecBiome.at(i);
    }
    
   
    return Biome();
    
    
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
