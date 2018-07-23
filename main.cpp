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
void DrawEverything(MapData _mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;












using namespace boost;


std::vector<sf::Text> testStrings;
 sf::Text tempText;





NoiseMap noiseMap;



void PointerTest()
{
    
    
    
}


int main()
{
    
    
    
    

    

   

srand(time(NULL));
   
    

    
    ParseTileFile();
    BasicTileRuleset();
    window.setKeyRepeatEnabled(false);
    mapdata.SetWindow(&window);
   //SetupGameData(&caMap);
   SetupGameData(&noiseMap);
   SetupGUI(gui);
    for(int i = 0; i < noiseMap.GetWidth(); i++)
    {
        for(int j =0; j < noiseMap.GetHeight(); j++)
        {
            //std::cout << "\n New Elevation " << noiseMap.Map2D[i][j].elevation;
        }
    }
    
   
  
    
    


    



  



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
    
    
    Vision v2;
    Vision v3;
    v2 =  v3;
    
    
    
    std::list<Item*> creatureItems;
    std::list<Item*> creatureItems2;
    creatureItems = creatureItems2;
    CreatureBody bod(player.body);
    for(int i = 0; i < num_vertices(bod.anatomyGraph); i++)
    {
        std::cout << "\n Name: " << bod.anatomyGraph[i].getBodyPartName();
    }
    
    
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
    
    player.setPosition(10, 10);
    target.setPosition(11, 11);
 

    
    
   // player.body.EquipArmor(&testArmor);
  //  player.body.EquipWeapon(&testWeapon);
    //printBodyGraphVertices(target.body.anatomyGraph);
    
    
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
    testArmor6.setMovementModifier(6);
    
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
    
    
    

    
    //ItemManager newInventory(new ItemManager());
    
 
    //player.AddArmorToInventory(testArmor5);
  //  player.AddArmorToInventory(testArmor6);
    
 //  player.AddWeaponToInventory(testWeapon5);
    
    
    
   // Armor testArmor5,testArmor6,testArmor7,testArmor8;
   // Weapon testWeapon5,testWeapon6,testWeapon7;

    
    testArmor5.setDescriptiveText("Test Armor 5 Text");
    testArmor6.setDescriptiveText("Test Armor 6 Text");
    testArmor7.setDescriptiveText("Test Armor 7 Text");
    testArmor8.setDescriptiveText("Test Armor 8 Text");
    
    testWeapon5.setDescriptiveText("Test Weapon 5 Text");
    testWeapon6.setDescriptiveText("Test Weapon 6 Text");
    testWeapon7.setDescriptiveText("Test Weapon 7 Text");
    
    
   // player.AddWeaponToInventory(testWeapon5);
    //player.AddWeaponToInventory(testWeapon6);
    //player.AddWeaponToInventory((testWeapon7));
    
    
    

    player.AddArmorToInventory(testArmor5);
    player.AddArmorToInventory(testArmor6);
    player.AddArmorToInventory(testArmor7);
    player.AddArmorToInventory(testArmor8);
   
   player.AddWeaponToInventory(testWeapon5);
    player.AddWeaponToInventory(testWeapon6);

    player.AddWeaponToInventory((testWeapon7));

     
    

   // GetInventoryWindowData(player.inventory);
    
    
    
  
    
  
    for(int i=0; i < 10; i++)
    {
        player.inventory.showItemStats(i);
    }
    
    
    player.inventory.showItemStats(0);
  //  player.EquipItem(0);
    
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    

    
    for(int i=0; i < 10; i++)
    {
        player.inventory.showItemStats(i);
        std::cout << "\n";
    }
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    
    
    
    
    player.inventory.showItemStats(0);
  //  player.EquipItem(0);
    
    for(int i=0; i < 10; i++)
    {
        player.inventory.showItemStats(i);
    }

    
  
    
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
         std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    
    
    player.inventory.showItemStats(0);
   // player.EquipItem(0);
    
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    
    
    
    for(int i=0; i < 10; i++)
    {
        player.inventory.showItemStats(i);
    }

    
    
    player.inventory.showItemStats(0);
    //player.EquipItem(0);
    
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    
    
    
    for(int i=0; i < 10; i++)
    {
        player.inventory.showItemStats(i);
    }

    
    //itemManager.showItemStats(0);
    
   
    
    AttackStats stats;
    

    std::cout << "\n Num Vertices " << num_vertices(target.body.anatomyGraph);


    /*
         stats.enAttackForceType = enImpact;
         stats.force = 100;
         stats.contactArea = 5;
        stats.attackType = enBlunt;
         Single_Attack_Melee(stats,target);
    
         target.body.PrintWounds();
   
         stats.enAttackForceType = enImpact;
         stats.force = 100;
         stats.contactArea = 5;
         stats.attackType = enBlunt;
         Single_Attack_Melee(stats,target);
     
         target.body.PrintWounds();
     */
   


        
    
         stats.enAttackForceType = enImpact;
         stats.force = 100;
         stats.contactArea = 1;
         stats.attackType = enBlunt;
         Single_Attack_Melee(stats,player);
     
         target.body.PrintWounds();

          stats.enAttackForceType = enShear;
          stats.force = 100;
          stats.contactArea = 1;
          stats.attackType = enSlash;
          Single_Attack_Melee(stats,player);
    
    target.body.PrintWounds();
     
  
     
     
        //This breaks
         stats.enAttackForceType = enShear;
         stats.force = 100;
         stats.contactArea = 1;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,player);
     

  
     
         stats.enAttackForceType = enShear;
         stats.force = 100;
         stats.contactArea = 5;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,player);
     
         target.body.PrintWounds();
     
     
         stats.enAttackForceType = enShear;
         stats.force = 1000;
         stats.contactArea = 1;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,player);
         
         
     
    
         target.body.PrintWounds();
         
          target.body.PrintWounds();
        
               
      

    Armor testArmor2;
    testArmor2.setItemName("TestArmor1");
    testArmor2.addSection("upperbodysection");
    testArmor2.addSection("armsection");
    testArmor2.setDescriptiveText("Descriptive text");

    std::vector<int> verts;

   verts = getConnectedVertices(0,player.body.anatomyGraph);
    
    for(int i = 0; i < verts.size(); i++)
    {
        std::cout << "\n BP " << player.body.anatomyGraph[verts.at(i)].getBodyPartName();
    }
    std::cout << "\n";
   verts =  getConnectedVertices(5,player.body.anatomyGraph);

    for(int i = 0; i < verts.size(); i++)
    {
        std::cout << "\n BP " << player.body.anatomyGraph[verts.at(i)].getBodyPartName();
    }
    
   // mapdata.AddItemToMap(ui);
    //std::cout << mapdata.items.at(0)->getItemName();
    
    
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
            
            
               tempText.setString(std::to_string(mapstuff.Map2D[i][j].getIndex()));
               tempText.setPosition(i*fontSize*2, j*fontSize*2);
               // testStrings.push_back(tempText);
            
            
        }
    }
    



    //SetupInventoryWindow(player.inventory);
   

    GameLoop3();
    
   
    sf::Font fnt;
    
    //player.ReleaseInventoryMemory();

    
    
   
    

    
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
  char windowTitle[255] = "ImGui + SFML = <3";
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
              //  HandlePlayerInput(event,mapdata,player);
                    
                if(event.key.code == sf::Keyboard::X)
                {
                    noiseMap.Generate_NoiseMap(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT);
                        
                }
                    
            }
            
           // playerGUI.HandleWindowEvent(event,gui);
            //inventoryWindow.HandleEvent(event,gui,player.inventory);
            //inventoryWindow.UpdateInventory(player.inventory);
            
           gui.handleEvent(event); // Pass the event to the widgets

            
        }
        
     
        
            
            
        ImGui::SFML::Update(window, deltaClock.restart());
        
       
    
 
        
        BPCreatorInput();
        BPExaminer();
        BPConnector();
        BodyGraphViewer(player.body);
        

        ImGui::SFML::Render(window);
        
        
        
    
        
        
     
      
        
        DrawEverything(mapdata);
        
        
       // window.clear(bgColor); // fill background with color
       
        //window.display();
        
        
        
     
        
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

void InitializeMaps()
{
    
    
    MainMap.BasicRandom2DMap(sf::Vector2i(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE), MAP_WIDTH, MAP_HEIGHT);
   
    //Just a random ruleset]]
    
    
    
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
    noiseMap.Generate_NoiseMap(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT);
  // caMap.CaveTunnelMap()
}

void SetupCurrentMap(Map *map)
{
    mapdata.setMap(map);

   CreateTargetCreatures(mapdata);
    
   // GenerateRandomItems(mapdata,30);
    mapdata.PlaceCreaturesOnMap();
    mapdata.PlaceItemsOnMap();
    
}

void SetupGameData(Map *map)
{
    
    ReadMaterialFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/MaterialFiles/BasicMaterials.xml");
    ReadBiomeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/BiomeFiles/BiomeData.xml");
    ReadPlantFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/PlantFiles/BasicPlants.xml");
    ReadOreFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/OreFiles/BasicOre.xml");
    ReadTreeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Data/DataFiles/TreeFiles/BasicTrees.xml");
    printMaterials();
    printBiomes();
    
    if(materials.at(1) == materials.at(1))
    {
        std::cout << "\n0 and 1 equals";
    }
    
    if(materials.at(0) == materials.at(0))
    {
        std::cout << "\n0 and 0 equals";
    }
    
    
    if(materials.at(3) == materials.at(3))
    {
        std::cout << "\n3 and 3 equals";
    }
    
    if(materials.at(2) != materials.at(3))
    {
        std::cout << "\n2 and 3 not equals";
    }
    
    
    if(materials.at(1) != materials.at(2))
    {
        std::cout << "\n2 and 1 not equals";
    }
    
    InitializePlantMaterials();
    InitializeOreMaterials();
    InitializeTreeMaterials();
    
    InitializeGlobalBodyParts();
    InitializeCreatureTypes();
    InitializeGlobals();
    InitializeMaps();
    
    
    ReadInitialHistoryTokens();
    ReadFirstRewriteRules();
    
    /*
    for(int i=0; i < numOfStartRewriteRules; i++)
    {
        std::cout << "\n Starting new Rule";
        std::cout << startRewriteRules[i].initialRule << std::endl;
        
        std::cout << "Starting rewrite rules " << "\n";
        for(int j = 0; j < startRewriteRules[i].vecRewrittenRule.size(); j++)
        {
            std::cout << startRewriteRules[i].vecRewrittenRule.at(j) << ",";
        }
        std::cout << "\n\n";
    }
     
    
    
    for(int i=0; i < numOfGrammarRewriteRules; i++)
    {
        std::cout << "\n Starting new Rule";
        std::cout << arGrammarRewriteRules[i].initialRule << std::endl;
        
        std::cout << "Starting rewrite rules " << "\n";
        for(int j = 0; j < arGrammarRewriteRules[i].vecRewrittenRule.size(); j++)
        {
            std::cout << arGrammarRewriteRules[i].vecRewrittenRule.at(j) << ",";
        }
        std::cout << "\n\n";
    }
     */
    
    
    RewriteRules newRules;
    
    /*
    while(1)
    {
        newRules = SelectStartingHistoryRule();
        std::cout << "\n Starting Rule " << newRules.initialRule;
        ProcessRewrittenRule(newRules);
    }
     */
    
    
    
    
    SetupCurrentMap(map);
    GenerateTestEquipment();
    

    


 
    
    //Place player on first open tile

    //player.setPosition(5, 5);
    player.setStrength(3);
    player.setAgility(3);
   
    
  
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
    
    

    
    
    
    
    _mapdata.RemoveDeadCreature();
    _mapdata.DrawCreaturesOnMap();
    _mapdata.DrawItemsOnMap();
    
   ImGui::SFML::Render(window);
    
    //GetInventoryWindowData(player.inventory);
    
    gui.draw();

    
    
    
   
    

    mapdata.window->display();
    mapdata.window->clear();
    
    
    
    
    
}


/*
 while(!PlayerActionTaken)
 {
 
 
 
 
 
 while (window.pollEvent(event))
 {
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
 
 }
 
 
 }
 */


//  player.getVision().UpdateVision(*mapdata.map,player.getPosition());
//  std::vector<BaseCreature> visible =  player.getVision().getVisibleCreatures(*mapdata.map);
// player.getVision().getVisibleItems(*mapdata.map);


