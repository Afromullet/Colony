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

#include "BaseCreature.hpp"

#include "CreatureHandler.hpp"
#include "ItemGenerator.hpp"
#include "MapData.hpp"
#include "TestDataGenerator.hpp"
#include "PlayerControls.hpp"

#include <boost/graph/adjacency_list.hpp>
#include "MapEffect.hpp"

#include "DataWindow.hpp"

void GameLoop3();

void MoveAllCreatures();
void InitializeMaps();
void SetupCurrentMap();
void SetupGameData(Map *map);
void DrawEverything(MapData _mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;






typedef boost::property<int, int> noProperty;
typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::directedS, BodyPart,noProperty> BodyGraph;
typedef boost::graph_traits<BodyGraph>::vertex_descriptor Vertex;
typedef boost::graph_traits<BodyGraph>::edge_descriptor CustomEdge;
typedef std::pair<Vertex,Vertex> Edge;





BodyGraph humanoidBodyGraph;
//Can just be a list of max number of vertices for purposes of generalizing
Vertex headVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex chestVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex leftArmVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex rightArmVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex leftLegVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex rightLegVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex leftHandVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex rightHandVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex leftFootVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);
Vertex rightfootVertex = boost::add_vertex(headBodyPart,humanoidBodyGraph);






Edge edge_array[] =
{
    Edge(headVertex,chestVertex),
    
    Edge(chestVertex,leftLegVertex),
    Edge(chestVertex,rightLegVertex),
    Edge(chestVertex,leftArmVertex),
    Edge(chestVertex,rightArmVertex),
    
    
    Edge(rightLegVertex,rightfootVertex),
    Edge(leftLegVertex,leftFootVertex),
    
    Edge(rightArmVertex,rightHandVertex),
    Edge(leftArmVertex,leftHandVertex)
};




const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);

const int num_of_vertices = 10; //For humanoid body
const int num_of_edges = 8;

using namespace boost;

int main()
{
    
    
   // add_edge(headVertex,chestVertex,humanoidBodyGraph);
  
    
  

    MapEffect ef1;
    MapEffect ef2;
    MapEffect ef3;
    
    ef1.setID(1);
    ef2.setID(2);
    ef3.setID(1);
    

    
    ParseTileFile();
    BasicTileRuleset();
    window.setKeyRepeatEnabled(false);
    mapdata.SetWindow(&window);
    SetupGameData(&caMap);
    
    
    
    
    


    /*
     //textComponents.clear();
     sf::Text text;
     text.setFont(font);
     
     
     text.setString("abcdefg");
     text.setCharacterSize(24);
     text.setColor(sf::Color::Red);
     textComponents.push_back(text);
     
     text.setString("vyydasdr");
     text.setPosition(100, 100);
     text.setCharacterSize(24);
     text.setColor(sf::Color::Red);
     textComponents.push_back(text);

     */
    
    
    
    
    GameLoop3();
    
    return 0;
}











    












sf::Clock globalClock;




void GameLoop3()
{
    
    

   

    //player.EquipItemFromInventory(5);
    
    /*
    std::cout << "Adaj name " << tHeadArmor.getItemName();
    player.Equip(&tHeadArmor);
    player.Equip(&tChestArmor);
    player.Equip(&tLegArmor);
    player.Equip(&tHandArmor);
    player.Equip(&tFootArmor);
     */
    player.Equip(&FIST_WEAPON);
    
   // std::vector<sf::Vector2i> tempSquare = mapdata.map->getSquare(sf::Vector2i(5,1), 2);
   
    
    
    
    

    
 
    
    
    
    




    

   // player.Equip(&tHeadArmor);
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                errorLog.closeFile();
                
            }
            
           HandlePlayerInput(event,mapdata,player);
            
            
        }

        DrawEverything(mapdata);
        window.clear();
    
        
     
       // window.display();
        

        
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
    squareMap.CreateMap(sf::Vector2i(DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE),MAP_WIDTH, MAP_HEIGHT, 0);
    //Just a random ruleset
    CELL_CHANCETOSTARTALIVE = 0.65f;
    NUMBER_OF_STEPS = 5;
    BIRTH_LIMIT = 3;
    DEATH_LIMIT = 4;
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = BIRTH_LIMIT;
    ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
    ruleset.deathLimit = DEATH_LIMIT;
    caMap.SetRuleSet(ruleset);
    caMap.Generate_CA_MAP(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
}

void SetupCurrentMap(Map *map)
{
    mapdata.setMap(map);
    CreateTargetCreatures(mapdata);
    GenerateRandomItems(mapdata,10);
    mapdata.PlaceCreaturesOnMap();
    mapdata.PlaceItemsOnMap();
    
}

void SetupGameData(Map *map)
{
    
    InitializeGlobals();
    InitializeMaps();
    SetupCurrentMap(map);
    GenerateTestEquipment();
    InitializeGlobalBodyParts();
    
    player.loadCreatureTile("daeva.png",32,32);

    player.setPosition(5, 5);
    player.setStrength(3);
    player.setAgility(3);
    InitializeInventoryWindow();
    
    std::list<BaseCreature>::iterator creatIt;
    for(creatIt = mapdata.creaturesOnMap.begin(); creatIt != mapdata.creaturesOnMap.end(); ++creatIt)
    {
        (*creatIt).addBodyPart(humanoidBodySchema);
        (*creatIt).CalculateAttackParameters();
        (*creatIt).CalculateTotalHealth();
        
    }
    
    
   
    
   
    
    player.addBodyPart(humanoidBodySchema);
    player.CalculateAttackParameters();
    player.CalculateTotalHealth();
    
    player.PrintEquipment();
    player.PrintEquipment();
    
    
}

void DrawEverything(MapData _mapdata)
{
    
    
    mapdata.window->draw(*mapdata.map);
    mapdata.window->draw(player.creatureTile);
    elapsed = globalClock.getElapsedTime();
    //Only move creatures randomly every two seconds..testing
    if(elapsed.asMilliseconds() >= 1000)
    {
        //MoveAllCreatures();
        globalClock.restart();
    }
    _mapdata.RemoveDeadCreature();
    _mapdata.DrawCreaturesOnMap();
    _mapdata.DrawItemsOnMap();
    

    
    
    
    for(int i = 0; i < playerWindowCommands.dataWindows.size(); i++)
    {
        
        mapdata.window->draw(playerWindowCommands.dataWindows.at(i));
    }
    

    
    
    mapdata.window->display();
    mapdata.window->clear();
    
    
    
    
    
}
