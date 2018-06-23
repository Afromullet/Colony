//
//  TestDataGenerator.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "TestDataGenerator.hpp"
#include "BaseCreature.hpp"

#include "ItemGenerator.hpp"
#include "CAMap.hpp"


//Armor and weapons for the player
Armor tHeadArmor;
Armor tChestArmor;
Armor tLegArmor;
Armor tHandArmor;
Armor tFootArmor;

Weapon tOneHnaded;
Weapon tTwoHanded;


BaseCreature basicGoblin;
BaseCreature basicOrc;
BaseCreature basicPulser;

void InitializeCreatureTypes()
{

    
    basicGoblin.loadCreatureTile("goblin.png",32,32);
    basicPulser.loadCreatureTile("pulsating_lump.png",32,32);
    basicOrc.loadCreatureTile("orc_warrior.png",32,32);
    
  
}

//Places creatures randomly on the map
void CreateRandomCreatures(MapData &mapdata)
{
    
    std::list<BaseCreature> tempCreatureList;

    for(int i = 0; i < 10; i++)
    {
        BaseCreature testCreature;
        
        int randNum = rand() % 3;
        
        switch(randNum)
        {
            case 0:
                testCreature = basicGoblin;
                break;
            case 1:
                testCreature = basicOrc;
                break;
            case 2:
                testCreature = basicPulser;
                break;
        }
  
    
        
        testCreature.setPosition(rand() % mapdata.map->GetWidth(), rand() % mapdata.map->GetHeight());
        mapdata.AddCreatureToMap(testCreature);
        //tempCreatureList.push_back(testCreature);
    }
    
   // InitCreaturesOnMap(caMap,lCreatures);
    
    
}

void CreateTargetCreatures(MapData &mapdata)
{
    

    
   
    
    
    
    
    for(int i = 0; i < 10; i++)
    {
        BaseCreature testCreature;
         testCreature = basicOrc;
        testCreature.setPosition(rand() % MAP_WIDTH, rand() % MAP_HEIGHT);
 
            mapdata.AddCreatureToMap(testCreature);
        
    }
    
    
}


//Generates random items and places them on the map
void GenerateRandomItems(MapData &mapdata, int numberOfItems)
{
    
    for(int i = 0; i < numberOfItems; i++)
    {
        Item *item;
        mapdata.itemsOnMap.push_back(item);
    }
    
    std::list<Item*>::iterator itemIt;
    int counter = 0;
    
    int randX,randY;
    for(itemIt =  mapdata.itemsOnMap.begin(); itemIt !=  mapdata.itemsOnMap.end(); ++itemIt)
    {
        
        //A lot of redunancy in the code below..just testing for now
        Armor arm = GenerateRandomArmor();
        
        
        *itemIt = arm.clone();
        
        //std::cout << "\nInside random item gen after cast " << (* << "\n";
        
        // (*itemIt)->setItemName(arm.getItemName());
       // std::cout << "\nRandom item gen item armor name " << (*itemIt)->getItemName() << "\n";
       
        randX = rand() % mapdata.map->GetWidth();
        randY = rand() % mapdata.map->GetHeight();
        (*itemIt)->setPosition(randX, randY);
        //(*itemIt)->localItemID = counter;
        counter++;
    }
}


//Generate one set of armor for each slot the armor can fit
void GenerateTestEquipment()
{
    Armor armor;
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);


    

    armor.setItemName("HeadArmorTest");
    tHeadArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    

    armor.setItemName("ChestArmorTest");
    tChestArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
   
    

    armor.setItemName("LegArmorTest");
    tLegArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
    
    
;
    armor.setItemName("HandArmorTest");
    tHandArmor = armor;
    
    armor.setArmorBonus(rand() % 5);
    armor.setDodgeModifier(rand() % 2);
    armor.setDamageReduction(rand() % 2);
    armor.setMovementModifier(rand() % 2);
  
    

    armor.setItemName("FootArmorTest");
    tFootArmor = armor;
    
    Weapon weapon;
  


    weapon.setItemName("TwoHandedWep");
    weapon.setRange(1);
    weapon.setDamage(10);
    weapon.enWeaponSize = enLargeWeapon;
    tTwoHanded = weapon;
    

  
    weapon.setItemName("OneHandedWep");
    weapon.setRange(1);
    weapon.setDamage(5);
    weapon.enWeaponSize = enSmallWeapon;
    tOneHnaded = weapon;
    


    player.AddItemToInventory(&tHeadArmor);
    player.AddItemToInventory(&tChestArmor);
    player.AddItemToInventory(&tLegArmor);
    player.AddItemToInventory(&tHandArmor);
    player.AddItemToInventory(&tFootArmor);
    player.AddItemToInventory(&tOneHnaded);
    player.AddItemToInventory(&tTwoHanded);
    
    
    
    //Weapon.setFi
    
    
}

//Initializes the ruleset used for the cellular automota map



void GenerateRandomCave()
{
    CA_RuleSet ruleset;
    
    CELL_CHANCETOSTARTALIVE = 0.45f;
    NUMBER_OF_STEPS = 10;
    BIRTH_LIMIT = 3;
    DEATH_LIMIT = 8;
    
    ruleset.aliveTileID = 1;
    ruleset.deadTileID = 0;
    ruleset.birthLimit = BIRTH_LIMIT;
    ruleset.chanceToStartAlive = CELL_CHANCETOSTARTALIVE;
    ruleset.deathLimit = DEATH_LIMIT;
    caMap.SetRuleSet(ruleset);
    caMap.Generate_CA_MAP(sf::Vector2i(32,32), MAP_WIDTH,MAP_HEIGHT,ruleset);
}
