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


#include "BaseCreature.hpp"


#include "ItemGenerator.hpp"
#include "MapData.hpp"
#include "TestDataGenerator.hpp"
#include "PlayerControls.hpp"

#include "TestData.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/range/irange.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/config.hpp>
#include "MapEffect.hpp"

#include "DataWindow.hpp"
#include "Pathfinding.hpp"

#include "BodyGraph.hpp"
#include <string>

#include "BodyGraphGetters.hpp"
#include "Task.hpp"
#include "MovementAction.hpp"
#include "ExamineAction.hpp"


void GameLoop3();

void MoveAllCreatures();
void InitializeMaps();
void SetupCurrentMap();
void SetupGameData(Map *map);
void DrawEverything(MapData _mapdata);

MapData mapdata;
CA_RuleSet ruleset;
sf::Time elapsed;




/*

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
*/
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
    
   
  

 
    


    

    int currentID = 0;
    
    BasicMovementAction movementAction(caMap,player);
    BasicExamineSurroundingAction examineAction(caMap,player);
    
    Task task;
    task.AddEdge(&movementAction);
    task.AddEdge(&examineAction);
  


    CreatureBody bReader;
    //bReader.load("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/TestFile.xml");
    bReader.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
    bReader.readBodyTokenList();
    bReader.GenerateVertices();
    bReader.GenerateEdges();
    bReader.GenerateOrganVertices();
    bReader.GenerateOrganEdges();
    printBodyGraphEdges(bReader.anatomyGraph);
    printBodyGraphVertices(bReader.anatomyGraph);

    

    bReader.load();
    bReader.InitializeBodypartEquipment();
    
    Anatomy_DFS_Section_Visitor vis("armsection");
    depth_first_search(bReader.anatomyGraph,visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = vis.getVector();
    std::vector<int> vectorIndices;
    vectorIndices = vis.getVertexIndices();
    
    
    for(int i = 0; i < vectorIndices.size(); i++)
    {
        std::cout << bReader.anatomyGraph[vectorIndices.at(i)];
    }
    
    for(int i=0; i < aVec->size(); i++)
    {
       ;
        bReader.anatomyGraph[vectorIndices.at(i)].ApplyDamage(5);
    }
    
    for(int i=0; i < num_vertices(bReader.anatomyGraph); i++)
    {
        std::cout << bReader.anatomyGraph[i];
    }
    
    
    std::cout << "\n\n\n\n New";
    
    
    
    Armor testArmor;
    testArmor.setItemName("TestArmor1");
    testArmor.sections.push_back("upperbodysection");
    testArmor.sections.push_back("armsection");
    
    
    Weapon testWeapon;
    testWeapon.enWeaponSize = enLargeWeapon;
    testWeapon.sEquipmentName = "TestWeapon";
    testWeapon.setItemType(enWeaponType);
    
    bReader.Equip(&testArmor);
    bReader.EquipWeapon(&testWeapon);
    
    for(int i = 0; i < num_vertices(bReader.anatomyGraph); i++)
    {
        std::cout << "\n" << bReader.anatomyGraph[i];
    }
    
    
    getVerticesThatCanHoldWeapons(bReader.anatomyGraph);
    int b = getFirstUnequippedFromSection(bReader.anatomyGraph,"armsection");
    std::cout << "\n B = " << b;
    std::cout << bReader.anatomyGraph[b];
    
    std::cout << "\n\n\n\n New 1";
    
    b = getFirstUnequippedFromSection(bReader.anatomyGraph,"legsection");
    std::cout << "\n B = " << b;
    std::cout << bReader.anatomyGraph[b];
    
    b = getFirstUnequippedFromSection(bReader.anatomyGraph,"footsection");
    std::cout << "\n B = " << b;
    std::cout << bReader.anatomyGraph[b];

  
  
    
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
    


    
     
    
    
    

    
    std::vector<sf::Vector2i> neighbors;
    neighbors = GetPNeighbors(sf::Vector2i(5,5),caMap);
    for(int i =0; i < neighbors.size(); i++)
    {
        std::cout << " " << caMap.Map2D[neighbors.at(i).x][neighbors.at(i).y].index;
        
    }
    
   
    std::cout << "\n";
    
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
    //player.Equip(&FIST_WEAPON);
    
   // std::vector<sf::Vector2i> tempSquare = mapdata.map->getSquare(sf::Vector2i(5,1), 2);
   
    
    GridLocation start,end;
    start.x = 11;
    start.y = 5;
    
    end.x = 11;
    end.y = 20;
    
   std::map<GridLocation,GridLocation> cameFrom =  aStarSearch(caMap,  start,  end);
   
    
    std::vector<GridLocation> path = recontructPath(start,end, cameFrom);
    // aStarSearch(caMap,  start,  end);
    std::vector<sf::Vector2i> walkPath;
    
    for(int i =0; i < path.size(); i++)
    {
        
        //player.AddToPath(sf::Vector2i(path.at(i).x,path.at(i).y));
     
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
        
  
  
     

        
        
        //window.clear();
        
    
      
        player.vision.UpdateVision(*mapdata.map,player.getPosition());
         std::vector<BaseCreature> visible =  player.vision.getVisibleCreatures(*mapdata.map);
        player.vision.getVisibleItems(*mapdata.map);
       // GetItemBehavior(*mapdata.map, player);
       // player.WalkPath(*mapdata.map);

        std::cout << visible.size() << "\n";
       
        if(visible.size() > 1)
            std::cout << "\n New";
       
        
        DrawEverything(mapdata);
        
     
        
        PlayerActionTaken = false;
       
       // player.vision.UpdateVision(player.getPosition());
        
   
        
        
        
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
 setupTestCreatures();
   CreateTargetCreatures(mapdata);
    
    GenerateRandomItems(mapdata,30);
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
    
  
    std::list<BaseCreature>::iterator creatureIt;
    
    
    bool positionFound = false;
    int randXPos,randYPos;
    
    /*
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
     */
    
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

/*
 
 Examples of graph manipulation
 
 
 BodyGraph gr;
 gr.AddArmPairToChest(LeftArmBodyPart, RightArmBodyPart,leftHandBodyPart, rightHandBodyPart);
 gr.AddArmPairToChest(LeftArmBodyPart, RightArmBodyPart,leftHandBodyPart, rightHandBodyPart);
 
 int currentID = 0;
 
 
 
 IndexMap indMap = get(vertex_index, gr.anatomyGraph);
 anatomyEdgeIt ei,ei_end;
 
 Anatomy_BFS_Visitor vis;
 breadth_first_search(gr.anatomyGraph, vertex(0, gr.anatomyGraph), visitor(vis));
 
 boost::shared_ptr<std::vector<AnatomyVertex>> aVex = vis.getVector();
 std::cout << "\n\n" << aVex->size();
 
 std::string armstr = "leg";
 boost::shared_ptr<std::vector<AnatomyVertex>> aVec = gr.getVertices();
 
 //Accessing of a function of the bodypart in teh graph
 for(AnatomyVertex aVert : *aVec)
 gr.anatomyGraph[aVert].ApplyDamage(5);
 
 
 
 
 std::vector<int> nVec;
 
 for(int i=0; i < nVec.size(); i++)
 std::cout << "\nName and Health " <<  gr.anatomyGraph[nVec.at(i)].bodyPartName << " " << gr.anatomyGraph[nVec.at(i)].getHealth();
 
 

 
 nVec = gr.getVerticesOfType("hand");
 for(int i=0; i < nVec.size(); i++)
 std::cout << "\nName and Health " <<  gr.anatomyGraph[nVec.at(i)].bodyPartName << " " << gr.anatomyGraph[nVec.at(i)].getHealth();
 
 for(AnatomyVertex aVert : *aVec)
 std::cout << "\nName and Health " <<  gr.anatomyGraph[aVert].bodyPartName << " " << gr.anatomyGraph[aVert].getHealth();
 
 for(AnatomyVertex aVert : *aVec)
 gr.anatomyGraph[aVert].ApplyDamage(5);
 
 
 
 //Tomorrow todo, add edges to the return values of getVerticesByType
 //I.E, adding hands, adding feet..etc
 
 //Also ad a function for adding just a single body part to the graph
 ///And a function to print all of the body parts
 //Also a function to print the body parts and the edges between them
 
 gr.InitializeHandPairs();
 gr.printBody();
 
 for(AnatomyVertex aVert : *aVec)
 std::cout << "\nName and Health " <<  gr.anatomyGraph[aVert].bodyPartName << " " << gr.anatomyGraph[aVert].getHealth();
 
 
 
 

 for(std::pair<anatomyVertexIt,anatomyVertexIt> it = boost::vertices(gr.anatomyGraph); it.first != it.second; ++it.first)
 {
 AnatomyVertex v = *it.first;
 std::cout << indMap[v] <<  " ";
 }
 
 for (boost::tie(ei, ei_end) = edges(gr.anatomyGraph); ei != ei_end; ++ei)
 std::cout << "(" << indMap[source(*ei, gr.anatomyGraph)]
 << "," << indMap[target(*ei, gr.anatomyGraph)] << ") ";
 
 
 
 for(std::pair<anatomyVertexIt,anatomyVertexIt> it = boost::vertices(gr.anatomyGraph); it.first != it.second; ++it.first)
 {
 std::cout << gr.anatomyGraph[*it.first].bodyPartName << std::endl;
 }
 
 for(std::pair<anatomyVertexIt,anatomyVertexIt> it = boost::vertices(gr.anatomyGraph); it.first != it.second; ++it.first)
 {
 std::cout << gr.anatomyGraph[*it.first].bodyPartName << std::endl;
 }
 
 std::pair<AnatomyEdgeIt, AnatomyEdgeIt> edgeIteratorRange = boost::edges(gr.anatomyGraph);
 for(AnatomyEdgeIt edgeIterator = edgeIteratorRange.first; edgeIterator != edgeIteratorRange.second; ++edgeIterator)
 {
 std::cout << gr.anatomyGraph[*edgeIterator].connection << "\n";
 
 
 }


 
 */
