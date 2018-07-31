#include "imgui.h"
#include "imgui-SFML.h"
#include <TGUI/TGUI.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "StaticVarInitializer.hpp"
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
#include "FastNoise.h"
#include "NoiseMap.hpp"
#include "Plant.hpp"
#include "Tree.hpp"

#include <iostream>
#include <string>
#include <vector>

#include <regex>

#include <boost/regex.hpp>
#include "GenericReaders.hpp"
#include "HistoryTokenReader.hpp"
#include "HistoryGenerator.hpp"
#include "ItemManager.hpp"
#include <memory>
#include "PlayerWindows.hpp"
#include "ImguiDebug.hpp"



void GameLoop3();

void MoveAllCreatures();
void InitializeMaps();
void SetupCurrentMap();
void SetupGameData(Map *map);
void DrawEverything(MapData &_mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;












using namespace boost;


std::vector<sf::Text> testStrings;
 sf::Text tempText;





NoiseMap noiseMap;




void InitializeWindowData();
void InitialzeDataFromFiles();
void InitializeDebugData();
void InitializeGlobalData();
void InitializePlayerData();
void InitializeAllData();
void InitializeTestingData();


int main()
{
    
    srand(time(NULL));
    
    InitializeAllData();
    
   
    
     
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
    
    

    
   

    
    // run the main loop
  char windowTitle[255] = "Colony";
    window.setTitle(windowTitle);
    sf::Clock deltaClock;
    
    
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            
            
            if(event.type == sf::Event::Closed)
            {
                window.close();
                //errorLog.closeFile();
            }
                
            if(event.type == sf::Event::KeyPressed)
            {
                HandlePlayerInput(event,mapdata,player);
                    
                if(event.key.code == sf::Keyboard::X)
                {
                    noiseMap.Generate_NoiseMap(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT);
                        
                }
                    
            }
            
           playerGUI.HandleWindowEvent(event,gui);
            //inventoryWindow.HandleEvent(event,gui,player.inventory);
            //inventoryWindow.UpdateInventory(player.inventory);
            
           gui.handleEvent(event); // Pass the event to the widgets

            
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::SFML::Render(window);
        DrawEverything(mapdata);
        PlayerActionTaken = false;

        }
    
    

    
    
    ImGui::SFML::Shutdown();
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






void DrawEverything(MapData &_mapdata)
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
    
    _mapdata.RemoveDeadCreature();
    _mapdata.DrawCreaturesOnMap();
    _mapdata.DrawItemsOnMap();
    
    ImGui::SFML::Render(window);
    gui.draw();
    mapdata.window->display();
    mapdata.window->clear();
}

void SetupGameData(Map *map)
{
    
    
    
    
    
    InitializeGlobals();
    InitializeMaps();
    
    
    mapdata.setMap(map);
    int i;
    
    
    
    
    
}

void InitializeAllData()
{
    InitializeWindowData();
    InitialzeDataFromFiles();
    InitializeDebugData();
    InitializeGlobalData();
    InitializePlayerData();
    
    SetupGameData(&noiseMap);
    SetupGUI(gui);
    InitializeTestingData();
}

void InitialzeDataFromFiles()
{
    ParseTileFile();
    BasicTileRuleset();
    
    
    ReadMaterialFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/MaterialFiles/BasicMaterials.xml");
    ReadBiomeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/BiomeFiles/BiomeData.xml");
    ReadPlantFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/PlantFiles/BasicPlants.xml");
    ReadOreFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/OreFiles/BasicOre.xml");
    ReadTreeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/TreeFiles/BasicTrees.xml");
    
    InitializePlantMaterials();
    InitializeOreMaterials();
    InitializeTreeMaterials();
    
    
    ReadInitialHistoryTokens();
    ReadFirstRewriteRules();
    
}

void InitializeDebugData()
{
    InitializeCreatureTypes();
}

void InitializeGlobalData()
{
    
}

void InitializeMaps()
{
    
    /*
     
     MainMap.BasicRandom2DMap(sf::Vector2i(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE), MAP_WIDTH, MAP_HEIGHT);
     CELL_CHANCETOSTARTALIVE = 0.55f;
     NUMBER_OF_STEPS = 1;
     BIRTH_LIMIT = 5;
     DEATH_LIMIT = 2;
     ruleset.aliveTileID = FOREST_GRASS;
     ruleset.deadTileID = TREE_3_TILE;
     ruleset.birthLimit = BIRTH_LIMIT;
     ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
     ruleset.deathLimit = DEATH_LIMIT;
     ruleset.numberOfSteps = NUMBER_OF_STEPS;
     caMap.SetRuleSet(ruleset);
     caMap.Generate_CA_MAP(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
     */
    
    noiseMap.Generate_NoiseMap(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT);
    // caMap.CaveTunnelMap()
}

void InitializePlayerData()
{
    player.loadCreatureTile("daeva.png", 32, 32);
    player.setPosition(0, 10);
    
    //bReader.load("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/TestFile.xml");
    player.body.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
    player.body.readBodyTokenList();
    player.body.GenerateVertices();
    player.body.GenerateEdges();
    player.body.GenerateOrganVertices();
    player.body.GenerateOrganEdges();
    player.body.InitializeBodypartEquipment();
      player.setPosition(10, 10);
}


void InitializeWindowData()
{
    window.setKeyRepeatEnabled(false);
    mapdata.SetWindow(&window);
}

void InitializeTestingData()
{
    Armor testArmor;
    testArmor.setItemName("TestArmor1");
    testArmor.addSection("upperbodysection");
    testArmor.addSection("armsection");
    testArmor.setMovementModifier(5);
    testArmor.setDescriptiveText("Test Armor 1 Text");
    
    
    Weapon testWeapon;
    testWeapon.setWeaponSize(enLargeWeapon);
    //testWeapon.sEquipmentName = "TestWeapon";
    testWeapon.setItemName("TestWeapon");
    testWeapon.setIsRanged(true);
    testWeapon.setRange(5);
    testWeapon.setDamage(10);
    testWeapon.setDescriptiveText("test Weapon text");
    
    
    Armor testArmor5,testArmor6,testArmor7,testArmor8;
    Weapon testWeapon5,testWeapon6,testWeapon7;
    
    
    testArmor5.setItemName("Test Armor 5");
    testArmor5.addSection("headsection");
    testArmor5.addSection("upperbodysection");
    //  testArmor5.addSection("upperbodysection");
    //  testArmor5.addSection("headsection");
    testArmor5.setMovementModifier(5);
    
    testArmor6.setItemName("Test Armor 6");
    testArmor6.addSection("headsection");
    testArmor6.setMovementModifier(0);
    
    testArmor7.setItemName("Test Armor 7");
    testArmor7.addSection("legsection");
    testArmor7.setMovementModifier(7);
    
    testArmor8.setItemName("Test Armor 8");
    testArmor8.addSection("headsection");
    testArmor8.setMovementModifier(7);
    
    testWeapon5.setItemName("Test Weapon 5");
    testWeapon5.setWeaponSize(enMediumWeapon);
    testWeapon5.addSection("handsection");
    testWeapon5.setIsRanged(false);
    testWeapon5.setRange(5);
    testWeapon5.setDamage(5);
    testWeapon5.setContactArea(7);
    
    testWeapon6.setItemName("Test Weapon 6");
    testWeapon6.setWeaponSize(enLargeWeapon);
    testWeapon6.setIsRanged(true);
    testWeapon6.setRange(6);
    testWeapon6.setDamage(6);
    testWeapon6.setContactArea(9);
    
    testWeapon7.setItemName("Test WEapon 7");
    testWeapon7.setWeaponSize(enSmallWeapon);
    
    testWeapon7.setIsRanged(true);
    testWeapon7.setRange(7);
    testWeapon7.setDamage(7);
    testWeapon7.setContactArea(11);
    
    testArmor5.setDescriptiveText("Test Armor 5 Text");
    testArmor6.setDescriptiveText("Test Armor 6 Text");
    testArmor7.setDescriptiveText("Test Armor 7 Text");
    testArmor8.setDescriptiveText("Test Armor 8 Text");
    
    testWeapon5.setDescriptiveText("Test Weapon 5 Text");
    testWeapon6.setDescriptiveText("Test Weapon 6 Text");
    testWeapon7.setDescriptiveText("Test Weapon 7 Text");
    
    player.AddArmorToInventory(testArmor5);
    player.AddArmorToInventory(testArmor6);
    player.AddArmorToInventory(testArmor7);
    player.AddArmorToInventory(testArmor8);
    
    player.AddWeaponToInventory(testWeapon5);
    player.AddWeaponToInventory(testWeapon6);
    
    player.AddWeaponToInventory((testWeapon7));
    
    
    
    
    
    Armor testArmor2;
    testArmor2.setItemName("TestArmor1");
    testArmor2.addSection("upperbodysection");
    testArmor2.addSection("armsection");
    testArmor2.setDescriptiveText("Descriptive text");
    


}


