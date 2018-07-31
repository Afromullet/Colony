//
//  Tile.cpp
//  Colony
//
//  Created by Sean on 11/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "Tile.hpp"
#include <iostream>




Tile::Tile()
{
    
    tileVertices.setPrimitiveType(sf::Quads);
    tileVertices.resize(4);
    TileID = -1;
    creature = NULL;
    itemOnTile = NULL;
    hasFogOfWar = true;
    visited = false;
    movementCost = 1;
    canHoldCreature = true;
    
    //movementCost = rand() % 10000;
        //std::cout << "\nMov " << movementCost;
    
}

/*
 std::string tileName;
 int TileID; //Use a table to decode what kind of parameters this tile has (texture, etc)
 sf::Texture tileTexture;
 BaseCreature *creature; //Holds info on the creature on the tile. Only one creature can be on a tile
 TileTerrainType enTileTerrainType;
 bool canHoldCreature; //Determines whether or not the tile can hold a creature
 int movementCost;
 double elevation;
 double moisture;
 bool hasFogOfWar;
 sf::VertexArray tileVertices; //Pairs of 4s = 1 Tile,
 Item *itemOnTile; //For now only allow one item to be on a tile.
 
 
 enBiomes EnBiome;
 Biome biome;
 
 int index;
 bool visited;
 */
Tile::Tile(Tile &other)
{
    tileName = other.tileName;
    TileID = other.TileID;
    tileTexture = other.tileTexture;
    creature = other.creature;
    enTileTerrainType = other.enTileTerrainType;
    canHoldCreature = other.canHoldCreature;
    movementCost = other.movementCost;
    elevation = other.elevation;
    moisture = other.moisture;
    hasFogOfWar = other.hasFogOfWar;
    tileVertices = other.tileVertices;
    EnBiome = other.EnBiome;
    biome = other.biome;
    index = other.index;
    visited = other.visited;
    inventory = other.inventory;
}
Tile::Tile(const Tile &other)
{
    tileName = other.tileName;
    TileID = other.TileID;
    tileTexture = other.tileTexture;
    creature = other.creature;
    enTileTerrainType = other.enTileTerrainType;
    canHoldCreature = other.canHoldCreature;
    movementCost = other.movementCost;
    elevation = other.elevation;
    moisture = other.moisture;
    hasFogOfWar = other.hasFogOfWar;
    tileVertices = other.tileVertices;
    EnBiome = other.EnBiome;
    biome = other.biome;
    index = other.index;
    visited = other.visited;
    
}

void Tile::ClearCreatureOnTile()
{
    creature = NULL;
}

void Tile::SetTileVertices(int xOffset, int yOffset,sf::Vector2i tileSize)
{
    
    sf::Vertex * quad = &tileVertices[0];;
    // define its 4 corners
    quad[0].position = sf::Vector2f(xOffset * tileSize.x, yOffset * tileSize.y);
    quad[1].position = sf::Vector2f((xOffset + 1) * tileSize.x, yOffset * tileSize.y);
    quad[2].position = sf::Vector2f((xOffset + 1) * tileSize.x, (yOffset + 1) * tileSize.y);
    quad[3].position = sf::Vector2f(xOffset * tileSize.x, (yOffset + 1) * tileSize.y);
    
    // define its 4 texture coordinates
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(tileSize.x,0);
    quad[2].texCoords = sf::Vector2f(tileSize.x,tileSize.y);
    quad[3].texCoords = sf::Vector2f(0, tileSize.y);
    
    
}

void Tile::setTileID(int tileTypeID)
{
    TileID = tileTypeID;
    
    
    
}

void Tile::setCanHoldCreature(bool _canHoldCreature)
{
    canHoldCreature = _canHoldCreature;
}

void Tile::SetTileTerrainType(TileTerrainType _tileTerrainType)
{
    enTileTerrainType = _tileTerrainType;
}

void Tile::SetCreatureOnTile(BaseCreature *_creature)
{
    if(NULL == _creature)
        return;
    creature = _creature;
}

void Tile::SetItemOnTile(Item *item)

{
    if(NULL == item)
        return;
    
    itemOnTile = item;
}

void Tile::setFogOfWar(bool hasFog)
{
    hasFogOfWar = hasFog;
}

void Tile::SetBiome(enBiomes _biome)
{
    EnBiome = _biome;
}

void Tile::setVisited(bool val)
{
    visited = val;
}

void Tile::setMovementCost(int val)
{
    movementCost = val;
}

void Tile::setElevation(double val)
{
    elevation = val;
}

void Tile::setMoisture(double val)
{
    moisture = val;
}

void Tile::setEnBiome(enBiomes val)
{
    EnBiome = val;
}

void Tile::setBiome(Biome val)
{
    biome = val;
}

void Tile::setIndex(int val)
{
    index = val;
}

bool Tile::getHasFogOfWar() const
{
    return hasFogOfWar;
}

BaseCreature* Tile::getCreatureOnTile()
{
    
    return creature;
}

Item* Tile::getItemOnTile() 
{
    return itemOnTile;
}

bool Tile::isCreatureOnTile() const
{
    if(NULL == creature)
        return false;
    
    return true;
    
}

bool Tile::getCanHoldCreature() const
{
    return canHoldCreature;
}

sf::VertexArray Tile::getTileVertices() const
{
    return tileVertices;
}

sf::VertexArray& Tile::getTileVerticesRef()
{
    return tileVertices;
}


int Tile::getTileID() const
{
    return TileID;
}

bool Tile::getVisited() const
{
    return visited;
}

int Tile::getMovementCost() const
{
    return movementCost;
}

double Tile::getElevation() const
{
    return elevation;
}
double Tile::getMoisture() const
{
    return moisture;
}

enBiomes Tile::getEnBiome() const
{
    return EnBiome;
}

Biome Tile::getBiome() const
{
    return biome;
}

int Tile::getIndex() const
{
    
}

//For adding items to tiles
void Tile::AddArmor(Armor armor)
{
    inventory.addArmor(armor);
}
