//
//  NoiseMap.cpp
//  Colony
//
//  Created by Sean on 5/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "NoiseMap.hpp"
#include "FastNoise.h"
#include "TileReader.hpp"


NoiseMap::NoiseMap()
{
    
}

void NoiseMap::Generate_NoiseMap(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height)
{
    Generate2DMap(_tileSize, _width,_height );
    GenerateNoiseValues();
    SetBiomes();
    //GenerateRandom2DTiles();
    LoadBiomeTiles();
    LoadTileParameters();
    Group2DGridTiles();
    LoadTileTexture();
}

void NoiseMap::GenerateNoiseValues()
{
    
    FastNoise myNoise; // Create a FastNoise object
    myNoise.SetSeed(time(NULL));
    myNoise.SetNoiseType(FastNoise::SimplexFractal); // Set the desired noise type
    //myNoise.SetInterp(FastNoise::Linear);
    myNoise.SetFrequency(0.015);
 
    float frequency1 = 0.017,frequency2 = 0.02;
    
    for ( int i = 0; i < GetWidth(); ++i)
    {
        for ( int j = 0; j < GetHeight(); ++j)
        {
            
          
            double nx = (double)i/GetWidth()     , ny = (double)j/GetHeight()  ;
            Map2D[i][j].elevation = fabs(myNoise.GetNoise(i,j));
   
            
        
            
            
            
        
            
           

            
        }
        
   
    }
    
}


void NoiseMap::SetBiomes()
{
    for (unsigned int i = 0; i < GetWidth(); ++i)
    {
        for (unsigned int j = 0; j < GetHeight(); ++j)
        {
            //double nx = (double)i/GetWidth() - 0.5, ny = j/GetHeight() - 0.5;
            double nx = i , ny = j;
            
            if(Map2D[i][j].elevation < 0.1)
            {
                Map2D[i][j].biome = enWaterBiome;
                Map2D[i][j].setTileID(WATER_1_TILE);
                
            }
            else if(Map2D[i][j].elevation < 0.2)
            {
                Map2D[i][j].biome = enBeachBiome;
                if(Map2D[i][j].elevation < 0.15)
                {
                    Map2D[i][j].setTileID(BEACH_1_SAND);
                }
                else
                {
                    Map2D[i][j].setTileID(BEACH_PALM_1);
                }
                
                
            }
            else if(Map2D[i][j].elevation < 0.3)
            {
                Map2D[i][j].biome = enForestBiome;
                if(Map2D[i][j].elevation < 0.23)
                {
                    Map2D[i][j].setTileID(TREE_1_TILE);
                }
                else if(Map2D[i][j].elevation < 0.26)
                {
                    Map2D[i][j].setTileID(TREE_3_TILE);
                }
                else
                {
                    Map2D[i][j].setTileID(FOREST_GRASS);
                }
                
                
            }
            else if(Map2D[i][j].elevation < 0.5)
            {
                Map2D[i][j].biome = enJungleBiome;
                Map2D[i][j].setTileID(TREE_1_TILE);
                
            }
            else if(Map2D[i][j].elevation < 0.6)
            {
                Map2D[i][j].biome = enPlainsBiome;
                Map2D[i][j].setTileID(FOREST_GRASS);
                
            }
            else if(Map2D[i][j].elevation < 0.7)
            {
                
                if(Map2D[i][j].elevation < 0.76)
                {
                    Map2D[i][j].setTileID(DESERT_TILE_1);
                }
                else
                {
                    Map2D[i][j].setTileID(DESERT_CACTUS_1);
                }
                Map2D[i][j].biome = enDesertBiome;
                
                
            }
            else
            {
                Map2D[i][j].biome = enSnowBiome;
                Map2D[i][j].setTileID(SNOW_1_TILE);
                
            }
            
            
            /*
            if(Map2D[i][j].elevation <= 0.2)
            {
                //Map2D[i][j].biome = enDesert;
                Map2D[i][j].setTileID(7);
                
            }
            else if(Map2D[i][j].elevation <= 0.3)
            {
               // Map2D[i][j].biome = enDesert;
                Map2D[i][j].setTileID(8);

            }
            else if(Map2D[i][j].elevation <= 0.4)
            {
                //Map2D[i][j].biome = enForest;
                Map2D[i][j].setTileID(2);

            }
            else if(Map2D[i][j].elevation < 0.5)
            {
               // Map2D[i][j].biome = enPlains;
                Map2D[i][j].setTileID(3);

            }
            else if(Map2D[i][j].elevation < 0.6)
            {
                //Map2D[i][j].biome = enSwamp;
                Map2D[i][j].setTileID(4);
                
            }
            else if(Map2D[i][j].elevation < 0.7)
            {
                //Map2D[i][j].biome = enSwamp;
                Map2D[i][j].setTileID(5);
                
            }
            else
            {
                //Map2D[i][j].biome = enSwamp;
                Map2D[i][j].setTileID(3);
                
            }
             */
        
            
            
            
            
            
        }
    }
    
}

void NoiseMap::LoadBiomeTiles()
{
    
}
