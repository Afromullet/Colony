//
//  CAMap.hpp
//  Colony
//
//  Created by Sean on 11/24/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//


#include "Map.hpp"
#include <stdio.h>
#ifndef CAMap_hpp
#define CAMap_hpp




//Map build through cellular automota

typedef struct _CARuleset
{
    int aliveTileID;
    int deadTileID;
    float chanceToStartAlive;
    int numberOfSteps;
    int birthLimit;
    int deathLimit;
    int numToStayAliveLimit;
    
}CA_RuleSet;

extern float CELL_CHANCETOSTARTALIVE;
extern int DEATH_LIMIT;
extern int BIRTH_LIMIT;
extern int NUMBER_OF_STEPS;

class CA_Map : public Map
{
    
    
    
public:
    
    CA_Map();
    
    void Generate_CA_MAP(sf::Vector2i _tileSize,unsigned int _width, unsigned int _height,CA_RuleSet _ruleset);
    
    
    void SetInitialState();
    void SetRuleSet(CA_RuleSet _ruleset);
    void SimulationStep();
    void CaveSimulationStep();
    int GetLivingNeighbors(int aliveTileID, int deadTileID,int x, int y);
    
    void TestRuleset();
    
    void PlacementTest();
    void CaveTunnelMap();
    void CreateRoom(std::vector<std::vector<Tile> > &newMap,int roomSize,sf::Vector2i startingPoint, int floorTileID, int wallTileID);
    
    
    
    
    
private:
    
    CA_RuleSet ruleset;
    std::vector<int> allNumOfNeighbors; //Num of neighbors in each cell. In same order as MAP2D. the map offset into map2d is
    
};

extern CA_Map caMap;

#endif /* CAMap_hpp */
