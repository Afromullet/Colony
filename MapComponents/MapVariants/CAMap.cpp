//
//  CAMap.cpp
//  Colony
//
//  Created by Sean on 11/24/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "CAMap.hpp"
#include "Globals.hpp"



float CELL_CHANCETOSTARTALIVE;
int DEATH_LIMIT;
int BIRTH_LIMIT;
int NUMBER_OF_STEPS;


CA_Map::CA_Map()
{
    
    //Default Ruleset
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = 3;
    ruleset.chanceToStartAlive = 0.7;
    ruleset.deathLimit = 5;
    ruleset.numberOfSteps = 3;

}


void CA_Map::SetInitialState()
{
    
    float r;
    int randNum;
    
    for (unsigned int i = 0; i < GetWidth(); ++i)
    {
        
        for (unsigned int j = 0; j < GetHeight(); ++j)
        {
            r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            if(r < ruleset.chanceToStartAlive)
                Map2D[i][j].setTileID(ruleset.aliveTileID);
            else
                Map2D[i][j].setTileID(ruleset.deadTileID);
        }
        
    }

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

    int i;
}

void CA_Map::SimulationStep()
{
    std::vector<std::vector<Tile> > newMap = Map2D;
    //Loop over each row and column of the map
    for(int x=0; x<Map2D.size(); x++){
        for(int y=0; y<Map2D[0].size(); y++){
            int livingNeighbors = GetLivingNeighbors(ruleset.aliveTileID, ruleset.deadTileID,x, y);
            
            //Ned to set the TILE ID so we knwo waht kind of tile it is
            if(Map2D[x][y].getTileID() == ruleset.aliveTileID){
                if(livingNeighbors < ruleset.deathLimit){
                    newMap[x][y].setTileID(ruleset.deadTileID);
                }
                else{
                    newMap[x][y].setTileID(ruleset.aliveTileID);
                }
            } //Otherwise, if the cell is dead now, check if it has the right number of neighbours to be 'born'
            else{
                if(livingNeighbors > ruleset.birthLimit){
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