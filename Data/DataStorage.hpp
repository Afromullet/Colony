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


extern std::vector<Material> materials;

void printMaterials();

bool allMaterialsValid();

#endif /* DataStorage_hpp */
