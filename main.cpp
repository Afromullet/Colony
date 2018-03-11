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
#include "BasicBehavior.hpp"
#include "BodyGraph.hpp"
#include <string>
#include "BodyGraphReader.hpp"

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
    
   
  

 
    
    BodyGraph gr;

    

    int currentID = 0;
    



        
    
    
    //Tomorrow todo, add edges to the return values of getVerticesByType
    //I.E, adding hands, adding feet..etc
    
    //Also ad a function for adding just a single body part to the graph
    ///And a function to print all of the body parts
    //Also a function to print the body parts and the edges between them
    

    
    GraphConnection connect;
    
    // std::cout << "Edge exists?" << boost::edge(v0, v1, g).second << std::endl; // true
    
    //AnatomyVertex vert1 = gr.anatomyGraph[0];
    //AnatomyVertex vert2 = gr.anatomyGraph[1];
    
 
      AnatomyIndexMap indMap = get(vertex_index, gr.anatomyGraph);
    
    AnatomyVertex vert1 = indMap[0];
    AnatomyVertex vert2 = indMap[1];
    
    
    //typedef boost::property < boost::edge_weight_t, double,boost::property<edge_capacity_t,int>> GraphEdgeWeightProp;
    typedef boost::property < boost::edge_weight_t, float> GraphEdgeWeightProp;
    //typedef boost::property < boost::vertex_name_t, std::string,boost::property<vertex_color_t,int>> GraphVertNameProp;
    
    typedef boost::adjacency_list<vecS, vecS, bidirectionalS,boost::no_property,GraphEdgeWeightProp> TestGraph;
    
    typedef boost::graph_traits<TestGraph>::vertex_descriptor tVertex;
    typedef boost::graph_traits<TestGraph>::edge_descriptor tEdge;
    //Defining the iterators
    
    typedef boost::graph_traits <TestGraph>::edge_iterator tEdgeIt;
    typedef boost::graph_traits<TestGraph>::vertex_iterator tVertexIt;
    
    typedef boost::property_map<TestGraph,boost::edge_weight_t>::type WeightMap;
   // typedef boost::property_map<TestGraph,boost::edge_capacity_t>::type CapacityMap;
    
    
     //typedef boost::property_map<TestGraph,boost::vertex_name_t>::type NameMap;
   // typedef boost::property_map<TestGraph,boost::vertex_color_t>::type ColorMap;
    
    
    TestGraph graph;
    

    tVertex v1 = boost::add_vertex(graph);
    tVertex v2 = boost::add_vertex(graph);
    tVertex v3 = boost::add_vertex(graph);
    tVertex v4 = boost::add_vertex(graph);



    //GraphEdgeWeightProp edgeProp = GraphEdgeWeightProp(7,3);
    GraphEdgeWeightProp edgeProp = 5;
    boost::add_edge(v1,v2,edgeProp,graph);
    
    edgeProp = 3;
    boost::add_edge(v2,v3,edgeProp,graph);
    
    edgeProp = 2;
    boost::add_edge(v3,v1,edgeProp,graph);



    BodyTypeReader bReader;
    //bReader.load("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/TestFile.xml");
    bReader.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
    bReader.readBodyTokenList();
    bReader.GenerateVertices();
    bReader.GenerateEdges();
    bReader.GenerateOrganVertices();
    bReader.GenerateOrganEdges();
    printBodyGraphEdges(bReader.anatomyGraph);
    

    bReader.load();
    
    

  
    WeightMap wMap = get(edge_weight,graph);
    std::vector<tVertex> p(num_vertices(graph)); //Parents
    std::vector<int> d(num_vertices(graph)); //Distances
    tVertex s = v1;
    
    
    /*
     
     From the documentation on iterator property maps
     
     The first method uses the adaptor class iterator_property_map. This class wraps a random access iterator, creating a property map out of it. The random access iterator must point to the beginning of a range of property values, and the length of the range must be the number of vertices or edges in the graph (depending on whether it is a vertex or edge property map). The adaptor must also be supplied with an ID property map, which will be used to map the vertex or edge descriptor to the offset of the property value (offset from the random access iterator). The ID property map will typically be an interior property map of the graph. The following example shows how the iterator_property_map can be used to create exterior property maps for the capacity and flow properties, which are stored in arrays. The arrays are indexed by edge ID. The edge ID is added to the graph using a property, and the values of the ID's are given when each edge is added to the graph. The complete source code for this example is in example/exterior_edge_properties.cpp. The print_network() function prints out the graph with the flow and capacity values.
     

     */
    
    //tVertexIt vertIt = boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, graph));
    
   // typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);


    
    boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, graph)); //Provides a mapping from vertex index to property
    dijkstra_shortest_paths(graph, s,
                            predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, graph))).
                            distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, graph))));
    


    


    
    Anatomy_BFS_Visitor vis;
    //breadth_first_search(gr.anatomyGraph, vertex(0, gr.anatomyGraph), visitor(vis));
    boost::shared_ptr<std::vector<AnatomyVertex>> aVec = gr.getVertices();
    boost::shared_ptr<std::vector<AnatomyVertex>> nVec;
    
    std::cout << "\n A Vec size" << aVec->size();
    
 
    Anatomy_DFS_Visitor dVis;
    depth_first_search(gr.anatomyGraph,visitor(dVis));
    
    aVec = dVis.getVector();
    
    for(int i =0; i < aVec->size(); i++)
    {
        
        std::cout << gr.anatomyGraph[aVec->at(i)];
       // std::cout << gr.anatomyGraph[aVec->at(i)];
    }
    
    /*
    std::cout << "distances and parents:" << std::endl;
    tVertexIt  vi, vend;
    for (boost::tie(vi, vend) = vertices(graph); vi != vend; ++vi) {
        std::cout << "distance(" << indMap[*vi];
        std::cout << "parent(" << indMap[*vi] << ") = " << indMap[p[*vi]] << std::
        endl;
     */
        
        


    
 
    
 

    
    
  
    

    



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
    player.Equip(&FIST_WEAPON);
    
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
