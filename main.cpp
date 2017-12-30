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
#include "CreatureHandler.hpp"
#include "ItemGenerator.hpp"

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
//void CreatureRandomMove(Creature &creature, Map &map);
void MoveAllCreatures();
void GenerateWallOnlyMap(Map &_map);
void InitCreaturesOnMap(Map &_map, std::list<BaseCreature> &_creatures);

void GenerateTestEquipment();


Armor tHeadArmor;
Armor tChestArmor;
Armor tLegArmor;
Armor tHandArmor;
Armor tFootArmor;

Weapon tOneHnaded;
Weapon tTwoHanded;

//Generate one set of armor for each slot the armor can fit
void GenerateTestEquipment()
{
    Armor armor;
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    armor.setItemType(enArmorType);
    
    armor.setFitsBodyPart(enHeadBodyPart);
    armor.setItemName("HeadArmorTest");
    tHeadArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    
    armor.setFitsBodyPart(enChestBodyPart);
    armor.setItemName("ChestArmorTest");
    tChestArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    
    armor.setFitsBodyPart(enLegsBodyPart);
    armor.setItemName("LegArmorTest");
    tLegArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    
    armor.setFitsBodyPart(enHandsBodyPart);
    armor.setItemName("HandArmorTest");
    tHandArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    armor.setItemID(rand() % 1000);
    
    armor.setFitsBodyPart(enFeetBodyPart);
    armor.setItemName("FootArmorTest");
    tFootArmor = armor;
    
    Weapon weapon;
    weapon.setItemType(enWeaponType);
    weapon.setFitsBodyPart(enFitsBothHands);
    weapon.setItemName("TwoHandedWep");
    weapon.setRange(1);
    weapon.setDamage(10);
    tTwoHanded = weapon;
    
    weapon.setFitsBodyPart(enFitsOneHand);
    weapon.setItemName("OneHandedWep");
    weapon.setRange(1);
    weapon.setDamage(5);
    tOneHnaded = weapon;
    
    
    
    //Weapon.setFi
    

}



BaseCreature creat;

int main()
{
   
    



    
    
        creat.setPosition(10, 10);
    
  
    HumanoidBody hum;
    QuadrupedBody quadBody;
    
    creat.CloneBody(&hum);
       //creat.setBody(&hum);
   
   
    creat.setBody(&quadBody);
    std::cout << "\n\n";
 
    
   // body = hum;
    
    
    HumanoidBody humanoid;
    
    
    InitializeTileData();
   
    
    
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

        player.loadCreatureTile("deep_elf_blademaster.png",32,32);
    
  

    HumanoidBody humanoid;
    player.setBody(&humanoid);
    player.setPosition(5, 5);
    
    Item *it;
    Armor arm;
    Weapon wep;
    
 
    
    arm.setItemType(enArmorType);
    wep.setItemType(enWeaponType);
    arm.setFitsBodyPart(enChestBodyPart);
    //wep.setFitsBodyPart(enOneHanded);
    arm.setArmorBonus(10);
    wep.setDamage(5);
    wep.setItemName("weapon1");
    arm.setItemName("armor1");
    

    Item *pArm = &arm;
    Item *pWep = &wep;
    
    Armor arm2 = arm;
    arm2.setItemName("abc ");
    
    Item *testItem = arm2.clone();
    testItem->setItemName("asdsd");
    //Item *testItem = &arm2;
    
    GenerateTestEquipment();
    Item *testHA = &tHeadArmor;
    Item *testCA = &tChestArmor;
    Item *testLA = &tLegArmor;
    Item *testFA = &tFootArmor;
    Item *testHnd = &tHandArmor;
    Item *testOneHanded = &tOneHnaded;
    Item *testTwoHanded = &tTwoHanded;
    
    
    player.AddItemToInventory(testHA);
    player.AddItemToInventory(testCA);
    player.AddItemToInventory(testLA);
    player.AddItemToInventory(testFA);
    player.AddItemToInventory(testHnd);
    player.AddItemToInventory(testOneHanded);
    player.AddItemToInventory(testTwoHanded);
    

    
    
    //player.AddItemToInventory(pArm);
   // player.AddItemToInventory(pWep);
    //player.AddItemToInventory(testItem);
   
    player.PrintInventory();
   
    
   // Armor armor;
    //Item item
    //humanoid.EquipItem(armor);
    
    GenerateWallOnlyMap(MainMap);

   

    SetupTestTargestBox();
    
  //  squareMap.CreateRoom(2,1,sf::Vector2u(5,5));
   // squareMap.CreateRandomRooms(5, 1);
    //All of these map initilizations are for testing
    squareMap.BuildCorridor(10, Right, 1, sf::Vector2u(10,10));
    squareMap.LoadTileParameters();
    squareMap.Group2DGridTiles();
    squareMap.LoadTileTexture();
    
    MainMap.LoadTileParameters();
    MainMap.Group2DGridTiles();

    MainMap.LoadTileTexture();
    
    GenerateRandomCreatures();
    RandomItemGen();
    PlaceItemsOnMap(caMap);


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

            window.draw(caMap);
    
            elapsed = globalClock.getElapsedTime();
            //Only move creatures randomly every two seconds..testing
            if(elapsed.asMilliseconds() >= 1000)
            {
                MoveAllCreatures();
                globalClock.restart();
            }
            

      
            //For testing
            RemoveDeadCreature(caMap,lCreatures);
            
            std::list<BaseCreature>::iterator iter;
            for(iter = lCreatures.begin(); iter != lCreatures.end(); ++iter)
            {
                window.draw(iter->creatureTile);
            }
            
            std::list<Item*>::iterator itemIterator;
            
            for(itemIterator = itemsOnMap.begin(); itemIterator != itemsOnMap.end(); ++itemIterator)
            {
                
                window.draw((*itemIterator)->tile);
            }
            
           
            
            window.draw(player.creatureTile);
           
            window.display();
            window.clear();

        }
        
        return 0;
    
    
}


void GenerateRandomCreatures()
{
    
    

    for(int i = 0; i < 10; i++)
    {
        BaseCreature testCreature;
        HumanoidBody body;
        testCreature.CloneBody(&body);
        testCreature.loadCreatureTile("deep_elf_blademaster.png",32,32);
        testCreature.setPosition(rand() % MAP_WIDTH, rand() % MAP_HEIGHT);
        testCreature.getBody()->CalculateHealth();
        testCreature.getBody()->setTotalHealth(31); //For testing
        lCreatures.push_back(testCreature);
    }
    
    InitCreaturesOnMap(caMap,lCreatures);
    
    
}



CA_Map oldMap;
void CheckPlayerMovement(sf::Event &event, Map &map)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            MovePlayer(Right, player,caMap);
     
        }
        
        else if(event.key.code == sf::Keyboard::Left)
        {
            MovePlayer(Left, player,caMap);
        }
        
        else if(event.key.code == sf::Keyboard::Up)
        {

            MovePlayer(Up, player,caMap);
           
        }
        
        else if(event.key.code == sf::Keyboard::Down)
        {
             MovePlayer(Down, player,caMap);
        }
        else if(event.key.code == sf::Keyboard::G)
        {
            player.PickupItem(caMap,itemsOnMap);
            
        }
        else if(event.key.code == sf::Keyboard::I)
        {
            player.PrintInventory();
        }
        else if(event.key.code == sf::Keyboard::P)
        {
            player.getBody()->PrintEquippedItems();
            
        }
        else if(event.key.code == sf::Keyboard::E)
        {
            player.PrintInventory();
            int n;
            std::cout << "\nEnter item index \n";
            std::cin >> n;
            player.EquipItemFromInventory(n);
            std::cout << "Equipped";
            int k = 3;

        }
        
    }
    
}

//Initializes the ruleset used for the cellular automota map
void InitRuleset()
{
    
    CELL_CHANCETOSTARTALIVE = 0.45f;
    NUMBER_OF_STEPS = 5;
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

/*
 The tile of a map must be updated to indicate that a creature is on it.
 TODO handle this a better way. This is just for testing
 
 */
void InitCreaturesOnMap(Map &_map, std::list<BaseCreature> &_creatures)
{
    std::list<BaseCreature>::iterator iter;
    for(iter = _creatures.begin(); iter != _creatures.end(); ++iter)
    {
        BaseCreature &creat = *iter;
        _map.Map2D[iter->getPosition().x][iter->getPosition().y].SetCreatureOnTile(&creat);
    }
    
}

/* 
 Testing functions. Moves creatures randomly on the map 
 */
void MoveAllCreatures()
{
    std::list<BaseCreature>::iterator iter;
    for(iter = lCreatures.begin(); iter != lCreatures.end(); ++iter)
    {
        BaseCreature &creat = *iter;
        MoveCreatureRandomly(&creat, caMap);
    }
}

