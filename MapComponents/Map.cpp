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
#include <math.h>


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

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    //states.transform.scale(tileScale, tileScale);
    
    
    
    
    states.transform *= getTransform();
    
    
    
    for(int i = 0; i < tileGroups.size(); i++)
    {
        
        
        // texture0 =
        // texture0.loadFromFile("dirt_e.png");
        
        sf::RenderStates initialState = states;
        initialState.transform *= getTransform();
        initialState.blendMode = sf::BlendMultiply;
        
        
        
        
        states.texture = &tileGroups.at(i).m_tileset;
        target.draw(tileGroups.at(i).m_vertices, states);
        
        
        // target.draw(tileGroups.at(i).m_vertices,initialState);
        
        
        
        //target.draw(effectsOnMap, states);
        
        
    }
    
    //Make effects their own drawable later
    for(int i = 0; i < effects.size(); i++)
    {
        //sf::Transform transform;
        
        //states.transform *= getTransform();
        //states.transform.translate(tileSize.x, 0);
        
        target.draw(effects.at(i).vertices, states);
        //target.draw
    }
    
    
    
    // std::cout << "\n New size " <<  effectsOnMap.getVertexCount();
    // target.draw(effectsOnMap);
    
}



void Map::BasicRandom2DMap(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height)
{
    
    //effectsOnMap.setPrimitiveType(sf::Quads);
    Generate2DMap(_tileSize, _width,_height );
    GenerateRandom2DTiles();
    LoadTileParameters();
    Group2DGridTiles();
    LoadTileTexture();
    
    for(int i =0; i < tileGroups.size(); i++)
    {
        tileGroups.at(i).sprite.setColor(sf::Color::Red);
        
    }
    //Generate2DGrid();
}

//Generates the verticles for the map. They are not yet tetured, that will be done later
bool Map::Generate2DMap(sf::Vector2i _tileSize, unsigned int _width, unsigned int _height)
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
    //effectsOnMap.setPrimitiveType(sf::Quads);
    //effectsOnMap.resize(width * height * 4);
    
    // populate the vertex array, with one quad per tile
    
    
    Tile tempTile;
    ////std::cout << "\n" << iterations << "its and tiles=" << tiles.size() << "\n" ;
    
    int ind = 0;
    for (unsigned int i = 0; i < width; ++i)
    {
        
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number..harcoded right nofw
            int tileNumber = 0;
            // find its position in the tileset texture
            //hardcoded atm...The original example this was used in uses this to load the texture from a texture sheet
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
            
            quad[0].color = sf::Color::Black;
            quad[1].color = sf::Color::Black;
            quad[2].color = sf::Color::Black;
            quad[3].color = sf::Color::Black;
            
            quad[0].color.a = 10;
            quad[1].color.a = 10;
            quad[2].color.a = 10;
            quad[3].color.a = 10;
            
            
            
            
            
            
            tempTile.SetTileVertices(i, j,tileSize);
            Map2D[i][j] = tempTile;
            Map2D[i][j].index = ind;
            ind++;
            
            
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
                std::cout << "\n Text file name " << tileIDTable.at(j).textureFileName;
                tileGroups.at(i).m_tileset.loadFromFile(tileIDTable.at(j).textureFileName);
                tileGroups.at(i).sprite.setTexture(tileGroups.at(i).m_tileset);
                
                
                //tileGroups.at(i).sprite.setColor(sf::Color::Red);
                
                
                
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




unsigned int Map::GetWidth()
{
    return width;
}
unsigned int Map::GetHeight()
{
    return height;
}

bool Map::isInBounds(sf::Vector2i position)
{
    
    
    bool retVal = true;
    
    
    if(position.x < 0 || position.y < 0)
        return false;
    else if(position.x >= width || position.y >= height)
        return false;
    
    //std::cout << "\n x y" << position.x << "," << position.y;
    //  std::cout << "\n Retval " << retVal;
    
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

//The vertices don't matter. we just need the indices of the tiles
//Only returns position of tile if it's in bounds of the map (still need to test this)
//The drawing takes care of the vertices

void Map::ResetVisited()
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Map2D[i][j].visited = false;
        }
    }
}



sf::VertexArray Map::getVertices(std::vector<sf::Vector2i> tilePositions)
{
    sf::VertexArray vertArray;
    vertArray.setPrimitiveType(sf::Quads);
    vertArray.resize(tilePositions.size() * 4); //*4 because it's a square
    Tile tempTile;
    
    sf::VertexArray tempAr;
    int vertexCounter = 0; //Initially forgot this..I was using the tilePosition iterator as the verteArray index...
    for(int i = 0; i < tilePositions.size(); i++)
    {
        
        
        if(!isInBounds(tilePositions.at(i)))
            continue;
        tempAr = Map2D[tilePositions.at(i).x][tilePositions.at(i).y].getTileVertices();
        
        vertArray[vertexCounter] = tempAr[0];
        vertArray[vertexCounter+1] = tempAr[1];
        vertArray[vertexCounter+2] = tempAr[2];
        vertArray[vertexCounter+3] = tempAr[3];
        
        
        
        vertexCounter += 4;
        
    }
    
    return vertArray;
    
    
}



std::vector<BaseCreature*> Map::getCreatures(std::vector<sf::Vector2i> tilePositions)
{
    
    std::vector<BaseCreature*> tempCreatures;
    
    
    
    
    BaseCreature *tempCreat;
    int vertexCounter = 0; //Initially forgot this..I was using the tilePosition iterator as the verteArray index...
    for(int i = 0; i < tilePositions.size(); i++)
    {
        
        
        if(!isInBounds(tilePositions.at(i)))
            continue;
        
        tempCreat = Map2D[tilePositions.at(i).x][tilePositions.at(i).y].getCreatureOnTile();
        
        if(NULL != tempCreat)
            tempCreatures.push_back(tempCreat);
        
    }
    
    return tempCreatures;
    
}


void Map::AddEffect(int effectId, sf::VertexArray vertArray)
{
    //Don't need the vertices yet...
    MapEffect tempEffect;
    tempEffect.setID(effectId);
    
    bool exists = false;
    
    for(int i = 0; i < effects.size(); i++)
    {
        if(effectId == effects.at(i).getID())
        {
            exists = true;
            
        }
    }
    
    
    if(!exists)
    {
        
        tempEffect.vertices = vertArray;
        effects.push_back(tempEffect);
        
        std::cout << "\nEffect does not exist";
    }
    else
    {
        std::cout << "\nEffect exists";
    }
    
}

void Map::UpdateEffect(MapEffect newEffect)
{
    //Don't need the vertices yet...
    
    for(int i = 0; i < effects.size(); i++)
    {
        if(newEffect.getID() == effects.at(i).getID())
        {
            effects.at(i).tilePositions = newEffect.tilePositions;
            effects.at(i).vertices = newEffect.vertices;
            effects.at(i).setColor(newEffect.color);
            
        }
    }
    
    
    
    
    
    
}

void Map::RemoveEffect(MapEffect oldEffect)
{
    std::vector<MapEffect>::iterator effectIt;
    for(effectIt = effects.begin(); effectIt != effects.end(); ++effectIt)
    {
        if(effectIt->getID() == oldEffect.getID())
        {
            effects.erase(effectIt);
            return;
        }
    }
}

void Map::setupFogOfWar()
{
    fogOfWar = m_vertices;
    
}

//Sets the color of effect id
void Map::setEffectColor(int effectId, sf::Color color)
{
    for(int i = 0; i < effects.size(); i++)
    {
        effects.at(i).setColor(color);
    }
}

//The indices will make pathfinding easier..There's no easy way to define the relational operator for vector2i...avoiding pain
void Map::InitializeTileIndices()
{
    int ind = 0;
    for(int i=0; i<width; i++)
        for(int j = 0; j < height; i++)
        {
            Map2D[i][j].index = ind;
            ind++;
        }
}

sf::Vector2i Map::getCoordinates(int index)
{
    for(int i=0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(Map2D[i][j].index == index)
                return sf::Vector2i(i,j);
        }
    }
    
    return sf::Vector2i(-1,-1); //Failure conditon;
}



bool Map::isCreatureOnTile(sf::Vector2i point)
{
    
    std::cout << point.x << "," << point.y;
    if(NULL == Map2D[point.x][point.y].getCreatureOnTile())
        return false;
    
    
    return true;
}

bool Map::canHoldCreature(sf::Vector2i point)
{
    return Map2D[point.x][point.y].getCanHoldCreature();
    
    
}

Tile& Map::getByIndex(int index)
{
    for(int i=0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(Map2D[i][j].index == index)
                return Map2D[i][j];
        }
    }
}
