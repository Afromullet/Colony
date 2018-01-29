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
#include "Chest.hpp"
#include "Head.hpp"


#ifndef TestData_hpp
#define TestData_hpp











//extern Weapon weapon1;



short int randBonus();
short int randRangeWeaponRange();



Chest generateChest();
Head generateHead();
Weapon generateRandomWeapon();
EnumWeaponClass randomWeaponClass();

EnumArmorClass randArmorClass();



void printWeaponClass(EnumWeaponClass weaponClass);

std::string getWeaponClassString(EnumWeaponClass weaponClass);







#endif /* TestData_hpp */
