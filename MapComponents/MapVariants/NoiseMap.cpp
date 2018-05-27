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
#include <random>
#include <chrono>


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
    
    InitializeBiomeTemperatures();
}

void NoiseMap::GenerateNoiseValues()
{
    
     FastNoise myNoise,myNoise2; // Create a FastNoise object
    
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 g1 (seed1);

    myNoise.SetSeed(g1());
    myNoise.SetNoiseType(FastNoise::Simplex); // Set the desired noise type
    
    
    unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 g2 (seed2 + seed2);
    
    myNoise2.SetSeed(g2());
    myNoise2.SetNoiseType(FastNoise::Simplex); // Set the desired noise type
    
    
    myNoise.SetFrequency(0.015);
    myNoise2.SetFrequency(0.015);
    

 
    double e,m;
    double nx,ny;
    
    for ( int i = 0; i < GetWidth(); ++i)
    {
        for ( int j = 0; j < GetHeight(); ++j)
        {
            
            
          
            nx = (double)i/GetWidth() - 0.5, ny = (double)j/GetHeight() - 0.5  ;
            
            
            e = fabs(myNoise.GetNoise(i,j));
            m = fabs(myNoise2.GetNoise(i,j));
            
            Map2D[i][j].elevation = e;
            Map2D[i][j].moisture = m;
             
             

        
         
         
            

            //Map2D[i][j].elevation = fabs(e * 10);
            
            
            //Map2D[i][j].moisture = fabs(m * 10);
            
        }
        
        //std::cout << "\n NS";
       // std::cout << "\n NS";
        
        
        
   
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
                Map2D[i][j].setTileID(WATER_1_TILE);
                Map2D[i][j].SetBiome(enWaterBiome);
                
            }
            else if(Map2D[i][j].elevation < 0.16)
            {
                Map2D[i][j].setTileID(BEACH_1_SAND);
                Map2D[i][j].SetBiome(enBeachBiome);
            }
            
            else if(Map2D[i][j].elevation > 0.8)
            {
                if(Map2D[i][j].moisture < 0.5)
                {
                    Map2D[i][j].setTileID(TUNDRA_1_TILE);
                    Map2D[i][j].SetBiome(enTundraBiome);
                }
                else
                {
                    if(Map2D[i][j].elevation > 0.88)
                    {
                        Map2D[i][j].setTileID(SNOW_MOUNTAIN_1);
                        Map2D[i][j].SetBiome(enSnowMountainBiome); //Still a tundra for now
                    }
                    else
                    {
                        Map2D[i][j].setTileID(SNOW_1_TILE);
                        Map2D[i][j].SetBiome(enSnowBiome); //Still a tundra for now
                    }
                    
                }
                
            }
            else if(Map2D[i][j].elevation > 0.6)
            {
                
                if(Map2D[i][j].moisture < 0.33)
                {
                    Map2D[i][j].setTileID(DESERT_TILE_1); //Temperate desert/Cold Desert
                    Map2D[i][j].SetBiome(enTemperateDesertBiome);
                }
                else if(Map2D[i][j].moisture < 0.66)
                {
                    Map2D[i][j].setTileID(SHRUBLAND_1_TILE);
                    Map2D[i][j].SetBiome(enShrublandBiome);
                }
                else
                {
                    Map2D[i][j].setTileID(TAIGA_1_TILE); //Taiga/Borreal forest
                    Map2D[i][j].SetBiome(enTaigaBiome);
                }
                
                
            }
            else if(Map2D[i][j].elevation > 0.3)
            {
                if(Map2D[i][j].moisture < 0.16)
                {
                    Map2D[i][j].setTileID(DESERT_TILE_1); //Temperate desert
                    Map2D[i][j].SetBiome(enTemperateDesertBiome);
                }
                else if(Map2D[i][j].moisture < 0.50)
                {
                    
                    Map2D[i][j].setTileID(FOREST_GRASS); //Grassland
                    Map2D[i][j].SetBiome(enGrasslandBiome);
                    
                }
                else if(Map2D[i][j].moisture < 0.83)
                {
                    Map2D[i][j].setTileID(TREE_3_TILE); //Temperate decidious forest/seasonal forest
                    Map2D[i][j].SetBiome(enDecidiousForestBiome);
                }
                else
                {
                    Map2D[i][j].setTileID(JUNGLE_1_TILE); //Temperate rain forest
                    Map2D[i][j].SetBiome(enTemperateRainForestBiome);
                }
            }
            else if(Map2D[i][j].moisture < 0.16)
            {
                Map2D[i][j].setTileID(DESERT_TILE_1); //Subtropical desert
                Map2D[i][j].SetBiome(enSubtropicalDesertBiome);
            }
            else if(Map2D[i][j].moisture < 0.33)
            {
                Map2D[i][j].setTileID(FOREST_GRASS); //Grassland
                Map2D[i][j].SetBiome(enGrasslandBiome);
            }
            else if(Map2D[i][j].moisture < 0.66)
            {
                Map2D[i][j].setTileID(TREE_1_TILE); //Tropical seasonal forest
                Map2D[i][j].SetBiome(enTropicalSeasonalForest);
            }
            else
            {
                Map2D[i][j].setTileID(JUNGLE_1_TILE); //tropical rain forest
                Map2D[i][j].SetBiome(enTropicalRainForest);
            }
            
            
            /*
             
             
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
                
                
                if(Map2D[i][j].moisture < 0.16)
                {
                    Map2D[i][j].setTileID(DESERT_TILE_1);
                }
                else if(Map2D[i][j].moisture < 0.50)
                {
                    Map2D[i][j].setTileID(FOREST_GRASS);
                }
                else if(Map2D[i][j].moisture < 0.83)
                {
                    Map2D[i][j].setTileID(TREE_1_TILE);
                }
                else
                {
                    Map2D[i][j].setTileID(TREE_3_TILE); //Need rain forest tile
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
            */
        }
        
        
        
    }
    
}

void NoiseMap::LoadBiomeTiles()
{
    
}

/*
 
 Backup
 
 
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
 }
 }
 
 }
 
 /
 */
