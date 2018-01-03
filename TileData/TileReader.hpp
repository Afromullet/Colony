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
#include "Globals.hpp"
#include "EnumTypes.hpp"



#define TERRAIN_TYPE_TOKEN "TerrainType"
#define TEXTURE_LOCATION_TOKEN "TextureLocation"
#define KEY_VALUE_DELIMITER_TOKEN ":"
#define START_OF_BLOCK_TOKEN "{"
#define END_OF_BLOCK_TOKEN "}"



extern TileIDData tempData;
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
