//
//  EntityTile.cpp
//  Colony
//
//  Created by Sean on 11/25/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "EntityTile.hpp"


//Need to draw a creature withn the bounds of a tile
bool EntityTile::loadTile(const std::string& tileset, sf::Vector2u _tileSize, sf::Vector2u creaturePosition)
{
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;
    
    tileSize = _tileSize;
    
   // TileParameters tileParams;
    
    
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4); //Since a creature tile is just like any other tile..We are only drawing one tile for every creature, so the size is 4, one for each corner of the square
    
    // populate the vertex array, with one quad per tile
    
    int tileNumber = 0;
    
    // find its position in the tileset texture
    // int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
    // int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
    
    int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
    int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
    
    
    
   // tileParams.x = creaturePosition.x;
   // tileParams.y = creaturePosition.y;
    
    // get a pointer to the current tile's quad
    sf::Vertex * quad = &m_vertices[tileNumber];
    
    
    
    // define its 4 corners
    quad[0].position = sf::Vector2f(creaturePosition.x * tileSize.x, creaturePosition.y * tileSize.y);
    quad[1].position = sf::Vector2f((creaturePosition.x + 1) * tileSize.x, creaturePosition.y * tileSize.y);
    quad[2].position = sf::Vector2f((creaturePosition.x + 1) * tileSize.x, (creaturePosition.y + 1) * tileSize.y);
    quad[3].position = sf::Vector2f(creaturePosition.x * tileSize.x, (creaturePosition.y + 1) * tileSize.y);
    
    // define its 4 texture coordinates
    
    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
    
    
    
    return true;
}

//For a particular coordinate, sets the
void EntityTile::setPosition(int x, int y)
{
    
    
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);
    int tileNumber = 0;
    sf::Vector2u creaturePosition(x,y);
    //sf::Vector2u tileSize(32,32);
    sf::Vertex * quad = &m_vertices[tileNumber];
    
    
    
    
    int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
    int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
    
    
    quad[0].position = sf::Vector2f(creaturePosition.x * tileSize.x, creaturePosition.y * tileSize.y);
    quad[1].position = sf::Vector2f((creaturePosition.x + 1) * tileSize.x, creaturePosition.y * tileSize.y);
    quad[2].position = sf::Vector2f((creaturePosition.x + 1) * tileSize.x, (creaturePosition.y + 1) * tileSize.y);
    quad[3].position = sf::Vector2f(creaturePosition.x * tileSize.x, (creaturePosition.y + 1) * tileSize.y);
}
void EntityTile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    //states.transform.scale(tileScale, tileScale);
    
    states.transform *= getTransform();
    
    // apply the tileset texture
    states.texture = &m_tileset;
    
    
    //std::vector<TileParameters>::iterator tileIt;
    //std::vector<TileParameters>::iterator tileIt;
    //tileIt = vecTileParams.begin();
    
    // draw the vertex array
    target.draw(m_vertices, states);
}




sf::Vector2u EntityTile::getTileSize()
{
    return tileSize;
}

