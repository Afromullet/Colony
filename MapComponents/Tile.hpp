//
//  Tile.hpp
//  Colony
//
//  Created by Sean on 11/15/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//




#ifndef Tile_hpp
#define Tile_hpp

//#include "EnumTypes.hpp"
#include "BaseCreature.hpp"
#include "Biomes.hpp"
#include "Equipment.hpp"


#include <stdio.h>
#include <string>
#include <memory>
#include "ItemManager.hpp"

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
    
    //bool operator==(const Tile &other);
   // bool operator!=(const Tile &other);
    //bool operator=(const Tile &other);
    
    Tile();
    Tile(Tile &other);
    Tile(const Tile &other);
  
    
    
    void ClearCreatureOnTile();
    
    void SetTileVertices(int xOffset, int yOffset,sf::Vector2i tileSize);
    void setTileID(int tileTypeID);
    void setCanHoldCreature(bool _canHoldCreature);
    void SetTileTerrainType(TileTerrainType _tileTerrainType);
    void SetCreatureOnTile(BaseCreature *_creature);
    void SetItemOnTile(Item *item);
    void SetBiome(enBiomes _biome);
    void setFogOfWar(bool hasFog);
    void setVisited(bool val);
    void setMovementCost(int val);
    void setElevation(double val);
    void setMoisture(double val);
    void setEnBiome(enBiomes val);
    void setBiome(Biome val);
    void setIndex(int val);
    
    BaseCreature* getCreatureOnTile();
    int getTileID() const;
    bool getCanHoldCreature() const;
    Item* getItemOnTile();
    bool getHasFogOfWar() const;
    bool isCreatureOnTile() const;
    sf::VertexArray getTileVertices() const;
    sf::VertexArray& getTileVerticesRef();
    bool getVisited() const;
    int getMovementCost() const;
    double getElevation() const;
    double getMoisture() const;
    enBiomes getEnBiome() const;
    Biome getBiome() const;
    int getIndex() const;
   
    //For adding items to tiles
    void AddArmor(Armor armor);
    
    
    
   
    
    
    
    

    
    
    
    
private:
    
    ItemManager inventory;
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
   
};


#endif /* Tile_hpp */
