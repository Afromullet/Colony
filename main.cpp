#include <SFML/Graphics.hpp>


#include <iostream>
#include <Vector>
#include <cstdlib>

#include "Universal_Includes.h"
#include "Equipment_Includes.h"

#include "Globals.hpp"

//#include "Constants.hpp"
//#include "Globals.hpp"







#include "EnumTypes.hpp"




#include "TestData.hpp"
#include "EntityTile.hpp"
#include "Map.hpp"
#include "CAMap.hpp"
#include "TileReader.hpp"
#include "MovementHandler.hpp"
#include "MapUtil.hpp"
#include "SquareDiggingMap.hpp"
#include "Arm.hpp"
#include "Leg.hpp"
#include "HumanoidBody.hpp"
#include "BaseCreature.hpp"
#include "QuadrupedBody.hpp"
#include "CreatureHandler.hpp"
#include "ItemGenerator.hpp"
#include "MapData.hpp"
#include "TestDataGenerator.hpp"
#include "PlayerControls.hpp"


void GameLoop3();

void MoveAllCreatures();
void InitializeMaps();
void SetupCurrentMap();
void SetupGameData(Map *map);
void DrawEverything(MapData _mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;



int main()
{
    ParseTileFile();
    BasicTileRuleset();
    window.setKeyRepeatEnabled(false);
    mapdata.SetWindow(&window);
    SetupGameData(&caMap);
    
    
    
    
    GameLoop3();
    
    return 0;
}











    












sf::Clock globalClock;




void GameLoop3()
{
    
    

   

    player.EquipItemFromInventory(5);
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
            HandlePlayerInput(event,mapdata,player);
            
            
        }

        DrawEverything(mapdata);
        
        
        
        }
        
        return 0;
    
    
}
















/* 
 Testing functions. Moves creatures randomly on the map 
 */
void MoveAllCreatures()
{
    std::list<BaseCreature>::iterator iter;
    for(iter = mapdata.creaturesOnMap.begin(); iter != mapdata.creaturesOnMap.end(); ++iter)
    {
        BaseCreature &creat = *iter;
        MoveCreatureRandomly(&creat, *mapdata.map);
    }
}

void InitializeMaps()
{
    
    
    MainMap.BasicRandom2DMap(sf::Vector2u(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE), MAP_WIDTH, MAP_HEIGHT);
    squareMap.CreateMap(sf::Vector2u(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE),MAP_WIDTH, MAP_HEIGHT, 0);
    //Just a random ruleset
    CELL_CHANCETOSTARTALIVE = 0.45f;
    NUMBER_OF_STEPS = 10;
    BIRTH_LIMIT = 3;
    DEATH_LIMIT = 8;
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = BIRTH_LIMIT;
    ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
    ruleset.deathLimit = DEATH_LIMIT;
    caMap.SetRuleSet(ruleset);
    caMap.Generate_CA_MAP(sf::Vector2u(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
}

void SetupCurrentMap(Map *map)
{
    mapdata.setMap(map);
    CreateRandomCreatures(mapdata);
    GenerateRandomItems(mapdata,10);
    mapdata.PlaceCreaturesOnMap();
    mapdata.PlaceItemsOnMap();
    
}

void SetupGameData(Map *map)
{
    InitializeMaps();
    SetupCurrentMap(map);
    GenerateTestEquipment();
    
    player.loadCreatureTile("deep_elf_blademaster.png",32,32);
    HumanoidBody humanoidBody;
    player.setBody(humanoidBody.clone());
    player.setPosition(5, 5);
    player.setStrength(3);
    player.setAgility(3);
    
    
}

void DrawEverything(MapData _mapdata)
{
    mapdata.window->draw(*mapdata.map);
    mapdata.window->draw(player.creatureTile);
    elapsed = globalClock.getElapsedTime();
    //Only move creatures randomly every two seconds..testing
    if(elapsed.asMilliseconds() >= 1000)
    {
        MoveAllCreatures();
        globalClock.restart();
    }
    _mapdata.RemoveDeadCreature();
    _mapdata.DrawCreaturesOnMap();
    _mapdata.DrawItemsOnMap();
    
    
    mapdata.window->display();
    mapdata.window->clear();
    
    
    
    
}
