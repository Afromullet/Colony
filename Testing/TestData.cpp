//
//  TestData.cpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//

#include "TestData.hpp"
#include "TestDataGenerator.hpp"
#include <cstdlib>

#ifdef DEBUG_OUTPUT
#include <fstream>
#include <iostream>
#endif

/*
 Todo, do better random generation
 Replace iterators with .size()
 
 
 */


BaseCreature testCreature1;

void setupTestCreatures()
{
    
    testCreature1 = basicOrc;
    testCreature1.setPosition(5, 5);
}


//To save myself some typing
short int randBonus()
{
    return rand() % 10;
    
}

//Need a longer range for ranged weapons...used for random ranged weapon generation
short int randRangeWeaponRange()
{
    return rand() & 50;
}












