//
//  EntityTile.hpp
//  Colony
//
//  Created by Sean on 11/25/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef EntityTile_hpp
#define EntityTile_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>

//Handles the drawing of a single tile for things such as creatures or items. The creaturePosition variable is misleading..It can be the position of anything. TODO change that

class EntityTile : public sf::Drawable, public sf::Transformable
{
public:
    
    // bool loadCreature(const std::string& tileset, sf::Vector2u tileSize, int creatureXPosition, int creatureYPosition);
    
    
    //TODO rename creaturePosition since the tile can also represent an item. this will prevent confusion
    bool loadTile(const std::string& tileset, sf::Vector2u _tileSize, sf::Vector2u creaturePosition);
    
    void setPosition(int x, int y);

    
    sf::Vector2u getTileSize();
    
    // std::vector<TileParameters> vecTileParams;
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
    
    sf::VertexArray m_vertices; //Pairs of 4s = 1 Tile
    sf::Texture m_tileset;
    sf::Vector2u tileSize;
    unsigned int width;
    unsigned int height;
    
    
    
};


#endif /* EntityTile_hpp */
