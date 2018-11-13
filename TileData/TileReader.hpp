//
//  TileReader.hpp
//  Colony
//
//  Created by Sean on 12/31/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef TileReader_hpp
#define TileReader_hpp



#include <string>
#include <stdio.h>
#include <vector>

#include "EnumTypes.hpp"

#include <iostream>
#include <fstream>



#define TERRAIN_TYPE_TOKEN "TerrainType"
#define TEXTURE_LOCATION_TOKEN "TextureLocation"
#define CAN_HOLD_CREATURE_TOKEN "CanHoldCreature"

#define KEY_VALUE_DELIMITER_TOKEN ":"
#define START_OF_BLOCK_TOKEN "{"
#define END_OF_BLOCK_TOKEN "}"

#define TREE_1_TILE 0
#define TREE_2_TILE 1
#define TREE_3_TILE 2
#define FOREST_GRASS 3

#define BEACH_1_SAND 4
#define BEACH_PALM_1 5

#define DESERT_TILE_1 6
#define DESERT_CACTUS_1 7
#define DESERT_DEAD_TREE_1 8

#define SNOW_1_TILE 9

#define WATER_1_TILE 10

#define TUNDRA_1_TILE 11

#define SHRUBLAND_1_TILE 12

#define TAIGA_1_TILE 13

#define JUNGLE_1_TILE 14

#define SNOW_MOUNTAIN_1 15

#define GRASS_MOUNTAIN_1 16
//Matches up a tile ID with a tile type, texture, etc.
//To be loaded at initilization, so when generating maps, you have the necessary data
typedef struct TileIdentificationData
{
    TileTerrainType enTileTerrainType;
    int ID;
    bool canHoldCreature;
    std::string textureFileName;
    
}TileIDData;

extern TileIDData tempData;
extern std::vector<TileIDData> tileIDTable;

extern std::vector<std::string> terrainTypeTable;
extern int tileTableSize;

void InitializeTileReader();

bool LoadTileTerrainType(const std::string &s);
bool LoadTextureLocation(const std::string &s);

TileTerrainType DecodeTerrainType(const std::string &terrainTypeString);


void BasicTileRuleset();
extern std::vector<TileIDData> tileDataTable;
extern std::string tileFileLocation;
void ParseTileFile();
std::string split(const std::string& s, std::string delim);
std::string split(const std::string &s, std::string startDelim,const char &endDelim);


#endif /* TileReader_hpp */
