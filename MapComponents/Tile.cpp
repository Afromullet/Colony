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
    
}

sf::VertexArray Tile::getTileVertices()
{
    return tileVertices;
}

sf::VertexArray& Tile::getTileVerticesRef()
{
    return tileVertices;
}


int Tile::getTileID()
{
    return TileID;
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

bool Tile::getCanHoldCreature()
{
    return canHoldCreature;
}

void Tile::SetTileTerrainType(TileTerrainType _tileTerrainType)
{
    enTileTerrainType = _tileTerrainType;
}

void Tile::SetCreatureOnTile(BaseCreature *_creature)
{
    creature = _creature;
}

void Tile::SetItemOnTile(Item *item)
{
    itemOnTile = item;
}

void Tile::setFogOfWar(bool hasFog)
{
    hasFogOfWar = hasFog;
}


bool Tile::getHasFogOfWar()
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

