//
//  TestData.hpp
//  Colony
//
//  Created by Sean on 9/3/17.
//  Copyright © 2017 Afromullet. All rights reserved.
//


#include <stdio.h>


#include <iostream>

#include <vector>



#ifndef TestData_hpp
#define TestData_hpp





#include "BaseCreature.hpp"

extern BaseCreature testCreature1;

void setupTestCreatures();




//extern Weapon weapon1;



short int randBonus();
short int randRangeWeaponRange();




Weapon generateRandomWeapon();












#endif /* TestData_hpp */
