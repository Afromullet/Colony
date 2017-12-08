//
//  Map.cpp
//  Colony
//
//  Created by Sean on 11/12/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Map.hpp"
#include <iostream>

#include <vector>
#include <unordered_map>
#include "Globals.hpp"
#include "Constants.hpp"


/*
 
 An explicit example showing how to build a vertexarrays from existing vertices,
 select a texture, and draw it
 
 
 sf::VertexArray vArray;
 sf::Texture texture0;
 Tile tile;
 sf::Vertex newVert;
 
 vArray.setPrimitiveType(sf::Quads);
 //vArray.resize(width * height * 4); //We need four vertices for every tile
 states.transform *= getTransform();
 
 for(int i = 0; i < tiles.size(); i++)
 {
 
 int randNum = rand() % 3;
 
 if(randNum == 0)
 {
 if (!texture0.loadFromFile("dirt_e.png"))
 return false;
 }
 else if(randNum == 1)
 {
 if (!texture0.loadFromFile("ice0.png"))
 return false;
 }
 else if(randNum == 2)
 {
 if (!texture0.loadFromFile("tomb1.png"))
 return false;
 }
 
 
 
 tile = tiles.at(i);
 vArray.clear();
 newVert.position = tile.getTileVertices()[0].position;
 newVert.texCoords = tile.getTileVertices()[0].texCoords;
 vArray.append(newVert);
 
 newVert.position = tile.getTileVertices()[1].position;
 newVert.texCoords = tile.getTileVertices()[1].texCoords;
 vArray.append(newVert);
 
 newVert.position = tile.getTileVertices()[2].position;
 newVert.texCoords = tile.getTileVertices()[2].texCoords;
 vArray.append(newVert);
 
 newVert.position = tile.getTileVertices()[3].position;
 newVert.texCoords = tile.getTileVertices()[3].texCoords;
 
 
 vArray.append(newVert);
 states.texture = &texture0;
 
 target.draw(vArray, states);
 }
 
 
 
 */


void Map::BasicRandom2DMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height)
{
    Generate2DMap(_tileSize, _width,_height );
    GenerateRandom2DTiles();
    LoadTileParameters();
    Group2DGridTiles();
    LoadTileTexture();
    //Generate2DGrid();
}

//Generates the verticles for the map. They are not yet tetured, that will be done later
bool Map::Generate2DMap(sf::Vector2u _tileSize, unsigned int _width, unsigned int _height)
{
 
    
    //Allocate necessary space
    //Map2D.resize(MAP_WIDTH);
    width = _width;
    height = _height;
    
    Map2D.resize(width);

    for (int i = 0; i <= MAP_WIDTH-1; ++i)
        Map2D[i].resize(height);
        //Map2D[i].resize(MAP_HEIGHT);
    
    
    tileSize = _tileSize;
    //tiles.clear(); //Todo remove in the future. This is just here for testing
    
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4); //We need four vertices for every tile
    
    // populate the vertex array, with one quad per tile
    
   
    Tile tempTile;
    ////std::cout << "\n" << iterations << "its and tiles=" << tiles.size() << "\n" ;
    for (unsigned int i = 0; i < width; ++i)
    {
        
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number..harcoded right now
            int tileNumber = 0;
            // find its position in the tileset texture
            //hardcoded atm
            int tu = tileNumber % (32 / 32);
            int tv = tileNumber / (32 / 32);
            
            // get a pointer to the current tile's quad
            sf::Vertex * quad = &m_vertices[(i + j * width) * 4];
            
            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            
            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(0, 0);
            quad[1].texCoords = sf::Vector2f( tileSize.x, 0);
            quad[2].texCoords = sf::Vector2f(tileSize.x, tileSize.y);
            quad[3].texCoords = sf::Vector2f(0, tileSize.y);
            
            tempTile.SetTileVertices(i, j,tileSize);
            Map2D[i][j] = tempTile;
            
            
        }
    }
    
    
    
    
 
}

void Map::Group2DGridTiles()
{
    //Get Unique group IDs
    
    
    bool foundTile = false;
    MapTileParams groupParams;
    Tile tile;
    sf::Vertex newVert;

    tileGroups.clear();
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            
            foundTile = false;
            groupParams.TileID = Map2D[i][j].getTileID();
            groupParams.m_vertices.setPrimitiveType(sf::Quads);
            
            for(int k = 0; k < tileGroups.size(); k++)
            {
                //Group tiles by ID
                if(Map2D[i][j].getTileID() == tileGroups.at(k).TileID)
                {
                    
                   
                    foundTile = true;
                        
                    tile = Map2D[i][j];
                    
                    newVert.position = tile.getTileVertices()[0].position;
                    newVert.texCoords = tile.getTileVertices()[0].texCoords;
                    tileGroups.at(k).m_vertices.append(newVert);
                        
                    newVert.position = tile.getTileVertices()[1].position;
                    newVert.texCoords = tile.getTileVertices()[1].texCoords;
                    tileGroups.at(k).m_vertices.append(newVert);
                        
                    newVert.position = tile.getTileVertices()[2].position;
                    newVert.texCoords = tile.getTileVertices()[2].texCoords;
                    tileGroups.at(k).m_vertices.append(newVert);
                        
                    newVert.position = tile.getTileVertices()[3].position;
                    newVert.texCoords = tile.getTileVertices()[3].texCoords;
                    tileGroups.at(k).m_vertices.append(newVert);
                    break;
                }
                
                
                
                
            }
            
            if(!foundTile)
            {
                
                
                tile = Map2D[i][j];
                
                newVert.position = tile.getTileVertices()[0].position;
                newVert.texCoords = tile.getTileVertices()[0].texCoords;
                groupParams.m_vertices.append(newVert);
                
                newVert.position = tile.getTileVertices()[1].position;
                newVert.texCoords = tile.getTileVertices()[1].texCoords;
                groupParams.m_vertices.append(newVert);
                
                newVert.position = tile.getTileVertices()[2].position;
                newVert.texCoords = tile.getTileVertices()[2].texCoords;
                groupParams.m_vertices.append(newVert);
                
                newVert.position = tile.getTileVertices()[3].position;
                newVert.texCoords = tile.getTileVertices()[3].texCoords;
                groupParams.m_vertices.append(newVert);
                tileGroups.push_back(groupParams);
                
                
            }
            
            

            
            
        }
        
        
    }
}

//Loads tile texture based on the tile ID. There is a global table that assocaites each ID with a type
//TileIDData struct contains info on texture, tile type (floor, wall, etc)
void Map::LoadTileTexture()
{
    int randNum;
    std::string textureFileName;
    
    //Todo, add condition for when the tile ID is not found
    //load error texture
    //Also for when textureFilename is not found, handle that condition
    for(int i = 0; i < tileGroups.size(); i++)
    {
        
        for(int j = 0; j < tileIDTable.size(); j++)
        {
            if(tileIDTable.at(j).ID == tileGroups.at(i).TileID)
            {
                tileGroups.at(i).m_tileset.loadFromFile(tileIDTable.at(j).textureFileName);
                
                break;

            }
        }
    }
    
    
}

//Currently, it just generates a random number (currently hardcoded)
//Each of these numbers matches up to a tileID with a texture
void Map::GenerateRandom2DTiles()
{
    int RandomUpperLimit = 3;
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
            Map2D[i][j].setTileID(rand() % RandomUpperLimit);
}


void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    //states.transform.scale(tileScale, tileScale);
    
    
    

    states.transform *= getTransform();
   

    
    for(int i = 0; i < tileGroups.size(); i++)
    {
        
        
       // texture0 =
       // texture0.loadFromFile("dirt_e.png");
      
        states.texture = &tileGroups.at(i).m_tileset;;
        target.draw(tileGroups.at(i).m_vertices, states);

        
    }
 
}


unsigned int Map::GetWidth()
{
    return width;
}
unsigned int Map::GetHeight()
{
    return height;
}

bool Map::isInBounds(sf::Vector2u position)
{
    if((position.x == 0 || position.x > width) || (position.y == 0 || position.y > height))
        return false;
    
    return true;
    
    
}

//Load the info needed to fill out a tile of a particular ID
void Map::LoadTileParameters()
{
    int RandomUpperLimit = 3;
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            Map2D[i][j].SetTileTerrainType(tileIDTable.at(Map2D[i][j].getTileID()).enTileTerrainType);
            Map2D[i][j].setCanHoldCreature(tileIDTable.at(Map2D[i][j].getTileID()).canHoldCreature);
            
            
            
        }
    
}

//Performs flood fill on coordinate X,Y.
//Need to group tiles again after this (if they are already grouped)
void Map::FloodFill(int x, int y, int targetTileID, int replacementTileID)
{
    if(targetTileID == replacementTileID)
        return;
    //Do some boundary checking first
    if((x < 0 || x >= width) || (y < 0 || y >= height))
    {
        return;
    }
    
 
    else if(Map2D[x][y].getTileID() != targetTileID)
    {
        return;
    }
    
    Map2D[x][y].setTileID(replacementTileID);
    FloodFill(x,y-1,targetTileID,replacementTileID); //North
    FloodFill(x,y+1,targetTileID,replacementTileID); //South
    FloodFill(x-1,y,targetTileID,replacementTileID); //West
    FloodFill(x+1,y,targetTileID,replacementTileID); //East
}

