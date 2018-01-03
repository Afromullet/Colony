//
//  CAMap.hpp
//  Colony
//
//  Created by Sean on 11/24/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#ifndef CAMap_hpp
#define CAMap_hpp

#include <stdio.h>
#include "Map.hpp"


//Map build through cellular automota

typedef struct _CARuleset
{
    int aliveTileID;
    int deadTileID;
    float chanceToStartAlive;
    int numberOfSteps;
    int birthLimit;
    int deathLimit;
    
}CA_RuleSet;

extern float CELL_CHANCETOSTARTALIVE;
extern int DEATH_LIMIT;
extern int BIRTH_LIMIT;
extern int NUMBER_OF_STEPS;

class CA_Map : public Map
{
    
    
    
public:
    
    CA_Map();
    
    void Generate_CA_MAP(sf::Vector2u _tileSize,unsigned int _width, unsigned int _height,CA_RuleSet _ruleset);
    
    
    void SetInitialState();
    void SetRuleSet(CA_RuleSet _ruleset);
    void SimulationStep();
    int GetLivingNeighbors(int aliveTileID, int deadTileID,int x, int y);
    
    void TestRuleset();

    
    
private:
    
    CA_RuleSet ruleset;
    
};

#endif /* CAMap_hpp */
