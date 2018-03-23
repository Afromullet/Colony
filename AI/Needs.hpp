//
//  Needs.hpp
//  Colony
//
//  Created by Sean on 3/23/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef Needs_hpp
#define Needs_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "AbstractAction.hpp"


class Needs;

/*
 A need consists of a graph of actions that can be used to fulfill it.
 
 
 
 */


enum NeedType
{
    enFoodNeed,
    enWaterNeed,
    enArmorNeed,
    enWeaponneed,
    enWeaponLocationNeed,
    enArmorLocationNeed,
    enAllyLocationNeed,
    enEnemyLocationNeed,
    enFoodLocationNeed
   
    
};


class Need
{
    
private:
    
    NeedType enNeedType;
    std::vector<ActionType> validActions; //All actions that are valid for this kind of need
    float value;
    
public:
    Need();
};

class Needs
{
private:
    std::vector<Need> needVector;
public:
    Needs();
    
    void addNeed(Need need);
    
    
    
};


#endif /* Needs_hpp */
