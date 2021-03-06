//
//  TileReader.cpp
//  Colony
//
//  Created by Sean on 12/31/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "TileReader.hpp"

TileIDData tempData;
std::vector<TileIDData> tileIDTable; //Tile types are predefined. TODO, populate this from a file.
int tileTableSize = 0; //Helpds with population terrainTypeTable

std::string tileFileLocation = "//Users//Afromullet//Documents//SFML//Colony2//Colony//TileData//tileData.afr";
std::vector<TileIDData> tileDataTable;

//Not using an external library to do the parsing..That would be a far better idea, but I'm trying to familiarize myself with C++ strings some more

std::vector<std::string> terrainTypeTable;

void InitializeTileReader()
{
    terrainTypeTable.push_back("enGrass1");
    terrainTypeTable.push_back("enSnow1");
    terrainTypeTable.push_back("enSwamp1");
    terrainTypeTable.push_back("enFloor1");
    terrainTypeTable.push_back("enWall1");
    terrainTypeTable.push_back("enUndefinedTerrain");
};

//Not going to use sfml inputstream in case I want to port this code later to something that is not sfml, so I will just use standard c++ io
/*
 Format of a block is as follows
 {
 TerrainType:  enTerrainTypeItemHere
 TextureLocation: file location of texture;
 }
 
 _______
 {The { and } are tokens to indicate the start and stop of a block
 
 */



//Very simple parsing..Not much error handling. Replace with a better way later, for now I just need to load the tiles to test some things
void ParseTileFile()
{
    
    InitializeTileReader();
    
    std::string line;
    std::ifstream tileFile (tileFileLocation);
    
    std::string tempString; //For processing
    
    std::string terrainTypeLine = "";
    std::string textureLocationLine = "";

    
    if(tileFile.is_open())
    {
        
        /*
            Every time we return to the outside loop, we should be at a new block
            A new block starts with "{" and ends with "}"
            In the loop, we call getline several times and store it in a temporary string
            //This parses a block
         */
        
        while(std::getline(tileFile,line))
        {
            tempData.ID = tileTableSize;
            //At the start of a block
            if(line != START_OF_BLOCK_TOKEN)
            {
                std::cout << "Error finding start of tile data block\n";
                break;
            }
            
            //First read the terrain type
            std::getline(tileFile,terrainTypeLine);
            if(!LoadTileTerrainType(terrainTypeLine))
            {
                std::cout << "No terrain type loaded. Using default value for everything\n";
                tileDataTable.push_back(tempData);
                tileTableSize++;

                break; //TODO maybe add just skipping this block rather than breaking.
            }
            
      
            //std::cout << "\nSplit String " <<  ;
            std::getline(tileFile,textureLocationLine);
        
            
            if(!LoadTextureLocation(textureLocationLine))
            {
                std::cout << "Problems with loading texture";
                tileDataTable.push_back(tempData);
                tileTableSize++;
                break; //TODO maybe add just skipping this block rather than breaking
            }
            
            
            //Shold be at the end of a block now
            std::getline(tileFile,line);
            
            //std::cout << "\nTexture file name  loaded: " << tempData.textureFileName << "\n";
            
            if(line != END_OF_BLOCK_TOKEN)
            {
                std::cout << "Error finding end of block\n";
                break;
            }
            
            
            
            
            tileDataTable.push_back(tempData);
            tileTableSize++;
      
        }
        
   
        
        tileFile.close();
       
        

        
    }
    else
    {
        std::cout << "\n Not open\n";
    }
    
   
}

//The function below manipulate gloal tempData...

//Parses a string of the form TerrainType:enTerrainType
//the enTerrainType string must match up with the enTerrainType enum values, those are stored in a table
//Loads all tiles as bad if the first one does not load..well, rather, it loads only one tile ID
bool LoadTileTerrainType(const std::string &s)
{
    std::string tempString = split(s,TERRAIN_TYPE_TOKEN);
    
  
    tempData.ID = tileTableSize;
    
    //This loads all tile values, no point in parsing further, and want to notify the creator
    //That something has gone wrong at the start.
    if(tempString.size() <= 0)
    {
        
        std::cout << "Invalid terrain type string. Loading default value";
        tempData.enTileTerrainType = enUndefinedTerrain;
        tempData.canHoldCreature = true;
        
        //TODO error texture string for loading error tile
        return false;
    }
    
    tempString = split(s,KEY_VALUE_DELIMITER_TOKEN); //should return :enTerrainType format
    tempString.replace(0, sizeof(KEY_VALUE_DELIMITER_TOKEN)-1, "");//Removes the token
   
    //Starting after the token..So we ignore the first
    for(int i = 1; i < terrainTypeTable.size(); i++)
    {
        if(tempString == terrainTypeTable.at(i))
        {
            tempData.enTileTerrainType = DecodeTerrainType(tempString);
            break;
        }
    }
    
    return true;
}

bool LoadTextureLocation(const std::string &s)
{
    std::string tempString = split(s,TEXTURE_LOCATION_TOKEN);
    
    
    
    //This loads all tile values, no point in parsing further, and want to notify the creator
    //That something has gone wrong at the start.
    if(tempString.size() <= 0)
    {
        
        std::cout << "Invalid texture type string. Loading default value";
        tempData.enTileTerrainType = enUndefinedTerrain;
        tempData.canHoldCreature = true;
        //tempData.ID = tileTableSize;
        //TODO error texture string for loading error tile
        return false;
    }
    
    tempString = split(s,KEY_VALUE_DELIMITER_TOKEN); //should return :enTerrainType format
    tempString.replace(0, sizeof(KEY_VALUE_DELIMITER_TOKEN)-1, "");//Removes the token
    
    
 
    tempData.textureFileName = tempString; //Doesn't do any checking to see if the path is correct
    
    return true;
    
}
//keepDelimiter keeps the delimiter of the string being split
std::string split(const std::string &s, std::string startDelim,const char &endDelim)
{
    std::size_t found = s.find(startDelim);
    std::string splitString = "";
    if(found == std::string::npos)
    {
        std::cout << "Token not found: " << startDelim << std::endl;
        return splitString;
        
        
    }
    
    int offset = 0;
    
    
    
    //
    for(int i = found; i < s.size(); i++)
    {
        
        if(s.at(i) == endDelim)
            break;
        
        splitString += s.at(i);
        
        //splitString.push_back(s.at(i));
        std::cout << "\n" << s.at(i);
    }
    std::cout << "Split string " << splitString;
    return splitString;
    
}

//keepDelimiter keeps the delimiter of the string being split
std::string split(const std::string &s, std::string delimiter)
{
    std::size_t found = s.find(delimiter);
    std::string splitString = "";
    if(found == std::string::npos)
    {
        std::cout << "Token not found: " << delimiter << std::endl;
        return splitString;
        
    }
    
    int offset = 0;
    
 
    
    //
    for(int i = found; i < s.size(); i++)
    {
        splitString += s.at(i);
        
        //splitString.push_back(s.at(i));
       
    }
    
    return splitString;

}

TileTerrainType DecodeTerrainType(const std::string &terrainTypeString)
{

    std::cout << "Decoding terrain string " << terrainTypeString << "\n";
    if(terrainTypeString == "enTree1")
    {
        return enTree1;
    }
    else if(terrainTypeString == "enTree2")
    {
        return enTree2;
    }
    else if(terrainTypeString == "enTree3")
    {
        return enTree3;
    }
    else if(terrainTypeString == "enForestGrass1")
    {
        return enForestGrass1;
    }
    else if(terrainTypeString == "enBeach1")
    {
        return enBeach1;
    }
    else if(terrainTypeString == "enBeachPalm1")
    {
        return enBeachPalm1;
    }
    else if(terrainTypeString == "enDesert1")
    {
        return enDesert1;
    }
    else if(terrainTypeString == "enDesertCactus1")
    {
        return enDesertCactus1;
    }
    else if(terrainTypeString == "enDesertTree1")
    {
        return enDesertTree1;
    }
    else if(terrainTypeString == "enSnow1")
    {
        return enSnow1;
    }
    else if(terrainTypeString == "enWater1")
    {
        return enWater1;
    }
    else if(terrainTypeString == "enTundra1")
    {
        return enTundra1;
    }
    else if(terrainTypeString == "enShrubland1")
    {
        return enShrubland1;
    }
    else if(terrainTypeString == "enTaiga1")
    {
        return enTaiga1;
    }
    else if(terrainTypeString == "enJungle1")
    {
        return enJungle1;
    }
    else if(terrainTypeString == "enSnowMountain1")
    {
        return enSnowMountain1;
    }
    else if(terrainTypeString == "enGrassMountain1")
    {
        return enGrassMountain1;
    }
    
 
 
    else
    {
        std::cout << "\n" << "Can't find terrain type..using undefined terrain" << "\n";
        return enUndefinedTerrain;
    }
    
    
}

//Each tile type also identifies several parameters
//For now the only additional parameter is canHoldCreature
//This function loads the default values
void BasicTileRuleset()
{
    for(int i = 0; i < tileDataTable.size(); i++)
    {
        tileDataTable.at(i).canHoldCreature = true;
    
        /*
        if(tileDataTable.at(i).enTileTerrainType == enWall1)
        {
            tileDataTable.at(i).canHoldCreature = true;
        }
        else if(tileDataTable.at(i).enTileTerrainType == enFloor1)
        {
            
             tileDataTable.at(i).canHoldCreature = true;
        }
        else if(tileDataTable.at(i).enTileTerrainType == enGrass1)
        {
            
        }
        else if(tileDataTable.at(i).enTileTerrainType == enSnow1)
        {
            
            tileDataTable.at(i).canHoldCreature = true;
        }
        else if(tileDataTable.at(i).enTileTerrainType == enSwamp1)
        {
            tileDataTable.at(i).canHoldCreature = true;
        }
        else if(tileDataTable.at(i).enTileTerrainType == enSnow1)
        {
            
            tileDataTable.at(i).canHoldCreature = true;
        }
        else if(tileDataTable.at(i).enTileTerrainType == enUndefinedTerrain)
        {
            
        }
         */
      
        
   


        
    }
    
    for(int i = 0; i < tileTableSize; i++)
    {
        tileIDTable.push_back(tileDataTable.at(i));
    }
    
}
