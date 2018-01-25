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
#include "Equipment.hpp"

/*
 
 
 
 
 [x1,y1]------------[x2,y1]
 |                      |
 |                      |
 |                      |
 |                      |
 |                      |
 [x1,y2]----------[x1,y2]
 
 
 */

#define BOTTOM_LEFT 0
#define TOP_LEFT 1
#define TOP_RIGHT 2
#define BOTTOM_RIGHT 3

class BaseCreature;
class Tile
{
    
    


public:
    Tile();
    
    void SetTileVertices(int xOffset, int yOffset,sf::Vector2i tileSize);
    sf::VertexArray getTileVertices();
    sf::VertexArray& getTileVerticesRef();
    void setTileID(int tileTypeID);
    void setCanHoldCreature(bool _canHoldCreature);
    int getTileID();
    void SetTileTerrainType(TileTerrainType _tileTerrainType);
    void SetCreatureOnTile(BaseCreature *_creature);
    void SetItemOnTile(Item *item);
    
    BaseCreature* getCreatureOnTile();
    
    bool getCanHoldCreature();
    Item* getItemOnTile();
    
   
    void ClearCreatureOnTile();
    
    void setFogOfWar(bool hasFog);
    bool getHasFogOfWar();
    
    
    bool isCreatureOnTile();

    

   
    
    
    
private:
    
    std::string tileName;
    int TileID; //Use a table to decode what kind of parameters this tile has (texture, etc)
    sf::Texture tileTexture;
    BaseCreature *creature; //Holds info on the creature on the tile. Only one creature can be on a tile
    TileTerrainType enTileTerrainType;
    bool canHoldCreature; //Determines whether or not the tile can hold a creature
    
    bool hasFogOfWar;
 
    sf::VertexArray tileVertices; //Pairs of 4s = 1 Tile,
    
    Item *itemOnTile; //For now only allow one item to be on a tile.
   
};


#endif /* Tile_hpp */
