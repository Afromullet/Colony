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



#include "Vision.hpp"

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
#include <boost/graph/graphviz.hpp>
#include "MapEffect.hpp"

#include "DataWindow.hpp"
#include "Pathfinding.hpp"

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


std::vector<sf::Text> testStrings;
 sf::Text tempText;
int main()
{
    
    
   // add_edge(headVertex,chestVertex,humanoidBodyGraph);
  
    
  
srand(time(NULL));
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
   
    
    
    // create a typedef for the Graph type

    
    
    BaseCreature cr1;
    BaseCreature cr2;
    BaseCreature cr3;
    BaseCreature cr4;
    BaseCreature cr5;
    BaseCreature cr6;
    
    // create a typedef for the Graph type
    typedef adjacency_list<vecS, vecS, bidirectionalS,BaseCreature> CustomGraph;
    typedef graph_traits<CustomGraph>::vertex_descriptor CustomVertex;
    typedef boost::graph_traits<CustomGraph>::edge_descriptor CustomEdge;
    
    CustomGraph customGraph;
    
    CustomVertex v0 = boost::add_vertex(cr1, customGraph);
    CustomVertex v1 = boost::add_vertex(cr2, customGraph);
    CustomVertex v2 = boost::add_vertex(cr3, customGraph);
    CustomVertex v3 = boost::add_vertex(cr4, customGraph);
    
    // Make convenient labels for the vertices
    
    CustomEdge edge;
    bool edgeExists;
    
    //boost::tie(edge, edgeExists) = boost::edge(v0 , v1, customGraph);
   // boost::tie(edge, edgeExists) = boost::edge(v2 , v3, customGraph);
   // boost::tie(edge, edgeExists) = boost::edge(v0 , v3, customGraph);
    //if(!edgeExists)
        boost::add_edge(v0 , v1, customGraph);
    
    //if(!edgeExists)
        boost::add_edge(v2 , v3, customGraph);
    
 
    
    

    
    boost::write_graphviz(std::cout, customGraph);
    
    sf::Vector2i vec1;
    sf::Vector2i vec2;
    
 

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
   
    
    GridLocation start,end;
    start.x = 5;
    start.y = 3;
    
    end.x = 23;
    end.y = 10;
    
   std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(caMap,  start,  end);
    std::vector<GridLocation> path = recontructPath(start,end, cameFrom);
    // aStarSearch(caMap,  start,  end);
    std::vector<sf::Vector2i> walkPath;
    
    for(int i =0; i < path.size(); i++)
    {
        
        player.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
     
    }
    
    
    
   
    


    //GetBasicPath(sf::Vector2i(10,10),sf::Vector2i(15,10),*mapdata.map);
    
    






    

    for(int i =0; i < 10; i++)
    {
      // player.AddToPath(sf::Vector2i(i+1,i));
    }
   // player.Equip(&tHeadArmor);
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
        
     
       /*
        sf::VertexArray var;
        sf::Vertex v1;
        sf::Vertex v2;
        
        v1.position = sf::Vector2f(0,0);
        v2.position = sf::Vector2f(10,10);
        
        v1.color = sf::Color::Red;
        v2.color = sf::Color::Red;
        
        
        
        
        var.append(v1);
        var.append(v2);
        
        
        window.draw(var);
        */
        
  
     

        
        
        //window.clear();
        
    
      
        player.vision.UpdateVision(*mapdata.map,player.getPosition());
        player.vision.getVisibleCreatures(*mapdata.map);
        player.vision.getVisibleItems(*mapdata.map);

       
        
        DrawEverything(mapdata);
        
        std::cout << "\nPlayerActionTaken " << PlayerActionTaken;
        
        PlayerActionTaken = false;
       
     //   player.vision.UpdateVision(player.getPosition());
       // player.vision.getVisibleCreatures(*mapdata.map);
        
   
        
        
        
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
  // CreateTargetCreatures(mapdata);
    GenerateRandomItems(mapdata,10);
    mapdata.PlaceCreaturesOnMap();
    mapdata.PlaceItemsOnMap();
    
}

void SetupGameData(Map *map)
{
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
    
    std::list<BaseCreature>::iterator creatIt;
    for(creatIt = mapdata.creaturesOnMap.begin(); creatIt != mapdata.creaturesOnMap.end(); ++creatIt)
    {
        (*creatIt).addBodyPart(humanoidBodySchema);
        (*creatIt).CalculateAttackParameters();
        (*creatIt).CalculateTotalHealth();
        
    }
    
    std::list<BaseCreature>::iterator creatureIt;
    
    
    bool positionFound = false;
    int randXPos,randYPos;
    for(creatureIt=mapdata.creaturesOnMap.begin(); creatureIt != mapdata.creaturesOnMap.end();++creatureIt)
    {
        
        randXPos = rand() % mapdata.map->GetWidth();
        randYPos = rand() % mapdata.map->GetHeight();
       
        
        while (positionFound == false)
        {
            randXPos = rand() % mapdata.map->GetWidth();
            randYPos = rand() % mapdata.map->GetHeight();
            std::cout << "\n" << randXPos;
            
            if(mapdata.map->Map2D[randXPos][randYPos].getCanHoldCreature() == true)
            {
                (creatureIt)->setPosition(randXPos, randYPos);
            
               mapdata.map->Map2D[randXPos][randYPos].SetCreatureOnTile(&(*creatureIt));
                positionFound = true;
            }
        }
        
        positionFound = false;
 
        
        
        
    }
    
    player.loadCreatureTile("daeva.png", 32, 32);
    player.setPosition(0, 10);
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
    //Only move creatures randomly every  second..testing
    /*
    if(elapsed.asMilliseconds() >= 1000)
    {
      
   

        globalClock.restart();
    }
    */
    
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
    

    /*
    for(int i = 0; i < testStrings.size(); i++)
    {
        window.draw(testStrings.at(i));
    }
     */
    
    mapdata.window->draw(testStrings.at(0));
    mapdata.window->display();
    mapdata.window->clear();
    
    
    
    
    
}
