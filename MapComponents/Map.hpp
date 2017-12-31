//
//  Map.hpp
//  Colony
//
//  Created by Sean on 11/12/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//






#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>


#include "Tile.hpp"
#include <unordered_map>


//Groups tile vertices by a tile ID
//Todo make vertexarray a reference so we do not contain the vertices twice
typedef struct MapTileParameters
{
    sf::VertexArray m_vertices; //Pairs of 4s = 1 Tile
    sf::Texture m_tileset;
    int TileID; //ID should match with those in a lookup table so we can load anything useful
   
  
    
}MapTileParams;


#define NOT_VISITED_TILE_ID 0
#define VISITED_TILE_ID 1


class Tile;

class Map : public sf::Drawable, public sf::Transformable
{
public:
    
    
     std::vector<MapTileParams> tileGroups;
    
    void BasicRandom2DMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height);
    bool Generate2DMap(sf::Vector2u _tileSize, unsigned int _width, unsigned int _height);
    void Group2DGridTiles();
    void LoadTileTexture();
    void GenerateRandom2DTiles();
    void LoadTileParameters();
    sf::Vector2u getTileSize();
    unsigned int GetWidth();
    unsigned int GetHeight();
    bool isInBounds(sf::Vector2u position);
    void FloodFill(int x, int y, int targetTileID, int replacementTileID);
    void FloodFill(int x, int y, int targetTileID, int replacementTileID, int blockSize);
    
    std::vector<std::vector<Tile> > Map2D;
    
    
    
   
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    sf::Vector2u tileSize;
    unsigned int width;
    unsigned int height;
    
    //Tiles stores the position of the tiles, m_vertices.
    //This vector is basically a bag of vertices we can use to create the map
    sf::VertexArray m_vertices; //Pairs of 4s = 1 Tile
    
    
};
#endif /* Map_hpp */



/*
 
 
 
 Old notes on when I was attempting to understand the way to draw the map
 
 
 Pretty much what's being
 
 Just dividing a carthesian plane into cells. those cells are squares. those squares are roomsizes. the size of the cell is based on the tilesise x and y cooridnates
 
 
 
 
 _______________
 Olrder
 |
 |
 |
 v
 
 
 I see now..I was mistaking ""width"" with the width of the tile, when it's actually the width of the map.
 
 And also, I wasn't thinking about the representation of the vertexes in terms of displaying them on the screen..There's a difference between world space and player space. Player space are things such as player line of sight, world space is the graphical representation
 
 (I still have to figure out how to convert from world space to player space, but that's beyond the scope of this comments)
 
 
 Each tile it four squares so...now let's look at
 
 &m_vertices[(i + j * width) * 4]; //
 
 let's use the following array as an example:
 
 [a,b,c
 [d,e,f]
 
 
 i = width
 j = height
 
 
 
 
 Also, even though the map is two dimensional, we are not using a two dimensional array to represent the positions, but where to draw the tiles.
 
 Since a tile is a square, it's represented in sfml as a quad. So we need four coordinates to determine where to draw it
 
 (Doesn't look like a square since the line sizes are different)
 
 
 
 DIAGRAM
 
 [x1,y1]------------[x2,y1]
 |                      |
 |                      |
 |                      |
 |                      |
 |                      |
 [x1,y2]----------[x1,y2]
 
 
 
 
 Four vertices
 
 
 |
 |
 |
 |
 |
 |
 v
 &m_vertices[(i + j * width) * 4]; //
 
 
 
 
 DIAGRAM END
 
 This is why we iterate i + j * width. Each of those tiles needs four coordinates, so we pull out the vertices in pairs of 4 to fill the quad object.
 
 sf::Vertex * quad = &m_vertices[(i + j * width) * 4];
 
 We're just grabbing four vertics, their position isn't determined yet. We know how vertices we need because we know the width and height of the map, so we know how many vertices there are
 
 m_vertices.resize(width * height * 4);
 
 
 
 
 
 
 And the way pointers work, a reference grabs as much memory as it can to fill the data structure. Here is an example. When reading this again, try to jump past it
 
 EXAMPLE
 
 struct a
 int v1
 
 struct b
 int v1
 int v2
 
 struct c
 int v1
 int v2
 int v3
 
 array arr = [1,2,3,4,5,6,7,8,9,10]
 
 
 *a = &arr[0];
 *b = &arr[0];
 *c = &arr[0];
 
 struct a contains:
 
 a.v1 = 1;
 
 b.v1 = 1;
 b.v2 = 2;
 
 b.v1 = 1;
 b.v2 = 2;
 
 
 a.v1 = 5
 
 b.v1 = 5;
 b.v2 = 6;
 
 c.v1 = 5;
 c.v2 = 6;
 c.v4 = 7;
 
 EXAMPLE END
 
 
 Back to &m_vertices[(i + j * width) * 4]; //
 
 
 where i = width and j = height
 
 We're just grabbing four vertics, their position isn't determined yet. We know how to place them based on the tilesize.
 
 
 
 ***This is important***
 
 The size of the map has nothing to do with screen size
 
 Width and height are just that, how high we want the map to be in terms of size (player space)
 
 screen x and screen y is how we show that map regardless of size (world space)
 
 The number of tiles we draw on the map does not depend on the width and height in pixels
 , just on the width and height in vertices (tilesize). I just happened to choose values that will completely fill the screen to help with testing the drawing.
 
 The tilesize tells us where the x and y is
 
 
 Look at
 // define its 4 corners
 quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
 quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
 quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
 quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
 
 
 Top Part of square
 
 [x1,y2]----------[x1,y2]
 
 
 Bottom Part of square
 
 [x1,y1]------------[x2,y1]
 |                      |
 
 
 We're drawing the square in term sof tilesize, that's why we multiply by the tilesize
 
 sf::Vector2f(i * tileSize.x, j * tileSize.y);
 
 So when we return from the inner loop and back to the outer
 
 
 for (unsigned int i = 0; i < width; ++i)
 for (unsigned int j = 0; j < height; ++j)
 {
 
 
 We're calculating the position of the next row of squares
 
 a,b,c,d,e,f
 g,h,i,j,k,l
 
 
 the tilesize, on the other hand, is determined in pixels. We are drawing the square around the width and height of the tilesize.
 
 
 
 Look at
 
 quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
 
 Specifically, (i * tileSize.x, j * tileSize.y)
 
 We can calculate the offset to the next pair because the tile sizes are symmetric.
 
 Returning to the next inner loop iteration of ...
 
 for (unsigned int i = 0; i < width; ++i)
 for (unsigned int j = 0; j < height; ++j)
 {
 
 we are drawing like this:
 
 drawing columns, not rows
 
 (for a map size 2x2)
 
 |
 |
 
 
 ||
 |
 
 ||
 ||
 |
 
 ||
 ||
 ||
 
 Not like this
 
 _
 
 _ _
 
 _ _
 _
 
 _ _
 _ _
 
 
 
 
 anyways
 
 Returning to the next inner loop iteration of ...
 
 for (unsigned int i = 0; i < width; ++i)
 for (unsigned int j = 0; j < height; ++j)
 
 We're drawing the next square.
 
 Outer loop, start next row
 
 draw rest of row
 
 And just doing that width by heights time
 
 Next, calculating the texture location
 
 // find its position in the tileset texture
 int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
 int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
 
 The texture size is based on the tilesize, but they're still not the location
 of the tile itself..The texture is scaled to fit
 
 int tileNumber = tiles[i + j * width]; gets us the offset to the tile
 
 
 ***Important part end***
 
 */



