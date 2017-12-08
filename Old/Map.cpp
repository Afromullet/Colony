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
    Map2D.resize(MAP_WIDTH);
    for (int i = 0; i <= MAP_WIDTH-1; ++i)
        Map2D[i].resize(MAP_HEIGHT);
    
    tileSize = _tileSize;
    width = _width;
    height = _height;
    //tiles.clear(); //Todo remove in the future. This is just here for testing
    
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4); //We need four vertices for every tile
    
    // populate the vertex array, with one quad per tile
    
   
    Tile tempTile;
    //std::cout << "\n" << iterations << "its and tiles=" << tiles.size() << "\n" ;
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

void Map::LoadTileParameters()
{
    int RandomUpperLimit = 3;
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            Map2D[i][j].SetTileTerrainType(tileIDTable.at(Map2D[i][j].getTileID()).enTileTerrainType);
            
            
        }
    
}










/*
 
 Look at this example to show how to manipulate the vector map as a 2d array
 It is not efficient at the moment
 
 
 *NOTE
 Need to use the following steps to manipulate a vecor array as a 2d array
 

 1) Generate Tile Vertices (GenerateTileQuads)
    Does not yet have a tile ID
 2) Set initial Tile ID based on whatever ruleset used to generate map (In example below, uses cellular automota, and labels tiles as either alive or dead)
 3) Push those tiles into Map2D.
    Tiles is organized row by row
 4) Manipulate 2d array based on ruleset (ceullar automotota, here it does the starvation, death, stasis thing)
 5) Copy Map2d back into Tiles (So that we can group, load textures etc)
 6) Group tiles based on tile ID
 7) Load Textures
 
 
 */
//Currently modifies the 2D grid and copies it into tiles, then groups and draws
//Using Map2D and tiles vector separately will be fixed later. For now, doing the copying
//To prototype random map generator. At the end, I just want a 2d array










/*
 
 Old map generation. Here for historical purposes
 
 void Map::BasicRandomMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height)
 {
 GenerateTileQuads(_tileSize, _width,_height );
 GenerateRandomTiles();
 GroupTiles();
 
 Generate2DGrid();
 
 
 }
 
 Old cellular automota cave generation
 void Map::RandomCaveMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height, int aliveTileID, int deadTileId, float chanceToStartAlive, int NumberOfSteps, int birthLimit, int deathLimit)
 {
 tiles.clear();
 
 GenerateTileQuads(_tileSize, _width,_height );
 tileGroups.clear();
 
 float r;
 int randNum;
 
 
 
 //Randomly decide whether a tile is dead or alive;
 for(int i = 0; i < tiles.size(); i++)
 {
 r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
 if(r < chanceToStartAlive)
 tiles.at(i).setTileID(aliveTileID);
 else
 tiles.at(i).setTileID(deadTileId);
 }
 Generate2DGrid();
 
 //Apply ruleset NumefOfSteps time
 NumberOfSteps = 3;
 //Do the cellular automota steps
 //Simulation Step/TestRuleset iterate over every cell, determine the surrounding neighbors, and decide what the cell state is from that
 for(int i = 0; i < NumberOfSteps; i++)
 {
 SimulationStep(1, 0,birthLimit,deathLimit);
 //TestRuleset(); //Ruleset for what a cell does based on neighbor being dead/alive/overopulated
 
 }
 
 //Copy tiles into tiles vector so they can be grouped and drawn
 int tileCounter = 0;
 for(int i = 0; i <= Map2D.size() -1; i++)
 {
 for(int j = 0; j <= Map2D[i].size() -1; j++)
 {
 
 
 //tiles.at(tileCounter).setTileID(0);
 tiles.at(tileCounter) = Map2D[i][j];
 tileCounter++;
 }
 
 
 
 //tileCounter++;
 
 }
 
 
 
 GroupTiles();
 LoadTileTexture();
 
 
 
 
 }
 
 void Map::SimulationStep(int aliveTileID, int deadTileID, int birthLimit, int deathLimit)
 {
 
 
 std::vector<std::vector<Tile> > newMap = Map2D;
 //Loop over each row and column of the map
 for(int x=0; x<Map2D.size(); x++){
 for(int y=0; y<Map2D[0].size(); y++){
 int livingNeighbors = GetLivingNeighbors(aliveTileID, deadTileID,x, y);
 
 //Ned to set the TILE ID so we knwo waht kind of tile it is
 if(Map2D[x][y].getTileID() == aliveTileID){
 if(livingNeighbors < deathLimit){
 newMap[x][y].setTileID(deadTileID);
 }
 else{
 newMap[x][y].setTileID(aliveTileID);
 }
 } //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
 else{
 if(livingNeighbors > birthLimit){
 newMap[x][y].setTileID(aliveTileID);
 }
 else{
 newMap[x][y].setTileID(deadTileID);
 }
 }
 }
 }
 Map2D = newMap;
 
 }
 
 
 
 //Currently modifies the 2D grid and copies it into tiles, then groups and draws
 //Using Map2D and tiles vector separately will be fixed later. For now, doing the copying
 //To prototype random map generator. At the end, I just want a 2d array
 void Map::Random2DCaveMap(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height, int aliveTileID, int deadTileId, float chanceToStartAlive, int NumberOfSteps, int birthLimit, int deathLimit)
 {
 //tiles.clear();
 
 Generate2DMap(_tileSize, _width,_height );
 tileGroups.clear();
 
 float r;
 int randNum;
 
 
 for (unsigned int i = 0; i < width; ++i)
 {
 
 for (unsigned int j = 0; j < height; ++j)
 {
 std::cout << "\n(i,j)" << i << "," << j;
 r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
 if(r < chanceToStartAlive)
 Map2D[i][j].setTileID(aliveTileID);
 else
 Map2D[i][j].setTileID(deadTileId);
 
 }
 
 
 }
 
 
 
 //Apply ruleset NumefOfSteps time
 NumberOfSteps = 3;
 //Do the cellular automota steps
 //Simulation Step/TestRuleset iterate over every cell, determine the surrounding neighbors, and decide what the cell state is from that
 for(int i = 0; i < NumberOfSteps; i++)
 {
 SimulationStep(1, 0,birthLimit,deathLimit);
 //TestRuleset(); //Ruleset for what a cell does based on neighbor being dead/alive/overopulated
 
 }
 
 
 
 
 
 Group2DGridTiles();
 LoadTileTexture();
 
 
 int Map::GetLivingNeighbors(int aliveTileID, int deadTileID,int x, int y)
 {
 int count = 0;
 for(int i=-1; i<2; i++){
 for(int j=-1; j<2; j++){
 int neighbour_x = x+i;
 int neighbour_y = y+j;
 //If we're looking at the middle point
 if(i == 0 && j == 0){
 //Do nothing, we don't want to add ourselves in!
 }
 //In case the index we're looking at it off the edge of the map
 //If neighbor is off the map, assume it is alive
 else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= Map2D.size() || neighbour_y >= Map2D[0].size()){
 count = count + 1;
 }
 //Otherwise, a normal check of the neighbour
 else if(Map2D[neighbour_x][neighbour_y].getTileID() == aliveTileID){
 count = count + 1;
 }
 }
 }
 
 return count;
 
 }
 

 
 
 }
 

 

 void Map::TestRuleset()
 {
 
 int aliveTileID = 1;
 int deadTileID = 0;
 int birthLimit = 2;
 int deathLimit = 4;
 int overPopulationLimit = 5 ;
 std::vector<std::vector<Tile> > newMap = Map2D;
 //Loop over each row and column of the map
 for(int x=0; x<Map2D.size(); x++){
 for(int y=0; y<Map2D[0].size(); y++){
 int livingNeighbors = GetLivingNeighbors(aliveTileID, deadTileID,x, y);
 
 
 //Ned to set the TILE ID so we knwo waht kind of tile it is
 if(Map2D[x][y].getTileID() == aliveTileID){
 
 //Alive but too many neighboors
 if(livingNeighbors < deathLimit)
 newMap[x][y].setTileID(deadTileID);
 else if(livingNeighbors == 2 || livingNeighbors == 3)
 newMap[x][y].setTileID(aliveTileID); //statis
 else if(livingNeighbors > overPopulationLimit)
 newMap[x][y].setTileID(deadTileID);
 //Alive but too few neighbors
 
 
 
 } //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
 else{
 if(livingNeighbors >= birthLimit){
 newMap[x][y].setTileID(aliveTileID);
 }
 
 
 
 
 
 }
 }
 }
 Map2D = newMap;
 
 
 }

 
 
 //Generates the verticles for the map. They are not yet tetured, that will be done later
 bool Map::GenerateTileQuads(sf::Vector2u _tileSize, unsigned int _width, unsigned int _height)
 {
 
 tileSize = _tileSize;
 width = _width;
 height = _height;
 tiles.clear(); //Todo remove in the future. This is just here for testing
 
 // resize the vertex array to fit the level size
 m_vertices.setPrimitiveType(sf::Quads);
 m_vertices.resize(width * height * 4); //We need four vertices for every tile
 //tiles.resize(width * height); //Since there's width by height tiles
 
 // populate the vertex array, with one quad per tile
 
 int iterations = 0;
 int k = 0;
 Tile tempTile;
 
 //std::cout << "\n" << iterations << "its and tiles=" << tiles.size() << "\n" ;
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
 tiles.push_back(tempTile);
 
 
 }
 }
 
 return true;
 }
 

 void Map::GroupTiles()
 {
 //Get Unique group IDs
 
 
 bool foundTile = false;
 MapTileParams groupParams;
 Tile tile;
 sf::Vertex newVert;
 
 
 for(int i = 0; i < tiles.size(); i++)
 {
 foundTile = false;
 groupParams.TileID = tiles.at(i).getTileID();
 groupParams.m_vertices.setPrimitiveType(sf::Quads);
 for(int j = 0; j < tileGroups.size(); j++)
 {
 if(tiles.at(i).getTileID() == tileGroups.at(j).TileID)
 {
 foundTile = true;
 
 tile = tiles.at(i);
 
 newVert.position = tile.getTileVertices()[0].position;
 newVert.texCoords = tile.getTileVertices()[0].texCoords;
 tileGroups.at(j).m_vertices.append(newVert);
 
 newVert.position = tile.getTileVertices()[1].position;
 newVert.texCoords = tile.getTileVertices()[1].texCoords;
 tileGroups.at(j).m_vertices.append(newVert);
 
 newVert.position = tile.getTileVertices()[2].position;
 newVert.texCoords = tile.getTileVertices()[2].texCoords;
 tileGroups.at(j).m_vertices.append(newVert);
 
 newVert.position = tile.getTileVertices()[3].position;
 newVert.texCoords = tile.getTileVertices()[3].texCoords;
 tileGroups.at(j).m_vertices.append(newVert);
 
 break;
 
 }
 }
 
 if(!foundTile)
 {
 
 
 tile = tiles.at(i);
 
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
 

 //Currently, it just generates a random number (currently hardcoded)
 //Each of these numbers matches up to a tileID with a texture
 void Map::GenerateRandomTiles()
 {
 int randNum;
 for(int i = 0; i < tiles.size(); i++)
 {
 randNum = rand() % 3;
 
 tiles.at(i).setTileID(randNum);
 
 
 }
 
 }
 
 void Map::Copy2DMapToVector()
 {
 //Copy tiles into tiles vector so they can be grouped and drawn
 int tileCounter = 0;
 for(int i = 0; i <= Map2D.size() -1; i++)
 {
 for(int j = 0; j <= Map2D[i].size() -1; j++)
 {
 
 
 //tiles.at(tileCounter).setTileID(0);
 tiles.at(tileCounter) = Map2D[i][j];
 tileCounter++;
 }
 
 
 
 //tileCounter++;
 
 }
 
 
 }

 void Map::drawCreature(sf::RenderTarget& target, sf::RenderStates states) const
 {
 // apply the transform
 states.transform *= getTransform();
 
 // apply the tileset texture
 states.texture = &m_tileset;
 
 
 
 
 // draw the vertex array
 target.draw(m_vertices, states);
 }
 
 sf::Vector2u Map::getTileSize()
 {
 return tileSize;
 }
 
 Currently, the tile drawing is based on an example from the sfml documentation
 So I did not use the 2d tile. Convert the vector to a 2d array. maybe later
 starts off with a 2d array rather than converting
 
 Loop through tiles vector, and for every time i == height, start a new row
 
 Because the example drew the map in colums rather than rows, we use height
 
 
 TODO update this to use pointers to the tile from tiles. Currently it copies the tile
 That won't do
 
void Map::Generate2DGrid()
{
    //std::vector<std::vector<Tile> > matrixMap;
    
    // Set up sizes. (HEIGHT x WIDTH)
    Map2D.resize(MAP_WIDTH);
    
    int cnt = -1;
    cnt = MAP_WIDTH;
    for (int i = 0; i <= MAP_WIDTH-1; ++i)
    {
        Map2D[i].resize(MAP_HEIGHT);
        
        cnt+=MAP_HEIGHT-1;
    }
    
    
    
}
 
 
 
 */

