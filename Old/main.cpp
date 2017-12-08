#include <SFML/Graphics.hpp>


#include <iostream>
#include <Vector>
#include <cstdlib>

#include "Universal_Includes.h"

//#include "Constants.hpp"
//#include "Globals.hpp"

#include "GameObject.hpp"
#include "BasicMovement.hpp"
#include "CircleGraphic.hpp"
#include "EdgeDetection.hpp"
#include "BasicAIComponent.hpp"




#include "Equipment.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "EnumTypes.hpp"


#include "Bodyparts_Include.h"

#include "TestData.hpp"
#include "Combat.hpp"
#include "TileMap.hpp"
#include "Map.hpp"
#include "CAMap.hpp"
#include "BasicCreatureMovement.hpp"

void GameLoop();
void GameLoop3();

//sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "My window");
//std::vector<Entity> actors;
CreatureTile player;

void CheckPlayerMovement(sf::Event &event);
void InitRuleset();
void InitCreatureList(int number);
void DrawCreatureList();
void RandomCave();


int main()
{
   
    

    creature.setMovementComponent(new BasicCreatureMovement());
    
    
    InitializeTileData();
    FillCreatureVector(5);
    GameLoop3();
    
    return 0;
}











    




CA_Map caMap;
CA_RuleSet ruleset;








//Currently, moveCreature only works with mainmap. hardcoded until i generalize it
void GameLoop3()
{
    
    
    //I see now..I was mistaking ""width"" with the width of the tile, when it's actually the width of the map.
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "Tilemap");
    window.setKeyRepeatEnabled(false);
    
    
    MainMap.BasicRandom2DMap(sf::Vector2u(32,32), MAP_WIDTH, MAP_HEIGHT);
        caMap.Generate_CA_MAP(sf::Vector2u(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
    creature.loadCreatureTile("deep_elf_blademaster.png",32,32);
       
   
        // run the main loop
        while (window.isOpen())
        {
            // handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                
                CheckPlayerMovement(event);
            }

      
            
           
            RandomCave();
            window.draw(caMap);
            window.draw(creature.creatureTile);
            
            
            for(int i = 0; i < creatureList.size(); i++)
            {
                
                
                window.draw(creatureList.at(i).creatureTile);
            }
            
            window.display();
            window.clear();

        }
        
        return 0;
    
    
}



void CheckPlayerMovement(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            creature.setVelocity(1, 0);
            creature.UpdatePosition();
            creature.setVelocity(0, 0);
            
            
            //creature.MoveCreature(1,0);
        }
        
        else if(event.key.code == sf::Keyboard::Left)
        {
            creature.setVelocity(-1, 0);
            creature.UpdatePosition();
            creature.setVelocity(0, 0);
            //creature.MoveCreature(-1,0);
        }
        
        else if(event.key.code == sf::Keyboard::Up)
        {
            
            
            creature.setVelocity(0, -1);
            creature.UpdatePosition();
            creature.setVelocity(0, 0);
            
            //creature.MoveCreature(0,-1);
        }
        
        else if(event.key.code == sf::Keyboard::Down)
        {
            
            creature.setVelocity(0, 1);
            creature.UpdatePosition();
            creature.setVelocity(0, 0);
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






/*******************************
 
 OLD
 
 ********************************/


MVector tar(250,250);

GameObject* createObj()
{
    return new GameObject(new BasicMovement(),new CircleGraphic(),new EdgeDetection(),new BasicAIComponent());
}

GameObject *obj;
GameObject *obj2;

void SetupShit()
{
    obj = createObj();
    obj2 = createObj();
    
    obj->acceleration.setX(0);
    obj->acceleration.setY(0);
    obj->velocity.setX(0);
    obj->velocity.setY(0);
    obj->location.setX(10);
    obj->location.setY(2);
    obj->shape.setFillColor(GREEN);
    obj->shape.setRadius(50);
    obj->maxForce = 5;
    obj->maxSpeed = 5;
    obj->seekTarget = tar;
    obj->setWindow(&window);
    
    //std::cout << "test";
    
    //GameGrid grid(50,50,5,5);
    
}




