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

#include "MovementHandler.hpp"
#include "MapUtil.hpp"
#include "SquareDiggingMap.hpp"
#include "Arm.hpp"
#include "Leg.hpp"
#include "HumanoidBody.hpp"
#include "BaseCreature.hpp"
#include "QuadrupedBody.hpp"

void GameLoop();
void GameLoop3();

//sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");
//std::vector<Entity> actors;
//EntityTile player;

void CheckPlayerMovement(sf::Event &event, Map &map);
void InitRuleset();
void InitCreatureList(int number);
void DrawCreatureList();
void GenerateRandomCreatures();
void RandomCave();
//void SetPlayerVisibleTiles();
//void FillCreaturesToMap(Map &map);
void CreatureRandomMove(Creature &creature, Map &map);
void MoveAllCreatures();
void GenerateWallOnlyMap(Map &_map);


BaseCreature creat;

int main()
{
   
    



    
    
        creat.setPosition(10, 10);
    
  
    HumanoidBody hum;
    QuadrupedBody quadBody;
    
    creat.setBody(&hum);
    for(int i = 0; i < 10; i++)
    {
         creat.getBody()->AttackRandomBodyPart(5,2);
    }
   
    creat.setBody(&quadBody);
    std::cout << "\n\n";
    for(int i = 0; i < 10; i++)
    {
        creat.getBody()->AttackRandomBodyPart(5,3);
    }
    
   // body = hum;
    
    
    HumanoidBody humanoid;
    
    
    InitializeTileData();
    GenerateRandomCreatures();
    
    GameLoop3();
    
    return 0;
}











    



SqureDiggingMap squareMap;
CA_Map caMap;
CA_Map caMapSecondWindow;
CA_RuleSet ruleset;



void RemoveDeadFromCreatureList()
{

}


//just use a quad]]
sf::VertexArray targetBodyBox(sf::Quads,4);
void SetupTestTargestBox()
{
    
    // define it as a rectangle, located at (10, 10) and with size 100x100
    targetBodyBox[1].position = sf::Vector2f(0, 1000);
    
    targetBodyBox[2].position = sf::Vector2f(800, 1000);
    
    
    targetBodyBox[0].position = sf::Vector2f(0, 1300);
    targetBodyBox[0].position = sf::Vector2f(0, 1300);
    
    
    targetBodyBox[3].position = sf::Vector2f(800, 1300);
    
    targetBodyBox[0].color = sf::Color::Green;
    targetBodyBox[1].color = sf::Color::Green;
    targetBodyBox[2].color = sf::Color::Green;
    targetBodyBox[3].color = sf::Color::Green;

    
}



sf::Clock globalClock;




void GameLoop3()
{
    
    sf::Time elapsed;

    
    //I see now..I was mistaking ""width"" with the width of the tile, when it's actually the width of the map.
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Tilemap");
    
    window.setKeyRepeatEnabled(false);
    
    
    MainMap.BasicRandom2DMap(sf::Vector2u(32,32), MAP_WIDTH, MAP_HEIGHT);
    caMap.Generate_CA_MAP(sf::Vector2u(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
    RandomCave();
    
    squareMap.CreateMap(sf::Vector2u(32,32),MAP_WIDTH, MAP_HEIGHT, 0);

    creat.loadCreatureTile("deep_elf_blademaster.png",32,32);
    player.loadCreatureTile("deep_elf_blademaster.png",32,32);
    HumanoidBody humanoid;
    player.setBody(&humanoid);
    player.setPosition(5, 5);

    
   // FillCreaturesToMap(MainMap);
    //FillCreaturesToMap(caMap);
    
    GenerateWallOnlyMap(MainMap);

    
    
    
   // SetPlayerVisibleTiles();
    SetupTestTargestBox();
    
  //  squareMap.CreateRoom(2,1,sf::Vector2u(5,5));
   // squareMap.CreateRandomRooms(5, 1);
    
    squareMap.BuildCorridor(10, Right, 1, sf::Vector2u(10,10));
    squareMap.LoadTileParameters();
    squareMap.Group2DGridTiles();
    squareMap.LoadTileTexture();
    
        MainMap.LoadTileParameters();
    MainMap.Group2DGridTiles();

    MainMap.LoadTileTexture();
    
    
   
        // run the main loop
        while (window.isOpen())
        {
            // handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                
                CheckPlayerMovement(event,MainMap);
            }

            
            
      
            
           
            //RandomCave();
            //window.draw(MainMap);
            //window.draw(caMap);
            //window.draw(targetBodyBox);
            window.draw(caMap);
       

            //DrawCreatureList();
           
            
            
            elapsed = globalClock.getElapsedTime();
            
            //Only move creatures randomly every two seconds..testing
            if(elapsed.asMilliseconds() >= 1000)
            {
                //MoveAllCreatures();
                globalClock.restart();
            }
            
            
           // window.draw(creat.creatureTile);
            // MoveAllCreatures();
           // window.display();
           // window.clear();
            
            /*
            int x1,y1,roomSize;
            //std::cout << "Enter room size";
            std::cin >> roomSize;
            //std::cout << "Enter coordiantes ";
            std::cin >> x1;
            std::cin >> y1;
            */
            
            

            
            
      
            
           // MoveAllCreatures();
            window.draw(creat.creatureTile);
            window.draw(player.creatureTile);
            window.display();
            window.clear();

        }
        
        return 0;
    
    
}


void GenerateRandomCreatures()
{
    
    
    

    
 

    
    
    
}

void DrawCreatureList()
{

}


CA_Map oldMap;
void CheckPlayerMovement(sf::Event &event, Map &map)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            MovePlayer(Right, player,map);
     
        }
        
        else if(event.key.code == sf::Keyboard::Left)
        {
            MovePlayer(Left, player,map);
        }
        
        else if(event.key.code == sf::Keyboard::Up)
        {
            
           
            MovePlayer(Up, player,map);
           // caMap = oldMap;
          //  caMap.Group2DGridTiles();
          //  caMap.LoadTileTexture();
            
            //creature.setVelocity(0, -1);
            //creature.UpdatePosition();
            //creature.setVelocity(0, 0);
            
            //creature.MoveCreature(0,-1);
        }
        
        else if(event.key.code == sf::Keyboard::Down)
        {
             MovePlayer(Down, player,map);
            //creature.setVelocity(0, 1);
           // creature.UpdatePosition();
           // creature.setVelocity(0, 0);
            //creature.MoveCreature(0,1);
        }
        
    }
    
}


void InitRuleset()
{
    
    CELL_CHANCETOSTARTALIVE = 0.45f;
    NUMBER_OF_STEPS = 2;
    BIRTH_LIMIT = 4;
    DEATH_LIMIT = 3;
    
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = BIRTH_LIMIT;
    ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
    ruleset.deathLimit = DEATH_LIMIT;
    ruleset.numberOfSteps = 3;
    
}




void RandomCave()
{
    InitRuleset();
    caMap.SetRuleSet(ruleset);
    caMap.Generate_CA_MAP(sf::Vector2u(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
    
    sf::Clock clock;;
    
    while(1)
    {
        sf::Time elapsed = clock.getElapsedTime();
        
        
        if(elapsed.asMilliseconds() >= 1500)
        {
            break;
        }
        
    }
    
    clock.restart();
    
}



//Currently, moveCreature only works with mainmap. hardcoded until i generalize it









//Uses hardcoded tile id for wall atm for testing
void GenerateWallOnlyMap(Map &_map)
{
    
    for(int i = 0; i < _map.GetWidth(); i++)
        for(int j = 0; j < _map.GetHeight(); j++)
        {
            _map.Map2D[i][j].setTileID(0);
            
            _map.Group2DGridTiles();
            _map.LoadTileParameters();
            _map.LoadTileTexture();
            
            
        }
    
}

