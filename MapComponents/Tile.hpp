//
//  Tile.hpp
//  Colony
//
//  Created by Sean on 11/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <string>
#include "EnumTypes.hpp"
#include "BaseCreature.hpp"

/*
 
 
 
 
 [x1,y1]------------[x2,y1]
 |                      |
 |                      |
 |                      |
 |                      |
 |                      |
 [x1,y2]----------[x1,y2]
 
 
 */

class Creature;

class Tile
{
    
    
public:
    Tile();
    
    void SetTileVertices(int xOffset, int yOffset,sf::Vector2u tileSize);
    sf::VertexArray getTileVertices();
    sf::VertexArray& getTileVerticesRef();
    void setTileID(int tileTypeID);
    void setCanHoldCreature(bool _canHoldCreature);
    int getTileID();
    void SetTileTerrainType(TileTerrainType _tileTerrainType);
    void SetCreatureOnTile(BaseCreature *_creature);
    
    BaseCreature* getCreatureOnTile();
    
    bool getCanHoldCreature();
    
   
    void ClearCreatureOnTile();
    

    

   
    
    
    
private:
    
    std::string tileName;
    int TileID; //Use a table to decode what kind of parameters this tile has (texture, etc)
    sf::Texture tileTexture;
    BaseCreature *creature; //Holds info on the creature on the tile. Only one creature can be on a tile
    TileTerrainType enTileTerrainType;
    bool canHoldCreature; //Determines whether or not the tile can hold a creature
 
    sf::VertexArray tileVertices; //Pairs of 4s = 1 Tile,
   
};


#endif /* Tile_hpp */
