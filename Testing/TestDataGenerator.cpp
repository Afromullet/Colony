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
    weapon.setWeaponSize(enLargeWeapon);
    tTwoHanded = weapon;
    

  
    weapon.setItemName("OneHandedWep");
    weapon.setRange(1);
    weapon.setDamage(5);
    weapon.setWeaponSize(enSmallWeapon);
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
