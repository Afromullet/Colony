#include <SFML/Graphics.hpp>


#include <iostream>
#include <Vector>
#include <cstdlib>

#include "Universal_Includes.h"
#include "Equipment_Includes.h"

#include "Globals.hpp"
#include "EnumTypes.hpp"








#include "CAMap.hpp"
#include "TileReader.hpp"
#include "MovementHandler.hpp"



#include "BaseCreature.hpp"


#include "ItemGenerator.hpp"
#include "MapData.hpp"
#include "TestDataGenerator.hpp"
#include "PlayerControls.hpp"




#include "BodyGraph.hpp"
#include <string>

#include "BodyGraphGetters.hpp"
#include "AttackHandler.hpp"
#include "DataReaders.hpp"
#include "DataStorage.hpp"
#include "Wound.hpp"

//-----Unit testing Part------






//--Unit Testing end


void GameLoop3();

void MoveAllCreatures();
void InitializeMaps();
void SetupCurrentMap();
void SetupGameData(Map *map);
void DrawEverything(MapData _mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;












using namespace boost;


std::vector<sf::Text> testStrings;
 sf::Text tempText;





int main()
{
    
    
   // add_edge(headVertex,chestVertex,humanoidBodyGraph);
  
    
  
srand(time(NULL));
   
    

    
    ParseTileFile();
    BasicTileRuleset();
    window.setKeyRepeatEnabled(false);
    mapdata.SetWindow(&window);
    SetupGameData(&caMap);
    
   
  

 
    


    



  



    CreatureBody bReader;
    
    BaseCreature target;
    
    //bReader.load("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/TestFile.xml");
    player.body.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
    player.body.readBodyTokenList();
    player.body.GenerateVertices();
    player.body.GenerateEdges();
    player.body.GenerateOrganVertices();
    player.body.GenerateOrganEdges();
    player.body.InitializeBodypartEquipment();
    
    //bReader.load("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/TestFile.xml");
    target.body.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
    target.body.readBodyTokenList();
    target.body.GenerateVertices();
    target.body.GenerateEdges();
    target.body.GenerateOrganVertices();
    target.body.GenerateOrganEdges();
    target.body.InitializeBodypartEquipment();
    
    
    
    Armor testArmor;
    testArmor.setItemName("TestArmor1");
    testArmor.sections.push_back("upperbodysection");
    testArmor.sections.push_back("armsection");
    
    
    Weapon testWeapon;
    testWeapon.enWeaponSize = enLargeWeapon;
    testWeapon.sEquipmentName = "TestWeapon";
    testWeapon.isRanged = true;
    testWeapon.setRange(5);
    testWeapon.setDamage(10);
    
    player.setPosition(10, 10);
    target.setPosition(11, 11);
 
    
    player.body.EquipArmor(&testArmor);
    player.body.EquipWeapon(&testWeapon);
    printBodyGraphVertices(player.body.anatomyGraph);

    Material iron;
    iron.setDeformationStrenghts(10,10,10,10,10);
    iron.setFractureStrength(10,10,10,10,10);
    iron.setMaterialName("Iron");
    

    
    iron.setFractureStrength(10,10,10,10,10);
    iron.setDensity(10);

    
    iron.clearAppliedMaterialEffects();
    std::vector<AppliedForceEffect>& effects = iron.getAppliedForceEffects();
    
    for(int i =0; i < effects.size(); i++)
    {
        std::cout << effects.at(i);
    }
    
    
    iron.clearAppliedMaterialEffects();
    iron.PerformMaterialCalculations(1000,2,enImpact,enSlash);
    
    
   effects = iron.getAppliedForceEffects();
    
    for(int i =0; i < effects.size(); i++)
    {
        std::cout << effects.at(i);
    }
    
    iron.clearAppliedMaterialEffects();
    iron.PerformMaterialCalculations(100,2,enShear,enSlash);
    
    
    effects = iron.getAppliedForceEffects();
    
    for(int i =0; i < effects.size(); i++)
    {
        std::cout << effects.at(i);
    }
    
    iron.clearAppliedMaterialEffects();
    iron.PerformMaterialCalculations(5,2,enShear,enSlash);
   
    effects = iron.getAppliedForceEffects();
    
    for(int i =0; i < effects.size(); i++)
    {
        std::cout << effects.at(i);
    }
    
    
    AppliedForceEffect effect;
    effect.ratio = 100;
    effect.effect = enImpactFracEffect;
    effect.woundSeverity = enMinorWound;
    effect.attackType = enSlash;
    
    WoundCalculations woundCalcs(0);
    woundCalcs.ApplyImpactWound(effect,player.body.anatomyGraph);
    
    effect.woundSeverity = enModerateWound;
    woundCalcs.ApplyImpactWound(effect,player.body.anatomyGraph);
    
    effect.woundSeverity = enMajorWound;
    woundCalcs.ApplyImpactWound(effect,player.body.anatomyGraph);


    
    
    
 
   
    
    
 
  
  
    
    Map mapstuff = *mapdata.map;
    
    int fontSize = 25;
    tempText.setFont(defaultFont);
    tempText.setCharacterSize(fontSize);
    tempText.setColor(sf::Color::Red);
    //tempText.setString("0");
  
   // tempText.setPosition(100, 100);
    testStrings.push_back(tempText);
    
    
    for(int i=0; i < mapstuff.GetWidth(); i++)
    {
        for(int j = 0; j < mapstuff.GetHeight(); j++)
        {
            
            
               tempText.setString(std::to_string(mapstuff.Map2D[i][j].index));
               tempText.setPosition(i*fontSize*2, j*fontSize*2);
                testStrings.push_back(tempText);
            
            
        }
    }
    


    
     
    
    
    

    

   

    GameLoop3();
    
   
    sf::Font fnt;
    

    
    
   
    

    
    return 0;
}











    












sf::Clock globalClock;


sf::VertexArray v(sf::Lines,11);

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = dx+dy, e2; /* error value e_xy */
    
    int i = 0;
    for(;;){  /* loop */
        std::cout << x0 <<  "," << y0 << "\n";
        v[i].position = sf::Vector2f(x0+100,y0+100);
        v[i].color = sf::Color::Red;
        if (x0==x1 && y0==y1) break;
        e2 = 2*err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
        i++;
    }
}


void GameLoop3()
{
    
    

    drawLine(0,0,10,10);
   

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        
        while(!PlayerActionTaken)
        {
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    errorLog.closeFile();
                }
            
                if(event.type == sf::Event::KeyPressed)
                {
                    HandlePlayerInput(event,mapdata,player);
              
                }
            
            }
        }
        
  
  
     

        
        
        
    
      
        player.vision.UpdateVision(*mapdata.map,player.getPosition());
         std::vector<BaseCreature> visible =  player.vision.getVisibleCreatures(*mapdata.map);
        player.vision.getVisibleItems(*mapdata.map);
     
      
        DrawEverything(mapdata);
        
     
        
        PlayerActionTaken = false;

        
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
    
    
    MainMap.BasicRandom2DMap(sf::Vector2i(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE), MAP_WIDTH, MAP_HEIGHT);
   
    //Just a random ruleset]]
    
    
    
    CELL_CHANCETOSTARTALIVE = 0.55f;
    NUMBER_OF_STEPS = 1;
    BIRTH_LIMIT = 5;
    DEATH_LIMIT = 2;
    
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = BIRTH_LIMIT;
    ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
    ruleset.deathLimit = DEATH_LIMIT;
    ruleset.numberOfSteps = NUMBER_OF_STEPS;
    caMap.SetRuleSet(ruleset);
    caMap.Generate_CA_MAP(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
  // caMap.CaveTunnelMap()
}

void SetupCurrentMap(Map *map)
{
    mapdata.setMap(map);

   CreateTargetCreatures(mapdata);
    
    GenerateRandomItems(mapdata,30);
    mapdata.PlaceCreaturesOnMap();
    mapdata.PlaceItemsOnMap();
    
}

void SetupGameData(Map *map)
{
    
    ReadMaterialFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/MaterialFiles/BasicMaterials.xml");
    printMaterials();
    
    
    InitializeGlobalBodyParts();
    InitializeCreatureTypes();
    InitializeGlobals();
    InitializeMaps();
    
    
    SetupCurrentMap(map);
    GenerateTestEquipment();
    
    

    


 
    
    //Place player on first open tile

    //player.setPosition(5, 5);
    player.setStrength(3);
    player.setAgility(3);
    InitializeInventoryWindow();
    
  
    std::list<BaseCreature>::iterator creatureIt;
    
    
    bool positionFound = false;
    int randXPos,randYPos;
    
    player.loadCreatureTile("daeva.png", 32, 32);
    player.setPosition(0, 10);

    

    
}

void DrawEverything(MapData _mapdata)
{
    
    
    mapdata.window->draw(*mapdata.map);
    mapdata.window->draw(player.creatureTile);
    elapsed = globalClock.getElapsedTime();
    //Only move creatures randomly every  second..testing
    
    if(elapsed.asMilliseconds() >= 1000)
    {
      
   

        globalClock.restart();
    }
    
    
      MoveAllCreatures();
    
    
    sf::VertexArray bigSquare = mapdata.map->m_vertices;
    
    
    
    bigSquare.setPrimitiveType(sf::Quads);
    bigSquare.resize(4);
    
    
    
    
    _mapdata.RemoveDeadCreature();
    _mapdata.DrawCreaturesOnMap();
    _mapdata.DrawItemsOnMap();
    

    
    
    
    for(int i = 0; i < playerWindowCommands.dataWindows.size(); i++)
    {
        
        mapdata.window->draw(playerWindowCommands.dataWindows.at(i));
    }
    
    mapdata.window->draw(testStrings.at(0));
    mapdata.window->display();
    mapdata.window->clear();
    
    
    
    
    
}

