//
//  SettlementEV.hpp
//  Colony
//
//  Created by Sean on 9/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef SettlementEV_hpp
#define SettlementEV_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "EntityTile.hpp"
#include "MapEffect.hpp"
#include "Tile.hpp"
#include "Constants.hpp"
#include "MapEffect.hpp"
//Until I determine how I want to organize the classes, this file will contain them all



class Relation;
class District;

//A terrain feature is required for a resource. Terrain features use enumerated types. There is no need to have a class representing them

//The type of resource function
enum EnResourceFunctionType
{
    enOpen,enClosed,enBalanced,enInvalidResourceFunction
};


class ResourceFunction
{
    
private:
    float multiplier;
    float minDistance;
    float maxDistance;
    std::string name;
    
    EnResourceFunctionType enResourceFunctonType; //Resource function is not different enough between the types to justify subclassing.
    EnTerrainFeature enTerrainFeature; //Only use one terrain feature per product. Don't want to overcomplicate things
    
public:
    
    void operator=(const ResourceFunction &other) ;
    
    ResourceFunction();
    ResourceFunction(const ResourceFunction &other);
    ResourceFunction(std::string newName,float mult, float min,float max,EnResourceFunctionType resourceFunctionType,EnTerrainFeature terrainFeature);
    
    
    void setTerrainFeature(EnTerrainFeature val);
    void setMultiplier(float val);
    void setMinDistance(float val);
    void setMaxDistance(float val);
    void setName(std::string str);
    
    
    
    EnTerrainFeature getTerrainFeature();
    float getMultiplier();
    float getMinDistance();
    float getMaxDistance();
    std::string getName();
    
    std::vector<sf::Vector2i> getCircle(float xPos,float yPos);
    
    
    
    
    
    
};




//Consider making the product a shared pointer. Not yet sure if I want to take quantity into account. If quantity is used, then we can't use a shared pointer, so for now assume that you're going to use it in the future and have each instance store its own copy
class Relation
{
private:
    std::string name;
    std::vector<ResourceFunction> in;
    std::vector<ResourceFunction> out;
    float attitudeEffect;
    ResourceFunction resourceFunction;
  
    
    
public:
    Relation();
    Relation(std::string _name);
    
    void setResourceFunction(ResourceFunction val);
    void setName(std::string val);
    void setAttitudeEffect(float val);
    void addInProduct(ResourceFunction val);
    void addOutProduct(ResourceFunction val);
    
};


class District
{
private:
    std::string name;
    //todo needs vector
    std::vector<ResourceFunction> products;
    Relation relation; //Relation to parent settmenet
    sf::Vector2i position;
public:
    District();
    
    void setName(std::string val);
    void addProduct(ResourceFunction val);
    void setRelation(Relation val);
    void setPosition(int x, int y);
    
    sf::Vector2i getPosition();
    
    
};



class Settlement
{
private:
    std::string name;
    //Todo (Settlement,Relation) vector
    sf::Vector2i position;
    std::vector<District> districts;
    
    //Stores the max distance of the product furthest away. That way we don't have to search the districts and products every time we need it
    float maxDistance;
    int radius; //Radius of the circle of an areas reach
    
    
    
    
    
public:
    Settlement();
    
    EntityTile tile;
    
    std::vector<sf::Vector2i> area; //The circle for maxDistance. Just here for testing for now

    
    void loadTile(const std::string& tileset, int tileXSize,int tileYSize);
    
    void setPosition(int x, int y);
    void setMaxDist(float val);
    
     sf::Vector2i getPosition();
    float getMaxDist();
    sf::Vector2i getRandomPointInCircle();
    
    
    
    
};




//Test data follows here
#define NUM_TEST_SETTLEMENTS 3



extern std::vector<Settlement> settlements;
extern ResourceFunction testResourceFunctions[10];
extern int numResFunctions;



void createTestSettlements();







#endif /* SettlementEV_hpp */
