//
//  Resource.hpp
//  Colony
//
//  Created by Sean on 5/28/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Resource_hpp
#define Resource_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Material.hpp"

class Resource;


//Need a resource ruleset that determines what trees/plants can appear accoriding to biome

#define MAX_RESOURCES_PER_GROUP 10

class Plant;
class Tree;







extern int numWoodResources;


//For testing
void GenerateTestResources();


enum EnResourceCategory{enMetal,enStone,enPlant,enWood,enFood,enUndefinedResourceCategory,enErrorResourceCategory,enOre,enTree};

class Resource
{
private:
    bool isRenewable;
    bool isEdible;
    EnResourceCategory resourceCategory;
    std::string name;
    float rarity;
    Material material;
    
    
    
public:
    Resource();
    Resource(bool _isRenewable,EnResourceCategory _resourceCategory,std::string _name,float _rarity,bool _isEdible);
    
    void setResourceCategory(EnResourceCategory category);
    void setIsRenewable(bool val);
    void setResourceName(std::string _name);
    void setRarity(float _rarity);
    void setIsEdible(bool val);
    void setName(std::string _name);
    void setMaterial(Material _material);
    void setMaterialName(std::string str);
    
    bool getIsRenewable();
    EnResourceCategory getResourceCategory();
    std::string getResourceName();
    float getRarity();
    bool getIsEdible();
    std::string getName();
    Material getMaterial();
    std::string getMaterialName();
    
};



#endif /* Resource_hpp */
