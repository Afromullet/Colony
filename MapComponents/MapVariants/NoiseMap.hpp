//
//  NoiseMap.hpp
//  Colony
//
//  Created by Sean on 5/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef NoiseMap_hpp
#define NoiseMap_hpp

#include <stdio.h>
#include "Map.hpp"


class NoiseMap : public Map
{
public:
    NoiseMap();
    void Generate_NoiseMap(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height);
    void GenerateNoiseValues();
    void SetBiomes();
    void LoadBiomeTiles();
 
};

#endif /* NoiseMap_hpp */
