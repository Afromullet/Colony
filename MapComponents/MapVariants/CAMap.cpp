//
//  CAMap.cpp
//  Colony
//
//  Created by Sean on 11/24/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "CAMap.hpp"
//#include "Globals.hpp"
#include <time.h>
#include <math.h>


float CELL_CHANCETOSTARTALIVE;
int DEATH_LIMIT;
int BIRTH_LIMIT;
int NUMBER_OF_STEPS;


CA_Map::CA_Map()
{
    
    //Default Ruleset
    ruleset.aliveTileID = 4;
    ruleset.deadTileID = 2;
    ruleset.birthLimit = 3;
    ruleset.chanceToStartAlive = 0.7;
    ruleset.deathLimit = 5;
    ruleset.numberOfSteps = 20;
    
}


void CA_Map::SetInitialState()
{
    
    float r;
    int randNum;
    int numAlive = 0;
    int numDead = 0;
    srand(time(NULL));
    for (unsigned int i = 0; i < GetWidth(); ++i)
    {
        
        for (unsigned int j = 0; j < GetHeight(); ++j)
        {
            // r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            //
            r = static_cast <float>((rand() / (float)RAND_MAX ));
            
            
            if(r <= ruleset.chanceToStartAlive)
            {
                numAlive++;
                Map2D[i][j].setTileID(ruleset.aliveTileID);
            }
            else
            {
                numDead++;
                Map2D[i][j].setTileID(ruleset.deadTileID);
            }
        }
        
    }
    
    /*
     std::cout << "\n Alive,Dead: " << numAlive << "," << numDead;
     std::cout << "\n Alive,Dead: " << numAlive << "," << numDead;
     */
    
}

void CA_Map::Generate_CA_MAP(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height,CA_RuleSet _ruleset)
{
    Generate2DMap(_tileSize, _width,_height );
    
    
    tileGroups.clear();
    
    float r;
    int randNum;
    
    
    SetInitialState();
    
    
    //Apply ruleset NumefOfSteps time
    //Do the cellular automota steps
    //Simulation Step/TestRuleset iterate over every cell, determine the surrounding neighbors, and decide what the cell state is from that
    for(int i = 0; i < ruleset.numberOfSteps; i++)
    {
        SimulationStep();
        
        //CaveSimulationStep();
    }
    
    
    
    //PlacementTest();
    Group2DGridTiles();
    
    LoadTileParameters();
    LoadTileTexture();
    for(int i = 0; i < GetWidth(); i++)
    {
        for(int j = 0; j < GetHeight(); j++)
        {
            Map2D[i][j].SetCreatureOnTile(NULL);
        }
    }
    
    
    
    
}

void CA_Map::SimulationStep()
{
    std::vector<std::vector<Tile> > newMap = Map2D;
    //Loop over each row and column of the map
    for(int x=0; x<Map2D.size(); x++){
        for(int y=0; y<Map2D[0].size(); y++){
            int livingNeighbors = GetLivingNeighbors(ruleset.aliveTileID, ruleset.deadTileID,x, y);
            //allNumOfNeighbors.push_back(livingNeighbors);
            //Ned to set the TILE ID so we knwo waht kind of tile it is
            if(Map2D[x][y].getTileID() == ruleset.aliveTileID){
                if(livingNeighbors < ruleset.deathLimit){
                    newMap[x][y].setTileID(ruleset.deadTileID);
                }
                else{
                    newMap[x][y].setTileID(ruleset.aliveTileID); //Stay alive
                }
            } //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
            else{
                if(livingNeighbors >= ruleset.birthLimit){
                    newMap[x][y].setTileID(ruleset.aliveTileID);
                }
                else{
                    newMap[x][y].setTileID(ruleset.deadTileID);
                }
            }
            
        }
        
        
    }
    Map2D = newMap;
    
    
}

void CA_Map::CaveSimulationStep()
{
    std::vector<std::vector<Tile> > newMap = Map2D;
    //Loop over each row and column of the map
    for(int x=0; x<Map2D.size(); x++){
        for(int y=0; y<Map2D[0].size(); y++){
            int livingNeighbors = GetLivingNeighbors(ruleset.aliveTileID, ruleset.deadTileID,x, y);
            
            //Ned to set the TILE ID so we knwo waht kind of tile it is
            //TODO add list of parameters for each part of rueleset
            if(Map2D[x][y].getTileID() == ruleset.aliveTileID){
                if(livingNeighbors < 2 || livingNeighbors > 5){
                    newMap[x][y].setTileID(ruleset.deadTileID);
                }
                
                else if(livingNeighbors == 2 || livingNeighbors == 3)
                {
                    newMap[x][y].setTileID(ruleset.aliveTileID); //Just to be safe...
                }
                else{
                    newMap[x][y].setTileID(ruleset.aliveTileID);
                }
            } //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
            else{
                if(livingNeighbors == 3){
                    newMap[x][y].setTileID(ruleset.aliveTileID);
                }
                
            }
        }
    }
    Map2D = newMap;
    
    
}

/*
 aliveTileID and deadTileID = the tile ID we use to represent whether a tile is dead or alive
 X and Y are the cell coordinates in the 2D map
 Way Cellular Automota cave generation works is based on
 https://gamedevelopment.tutsplus.com/tutorials/generate-random-cave-levels-using-cellular-automata--gamedev-9664
 
 
 Rather than using a boolean array it uses two tile IDs, where one tile is "dead" and the other is "alive"
 
 MOORE NEIGHBORHOOD
 */
int CA_Map::GetLivingNeighbors(int aliveTileID, int deadTileID,int x, int y)
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

void CA_Map::TestRuleset()
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



void CA_Map::SetRuleSet(CA_RuleSet _ruleset)
{
    ruleset = _ruleset;
}


//Places features on dead tiles that have only living surrounding cells
void CA_Map::PlacementTest()
{
    int x,y;
    
    
    //Because the map changed , need to recalculate the number of neighbors..Storing it in a vector because I need to
    //Know the total number of cells with only one living neigbor before making any decisio
    
    
    
    std::cout << "\nNum of " << allNumOfNeighbors.size();
    
    std::vector<std::vector<Tile> > newMap = Map2D;
    newMap = Map2D;
    
    for(int i=0; i<newMap.size(); i++)
    {
        for(int j=0; j<newMap[0].size(); j++)
        {
            //aliveTileID
            //deadTileID
            int n = 0;
            if(newMap[i][j].getTileID() == ruleset.deadTileID)
            {
                n = GetLivingNeighbors(ruleset.aliveTileID, ruleset.aliveTileID,i, j);
            }
            
            if(n == 8)
            {
                sf::Vector2i roomPos(i,j);
                CreateRoom(newMap,3, roomPos, 1, 2);
            }
            
            allNumOfNeighbors.push_back(GetLivingNeighbors(ruleset.deadTileID, ruleset.aliveTileID,i, j));
        }
    }
    
    Map2D = newMap;
    
    /*
     for(int i = 0; i < allNumOfNeighbors.size(); i++)
     {
     
     x = floor(i / GetWidth()); //Can't remember if C++ rounds up or down, so using floor to be safe
     y = i % GetWidth(); //Modulo gets the Y
     
     
     if(allNumOfNeighbors.at(i) == 0)
     {
     Map2D[x][y].setTileID(2);
     }
     
     }
     */
}

void CA_Map::CaveTunnelMap()
{
    int x,y;
    
    
    //Because the map changed , need to recalculate the number of neighbors..Storing it in a vector because I need to
    //Know the total number of cells with only one living neigbor before making any decisio
    
    
    
    std::cout << "\nNum of " << allNumOfNeighbors.size();
    
    std::vector<std::vector<Tile> > newMap = Map2D;
    newMap = Map2D;
    
    for(int i=0; i<newMap.size(); i++)
    {
        for(int j=0; j<newMap[0].size(); j++)
        {
            int n = GetLivingNeighbors(ruleset.aliveTileID, ruleset.deadTileID,i, j);
            
            if(n == 8)
            {
                
                newMap[i][j].setTileID(0);
                
                
            }
            
            allNumOfNeighbors.push_back(GetLivingNeighbors(ruleset.deadTileID, ruleset.aliveTileID,i, j));
        }
    }
    
    Map2D = newMap;
    
    /*
     for(int i = 0; i < allNumOfNeighbors.size(); i++)
     {
     
     x = floor(i / GetWidth()); //Can't remember if C++ rounds up or down, so using floor to be safe
     y = i % GetWidth(); //Modulo gets the Y
     
     
     if(allNumOfNeighbors.at(i) == 0)
     {
     Map2D[x][y].setTileID(2);
     }
     
     }
     */
    
    
    
}

//Move to parent class later
void CA_Map::CreateRoom(std::vector<std::vector<Tile> > &newMap,int roomSize, sf::Vector2i startingPoint, int floorTileID, int wallTileID)
{
    int newX,newY;
    
    //roomSize = 0;
    int iterations = 0;
    for(int i = -roomSize; i < roomSize; i++)
    {
        for(int j = -roomSize; j < roomSize; j++)
        {
            newX = startingPoint.x + i;
            newY = startingPoint.y + j;
            
            
            // map.Map2D[newX][newY].setTileID(roomTileID);
            
            
            if(isInBounds(sf::Vector2i(newX,newY)))
            {
                newMap[newX][newY].setTileID(wallTileID);
                
            }
        }
    }
    
    //Now hollow out the rooms
    //Hollowing out is almost same as getting bounding rectangle
    
    //Doing this in a very inelegant way. Work on later, for now I just want to get a basic implementation
    //Explicitly going over every edge todo rest
    
    for(int i = 0; i < roomSize; i++)
    {
        
        int x = startingPoint.x - i - (floor(roomSize/2));
        int y = startingPoint.y + (roomSize/2 + 1);
        
        if(isInBounds(sf::Vector2i(x,y)))
            newMap[x][y].setTileID(0);
        
        x = startingPoint.x + i + 1 - (floor(roomSize/2));
        y = startingPoint.y + (roomSize/2 + 1);
        
        if(isInBounds(sf::Vector2i(x,y)))
            newMap[x][y].setTileID(0);
    }
    
    
    
    
}

CA_Map caMap;
