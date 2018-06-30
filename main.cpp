#include <SFML/Graphics.hpp>

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


std::unique_ptr<Item> newItemPointer;

void PointerTest()
{
    
    Armor tA;
    tA.setItemName("A");
    tA.setMovementModifier(311);
    std::unique_ptr<Item> newStuff(new Armor(tA));
    
    newItemPointer = std::move(newStuff);
    
    Armor *fas;
     fas = dynamic_cast<Armor*>(newItemPointer.get());
    
    //free(fas);
     std::cout << "\n " << fas->getItemName() << "," << fas->fGetMovementModifier();
    std::cout << "\n " << fas->getItemName() << "," << fas->fGetMovementModifier();
   // newItemPointer = std::move(newStuff);
    
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
    
    
    Weapon testWeapon;
    testWeapon.setWeaponSize(enLargeWeapon);
     //testWeapon.sEquipmentName = "TestWeapon";
    testWeapon.setItemName("TestWeapon");
    testWeapon.setIsRanged(true); 
    testWeapon.setRange(5);
    testWeapon.setDamage(10);
    
    player.setPosition(10, 10);
    target.setPosition(11, 11);
 

    
    
    player.body.EquipArmor(&testArmor);
    player.body.EquipWeapon(&testWeapon);
    //printBodyGraphVertices(target.body.anatomyGraph);
    
    std::cout << "\n\n\n";
    for(int i =0; i < num_vertices(player.body.anatomyGraph); i++)
    {
        std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getArmorRef().getItemName() << "\n";
        
         std::cout << player.body.anatomyGraph[i].getBodyPartName() << "," << player.body.anatomyGraph[i].getWeaponRef().getItemName() << "\n";
    }
    
   
    
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
         Single_Attack_Melee(stats,target);
     
         target.body.PrintWounds();

          stats.enAttackForceType = enShear;
          stats.force = 100;
          stats.contactArea = 1;
          stats.attackType = enSlash;
          Single_Attack_Melee(stats,target);
    
    target.body.PrintWounds();
     
  
     
     
        //This breaks
         stats.enAttackForceType = enShear;
         stats.force = 100;
         stats.contactArea = 1;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,target);
     

  
     
         stats.enAttackForceType = enShear;
         stats.force = 100;
         stats.contactArea = 5;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,target);
     
         target.body.PrintWounds();
     
     
         stats.enAttackForceType = enShear;
         stats.force = 1000;
         stats.contactArea = 1;
         stats.attackType = enPierce;
         Single_Attack_Melee(stats,target);
         
         
     
         
         target.body.PrintWounds();
         
          target.body.PrintWounds();
        
               
      

    Armor testArmor2;
    testArmor2.setItemName("TestArmor1");
    testArmor2.addSection("upperbodysection");
    testArmor2.addSection("armsection");
    
    
    std::unique_ptr<Item> ui(&  testArmor2);
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
                testStrings.push_back(tempText);
            
            
        }
    }
    


    
     
    
    Item *testItem;
    testItem = testArmor.clone();
    
    
    Armor *arm = dynamic_cast<Armor*>(testItem);
    std::cout << "\n " << arm->getItemName() << "," << arm->fGetMovementModifier();
    

    std::unique_ptr<Armor> ar(new Armor(testArmor));
    std::unique_ptr<Item> it(new Armor(testArmor));
    //it = testArmor.clone();
    
    std::cout << "\n New Val " << ar->fGetMovementModifier();
    
    //arm = dynamic_cast<Armor*>(testItem);

    std::cout << "\n New 1 " << arm->getItemName() << "," << arm->fGetMovementModifier();

   // arm = dynamic_cast<Armor*>(newItemPointer);
    
    
    PointerTest();
    
    arm = dynamic_cast<Armor*>(newItemPointer.get());
      std::cout << "\n New 2 " << arm->getItemName() << "," << arm->fGetMovementModifier();

 
    
  
    
     std::cout << "\n New 3 " << arm->getItemName() << "," << arm->fGetMovementModifier();

    std::cout << "\n Tile ID " << EntityTile::getEntityTileIDCounter();
   

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
                    
                     if(event.key.code == sf::Keyboard::X)
                    {
                        noiseMap.Generate_NoiseMap(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT);
                        
                    }
              
                }
            
            }
        }
        
  
  
     

        
        
        
    
      
        player.getVision().UpdateVision(*mapdata.map,player.getPosition());
         std::vector<BaseCreature> visible =  player.getVision().getVisibleCreatures(*mapdata.map);
        player.getVision().getVisibleItems(*mapdata.map);
     
      
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
    
    GenerateRandomItems(mapdata,30);
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

