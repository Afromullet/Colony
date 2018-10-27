//
//  SettlementEV.cpp
//  Colony
//
//  Created by Sean on 9/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "SettlementEV.hpp"
#include "Constants.hpp"
#include "MapEffect.hpp"
#include <iostream>


/*
 
 
 RESOURCE FUNCTION CLASS DEFINITION
 
 
 */

void ResourceFunction::operator=(const ResourceFunction &other)
{
    multiplier = other.multiplier;
    minDistance = other.minDistance;
    maxDistance = other.maxDistance;
    enResourceFunctonType = other.enResourceFunctonType;
    enTerrainFeature = other.enTerrainFeature;
}

ResourceFunction::ResourceFunction()
{
    multiplier = ERROR_VALUE;
    minDistance = ERROR_VALUE;
    maxDistance = ERROR_VALUE;
    enResourceFunctonType = enInvalidResourceFunction;
    enTerrainFeature = enInvalidTerrainFeature;
    
}

ResourceFunction::ResourceFunction(const ResourceFunction &other)
{
    multiplier = other.multiplier;
    minDistance = other.minDistance;
    maxDistance = other.maxDistance;
    enResourceFunctonType = other.enResourceFunctonType;
    enTerrainFeature = other.enTerrainFeature;
    
}

ResourceFunction::ResourceFunction(std::string newName,float mult, float min,float max,EnResourceFunctionType resourceFunctionType,EnTerrainFeature terrainFeature) : name(newName),multiplier(mult), minDistance(min), maxDistance(max),enResourceFunctonType(resourceFunctionType),enTerrainFeature(terrainFeature)
{
    
}


void ResourceFunction::setTerrainFeature(EnTerrainFeature val)
{
    enTerrainFeature = val;
}

void ResourceFunction::setMultiplier(float val)
{
    multiplier = val;
}

void ResourceFunction::setMinDistance(float val)
{
    minDistance = val;
}

void ResourceFunction::setMaxDistance(float val)
{
    maxDistance = val;
}

void ResourceFunction::setName(std::string str)
{
    name = str;
}

EnTerrainFeature ResourceFunction::getTerrainFeature()
{
    return enTerrainFeature;
}

float ResourceFunction::getMultiplier()
{
    return multiplier;
}

float ResourceFunction::getMinDistance()
{
    return minDistance;
}

float ResourceFunction::getMaxDistance()
{
    return maxDistance;
}


std::vector<sf::Vector2i> ResourceFunction::getCircle(float xPos,float yPos)
{
    MapEffect circle = MapEffect();
    circle.setCircle(xPos, yPos, maxDistance / 2);
    return circle.getTilePositions();
}


std::string ResourceFunction::getName()
{
    return name;
}

/*
 
 
 RELATION CLASS DEFINITION
 
 
 */


Relation::Relation()
{
    name = ERROR_STRING;
}

Relation::Relation(std::string _name)
{
    name = _name;
}

void Relation::setResourceFunction(ResourceFunction val)
{
    resourceFunction = val;
}

void Relation::setName(std::string val)
{
    name = val;
}

void Relation::setAttitudeEffect(float val)
{
    attitudeEffect = val;
}

void Relation::addInProduct(ResourceFunction val)
{
    in.push_back(val);
}

void Relation::addOutProduct(ResourceFunction val)
{
    out.push_back(val);
}

Settlement::Settlement()
{
    
}

void Settlement::loadTile(const std::string& tileset, int tileXSize,int tileYSize)
{
    tile.loadTile(tileset,  sf::Vector2i(tileXSize, tileYSize), sf::Vector2i(position.x, position.y));
}

void Settlement::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    
}

void Settlement::setMaxDist(float val)
{
    maxDistance = val;
    
    MapEffect circle = MapEffect();
    circle.setCircle(position.x, position.y, maxDistance / 2);
    
    radius = circle.getRadius();
    

    area = circle.getTilePositions();
    
        /*
    
    for(int j = 0; j < 10; j++)
    {
        sf::Vector2i tempVec = circle.getRandomPointInCircle();
        area.push_back(tempVec);
    }
*/
    
    
 
}

sf::Vector2i Settlement::getPosition()
{
    return position;
}

float Settlement::getMaxDist()
{
    return maxDistance;
}


sf::Vector2i Settlement::getRandomPointInCircle()
{
    // int x = rand() % radius + (-radius) + origin.x;
    //  int y = rand() % radius + (-radius) + origin.y;
    
    
    int x = rand() % radius ;
    int y = rand() % radius ;
    
    int xSelection = rand() % 1;
    int ySelection = rand() % 2;
    
    //So that we don't only draw in positive direction..Point can be x,-x,y,-y
    if(xSelection == 0)
        x *= -1;
    if(ySelection == 0)
        y *= -1;
    
    
    
       std::cout << "\n Radius " << radius;
        std::cout << "\n Origin: " << + position.x << "," <<  position.y;
        std::cout << "\n New x and y" << x + position.x << "," << y + position.y<< "\n";
   
    
    return sf::Vector2i(x + position.x,y + position.y);
}




District::District()
{
    
}

void District::setName(std::string val)
{
    name = val;
}

void District::addProduct(ResourceFunction val)
{
    products.push_back(val);
}
void District::setRelation(Relation val)
{
    relation = val;
}

void District::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    
}

sf::Vector2i District::getPosition()
{
    return position;
}



//Test data follows here

std::vector<Settlement> settlements;
ResourceFunction testResourceFunctions[10];

//ResourceFunction(std::string newName,float mult, float min,float max,EnResourceFunctionType resourceFunctionType,EnTerrainFeature terrainFeature);



//int numResFunctions = 0;

void createTestSettlements()
{
    
    Settlement settlement;
    for(int i = 0; i < NUM_TEST_SETTLEMENTS; i++)
    {
        
       
        //settlement.setPosition(rand() % 100, rand() % 100);
        
        settlement.setPosition(rand() % 50, rand() % 50);
        settlement.setMaxDist(rand() % 10);
        settlement.loadTile("marble_wall1.png", 32, 32);
        settlements.push_back(settlement);
        
         
        

        
    }
    
    
    
    testResourceFunctions[0] = ResourceFunction("food",2.0,30,150,enOpen,enWaterFeature);
    testResourceFunctions[1] = ResourceFunction("food",2.0,30,150,enOpen,enLandFertilityFeature);
    testResourceFunctions[2] = ResourceFunction("manpower",2.0,30,150,enOpen,enDominationFeature);
    testResourceFunctions[3] = ResourceFunction("ore",2.0,30,150,enOpen,enMetalFeature);

     
}
