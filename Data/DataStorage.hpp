//
//  DataStorage.hpp
//  Colony
//
//  Created by Sean on 4/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef DataStorage_hpp
#define DataStorage_hpp

#include <stdio.h>
#include <vector>
#include <Material.hpp>
#include "Biomes.hpp"

extern std::vector<Material> materials;
extern std::vector<Biome> vecBiome;


void printMaterials();
void printBiomes();

bool allMaterialsValid();

Biome findBiome(std::string biomeString);

#endif /* DataStorage_hpp */
