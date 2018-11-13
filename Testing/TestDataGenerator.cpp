//
//  TestDataGenerator.cpp
//  Colony
//
//  Created by Sean on 1/1/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "TestDataGenerator.hpp"


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

std::vector<BaseCreature> testCreatures;

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

    for(int i = 0; i < 1; i++)
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
  
        //testCreature
        testCreature.setPosition(1+i, 0);
        //testCreature.setPosition(rand() % mapdata.map->GetWidth(), rand() % mapdata.map->GetHeight());

        
        testCreatures.push_back(testCreature);
        mapdata.AddCreatureToMap(testCreatures.at(i));
        
        testCreatures.at(i).body.openBodyTypeFile("/Users/Afromullet/Documents/SFML/Colony2/Colony/Creature/BodyData/BasicHumanoidBody.xml");
        testCreatures.at(i).body.readBodyTokenList();
        testCreatures.at(i).body.GenerateVertices();
        testCreatures.at(i).body.GenerateEdges();
        testCreatures.at(i).body.GenerateOrganVertices();
        testCreatures.at(i).body.GenerateOrganEdges();
        //tempCreatureList.push_back(testCreature);
    }
    
    //InitCreaturesOnMap(caMap,lCreatures);
    InitCreaturesOnMap(mapdata);
    
}

void InitCreaturesOnMap(MapData &mapdata)
{
    std::list<BaseCreature>::iterator it;
    for(it = mapdata.creaturesOnMap.begin(); it != mapdata.creaturesOnMap.end(); ++it)
    {
        
        it->loadCreatureTile("goblin.png",32,32);
     
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

void GenerateItemsOnMap()
{
    
    Armor tempArmor, tempArmor2,tempArmor3;
    Weapon tempWeapon,tempWeapon2,tempWeapon3;
    for(int i = 0; i < MAP_WIDTH; i++)
    {
        for(int j = 0; j < 1; j++)
        {
           
            tempArmor.setPosition(i, j);
            tempArmor.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempArmor.setItemName("A");
            tempArmor2.setPosition(i, j);
            tempArmor2.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempArmor2.setItemName("B");
            tempArmor3.setPosition(i, j);
            tempArmor3.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempArmor3.setItemName("C");
            tempWeapon.setPosition(i, j);
            tempWeapon.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempWeapon.setItemName("WA");
            tempWeapon2.setPosition(i, j);
            tempWeapon2.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempWeapon2.setItemName("WB");
            tempWeapon3.setPosition(i, j);
            tempWeapon3.UpdateTileTexture("blessed_blade.png",sf::Vector2i(32,32));
            tempWeapon3.setItemName("WC");
            
            mapdata.map->Map2D[i][j].AddArmor(tempArmor);
            mapdata.map->Map2D[i][j].AddArmor(tempArmor2);
            mapdata.map->Map2D[i][j].AddArmor(tempArmor2);
            mapdata.map->Map2D[i][j].AddArmor(tempArmor3);
            mapdata.map->Map2D[i][j].AddWeapon(tempWeapon);
            mapdata.map->Map2D[i][j].AddWeapon(tempWeapon);
            mapdata.map->Map2D[i][j].AddWeapon(tempWeapon);
            mapdata.map->Map2D[i][j].AddWeapon(tempWeapon2);
            mapdata.map->Map2D[i][j].AddWeapon(tempWeapon3);
        }
    }

}
